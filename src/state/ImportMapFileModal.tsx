import { atomWithReducer } from 'jotai/utils'
import { ImportMapFileModalDefaultState, ImportMapFileModalState } from '../types/ImportMapFileModalState'

const reducer = (state: ImportMapFileModalState, newState: Partial<ImportMapFileModalState>) => {
  return { ...state, ...newState }
}

export const importMapFileModalReducerAtom = atomWithReducer(ImportMapFileModalDefaultState, reducer)
