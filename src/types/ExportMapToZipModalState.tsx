import { Map } from '../sourcehold/architecture/Map'

export type ExportMapToZipModalState = {
  map: Map;
  objectURL: string;
  fileName: string;
  show: boolean;
  handleCancel: () => void;
  handleOK: () => void;
}

export const DefaultExportMapToZipModalState = {
  map: new Map(),
  objectURL: '',
  fileName: '',
  show: false,
  handleCancel: () => {},
  handleOK: () => {}
}
