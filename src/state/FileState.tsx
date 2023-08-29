import { atomWithStorage } from 'jotai/utils'

export const fileStateAtom = atomWithStorage<File>('file', {} as unknown as File)
