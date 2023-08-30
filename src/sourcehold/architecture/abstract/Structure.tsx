import { InterpretationBuffer } from './InterpretationBuffer'

export class Structure {
  deserialize_from (buffer: InterpretationBuffer): Structure {
    throw Error('not implemented')
  }

  serialize_to (buffer: InterpretationBuffer) {
    throw Error('not implemented')
  }

  async pack () {
    // throw Error('not implemented')
  }

  async unpack () {
    // throw Error('not implemented')
  }

  get_data (): Uint8Array {
    throw Error('not implemented')
  }

  set_data (data: Uint8Array) {
    throw Error('not implemented')
  }
}
