import React from 'react'
import { Container, Nav, NavDropdown, Navbar } from 'react-bootstrap'
import { showImportMapFileModalDialog } from './ImportMapFileModal'
import { useAtom } from 'jotai/react'
import { importMapFileModalReducerAtom } from '../state/ImportMapFileModal'
import { fileStateAtom } from '../state/FileState'
import { bufferToMap } from '../sourcehold/Architecture'
import { mapStateAtom } from '../state/MapState'
import { showExportMapToZipModalDialog } from './EportMaptoZipModal'
import { ExportMapToZipModalReducerAtom } from '../state/ExportMapToZipModalState'

function Toolbar () {
  const [, setImportMapFileModalState] = useAtom(importMapFileModalReducerAtom)

  const [fileState, setFileState] = useAtom(fileStateAtom)

  const [, setExportMapToZipModalState] = useAtom(ExportMapToZipModalReducerAtom)

  const [mapState, setMapState] = useAtom(mapStateAtom)

  return (
    <Navbar expand="lg" className="bg-body-tertiary boxrow header">
    <Container style={{ marginLeft: 0 }}>
      <Navbar.Brand>Map explorer</Navbar.Brand>
      <Navbar.Toggle aria-controls="basic-navbar-nav" />
      <Navbar.Collapse id="basic-navbar-nav">
        <Nav className="me-auto">
          <NavDropdown title="File" id="basic-nav-dropdown">
            <NavDropdown.Item href="#file/import" onClick={async () => {
              console.log('CLICK')
              const result = await showImportMapFileModalDialog({
                handleOK: (f: File) => {
                  console.log(f.name)
                  // setFileState(file)
                }
              }, setImportMapFileModalState)

              if (result.status === 'ok') {
                console.log('OK')
                console.log(result.file.name)
                setFileState(result.file)
                const map = await result.file.arrayBuffer().then(b => bufferToMap(b))
                console.log(map)
                setMapState(map)
              } else {
                console.log('CANCEL')
              }
            }}>Import .map</NavDropdown.Item>
            <NavDropdown.Item href="#file/export">
              Export .map
            </NavDropdown.Item>
            <NavDropdown.Divider />
            <NavDropdown.Item href="#file/import-zip">Import .map from .zip</NavDropdown.Item>
            <NavDropdown.Item href="#file/export-zip" onClick={async (e) => {
              mapState.export_to_zip().then((z) => z.generateAsync({ type: 'blob' }).then(async (zip) => {
                const url = window.URL.createObjectURL(zip)

                await showExportMapToZipModalDialog({
                  fileName: fileState.name + '.zip',
                  objectURL: url
                }, setExportMapToZipModalState)
              }))
            }}>
              Export .map as .zip
            </NavDropdown.Item>
          </NavDropdown>
          <Nav.Link href="#tab/tilemap-explorer">Tilemap explorer</Nav.Link>
        </Nav>
      </Navbar.Collapse>
    </Container>
  </Navbar>
  )
}

export default Toolbar
