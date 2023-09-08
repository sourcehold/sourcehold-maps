import { atom } from 'jotai'
import { DataField } from './DataField'
import { DisplayField } from './DisplayField'
import { OwnerEnumInformation } from './OwnerEnumInformation'
import UnitTypeEnum from './UnitTypeEnum'

export const DefaultUnitFields = [
  new DataField('UID', 0x98, 'int'),
  new DataField('TYPE', 0x8E, 'enumShort', UnitTypeEnum),
  new DataField('OWNER', 0x96, 'enumShort', OwnerEnumInformation),
  new DataField('X', 0xc4, 'short'),
  new DataField('Y', 0xc6, 'short'),
  new DataField('HEALTH', 0x3C8, 'int'),
  new DataField('MAX_HEALTH', 0x3CC, 'int')
]

export const DefaultUnitDisplayFields = DefaultUnitFields.map((dataField, index) => {
  return new DisplayField(dataField, index)
})

export const unitDisplayFieldsAtom = atom<DisplayField[]>(DefaultUnitDisplayFields)
export const activeUnitDisplayFieldsAtom = atom<DisplayField[]>((get) => {
  return get(unitDisplayFieldsAtom).filter((df) => {
    return df.isDisplayed
  }).sort((a, b) => {
    if (a.columnIndex === undefined || b.columnIndex === undefined) return 0
    return (a.columnIndex) - (b.columnIndex)
  })
})
export const activeUnitDataFieldsAtom = atom<DataField[]>((get) => {
  return get(activeUnitDisplayFieldsAtom).map((df) => {
    return df.field
  })
})
