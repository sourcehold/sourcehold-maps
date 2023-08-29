/* eslint-disable camelcase */
import JSZip from 'jszip'
import { compress, decompress, crc32 } from './CompressionInterface'
// const compress: (data: Uint8Array, compression: number) => Uint8Array = (data: Uint8Array, compression: number) => { throw Error('pkware not set') }
// const decompress: (data: Uint8Array, uncompressed_size: number) => Uint8Array = (data: Uint8Array, uncompressedSize: number) => { throw Error('pkware not set') }
// const crc32: (processed_data: any) => number = (processedData: any) => { throw Error('pkware not set') }

const LITTLE_ENDIAN = true

export class InterpretationBuffer {
  buffer: ArrayBuffer
  view: DataView
  index: number
  size: any
  constructor (buffer: ArrayBuffer) {
    // this.data = new Uint8Array(data);
    this.buffer = buffer || new ArrayBuffer(32000000) // 32MB
    this.view = new DataView(this.buffer)
    this.index = 0
    this.size = this.buffer.byteLength
  }

  readShort () {
    const value = this.view.getUint16(this.index, LITTLE_ENDIAN)
    this.index += 2
    return value
  }

  readShorts (n: number) {
    return new Uint16Array([...Array(n).keys()].map(() => this.readShort()))
  }

  readInt () {
    const value = this.view.getUint32(this.index, LITTLE_ENDIAN)
    this.index += 4
    return value
  }

  readInts (n: number) {
    return Array.from(new Uint32Array([...Array(n).keys()].map(() => this.readInt())))
  }

  readByte () {
    const value = this.view.getUint8(this.index)
    this.index += 1
    return value
  }

  readBytes (n: number) {
    return new Uint8Array([...Array(n).keys()].map(() => this.readByte()))
  }

  hasRemaining () {
    return this.index < this.size
  }

  writeInt (value: number) {
    this.ensureSize(undefined)
    // var buffer = new ArrayBuffer(4);
    // var view = new DataView(buffer);
    this.view.setUint32(this.index, value, LITTLE_ENDIAN)
    // for(var i = 0; i < 4; i++) {
    //     this.data[this.index + i] = view.getUint8(i);
    // }
    this.index += 4
    this.size += 4
  }

  writeInts (data: Uint32Array | number[]) {
    data.forEach(v => this.writeInt(v))
  }

  writeByte (value: number) {
    this.ensureSize(undefined)
    this.view.setUint8(this.index, value)
    this.index += 1
    this.size += 1
  }

  writeBytes (data: Uint8Array) {
    data.forEach(v => this.writeByte(v))
  }

  ensureSize (n: number | undefined) {
    const diff = this.size - this.index
    n = n || 16000000 // 16MB
    if (diff < n) {
      const newBuffer = new ArrayBuffer(this.size + n)
      new Uint8Array(newBuffer).set(new Uint8Array(this.buffer))
      this.buffer = newBuffer
      this.view = new DataView(this.buffer)
    }
  }

  truncate () {
    const newBuffer = new ArrayBuffer(this.index)
    new Uint8Array(newBuffer).set(new Uint8Array(this.buffer).subarray(0, this.index))
    this.buffer = newBuffer
    this.view = new DataView(this.buffer)
  }

  getValue () {
    return this.buffer
  }
}

export class Structure {
  deserialize_from (buffer: InterpretationBuffer): Structure {
    throw Error('not implemented')
  }

  serialize_to (buffer: InterpretationBuffer) {
    throw Error('not implemented')
  }

  async pack () {
    // throw "not implemented";
  }

  async unpack () {
    // throw "not implemented";
  }

  get_data (): Uint8Array {
    throw Error('not implemented')
  }

  set_data (data: Uint8Array) {
    throw Error('not implemented')
  }
}

export class SizePrefixedSection extends Structure {
  data_size: number = 0
  data!: Uint8Array

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeInt(this.data_size)
    buffer.writeBytes(this.data)

