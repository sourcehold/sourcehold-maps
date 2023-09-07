import { atom } from 'jotai'
import { STORE } from './Store'

/* eslint-disable no-unused-vars */
export enum LogLevel {
  FATAL = -3,
  ERROR = -2,
  WARNING = -1,
  INFO = 0,
  DEBUG = 1,
  TRACE = 2,
}

export function levelToString (logLevel: LogLevel) {
  switch (logLevel) {
    case LogLevel.DEBUG:
      return ' DEBUG'
    case LogLevel.ERROR:
      return ' ERROR'
    case LogLevel.FATAL:
      return ' FATAL'
    case LogLevel.INFO:
      return ' INFO '
    case LogLevel.TRACE:
      return ' TRACE'
    case LogLevel.WARNING:
      return ' WARN '
    default:
      throw Error(`Unknown log level: ${logLevel}`)
  }
}

export type LogMessage = {
  message: string,
  time: Date,
  level: LogLevel
}

export const DefaultStatusMessage: LogMessage = {
  message: 'Status messages appear here. Click to view a log',
  level: LogLevel.INFO,
  time: new Date()
}

export type Log = {
  messages: LogMessage[]
}

export const DefaultLogState: Log = {
  messages: [DefaultStatusMessage]
}

export const logStateAtom = atom(DefaultLogState)

export function getLatestLogMessage () {
  const log = STORE.get(logStateAtom)
  if (log !== undefined && log !== null && log.messages !== undefined && log.messages.length > 0) {
    return { ...log.messages[log.messages.length - 1] }
  }
  return undefined
}

export const currentStatusMessageAtom = atom((get) => {
  const log = get(logStateAtom)
  console.log(log)

  if (log !== undefined && log !== null && log.messages !== undefined && log.messages.length > 0) {
    return log.messages[log.messages.length - 1]
  }

  return DefaultStatusMessage
})

export class Logger {
  log (message: string, logLevel: undefined | LogLevel) {
    if (logLevel === undefined) {
      logLevel = LogLevel.DEBUG
    }
    const msg: LogMessage = {
      message,
      time: new Date(),
      level: logLevel
    }
    const state = STORE.get(logStateAtom)
    state.messages.push(msg)
    STORE.set(logStateAtom, { ...state })
    return msg
  }

  info (message: string) {
    return this.log(message, LogLevel.INFO)
  }

  warn (message: string) {
    return this.log(message, LogLevel.WARNING)
  }

  err (message: string) {
    return this.log(message, LogLevel.ERROR)
  }

  fatal (message: string) {
    return this.log(message, LogLevel.FATAL)
  }

  debug (message: string) {
    return this.log(message, LogLevel.DEBUG)
  }

  trace (message: string) {
    return this.log(message, LogLevel.TRACE)
  }
}

export const LOGGER = new Logger()

export function log (message: string, logLevel: undefined | LogLevel) {
  return LOGGER.log(message, logLevel)
}

export function info (message: string) {
  return LOGGER.info(message)
}

export function warn (message: string) {
  return LOGGER.warn(message)
}

export function err (message: string) {
  return LOGGER.err(message)
}

export function fatal (message: string) {
  return LOGGER.fatal(message)
}

export function debug (message: string) {
  return LOGGER.debug(message)
}

export function trace (message: string) {
  return LOGGER.trace(message)
}

export function logAsReact (msg: LogMessage) {

}

export function logAsString (msg: LogMessage) {
  return `${msg.time.toLocaleTimeString()} (${levelToString(msg.level)}): ${msg.message}`
}

export const logLevelToColor = (logLevel: LogLevel) => {
  switch (logLevel) {
    case LogLevel.DEBUG:
      return 'bg-secondary'
    case LogLevel.ERROR:
      return 'bg-danger'
    case LogLevel.FATAL:
      return 'bg-danger'
    case LogLevel.INFO:
      return 'bg-info'
    case LogLevel.TRACE:
      return 'bg-secondary'
    case LogLevel.WARNING:
      return 'bg-warning'
    default:
      throw Error(`Unknown log level: ${logLevel}`)
  }
}
