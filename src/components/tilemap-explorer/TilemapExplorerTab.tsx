import React, { useRef, useState } from 'react'

import './TilemapExplorerTab.css'

const mapData = Array(400 * 400).fill(1)

export function TilemapExplorerTab () {
  const [mapXPosition, setMapXPosition] = useState(0)
  const [mapYPosition, setMapYPosition] = useState(0)

  // const mapData = [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 3, 3, 4, 4, 3, 4, 3, 3, 2, 2, 2, 2, 1, 1, 2, 2, 3, 4, 8, 8, 4, 4, 3, 4, 4, 3, 2, 2, 1, 1, 2, 3, 3, 4, 16, 16, 16, 16, 4, 16, 5, 4, 3, 2, 2, 1, 2, 3, 4, 5, 16, 9, 9, 8, 4, 16, 8, 5, 4, 3, 2, 1, 2, 3, 4, 5, 5, 8, 8, 16, 9, 8, 8, 5, 4, 3, 2, 1, 2, 3, 3, 4, 5, 5, 8, 8, 8, 8, 5, 4, 3, 2, 2, 2, 2, 2, 3, 3, 4, 5, 8, 5, 5, 5, 4, 4, 3, 2, 2, 2, 1, 2, 2, 3, 3, 4, 5, 5, 5, 5, 4, 3, 2, 2, 2, 2, 1, 1, 2, 2, 3, 4, 4, 5, 5, 4, 4, 3, 2, 2, 2, 2, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 3, 3, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1]

  // const rows: React.JSX.Element[] = []
  // const cols: React.JSX.Element[] = []
  const tiles: React.JSX.Element[] = []

  // const tilesMap: React.JSX.Element[][] = []

  const mapSize = 400
  // const width = mapSize
  const height = mapSize

  // for (let y = 0; y < height; y++) {
  //   tilesMap.push((new Array(width)).fill(undefined))
  // }

  // const rowColMapping: {
  //   [key: string]: {
  //     [key: string]: {
  //       [key: string]: React.JSX.Element
  //     }
  //   }
  // } = {}

  // const getRow = (y: number) => {
  //   const results = rows.filter((e) => e.props.className.indexOf(`row-${y}`) !== -1)
  //   if (results.length > 0) {
  //     return results[0]
  //   } else {
  //     return createRow(y)
  //   }
  // }

  // const createRow = (y: number) => {
  //   const row = <tr className={`row-${y}`} style={{ transform: `translateY(${y * 4}em)` }} />

  //   rows.push(row)

  //   rowColMapping[`row-${y}`] = {}

  //   return row
  // }

  // const getCol = (y:number, x: number) => {
  //   const results = rows.filter((e) => e.props.className.indexOf(`col-${x}`) !== -1)
  //   if (results.length > 0) {
  //     return results[0]
  //   } else {
  //     return createCol(y, x)
  //   }
  // }

  // const createCol = (y: number, x:number) => {
  //   const col = <td className={`col-${x}`} style={{ transform: `translateX(${x * 4}em)` }}/>

  //   cols.push(col)

  //   return col
  // }

  // const getTile = (x: number, y:number) => {
  //   return tilesMap[y][x]
  // }

  const createTile = (x: number, y:number, tileNo: number) => {
    const tile = <div className='tile' style={{ zIndex: (1000 + x + y) * 2 }}>
      <div className={`tile-${tileNo}`}>

      </div>
    </div>

    tiles.push(tile)

    // tilesMap[y][x] = tile

    return tile
  }

  // const setTile = (x: number, y:number, tileNo: number) => {
  //   let tile = getTile(x, y)
  //   if (tile === undefined || tile === null) {
  //     tile = createTile(x, y, tileNo)
  //   }
  //   tile.props.className = `tile-${tileNo}`
  // }

  // for (let y = 0; y < mapSize; y++) {
  //   for (let x = 0; x < mapSize; x++) {
  //     setTile(x - (mapSize / 2), y - (mapSize / 2), mapData[(y * mapSize) + x] - 1)
  //   };
  // };

  const tableRef = useRef<HTMLTableElement | null>(null)

  const a = Array(height).fill(0).map((_, y) => {
    return (
      <tr key={y} className={`row-${y}`} style={{ transform: `translateY(${y * 4}em)` }} >
        {Array(height).fill(0).map((_, x) => {
          return (
            <td key={x} className={`col-${x}`} style={{ transform: `translateX(${x * 4}em)` }}>
              {createTile(x - (mapSize / 2), y - (mapSize / 2), mapData[(y * mapSize) + x] - 1)}
            </td>
          )
        })}
      </tr>
    )
  })

  let mousePosX = 0
  let mousePosY = 0
  let dragging = false

  const onMouseDown = (e: React.MouseEvent<HTMLDivElement, MouseEvent>) => {
    console.log(`Mouse down. Dragging: ${dragging}`)

    document.addEventListener('mouseup', onMouseUp)
    document.addEventListener('mousemove', onMouseMove)

    mousePosX = (e.pageX)
    mousePosY = (e.pageY)

    dragging = true
  }

  const onMouseMove = (e: MouseEvent) => {
    if (dragging) {
      setMapXPosition(mapXPosition + (e.pageX - mousePosX))
      setMapYPosition(mapYPosition + (e.pageY - mousePosY))
    }
  }

  const onMouseUp = (e: MouseEvent) => {
    console.log(`Mouse Up. Dragging: ${dragging}`)

    dragging = false

    document.removeEventListener('mouseup', onMouseUp)
    document.removeEventListener('mousemove', onMouseMove)
  }

  return (
    <div id="tileMapDiv" className='d-flex align-self-stretch'>
      <table ref={(r) => { tableRef.current = r }} style={{
        top: ((window.innerHeight / 2) - 100 / 2) + mapYPosition,
        left: ((window.innerWidth / 2) - 100 / 2) + mapXPosition
      }} onMouseDown={(e) => { onMouseDown(e) }}>
        <tbody>
          {
            a
          }
        </tbody>
      </table>
    </div>
  )
}
