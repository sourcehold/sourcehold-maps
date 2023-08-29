import React from 'react'
import './App.css'
import Toolbar from './components/Toolbar'
import ImportMapFileModal from './components/ImportMapFileModal'
import { fileStateAtom } from './state/FileState'
import { useAtom } from 'jotai'
import { compress, decompress } from './sourcehold/CompressionInterface'
import { currentStatusMessageAtom } from './state/CurrentStatusMessage'

function App () {
  const [file] = useAtom(fileStateAtom)
  const [currentStatusMessage] = useAtom(currentStatusMessageAtom)

  return (
    <>
      <div className="App box">
        <Toolbar />
        <div className="boxrow content">
          <p>todo</p>
        </div>
        <div className = "boxrow footer bg-light text-muted font" style={{ paddingLeft: 10 }}>
          <span>
          <small onClick={async () => {
            const compressed = await compress(new TextEncoder().encode('Hello world!'), 6)
            console.log(compressed)
            const decompressed = await decompress(compressed, undefined)
            console.log(decompressed)
            console.log(new TextDecoder().decode(decompressed))
          }}>Current file: {file.name}</small>
          </span>
          <span>
            {currentStatusMessage}
          </span>
        </div>
      </div>
      <ImportMapFileModal/>
    </>
  )
}

export default App
