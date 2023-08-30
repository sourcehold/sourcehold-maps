import { atom } from 'jotai'

export type GUIState = {
  activeTabKey: string;
}

export const DefaultGUIState: GUIState = {
  activeTabKey: 'info'
}

export const GUIStateAtom = atom(DefaultGUIState)
