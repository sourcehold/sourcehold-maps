// /* eslint-disable camelcase */

import CRC32 from 'crc-32'
import { Compression, DictionarySize, explode, implode } from '../vendor/pkware/src/index'
import { through, toBuffer } from '../vendor/pkware/src/stream'
import { Duplex } from 'stream'

// import Module from './pkware.js'

// export function compress (data: Uint8Array, level: number) {
//   level = level || 6

//   const OUTBUFFERSIZE = 31 * 1000 * 1000

//   const implode_nocb = Module.cwrap('implode_nocb', 'number', ['number', 'number', 'number', 'number', 'number', 'number'])
//   const indata = new Uint8Array(data)
//   const indatalen = indata.length

//   const pbInBuff = Module.allocate(indata, 'i8', Module.ALLOC_NORMAL)
//   const pbInBuffEnd = indatalen

//   const outdata = new Uint8Array(OUTBUFFERSIZE)
//   const outdatalen = outdata.length

//   const pbOutBuff = Module.allocate(outdata, 'i8', Module.ALLOC_NORMAL)
//   const pbOutBuffEnd = Module.allocate([outdatalen], 'i32', Module.ALLOC_NORMAL)

//   level = level - 3
//   const type = 0

//   const result = implode_nocb(pbOutBuff, pbOutBuffEnd, pbInBuff, pbInBuffEnd, type, level)
//   console.log(result)

//   const compressed = new Uint8Array(Module.HEAP8.subarray(pbOutBuff, pbOutBuff + Module.getValue(pbOutBuffEnd, 'i32')))

//   Module._free(pbInBuff)
//   Module._free(pbOutBuff)
//   Module._free(pbOutBuffEnd)

//   return compressed
// }

// export function decompress (data: Uint8Array | number[], decompressed_size: number) {
//   const OUTBUFFERSIZE = decompressed_size || 31 * 1000 * 1000

//   const explode_nocb = Module.cwrap('explode_nocb', 'number', ['number', 'number', 'number', 'number'])
//   const indata = new Uint8Array(data)
//   const indatalen = indata.length

//   const pbInBuff = Module.allocate(indata, 'i8', Module.ALLOC_NORMAL)
//   const pbInBuffEnd = indatalen

//   const outdata = new Uint8Array(OUTBUFFERSIZE)
//   const outdatalen = outdata.length

//   const pbOutBuff = Module.allocate(outdata, 'i8', Module.ALLOC_NORMAL)
//   const pbOutBuffEnd = Module.allocate([outdatalen], 'i32', Module.ALLOC_NORMAL)

//   // Call function and get result
//   const result = explode_nocb(pbOutBuff, pbOutBuffEnd, pbInBuff, pbInBuffEnd)

//   if (result !== 1) {
//     throw Error('exploding failed')
//   }

//   const decompressed = new Uint8Array(Module.HEAP8.subarray(pbOutBuff, pbOutBuff + Module.getValue(pbOutBuffEnd, 'i32')))

//   Module._free(pbInBuff)
//   Module._free(pbOutBuff)
//   Module._free(pbOutBuffEnd)

//   return decompressed
// }

export function crc32 (data: Uint8Array) {
  let hash = CRC32.buf(data)
  while (hash < 0) {
    hash += (2 ** 32)
  }
  return hash
}

export function compress (data: Uint8Array, level: number): Promise<Uint8Array> {
  let ds = DictionarySize.Large
  if (level === 5) ds = DictionarySize.Medium
  if (level === 4) ds = DictionarySize.Small
  const d = new Duplex()
  d.push(data)
  d.push(null)
  return new Promise<Uint8Array>(resolve => {
    d.pipe(through(implode(Compression.Binary, ds, { inputBufferSize: data.length, verbose: true }))).pipe(toBuffer((compressedData) => {
      const result = new Uint8Array(compressedData.buffer.slice(0), compressedData.byteOffset, compressedData.byteLength)
      resolve(result)
    }))
  })
}
export async function decompress (data: Uint8Array, decompressedSize: number): Promise<Uint8Array> {
  const d = new Duplex()
  d.push(data)
  d.push(null)
  return new Promise<Uint8Array>(resolve => {
    d.pipe(through(explode({ inputBufferSize: data.length, outputBufferSize: decompressedSize, verbose: true }))).pipe(toBuffer((decompressedData) => {
      const result = new Uint8Array(decompressedData.buffer.slice(0), decompressedData.byteOffset, decompressedData.byteLength)
      resolve(result)
    }))
  })
}