    return this
  }

  deserialize_from (buffer: InterpretationBuffer): SizePrefixedSection {
    this.data_size = buffer.readInt()
    this.data = buffer.readBytes(this.data_size)

    return this
  }

  async pack () {
    this.data_size = this.data.length
  }

  async unpack () {
    this.validate()
  }

  validate () {
    if (this.data_size !== this.data.length) {
      throw Error('size not equal to data length')
    }
  }

  get_data () {
    return this.data
  }

  set_data (data: Uint8Array) {
    this.data = data
  }
}

export class Section extends Structure {
  size () {
    throw Error('not implemented')
  }
}

export class DataSection extends Section {
  length: any
  data: any
  constructor (length: number) {
    super()
    this.length = length
  }

  size () {
    return this.length
  }

  async pack () {
    this.length = this.data.length
  }

  async unpack () {
    this.validate()
  }

  validate () {
    if (this.length !== this.data.length) {
      throw Error('invalid length specified')
    }
  }

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeBytes(this.data)
    return this
  }

  deserialize_from (buffer: InterpretationBuffer) {
    this.data = buffer.readBytes(this.length)
    return this
  }

  get_data () {
    return this.data
  }

  set_data (data: Uint8Array) {
    this.data = data
  }
}

export class CompressedSection extends Section {
  compressed_size: number = 0
  uncompressed_size: number = 0
  hash: number = 0
  data!: Uint8Array
  compression_level: number = 0
  processed_data!: Uint8Array
  size () {
    return 4 + 4 + 4 + this.compressed_size
  }

  deserialize_from (buffer: InterpretationBuffer) {
    this.uncompressed_size = buffer.readInt()
    this.compressed_size = buffer.readInt()
    this.hash = buffer.readInt()
    this.data = buffer.readBytes(this.compressed_size)

    return this
  }

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeInt(this.uncompressed_size)
    buffer.writeInt(this.compressed_size)
    buffer.writeInt(this.hash)
    buffer.writeBytes(this.data)

    return this
  }

  async unpack () {
    this.compression_level = this.data[1]
    this.processed_data = await decompress(this.data, this.uncompressed_size)
    this.validate()
  }

  validate () {
    if (crc32(this.processed_data) !== this.hash) {
      throw Error('invalid crc32, check decompression algorithm')
    }
    if (this.processed_data.length !== this.uncompressed_size) {
      throw Error('invalid size spec')
    }
  }

  async pack () {
    this.uncompressed_size = this.processed_data.length
    this.data = await compress(this.processed_data, this.compression_level || 6)
    this.hash = crc32(this.processed_data)
    this.compressed_size = this.data.length
  }

  get_data () {
    return this.processed_data
  }

  set_data (data: Uint8Array) {
    this.processed_data = data
  }
}

export class Preview extends CompressedSection {
  preview_size: any
  deserialize_from (buffer: InterpretationBuffer) {
    this.preview_size = buffer.readInt()
    super.deserialize_from(buffer)
    return this
  }

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeInt(this.preview_size)
    super.serialize_to(buffer)
    return this
  }

  async pack () {
    super.pack()
    this.preview_size = this.size
  }

  validate () {
    if (this.preview_size !== this.size) {
      throw Error('invalid size')
    }
  }
}

export class Description extends CompressedSection {
  description_size: any
  use_string_table: any
  string_table_index: any

  deserialize_from (buffer: InterpretationBuffer) {
    this.description_size = buffer.readInt()
    this.use_string_table = buffer.readInt()
    this.string_table_index = buffer.readInt()
    super.deserialize_from(buffer)

    return this
  }

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeInt(this.description_size)
    buffer.writeInt(this.use_string_table)
    buffer.writeInt(this.string_table_index)
    super.serialize_to(buffer)

    return this
  }

  validate () {
    if (this.description_size !== this.compressed_size + (5 * 4)) {
      throw Error('invalid size')
    }
    super.validate()
  }

  async unpack () {
    super.unpack()
  }

  async pack () {
    super.pack()
    this.description_size = this.compressed_size + (5 * 4)
  }
}

export class Directory extends Structure {
  u1: any
  directory_size: any
  total_data_size: any
  sections_count: any
  u2: any
  u3: any
  u4: any
  u5: any
  section_uncompressed_lengths: any
  section_lengths!: number[]
  section_indices!: number[]
  section_compressed!: number[]
  section_offsets!: number[]
  u6: any
  sections: Section[] = []
  get max_sections_count () {
    return this.u1 >= 161 ? 150 : 100
  }

