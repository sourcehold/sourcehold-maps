/* eslint-disable camelcase */
import JSZip from 'jszip'
import { MapPropertySection1, MapPropertySection2, MapPropertySection3, MapPropertySection4, getSectionClassForIndex } from './Sections'
import { Description } from './Description'
import { Directory } from './Directory'
import { Preview } from './Preview'
import { InterpretationBuffer } from './abstract/InterpretationBuffer'
import { Structure } from './abstract/Structure'

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
  deserialize_from(buffer: InterpretationBuffer) {
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

  serialize_to(buffer: InterpretationBuffer) {
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

  async unpack() {
    await this.preview.unpack()
    await this.description.unpack()
    await this.directory.unpack()
  }

  async pack() {
    this.magic = 0xFFFFFFFF
    await this.preview.pack()
    await this.description.pack()
    await this.directory.pack()
    await this.u1.pack()
    await this.u2.pack()
    await this.u3.pack()
    await this.u4.pack()
  }

  async export_to_zip() {
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
  async import_from_zip(zip: JSZip) {
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

export async function bufferToMap(buffer: ArrayBufferLike): Promise<Map> {
  const map = new Map().deserialize_from(new InterpretationBuffer(buffer))

  return new Promise<Map>(resolve => {
    map.unpack().then(() => {
      resolve(map)
    }).catch((err) => {
      window.alert(err);
    })
  })
}

export async function mapToBuffer(map: Map): Promise<ArrayBuffer> {
  const ab = new ArrayBuffer(32000000);
  const buffer = new InterpretationBuffer(ab);
  await map.pack();
  map.serialize_to(buffer);

  buffer.truncate();

  return buffer.buffer;
}