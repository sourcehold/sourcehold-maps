import { atomWithReducer } from 'jotai/utils'

export type ImportMapFileModalState = {
  file: File;
  show: boolean;
  handleCancel: () => void;
  handleOK: (file: File) => void;
};

export const ImportMapFileModalDefaultState: ImportMapFileModalState = {
  file: {
    name: '',
    arrayBuffer: new ArrayBuffer(0)
  } as unknown as File,
  show: false,
  handleCancel: () => {},
  handleOK: (file: File) => {}
}

export type ImportMapFileModalResult = {
  status: 'ok' | 'cancel';
  file: File
}

const reducer = (state: ImportMapFileModalState, newState: Partial<ImportMapFileModalState>) => {
  return { ...state, ...newState }
}

export const importMapFileModalReducerAtom = atomWithReducer(ImportMapFileModalDefaultState, reducer)
