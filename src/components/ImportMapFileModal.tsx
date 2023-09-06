import { atom, useAtom } from 'jotai'
import React from 'react'
import { Form } from 'react-bootstrap'
import Button from 'react-bootstrap/Button'
import Modal from 'react-bootstrap/Modal'
import { ImportMapFileModalDefaultState, ImportMapFileModalResult, ImportMapFileModalState, importMapFileModalReducerAtom } from '../state/ImportMapFileModal'
import { STORE } from '../state/Store'

function setImportMapFileModalState (state: Partial<ImportMapFileModalState>) {
  STORE.set(importMapFileModalReducerAtom, state)
}

export async function showImportMapFileModalDialog (customisations: Partial<ImportMapFileModalState>) {
  const defaultState = ImportMapFileModalDefaultState
  const customState = { ...defaultState, ...customisations }

  console.log(customState)

  return new Promise<ImportMapFileModalResult>(resolve => {
    const finalState = {
      ...customState,
      show: true,
      handleCancel: () => {
        setImportMapFileModalState({ ...customState, show: false })
        customState.handleCancel()
        resolve({
          status: 'cancel',
          file: customState.file
        })
      },
      handleOK: (file: File) => {
        setImportMapFileModalState({ ...customState, show: false })
        customState.handleOK(file)
        resolve({
          status: 'ok',
          file
        })
      }
    }

    setImportMapFileModalState(finalState)
  })
}

const localFileState = atom({} as unknown as File)

function ImportMapFileModal () {
  const [importMapFileModalState] = useAtom(importMapFileModalReducerAtom)

  const [file, setFile] = useAtom(localFileState)

  const onFileChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    if (e.target.files !== null) {
      const newFilePath = e.target.files[0].name
      if (file.name !== newFilePath) {
        console.log(`File path changed to: ${newFilePath}`)
        setFile(e.target.files[0])
      }
    }
  }

  return (
    <Modal show={importMapFileModalState.show} onHide={importMapFileModalState.handleCancel}>
      <Modal.Dialog>
        <Modal.Header closeButton>
          <Modal.Title>Select file</Modal.Title>
        </Modal.Header>

        <Modal.Body>
          <Form.Group controlId="importMapFile" className="mb-3">
            <Form.Label>Select a .map file to import</Form.Label>
            <Form.Control type="file" onChange={onFileChange}/>
          </Form.Group>
        </Modal.Body>

        <Modal.Footer>
          <Button variant="secondary" onClick={() => importMapFileModalState.handleCancel()}>Cancel</Button>
          <Button variant="primary" onClick={() => importMapFileModalState.handleOK(file)}>Import</Button>
        </Modal.Footer>
      </Modal.Dialog>
    </Modal>
  )
}

export default ImportMapFileModal