  deserialize_from (buffer: InterpretationBuffer) {
    this.directory_size = buffer.readInt()
    this.total_data_size = buffer.readInt()
    this.sections_count = buffer.readInt()
    this.u1 = buffer.readInt()
    this.u2 = buffer.readInt()
    this.u3 = buffer.readInt()
    this.u4 = buffer.readInt()
    this.u5 = buffer.readInt()
    this.section_uncompressed_lengths = buffer.readInts(this.max_sections_count)
    this.section_lengths = buffer.readInts(this.max_sections_count)
    this.section_indices = buffer.readInts(this.max_sections_count)
    this.section_compressed = buffer.readInts(this.max_sections_count)
    this.section_offsets = buffer.readInts(this.max_sections_count)
    this.u6 = buffer.readInt()

    this.sections = []
    for (let i = 0; i < this.sections_count; i++) {
      const compressed = this.section_compressed[i] === 1
      const length = this.section_lengths[i]
      const index = this.section_indices[i]
      const Cls = getSectionClassForIndex(index, compressed)
      this.sections.push((new Cls(length).deserialize_from(buffer)) as Section)
    }

    return this
  }

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeInt(this.directory_size)
    buffer.writeInt(this.total_data_size)
    buffer.writeInt(this.sections_count)
    buffer.writeInt(this.u1)
    buffer.writeInt(this.u2)
    buffer.writeInt(this.u3)
    buffer.writeInt(this.u4)
    buffer.writeInt(this.u5)
    buffer.writeInts(this.section_uncompressed_lengths)
    buffer.writeInts(this.section_lengths)
    buffer.writeInts(this.section_indices)
    buffer.writeInts(this.section_compressed)
    buffer.writeInts(this.section_offsets)
    buffer.writeInt(this.u6)

    for (const section of this.sections) {
      section.serialize_to(buffer)
    }

    return this
  }

  async pack () {
    for (const section of this.sections) {
      await section.pack()
    }

    let accumulator = 0

    this.sections_count = this.sections.length
    for (const i in this.sections) {
      const section = this.sections[i]
      if (section instanceof CompressedSection) {
        this.section_uncompressed_lengths[i] = section.uncompressed_size
        this.section_lengths[i] = section.size()
        this.section_compressed[i] = 1
      } else if (section instanceof DataSection) {
        this.section_uncompressed_lengths[i] = section.size()
        this.section_lengths[i] = section.size()
        this.section_compressed[i] = 0
      }

      this.section_offsets[i] = accumulator
      accumulator += this.section_lengths[i]
    }

    for (let i = this.sections_count; i < this.max_sections_count; i++) {
      this.section_lengths[i] = 0
      this.section_uncompressed_lengths[i] = 0
      this.section_compressed[i] = 0
      this.section_indices[i] = 0
      this.section_offsets[i] = 0 // TODO check this
    }

    this.total_data_size = accumulator
    this.directory_size = (20 * this.max_sections_count) + 36
  }

  section_for_index (index: number) {
    const i = this.section_indices.indexOf(index)
    if (i === -1) {
      throw Error('index not found in directory')
    }
    return this.sections[i]
  }

  async unpack () {
    for (const section of this.sections) {
      await section.unpack()
    }
  }
}

export class MapPropertySection1 extends SizePrefixedSection {

}

export class MapPropertySection2 extends SizePrefixedSection {

}

export class MapPropertySection3 extends SizePrefixedSection {

}

export class MapPropertySection4 extends SizePrefixedSection {

}

export class Map extends Structure {
  magic: any
  preview: Preview = new Preview()
  description: Description = new Description()
  u1: MapPropertySection1 = new MapPropertySection1()
  u2: MapPropertySection2 = new MapPropertySection2()
  u3: MapPropertySection3 = new MapPropertySection3()
  u4: MapPropertySection4 = new MapPropertySection4()
  ud: any
  directory: Directory = new Directory()
  deserialize_from (buffer: InterpretationBuffer) {
    this.magic = buffer.readInt()
    this.preview = new Preview().deserialize_from(buffer)
    this.description = new Description().deserialize_from(buffer)
    this.u1 = new MapPropertySection1().deserialize_from(buffer)
    this.u2 = new MapPropertySection2().deserialize_from(buffer)
    this.u3 = new MapPropertySection3().deserialize_from(buffer)
    this.u4 = new MapPropertySection4().deserialize_from(buffer)
    this.ud = buffer.readInt()

    this.directory = new Directory().deserialize_from(buffer)
    return this
  }

