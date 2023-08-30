import { getSectionClassForIndex } from './Sections'
import { InterpretationBuffer } from './abstract/InterpretationBuffer'
import { Section, CompressedSection, DataSection } from './abstract/Sections'
import { Structure } from './abstract/Structure'

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
