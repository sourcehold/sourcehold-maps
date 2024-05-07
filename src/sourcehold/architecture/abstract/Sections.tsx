import { decompress, crc32, compress } from '../../CompressionInterface'
import { InterpretationBuffer } from './InterpretationBuffer'
import { Structure } from './Structure'

export class Section extends Structure {
  size() {
    throw Error('not implemented')
  }
}

export class SizePrefixedSection extends Structure {
  data_size = 0
  data!: Uint8Array

  serialize_to(buffer: InterpretationBuffer) {
    buffer.writeInt(this.data_size)
    buffer.writeBytes(this.data)

    return this
  }

  deserialize_from(buffer: InterpretationBuffer): SizePrefixedSection {
    this.data_size = buffer.readInt()
    this.data = buffer.readBytes(this.data_size)

    return this
  }

  async pack() {
    this.data_size = this.data.length
  }

  async unpack() {
    this.validate()
  }

  validate() {
    if (this.data_size !== this.data.length) {
      throw Error('size not equal to data length')
    }
  }

  get_data() {
    return this.data
  }

  set_data(data: Uint8Array) {
    this.data = data
  }
}

export class DataSection extends Section {
  length: any
  data: any
  constructor(length: number) {
    super()
    this.length = length
  }

  size() {
    return this.length
  }

  async pack() {
    this.length = this.data.length

    return new Promise<void>((resolve) => resolve())
  }

  async unpack() {
    this.validate()

    return new Promise<void>((resolve) => resolve())
  }

  validate() {
    if (this.length !== this.data.length) {
      throw Error('invalid length specified')
    }
  }

  serialize_to(buffer: InterpretationBuffer) {
    buffer.writeBytes(this.data)
    return this
  }

  deserialize_from(buffer: InterpretationBuffer) {
    this.data = buffer.readBytes(this.length)
    return this
  }

  get_data() {
    return this.data
  }

  set_data(data: Uint8Array) {
    this.data = data
  }
}

export class CompressedSection extends Section {
  compressed_size = 0
  uncompressed_size = 0
  hash = 0
  data!: Uint8Array
  compression_level = 0
  processed_data!: Uint8Array
  size() {
    return 4 + 4 + 4 + this.compressed_size
  }

  deserialize_from(buffer: InterpretationBuffer) {
    this.uncompressed_size = buffer.readInt()
    this.compressed_size = buffer.readInt()
    this.hash = buffer.readInt()
    this.data = buffer.readBytes(this.compressed_size)

    return this
  }

  serialize_to(buffer: InterpretationBuffer) {
    buffer.writeInt(this.uncompressed_size)
    buffer.writeInt(this.compressed_size)
    buffer.writeInt(this.hash)
    buffer.writeBytes(this.data)

    return this
  }

  async unpack() {
    this.compression_level = this.data[1]
    this.processed_data = await decompress(this.data, this.uncompressed_size)
    // this.validate()
  }

  validate() {
    if (crc32(this.processed_data) !== this.hash) {
      throw Error('invalid crc32, check decompression algorithm')
    }
    if (this.processed_data.length !== this.uncompressed_size) {
      throw Error('invalid size spec')
    }
  }

  async pack() {
    this.uncompressed_size = this.processed_data.length
    this.data = await compress(this.processed_data, this.compression_level || 6)
    this.hash = crc32(this.processed_data)
    this.compressed_size = this.data.length
  }

  get_data() {
    return this.processed_data
  }

  set_data(data: Uint8Array) {
    this.processed_data = data
  }
}