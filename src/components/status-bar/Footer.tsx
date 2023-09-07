import React from 'react'
import { compress, decompress } from '../../sourcehold/CompressionInterface'
import { useAtom } from 'jotai'
import { fileStateAtom } from '../../state/FileState'
import { currentStatusMessageAtom, logAsString as convertLogMessageToString, LogMessage, getLatestLogMessage, DefaultStatusMessage } from '../../state/LogState'
import { showLogModal } from '../modals/LogModal'
import { STORE } from '../../state/Store'

const FooterStatusMessage = (props: { msg: LogMessage }) => {
  const { msg } = props

  return (
    <small>{`${convertLogMessageToString(msg)}`}</small>
  )
}

const Footer = () => {
  const [file] = useAtom(fileStateAtom)

  /**
   * Why does this not work? Ah, I should have recreated the object on update, pushing to the message list doesn't let anyone know the object was updated!
   */
  const [currentStatusMessage] = useAtom(currentStatusMessageAtom)
  console.log(`Footer message: ${currentStatusMessage.message}`)
  console.log(`Actual stored message: ${STORE.get(currentStatusMessageAtom).message}`)

  console.log(`Latest log message: ${getLatestLogMessage()?.message}`)

  /**
   * This does work luckily...
   */
  const msg = getLatestLogMessage() || DefaultStatusMessage

  return (
    <div className = "boxrow footer bg-light text-muted font " style={{ paddingLeft: 10 }}>
      <span className='d-flex' >
        <small onClick={async () => {
          const compressed = await compress(new TextEncoder().encode('Hello world!'), 6)
          console.log(compressed)
          const decompressed = await decompress(compressed, undefined)
          console.log(decompressed)
          console.log(new TextDecoder().decode(decompressed))
        }}>Current file: {file.name}</small>
      </span>

      <span className = "border-start border-dark d-flex ms-auto ps-2" style={{ minWidth: '60%' }}>
        {/* <span className={`badge rounded-pill ${logLevelToColor(msg.level)}`}><small>{levelToString(msg.level)}</small></span> */}
        <a href="#" onClick={async () => {
          await showLogModal({})
        }}>
          <FooterStatusMessage msg={msg}/>
        </a>
      </span>

    </div>
  )
}

export default Footer
