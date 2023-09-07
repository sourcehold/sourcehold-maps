import React from 'react'
import './LogModal.css'
import { atom, useAtom } from 'jotai'
import { Button, Modal } from 'react-bootstrap'
import { levelToString, logAsString, logLevelToColor, logStateAtom } from '../../state/LogState'
import { STORE } from '../../state/Store'

export type LogModalState = {
  objectURL: string;
  fileName: string;
  show: boolean;
  handleCancel: () => void;
  handleOK: () => void;
}

export const DefaultLogModalState: LogModalState = {
  objectURL: '',
  fileName: '',
  show: false,
  handleCancel: () => {},
  handleOK: () => {}
}

export const logModalStateAtom = atom(DefaultLogModalState)

export async function showLogModal (customisations: Partial<LogModalState>) {
  const customState = { ...DefaultLogModalState, ...customisations }

  console.log(customState)

  return new Promise<boolean>(resolve => {
    const finalState = {
      ...customState,
      show: true,
      handleCancel: () => {
        STORE.set(logModalStateAtom, { ...customState, show: false })
        customState.handleCancel()
        resolve(false)
      },
      handleOK: () => {
        STORE.set(logModalStateAtom, { ...customState, show: false })
        customState.handleOK()
        resolve(true)
      }
    }

    STORE.set(logModalStateAtom, finalState)
  })
}

const LogModal = () => {
  const [logModalState] = useAtom(logModalStateAtom)
  const [log] = useAtom(logStateAtom)

  return (
    <Modal show={logModalState.show} onHide={logModalState.handleCancel} className='modal-log'>
        <Modal.Header closeButton>
          <Modal.Title>Log</Modal.Title>
        </Modal.Header>

        <Modal.Body>
          {/* Maybe nice to use as an export log to file thing
          <Form.Group controlId="ExportMapToZip" className="mb-3">
            <Form.Label>Give a name to the .zip</Form.Label>
            <Form.Control type="input" defaultValue={logModalState.fileName} onChange={onFileNameChange}/>
          </Form.Group> */}
          <ul className="list-group">
            {log.messages.map((msg, i) => {
              return (
              <li key={`log-msg-${msg.time.getUTCSeconds()}-${i}`} className="list-group-item d-flex justify-content-between align-items-center">
                {logAsString(msg)}
                <span className={`badge rounded-pill ${logLevelToColor(msg.level)}`}>{levelToString(msg.level)}</span>
              </li>)
            })}
          </ul>
        </Modal.Body>

        <Modal.Footer>
          <Button variant="secondary" onClick={() => {
            console.log('CANCEL')
            // window.URL.revokeObjectURL(logModalState.objectURL)
            logModalState.handleCancel()
          }}>Cancel</Button>
          <Button variant="primary" onClick={async () => {
            console.log('OK')
            // console.log(aRef)
            // if (aRef.current !== null) {
            //   await aRef.current.click()
            //   window.URL.revokeObjectURL(logModalState.objectURL)
            //   logModalState.handleOK()
            // }
            logModalState.handleOK()
          }}>Export</Button>
          {/* <a ref={(r) => { console.log(r); aRef.current = r }} href={logModalState.objectURL} download={fileName} style={{ display: 'none' }} /> */}
        </Modal.Footer>
    </Modal>
  )
}

export default LogModal
