import { atom } from 'jotai'
import { Map } from '../sourcehold/architecture/Map'

export const mapStateAtom = atom<Map>(null as unknown as Map)

const supportedSections = [1, 2, 4]
export const mapStateAvailableTileMapSectionsAtom = atom((get) => {
  const m = get(mapStateAtom)
  if (m === undefined || m === null) return []

  return m.directory.section_indices.filter((v) => v !== 0).filter((ind) => {
    const s = m.directory.section_for_index(ind)

    if (s === undefined) {
      console.log(`null section: ${ind}`)
      return false
    }

    const data = s.get_data()
    if (data === undefined) {
      // console.log(`undefined data: ${ind}`)
      return false
    }
    const sLength = data.length
    const div = sLength / 80400
    return supportedSections.indexOf(div) !== -1
  })
})
