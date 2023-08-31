import { meshLib } from 'react-isometric-projection'

const { Group, Rect } = meshLib

const mapDimension = 400

const TileMesh = () => {
  const tiles = Array(mapDimension).fill(0).map((_, y) => {
    return Array(mapDimension).fill(0).map((_, x) => {
      return Rect({
        position: `${x} 0 ${y}`,
        dimensions: '1 0 1',
        colors: ['#420', '#420', '#301A00']
      })
    })
  }).flat()

  return (
    Group({
      position: '0 0 0',
      dimensions: '0 0 0',
      viewBoxDimensions: '2 2 2',
      children: tiles
    })
  )
}

export default TileMesh
