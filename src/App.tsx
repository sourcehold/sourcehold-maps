import React from 'react'
import './App.css'
import Toolbar from './components/Toolbar'
import ImportMapFileModal from './components/ImportMapFileModal'
import { fileStateAtom } from './state/FileState'
import { useAtom } from 'jotai'
import { decompress } from './sourcehold/CompressionInterface'

function App () {
  const [file] = useAtom(fileStateAtom)

  return (
    <>
      <div className="App box">
        <Toolbar />
        <div className="boxrow content">
          <p>todo</p>
        </div>
        <div className = "boxrow footer bg-light text-muted font" style={{ paddingLeft: 10 }}>
          <small onClick={async () => {
            const testResult = await decompress(new Uint8Array([0, 6, 130, 36, 37, 15, 2, 254, 1]), 100)
            console.log(testResult)
          }}>Current file: {file.name}</small>
        </div>
      </div>
      <ImportMapFileModal/>
    </>
  )
}

export default App
