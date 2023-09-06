import { atom } from 'jotai'
import { Map } from '../sourcehold/architecture/Map'

export type ExportMapToZipModalState = {
  map: Map;
  objectURL: string;
  fileName: string;
  show: boolean;
  handleCancel: () => void;
  handleOK: () => void;
}

export const DefaultExportMapToZipModalState: ExportMapToZipModalState = {
  map: new Map(),
  objectURL: '',
  fileName: '',
  show: false,
  handleCancel: () => {},
  handleOK: () => {}
}

export const ExportMapToZipModalReducerAtom = atom(DefaultExportMapToZipModalState)
