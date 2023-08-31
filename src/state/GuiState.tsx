import { atom } from 'jotai'

export type TilemapExplorerOptions = {
  section: number;
  continuousColorMode: boolean;
}

export type GUIState = {
  activeTabKey: string;
  tilemapExplorer: TilemapExplorerOptions
}

export const DefaultGUIState: GUIState = {
  activeTabKey: 'info',
  tilemapExplorer: {
    section: 1001,
    continuousColorMode: true
  }
}

export const GUIStateAtom = atom(DefaultGUIState)
