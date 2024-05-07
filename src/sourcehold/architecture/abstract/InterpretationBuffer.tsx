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
    return new Uint32Array([...Array(n).keys()].map(() => this.readInt()))
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
    n = n ?? 16000000 // 16MB
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
