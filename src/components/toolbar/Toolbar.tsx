import React from 'react'
import { Container, Form, Nav, NavDropdown, Navbar } from 'react-bootstrap'
import { showImportMapFileModalDialog } from '../modals/ImportMapFileModal'
import { useAtom } from 'jotai/react'
import { fileStateAtom } from '../../state/FileState'
import { mapStateAtom, mapStateAvailableTileMapSectionsAtom } from '../../state/MapState'
import { bufferToMap } from '../../sourcehold/architecture/Map'
import { GUIStateAtom } from '../../state/GuiState'
import { showExportMapToZipModalDialog } from '../modals/ExportMaptoZipModal'
import { debug, info, trace } from '../../state/LogState'

function Toolbar () {
  const [fileState, setFileState] = useAtom(fileStateAtom)

  const [mapState, setMapState] = useAtom(mapStateAtom)

  const [GUIState, setGUIState] = useAtom(GUIStateAtom)

  const [mapStateAvailableTileMapSections] = useAtom(mapStateAvailableTileMapSectionsAtom)

  const addOnTilemapExplorer = <Navbar.Collapse className="align-items-stretch"><Form.Select onChange={(e) => {
    setGUIState({ ...GUIState, tilemapExplorer: { ...GUIState.tilemapExplorer, section: parseInt(e.target.value) } })
  }}>
      <option value="0">Select a tilemap to explore (default: 1001)</option>
      {
        mapStateAvailableTileMapSections.map((v) => <option value={`${v}`} key={`section-option-${v}`}>
          {`Section: ${v}`}
        </option>)
      }
    </Form.Select>
    <Form.Switch style={{ width: '300px', paddingLeft: '50px' }} label="Continuous colors" id="continuous-colors-switch" checked={GUIState.tilemapExplorer.continuousColorMode} onChange={(e) => {
      setGUIState({ ...GUIState, tilemapExplorer: { ...GUIState.tilemapExplorer, continuousColorMode: e.target.checked } })
    }} />
    </Navbar.Collapse>

  return (
    <Navbar expand="lg" className="bg-body-tertiary boxrow header">
      <Container style={{ marginLeft: 0 }}>
        <Navbar.Brand>Map editor</Navbar.Brand>
        <Navbar.Toggle aria-controls="basic-navbar-nav" />
        <Navbar.Collapse id="basic-navbar-nav">
          <Nav variant="tabs" defaultActiveKey="info" onSelect={(e) => {
            if (e !== null) {
              setGUIState({ ...GUIState, activeTabKey: e })
            }
          }}>
            <NavDropdown title="File" id="basic-nav-dropdown">
              <NavDropdown.Item href="#file/import" onClick={async () => {
                console.log('CLICK')
                const result = await showImportMapFileModalDialog({
                  handleOK: (f: File) => {
                    debug(f.name)
                    // setFileState(file)
                  }
                })

                if (result.status === 'ok') {
                  trace('OK')
                  info(`Importing file... ${result.file.name}`)
                  setFileState(result.file)
                  const map = await result.file.arrayBuffer().then((b: ArrayBufferLike) => {
                    info('Converting file contents to a Map object')
                    return bufferToMap(b)
                  })
                  console.log(map)
                  info(`Import succesful, setting map object: ${map}`)
                  setMapState(map)
                } else {
                  info('Import cancelled by user')
                  console.log('CANCEL')
                }
              }}>Import .map</NavDropdown.Item>
              <NavDropdown.Item href="#file/export">
                Export .map
              </NavDropdown.Item>
              <NavDropdown.Divider />
              <NavDropdown.Item href="#file/import-zip">Import .map from .zip</NavDropdown.Item>
              <NavDropdown.Item href="#file/export-zip" onClick={async (e) => {
                const prefixMessage = `Creating zip from map file '${fileState.name}'`
                info(prefixMessage)

                if (mapState === null) {
                  info(`${prefixMessage}... aborted: no map file loaded`)
                  return
                }

                mapState.export_to_zip().then((z) => {
                  info(`${prefixMessage}... creating binary Blob`)
                  return z.generateAsync({ type: 'blob' }).then(async (zip) => {
                    info(`${prefixMessage}... creating Object URL`)

                    const url = window.URL.createObjectURL(zip)

                    info(`${prefixMessage}... showing export dialog`)
                    const dialogResult = await showExportMapToZipModalDialog({
                      fileName: fileState.name + '.zip',
                      objectURL: url
                    })

                    if (dialogResult === true) {
                      info(`${prefixMessage}... export finished, file downloaded`)
                    } else {
                      info(`${prefixMessage}... export cancelled`)
                    }
                  })
                })
              }}>
                Export .map as .zip
              </NavDropdown.Item>
            </NavDropdown>
            <Nav.Item>
              <Nav.Link eventKey="info">Info</Nav.Link>
            </Nav.Item>
            <Nav.Item>
              <Nav.Link eventKey="tilemap-explorer">Tilemap explorer</Nav.Link>
            </Nav.Item>
            <Nav.Item>
              <Nav.Link eventKey="units">
                Units
              </Nav.Link>
            </Nav.Item>
          </Nav>
        </Navbar.Collapse>
        <div className="me-auto">
        {
              GUIState.activeTabKey === 'tilemap-explorer' ? addOnTilemapExplorer : (<></>)
        }
        </div>
      </Container>

    </Navbar>
  )
}

export default Toolbar
