import CRC32 from 'crc-32'
import { Compression, DictionarySize, explode, implode } from '../vendor/pkware/src/index'
import { through, toBuffer } from '../vendor/pkware/src/stream'
import { Duplex } from 'stream'

export function crc32 (data: Uint8Array) {
  let hash = CRC32.buf(data)
  while (hash < 0) {
    hash += (2 ** 32)
  }
  return hash
}

export function compress (data: Uint8Array, level: number | DictionarySize): Promise<Uint8Array> {
  let ds = DictionarySize.Large
  if (level === 5) ds = DictionarySize.Medium
  if (level === 4) ds = DictionarySize.Small
  const d = new Duplex()
  d.push(data)
  d.push(null)
  return new Promise<Uint8Array>(resolve => {
    d.pipe(through(implode(Compression.Binary, ds, { inputBufferSize: data.length, verbose: false }))).pipe(toBuffer((compressedData) => {
      const result = new Uint8Array(compressedData.buffer.slice(0), compressedData.byteOffset, compressedData.length)
      resolve(result)
    }))
  })
}

export async function decompress (data: Uint8Array, decompressedSize: number | undefined): Promise<Uint8Array> {
  const d = new Duplex()
  d.push(data)
  d.push(null)
  return new Promise<Uint8Array>(resolve => {
    d.pipe(through(explode({ inputBufferSize: data.length, outputBufferSize: decompressedSize || 0, verbose: false }))).pipe(toBuffer((decompressedData) => {
      const result = new Uint8Array(decompressedData.buffer.slice(0), decompressedData.byteOffset, decompressedData.length)
      resolve(result)
    }))
  })
}
