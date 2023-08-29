export type ImportMapFileModalState = {
  file: File;
  show: boolean;
  handleCancel: () => void;
  handleOK: (file: File) => void;
};

export const ImportMapFileModalDefaultState = {
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
