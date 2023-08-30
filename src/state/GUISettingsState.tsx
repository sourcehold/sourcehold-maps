import { atom } from 'jotai'

export type GUISettingsState = {
  verboseCompression: boolean;
}

export const DefaultGUISettings = {
  verboseCompression: false
}

export const guiSettingsStateAtom = atom(DefaultGUISettings)
