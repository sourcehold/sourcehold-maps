import React from 'react'
import './App.css'
import Toolbar from './components/Toolbar'
import ImportMapFileModal from './components/ImportMapFileModal'
import { fileStateAtom } from './state/FileState'
import { useAtom } from 'jotai'
import { compress, decompress } from './sourcehold/CompressionInterface'
import { currentStatusMessageAtom } from './state/CurrentStatusMessage'
import ExportMapToZipModal from './components/EportMaptoZipModal'
import { Tab, TabContainer } from 'react-bootstrap'
import { GUIStateAtom } from './state/GuiState'
import OldTileExplorer from './components/tilemap-explorer/TilemapExplorerTabOld3D'
import { mapStateAtom } from './state/MapState'
import UnitsTab from './components/units-tab/UnitsTab'

function App () {
  const [file] = useAtom(fileStateAtom)
  const [currentStatusMessage] = useAtom(currentStatusMessageAtom)
  const [GUIState] = useAtom(GUIStateAtom)
  const [mapState] = useAtom(mapStateAtom)

  const si = GUIState.tilemapExplorer.section

  let tileExplorer = <div>No map active</div>
  if (mapState !== null) {
    tileExplorer = <OldTileExplorer map={mapState} sectionIndex={si} continuousColorMode={GUIState.tilemapExplorer.continuousColorMode}/>
  }

  return (
    <>
      <div className="App box">
        <TabContainer activeKey={GUIState.activeTabKey}>
          <Toolbar />
          <Tab.Content className="boxrow content text-light align-items-stretch">
            <Tab.Pane eventKey="info" className="align-self-stretch align-items-stretch">TODO</Tab.Pane>
            <Tab.Pane eventKey="tilemap-explorer" className="align-self-stretch align-items-stretch">
              { tileExplorer
              }
            </Tab.Pane>
            <Tab.Pane eventKey='units' className="align-self-stretch align-items-stretch">
              {UnitsTab()}
            </Tab.Pane>
          </Tab.Content>

        </TabContainer>

        <div className = "boxrow footer bg-light text-muted font " style={{ paddingLeft: 10 }}>
          <span >
            <small onClick={async () => {
              const compressed = await compress(new TextEncoder().encode('Hello world!'), 6)
              console.log(compressed)
              const decompressed = await decompress(compressed, undefined)
              console.log(decompressed)
              console.log(new TextDecoder().decode(decompressed))
            }}>Current file: {file.name}</small>
          </span>

          <span className = "ms-auto" style={{ minWidth: '100rem' }}>
            <small>{currentStatusMessage}</small>
          </span>

        </div>
      </div>
      <ImportMapFileModal/>
      <ExportMapToZipModal/>
    </>
  )
}

export default App
