import { InterpretationBuffer } from './abstract/InterpretationBuffer'
import { CompressedSection } from './abstract/Sections'

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
