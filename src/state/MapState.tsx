import { atom } from 'jotai'
import { Map } from '../sourcehold/architecture/Map'

export const mapStateAtom = atom<Map>(null as unknown as Map)
