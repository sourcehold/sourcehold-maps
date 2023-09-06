import React from 'react'
import { compress, decompress } from '../../sourcehold/CompressionInterface'
import { useAtom } from 'jotai'
import { fileStateAtom } from '../../state/FileState'
import { currentStatusMessageAtom } from '../../state/CurrentStatusMessage'

const Footer = () => {
  const [file] = useAtom(fileStateAtom)
  const [currentStatusMessage] = useAtom(currentStatusMessageAtom)

  return (
    <div className = "boxrow footer bg-light text-muted font " style={{ paddingLeft: 10 }}>
      <span className='d-flex' >
        <small onClick={async () => {
          const compressed = await compress(new TextEncoder().encode('Hello world!'), 6)
          console.log(compressed)
          const decompressed = await decompress(compressed, undefined)
          console.log(decompressed)
          console.log(new TextDecoder().decode(decompressed))
        }}>Current file: {file.name}</small>
      </span>

      <span className = "border-start border-dark d-flex ms-auto ps-2" style={{ minWidth: '50%' }}>
        <small>{currentStatusMessage.length > 0 ? currentStatusMessage : 'Status messages appear here'}</small>
      </span>

    </div>
  )
}

export default Footer
