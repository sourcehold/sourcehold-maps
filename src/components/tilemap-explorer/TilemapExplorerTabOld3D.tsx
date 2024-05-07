/* eslint-disable camelcase */
import React from 'react'
import Plot from 'react-plotly.js'
import { Map } from '../../sourcehold/architecture/Map'
import { InterpretationBuffer } from '../../sourcehold/architecture/abstract/InterpretationBuffer'
import { TileIndex } from '../../sourcehold/architecture/abstract/Points'
import nj from '@d4c/numjs'
import { Data, Layout } from 'plotly.js'

const OldTileExplorer = (props: { map: Map, sectionIndex: number; continuousColorMode: boolean }) => {
  const { map, sectionIndex, continuousColorMode } = props

  if (map === null || map === undefined) {
    return (
      <div>No map currently imported</div>
    )
  }

  const section = map.directory.sections[map.directory.section_indices.indexOf(sectionIndex)]

  const buffer = new InterpretationBuffer(new Uint8ClampedArray(section.get_data()).buffer)

  const denominator = 80400
  const datasize = buffer.size / denominator

  let data: number[] = null as unknown as number[]

  if (datasize === 2) {
    data = Array.from(buffer.readShorts(80400))
  } else if (datasize === 1) {
    data = Array.from(buffer.readBytes(80400))
  } else if (datasize === 4) {
    data = Array.from(buffer.readInts(80400))
  } else {
    if (datasize === 9) {
      alert('Sorry, this explorer currently does not support this section')
    }
    throw Error(`invalid datasize, are you sure it is a proper tilesection? ${datasize}`)
  }

  let d_value = Array(400).fill(undefined).map(() => Array(400).fill(0))
  const d_value_zeroes = Array(400).fill(0).map(() => Array(400).fill(undefined))
  const d_serialized_i = Array(400).fill(undefined).map(() => Array(400).fill(0))
  const d_serialized_j = Array(400).fill(undefined).map(() => Array(400).fill(0))
  const d_serialized_tile_index = Array(400).fill(undefined).map(() => Array(400).fill(0))
  const d_adjusted_tile_number = Array(400).fill(undefined).map(() => Array(400).fill(0))

  const d_x = Array(400).fill(0).map((v, y) => Array(400).fill(0).map((v, x) => x))
  const d_y = Array(400).fill(0).map((v, y) => Array(400).fill(0).map((v, x) => y))

  let dp = []

  if (continuousColorMode) {
    data.forEach(function (value, index) {
      const p = new TileIndex(index).to_serialized_point().to_adjusted_point()
      d_value[p.i][p.j] = value
      d_value_zeroes[p.i][p.j] = 0
      d_serialized_i[p.i][p.j] = new TileIndex(index).to_serialized_point().i
      d_serialized_j[p.i][p.j] = new TileIndex(index).to_serialized_point().j
      d_serialized_tile_index[p.i][p.j] = index
      d_adjusted_tile_number[p.i][p.j] = Math.floor((p.i * 400) + p.j)
    })

    // if (sectionIndex === 1045) {
    //   d_value_zeroes = d_value_zeroes.map((arr, i) => arr.map((v, j) => d_value_zeroes[i][j] !== undefined ? d_value[i][j] : undefined))
    // }

    dp = [
      {
        z: d_value_zeroes,
        type: 'surface',
        surfacecolor: d_value.map((arr, i) => arr.map((v, j) => d_value[j][i])),
        colorscale: 'Rainbow',
        zmin: 0,
        zmax: (2 ** (datasize * 8)) - 1,
        name: '',
        customdata: nj.stack([
          d_x as unknown as nj.NdArray,
          d_y as unknown as nj.NdArray,
          d_serialized_tile_index as unknown as nj.NdArray,
          d_value as unknown as nj.NdArray], 2).tolist(),
        hovertemplate: (['x:%{customdata[0]:i}',
          'y:%{customdata[1]:i}',
          'serialized index:%{customdata[2]:i}',
          'value:%{customdata[3]:0f}']).join('<br>')
      }
    ]
  } else {
    const unique_values = Array.from(new Set(data)).sort((a, b) => a - b)

    d_value = Array(400).fill(0).map(() => Array(400).fill(0))
    const d_value_indexed = Array(400).fill(0).map(() => Array(400).fill(0))

    data.forEach(function (value, index) {
      const p = new TileIndex(index).to_serialized_point().to_adjusted_point()
      d_value_zeroes[p.i][p.j] = 0
      d_value[p.i][p.j] = value
      d_value_indexed[p.i][p.j] = unique_values.indexOf(value)
      d_serialized_i[p.i][p.j] = new TileIndex(index).to_serialized_point().i
      d_serialized_j[p.i][p.j] = new TileIndex(index).to_serialized_point().j
      d_serialized_tile_index[p.i][p.j] = index
      d_adjusted_tile_number[p.i][p.j] = Math.floor((p.i * 400) + p.j)
    })

    // if (sectionIndex === 1045) {
    //   d_value_zeroes = d_value_zeroes.map((arr, i) => arr.map((v, j) => d_value_zeroes[i][j] !== undefined ? d_value[i][j] : undefined))
    // }

    dp = [
      {
        z: d_value_zeroes,
        type: 'surface',
        surfacecolor: d_value_indexed.map((arr, i) => arr.map((v, j) => d_value_indexed[j][i])),
        colorscale: 'Rainbow',
        zmin: 0,
        zmax: unique_values.length,
        name: '',
        customdata: nj.stack([
          d_x as unknown as nj.NdArray,
          d_y as unknown as nj.NdArray,
          d_serialized_tile_index as unknown as nj.NdArray,
          d_value as unknown as nj.NdArray], 2).tolist(),
        hovertemplate: (['x:%{customdata[0]:i}',
          'y:%{customdata[1]:i}',
          'serialized index:%{customdata[2]:i}',
          'value:%{customdata[3]:0f}']).join('<br>')
      }
    ]
  }

  const layout = {
    yaxis: { scaleanchor: 'x', scaleratio: 1 },
    autosize: false,
    width: 1918,
    height: 875,
    scene: {
      camera: {
        up: { x: 0, y: 0, z: 1 },
        center: { x: 0, y: 0, z: 0 },
        eye: { x: 0.1, y: 0.1, z: 1 }
      }
    }
  }

  return (
    <Plot
      data = {dp as unknown as Data[]}
      layout = {layout as Layout}
      className='d-flex align-self-stretch'
    />
  )
}

export default OldTileExplorer
