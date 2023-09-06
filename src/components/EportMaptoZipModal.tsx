import { atom, useAtom } from 'jotai'
import React, { useRef } from 'react'
import { Form } from 'react-bootstrap'
import Button from 'react-bootstrap/Button'
import Modal from 'react-bootstrap/Modal'
import { DefaultExportMapToZipModalState, ExportMapToZipModalReducerAtom, ExportMapToZipModalState } from '../state/ExportMapToZipModalState'
import { STORE } from '../state/Store'

function setExportMapToZipModalState (state: ExportMapToZipModalState) {
  STORE.set(ExportMapToZipModalReducerAtom, state)
}

export async function showExportMapToZipModalDialog (customisations: Partial<ExportMapToZipModalState>) {
  const defaultState = DefaultExportMapToZipModalState
  const customState = { ...defaultState, ...customisations }

  console.log(customState)

  return new Promise<boolean>(resolve => {
    const finalState = {
      ...customState,
      show: true,
      handleCancel: () => {
        setExportMapToZipModalState({ ...customState, show: false })
        customState.handleCancel()
        resolve(false)
      },
      handleOK: () => {
        setExportMapToZipModalState({ ...customState, show: false })
        customState.handleOK()
        resolve(true)
      }
    }

    setExportMapToZipModalState(finalState)
  })
}

const fileNameAtom = atom('')

function ExportMapToZipModal () {
  const [exportMapToZipModalState] = useAtom(ExportMapToZipModalReducerAtom)

  const [fileName, setFileName] = useAtom(fileNameAtom)

  const onFileNameChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    setFileName(e.target.value)
  }

  const aRef = useRef<HTMLAnchorElement | null>(null)

  return (
    <Modal show={exportMapToZipModalState.show} onHide={exportMapToZipModalState.handleCancel}>
      <Modal.Dialog>
        <Modal.Header closeButton>
          <Modal.Title>Select file</Modal.Title>
        </Modal.Header>

        <Modal.Body>
          <Form.Group controlId="ExportMapToZip" className="mb-3">
            <Form.Label>Give a name to the .zip</Form.Label>
            <Form.Control type="input" defaultValue={exportMapToZipModalState.fileName} onChange={onFileNameChange}/>
          </Form.Group>
        </Modal.Body>

        <Modal.Footer>
          <Button variant="secondary" onClick={() => {
            console.log('CANCEL')
            window.URL.revokeObjectURL(exportMapToZipModalState.objectURL)
            exportMapToZipModalState.handleCancel()
          }}>Cancel</Button>
          <Button variant="primary" onClick={async () => {
            console.log('OK')
            console.log(aRef)
            if (aRef.current !== null) {
              await aRef.current.click()
              window.URL.revokeObjectURL(exportMapToZipModalState.objectURL)
              exportMapToZipModalState.handleOK()
            }
          }}>Export</Button>
          <a ref={(r) => { console.log(r); aRef.current = r }} href={exportMapToZipModalState.objectURL} download={fileName} style={{ display: 'none' }} />
        </Modal.Footer>
      </Modal.Dialog>
    </Modal>
  )
}

export default ExportMapToZipModal