  serialize_to (buffer: InterpretationBuffer) {
    buffer.writeInt(this.magic)
    this.preview.serialize_to(buffer)
    this.description.serialize_to(buffer)
    this.u1.serialize_to(buffer)
    this.u2.serialize_to(buffer)
    this.u3.serialize_to(buffer)
    this.u4.serialize_to(buffer)
    buffer.writeInt(this.ud)

    this.directory.serialize_to(buffer)

    return this
  }

  async unpack () {
    await this.preview.unpack()
    await this.description.unpack()
    await this.directory.unpack()
  }

  async pack () {
    this.magic = 0xFFFFFFFF
    await this.preview.pack()
    await this.description.pack()
    await this.directory.pack()
    await this.u1.pack()
    await this.u2.pack()
    await this.u3.pack()
    await this.u4.pack()
  }

  async export_to_zip () {
    await this.unpack()

    // eslint-disable-next-line no-undef
    const zip = new JSZip()

    const preview_folder = zip.folder('preview')
    if (preview_folder === null) throw Error('null')
    preview_folder.file('processed_data', this.preview.processed_data)

    const description_folder = zip.folder('description')
    if (description_folder === null) throw Error('null')
    description_folder.file('processed_data', this.description.processed_data)
    description_folder.file('use_string_table', this.description.use_string_table.toString())
    description_folder.file('string_table_index', this.description.string_table_index.toString())

    const directory_folder = zip.folder('directory')
    if (directory_folder === null) throw Error('null')
    const compressed = this.directory.section_compressed.join(',')
    const indices = this.directory.section_indices.join(',')
    directory_folder.file('section_compressed', compressed)
    directory_folder.file('section_indices', indices)

    for (const index in this.directory.sections) {
      // const section = this.directory.sections[index]
      const key = this.directory.section_indices[index]

      directory_folder.file(key.toString(), this.directory.sections[index].get_data())
    }

    directory_folder.file('u1', this.directory.u1.toString())
    directory_folder.file('u2', this.directory.u2.toString())
    directory_folder.file('u3', this.directory.u3.toString())
    directory_folder.file('u4', this.directory.u4.toString())
    directory_folder.file('u5', this.directory.u5.toString())
    directory_folder.file('u6', this.directory.u6.toString())

    zip.file('u1', this.u1.get_data())
    zip.file('u2', this.u2.get_data())
    zip.file('u3', this.u3.get_data())
    zip.file('u4', this.u4.get_data())
    zip.file('ud', this.ud.toString())

    return zip
  }

