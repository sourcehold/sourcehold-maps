import React from 'react'
import './App.css'
import Toolbar from './components/toolbar/Toolbar'
import ImportMapFileModal from './components/modals/ImportMapFileModal'
import { useAtom } from 'jotai'
import ExportMapToZipModal from './components/modals/ExportMaptoZipModal'
import { Tab, TabContainer } from 'react-bootstrap'
import { GUIStateAtom } from './state/GuiState'
import OldTileExplorer from './components/tilemap-explorer/TilemapExplorerTabOld3D'
import { mapStateAtom } from './state/MapState'
import UnitsTab from './components/units-tab/UnitsTab'
import Footer from './components/status-bar/Footer'
import LogModal from './components/modals/LogModal'

function App () {
  const [GUIState] = useAtom(GUIStateAtom)
  const [mapState] = useAtom(mapStateAtom)

  const si = GUIState.tilemapExplorer.section

  return (
    <>
      <div className="App box">
        <TabContainer activeKey={GUIState.activeTabKey}>
          <Toolbar />
          <Tab.Content className="boxrow content text-light align-items-stretch">
            <Tab.Pane eventKey="info" className="align-self-stretch align-items-stretch">Info about map type etcetera should appear here</Tab.Pane>
            <Tab.Pane eventKey="tilemap-explorer" className="align-self-stretch align-items-stretch">
              <OldTileExplorer map={mapState} sectionIndex={si} continuousColorMode={GUIState.tilemapExplorer.continuousColorMode}/>
            </Tab.Pane>
            <Tab.Pane eventKey='units' className="align-self-stretch align-items-stretch">
              <UnitsTab/>
            </Tab.Pane>
          </Tab.Content>
        </TabContainer>
        <Footer/>
      </div>
      <ImportMapFileModal/>
      <ExportMapToZipModal/>
      <LogModal/>
    </>
  )
}

export default App
