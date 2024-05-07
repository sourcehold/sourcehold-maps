import { InterpretationBuffer } from './abstract/InterpretationBuffer'
import { CompressedSection } from './abstract/Sections'

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
    await super.pack()
    this.preview_size = this.size()
  }

  validate () {
    if (this.preview_size !== this.size()) {
      throw Error('invalid size')
    }
  }
}
