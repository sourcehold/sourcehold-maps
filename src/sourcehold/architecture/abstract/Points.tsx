/* eslint-disable camelcase */
export class SerializedPoint {
  i: number
  j: number
  size: number
  n_serialized_tiles: number
  constructor (i: number, j: number, size = 400) {
    this.i = i
    this.j = j
    this.size = size
    this.n_serialized_tiles = (2 * ((this.size / 2) * ((this.size / 2) + 1)))
  }

  to_tile_index () {
    if (this.i < (this.size / 2)) {
      return new TileIndex((this.i * (this.i + 1)) + this.j)
    } else {
      return new TileIndex((this.n_serialized_tiles - ((this.size - this.i) * (this.size - this.i + 1))) + this.j)
    }
  }

  to_adjusted_point () {
    if (this.i < this.size / 2) {
      return new AdjustedPoint(this.i, this.j + Math.abs(((this.size / 2) - 1) - this.i))
    } else {
      return new AdjustedPoint(this.i, this.j + Math.abs((this.size / 2) - this.i))
    }
  }

  to_screen_point () {
    let tx = -1; let ty = -1
    if (this.i < this.size / 2) {
      tx = (this.i * 2) + 1 - this.j
    } else {
      tx = this.size - this.j
    }

    if (this.i < this.size / 2) {
      ty = this.j
    } else {
      ty = (this.i - (this.size / 2)) * 2 + 1 + this.j
    }

    return new ScreenPoint(tx, ty)
  }
}

export class AdjustedPoint {
  i: number
  j: number
  size: number
  n_serialized_tiles: number
  constructor (i: number, j: number, size = 400) {
    this.i = i
    this.j = j
    this.size = size
    this.n_serialized_tiles = (2 * ((this.size / 2) * ((this.size / 2) + 1)))
  }
}

export class TileIndex {
  index: number
  size: number
  n_serialized_tiles: number
  constructor (index: number, size = 400) {
    this.index = index
    this.size = size
    this.n_serialized_tiles = (2 * ((this.size / 2) * ((this.size / 2) + 1)))
  }

  to_serialized_point () {
    let i = -1
    if (this.index < this.n_serialized_tiles / 2) {
      i = Math.floor(0.5 * ((Math.sqrt((4 * this.index) + 1)) - 1))
    } else {
      i = Math.floor(this.size - (0.5 * ((Math.sqrt((4 * ((2 * ((this.size / 2) * ((this.size / 2) + 1))) - this.index)) + 1)) - 1)))
    }
    const index = (new SerializedPoint(i, 0)).to_tile_index().index
    const j = this.index - index

    return new SerializedPoint(i, j)
  }
}

export class ScreenPoint {
  x: number
  y: number
  size: number
  constructor (x: number, y: number, size = 400) {
    this.x = x
    this.y = y
    this.size = size
  }

  get_diamond (tile_width = 32, tile_height = 16, x_offset = 16, y_offset = 16) {
    const x = this.x * (tile_width / 2)
    const y = this.y * (tile_height / 2)

    const xoff = x + x_offset
    const yoff = y + y_offset

    // let full_width = Math.floor((this.size + 1) * tile_width * 0.5)
    // full_width = Math.sqrt(this.size ** 2 + this.size ** 2) * tile_width
    // const full_height = Math.floor(this.size * tile_height * 0.5)

    return [
      [xoff, yoff],
      [xoff + (tile_width / 2), yoff + (tile_height / 2)],
      [xoff, yoff + tile_height],
      [xoff - (tile_width / 2), yoff + (tile_height / 2)]
    ]
  }
}

export class DiamondSystem {
  size: number
  constructor (size = 400) {
    this.size = size
  }

  to_screen_system (i: number, j: number) {
    // const x = i
    // const y = j

    // let tx = -1
    // let ty = -1

    // if (x < this.size / 2) {
    //   tx = (x * 2) + 1 - y
    // } else {
    //   tx = this.size - y
    // }

    // if (x < this.size / 2) {
    //   ty = y
    // } else {
    //   ty = (x - cut) * 2 + 1 + y
    // }
  }
}
