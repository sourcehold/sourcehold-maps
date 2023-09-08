import React from 'react'
import './SelectFieldsModal.css'
import { atom, useAtom } from 'jotai'
import { Button, Modal } from 'react-bootstrap'
import { STORE } from '../../state/Store'
import { DisplayField } from './DisplayField'
import { activeUnitDisplayFieldsAtom } from './DefaultUnitFields'

export type SelectFieldsModalState = {
  fields: DisplayField[],
  show: boolean;
  handleCancel: () => void;
  handleOK: () => void;
}

export const DefaultSelectFieldsModalState: SelectFieldsModalState = {
  fields: [],
  show: false,
  handleCancel: () => {},
  handleOK: () => {}
}

export const selectFieldsModalStateAtom = atom(DefaultSelectFieldsModalState)

export async function showSelectFieldsModal (customisations: Partial<SelectFieldsModalState>) {
  const customState = { ...DefaultSelectFieldsModalState, ...customisations }

  console.log(customState)

  const fields = STORE.get(activeUnitDisplayFieldsAtom)

  return new Promise<boolean>(resolve => {
    const finalState = {
      ...customState,
      fields,
      show: true,
      handleCancel: () => {
        STORE.set(selectFieldsModalStateAtom, { ...customState, show: false })
        customState.handleCancel()
        resolve(false)
      },
      handleOK: () => {
        STORE.set(selectFieldsModalStateAtom, { ...customState, show: false })
        customState.handleOK()
        resolve(true)
      }
    }

    STORE.set(selectFieldsModalStateAtom, finalState)
  })
}

const SelectFieldsModal = () => {
  const [selectFieldsModalState] = useAtom(selectFieldsModalStateAtom)

  return (
    <Modal show={selectFieldsModalState.show} onHide={selectFieldsModalState.handleCancel} className='modal-log'>
        <Modal.Header closeButton>
          <Modal.Title>Fields (columns)</Modal.Title>
        </Modal.Header>

        <Modal.Body className='overflow-scroll'>
          <ul>
            {
              selectFieldsModalState.fields.map((df) => {
                return (
                  <li key={`displayField-${df.field.name}`}>
                    <span>{df.columnIndex}</span>
                    <span>{df.isDisplayed}</span>
                    <span>{df.field.name}</span>
                    <span>{df.field.fieldOffset}</span>
                    <span>{df.field.type}</span>
                  </li>
                )
              })
            }
          </ul>
        </Modal.Body>

        <Modal.Footer>
          <Button variant="secondary" onClick={() => {
            console.log('CANCEL')
            // window.URL.revokeObjectURL(logModalState.objectURL)
            selectFieldsModalState.handleCancel()
          }}>Cancel</Button>
          <Button variant="primary" onClick={async () => {
            console.log('OK')
            // console.log(aRef)
            // if (aRef.current !== null) {
            //   await aRef.current.click()
            //   window.URL.revokeObjectURL(logModalState.objectURL)
            //   logModalState.handleOK()
            // }
            selectFieldsModalState.handleOK()
          }}>Apply</Button>
          {/* <a ref={(r) => { console.log(r); aRef.current = r }} href={logModalState.objectURL} download={fileName} style={{ display: 'none' }} /> */}
        </Modal.Footer>
    </Modal>
  )
}

export default SelectFieldsModal
