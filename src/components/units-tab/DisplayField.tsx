export type EnumInformation = {[key: number]: string}
export type DisplayFieldType = 'byte' | 'short' | 'int' | 'custom' | 'enumInt' | 'enumShort' | 'enumByte'

export class DisplayField {
  #dataViewTypeFuncs: {
    [key: string]: (dv: DataView, byteOffset: number) => number
  } = {
      byte: (dv: DataView, byteOffset: number) => dv.getInt8(byteOffset),
      short: (dv: DataView, byteOffset: number) => dv.getInt16(byteOffset, true),
      int: (dv: DataView, byteOffset: number) => dv.getInt32(byteOffset, true),
      enumInt: (dv: DataView, byteOffset: number) => dv.getInt32(byteOffset, true),
      enumShort: (dv: DataView, byteOffset: number) => dv.getInt16(byteOffset, true),
      enumByte: (dv: DataView, byteOffset: number) => dv.getInt8(byteOffset)
    }

  name: string
  fieldOffset: number
  type: string
  enumInformation: EnumInformation

  constructor (name: string, fieldOffset: number, type: DisplayFieldType, enumInformation?: EnumInformation) {
    this.name = name
    this.fieldOffset = fieldOffset
    this.type = type
    this.enumInformation = enumInformation || {}
  }

  get #isEnum () {
    return this.type.startsWith('enum')
  }

  get #func () {
    return this.#dataViewTypeFuncs[this.type]
  }

  value (dv: DataView, byteOffset: number): number | string {
    if (this.#isEnum) {
      return this.enumInformation[this.#func(dv, byteOffset + this.fieldOffset)]
    } else {
      return this.#func(dv, byteOffset + this.fieldOffset)
    }
  }
}
