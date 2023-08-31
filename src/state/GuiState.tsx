import { atom } from 'jotai'

export type TilemapExplorerOptions = {
  section: number;
  explorerColorMode: boolean;
}

export type GUIState = {
  activeTabKey: string;
  tilemapExplorer: TilemapExplorerOptions
}

export const DefaultGUIState: GUIState = {
  activeTabKey: 'info',
  tilemapExplorer: {
    section: 1001,
    explorerColorMode: true
  }
}

export const GUIStateAtom = atom(DefaultGUIState)
