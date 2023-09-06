import { atom } from 'jotai'

export type GUISettingsState = {
  verboseCompression: boolean;
}

export const DefaultGUISettings: GUISettingsState = {
  verboseCompression: false
}

export const guiSettingsStateAtom = atom(DefaultGUISettings)