  // eslint-disable-next-line no-undef
  async import_from_zip (zip: JSZip) {
    const preview_folder = zip.folder('preview')
    if (preview_folder === null) throw Error('null')
    this.preview = new Preview()
    const pfpd = preview_folder.file('processed_data')
    if (pfpd === null) throw Error('null')
    this.preview.processed_data = await pfpd.async('uint8array')

    const description_folder = zip.folder('description')
    if (description_folder === null) throw Error('null')
    this.description = new Description()
    const dfpd = description_folder.file('processed_data')
    if (dfpd === null) throw Error('null')
    this.description.processed_data = await dfpd.async('uint8array')
    const dfust = description_folder.file('use_string_table')
    if (dfust === null) throw Error('null')
    this.description.use_string_table = parseInt(await dfust.async('string'))
    const dfsti = description_folder.file('string_table_index')
    if (dfsti === null) throw Error('null')
    this.description.string_table_index = parseInt(await dfsti.async('string'))

    const directory_folder = zip.folder('directory')
    if (directory_folder === null) throw Error('null')
    this.directory = new Directory()
    const f1 = directory_folder.file('section_compressed')
    if (f1 === null) throw Error('null')
    const compressed = await f1.async('string')
    this.directory.section_compressed = compressed.split(',').map((v: string) => parseInt(v))
    const f2 = directory_folder.file('section_indices')
    if (f2 === null) throw Error('null')
    const indices = await f2.async('string')
    this.directory.section_indices = indices.split(',').map((v: string) => parseInt(v))

    this.directory.sections = []
    this.directory.section_offsets = []
    this.directory.section_lengths = []
    this.directory.section_uncompressed_lengths = []

    let count = 0

    for (const index in this.directory.section_indices) {
      const key = this.directory.section_indices[index]
      const compressed2 = this.directory.section_compressed[index]

      if (key === 0) {
        this.directory.section_offsets.push(0)
        this.directory.section_lengths.push(0)
        this.directory.section_uncompressed_lengths.push(0)
      } else {
        count += 1
        const Cls = getSectionClassForIndex(key, compressed2 === 1)
        const kf = directory_folder.file(key.toString())
        if (kf === null) throw Error('null')
        const data = await kf.async('uint8array')
        const length = data.length
        const section = new Cls(length)
        section.set_data(data)

        this.directory.sections.push(section)
        this.directory.section_offsets.push(0) // These values will be set later when pack() is called;
        this.directory.section_lengths.push(0) // These values will be set later when pack() is called;
        this.directory.section_uncompressed_lengths.push(0) // These values will be set later when pack() is called;
      }
    }

    this.directory.sections_count = count

    const u1f = directory_folder.file('u1')
    if (u1f === null) throw Error('null')
    const u2f = directory_folder.file('u2')
    if (u2f === null) throw Error('null')
    const u3f = directory_folder.file('u3')
    if (u3f === null) throw Error('null')
    const u4f = directory_folder.file('u4')
    if (u4f === null) throw Error('null')
    const u5f = directory_folder.file('u5')
    if (u5f === null) throw Error('null')
    const u6f = directory_folder.file('u6')
    if (u6f === null) throw Error('null')
    this.directory.u1 = parseInt(await u1f.async('string'))
    this.directory.u2 = parseInt(await u2f.async('string'))
    this.directory.u3 = parseInt(await u3f.async('string'))
    this.directory.u4 = parseInt(await u4f.async('string'))
    this.directory.u5 = parseInt(await u5f.async('string'))
    this.directory.u6 = parseInt(await u6f.async('string'))

    const ru1 = zip.file('u1')
    if (ru1 === null) throw Error('null')
    const ru2 = zip.file('u2')
    if (ru2 === null) throw Error('null')
    const ru3 = zip.file('u3')
    if (ru3 === null) throw Error('null')
    const ru4 = zip.file('u4')
    if (ru4 === null) throw Error('null')
    const rud = zip.file('ud')
    if (rud === null) throw Error('null')
    this.u1 = new MapPropertySection1()
    this.u1.set_data(await ru1.async('uint8array'))
    this.u2 = new MapPropertySection2()
    this.u2.set_data(await ru2.async('uint8array'))
    this.u3 = new MapPropertySection3()
    this.u3.set_data(await ru3.async('uint8array'))
    this.u4 = new MapPropertySection4()
    this.u4.set_data(await ru4.async('uint8array'))
    this.ud = parseInt(await rud.async('string'))

    return this
  }
}

let _BUFFER = new ArrayBuffer(4)
let _VIEW = new DataView(_BUFFER)

export function intToBytes (value: number) {
  _VIEW.setUint32(0, value, LITTLE_ENDIAN)
  return new Uint8Array(_BUFFER)
}

export function bytesToInt (values: Uint8Array) {
  values = values.subarray(0, 4)
  _BUFFER = values.buffer
  _VIEW = new DataView(_BUFFER)
  return _VIEW.getUint32(0, LITTLE_ENDIAN)
}

export class Section1001 extends CompressedSection {

}

export const MAP_SECTIONS: {[key: string]: typeof Section} = {
  1001: Section1001
}

export function getSectionClassForIndex (index: string | number, compressed: boolean) {
  if (Object.keys(MAP_SECTIONS).includes(index.toString())) {
    return MAP_SECTIONS[index]
  }
  if (compressed) {
    return CompressedSection
  }
  return DataSection
}
