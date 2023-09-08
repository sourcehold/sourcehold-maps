import React from 'react'
import { mapStateAtom } from '../../state/MapState'
import { atom, useAtom } from 'jotai'
import { CRUSADER_UNIT_SIZE } from '../../sourcehold/architecture/units/Constants'
import UnitsTable from './UnitsTableV2'
import { activeUnitDataFieldsAtom } from './DefaultUnitFields'
import SelectFieldsModal from './SelectFieldsModal'

const unitsDataAtom = atom((get) => {
  const mapState = get(mapStateAtom)
  if (mapState === null) {
    return undefined
  }

  const unitsSection = mapState.directory.section_for_index(1015)
  const unitsData = unitsSection.get_data()
  if (unitsData.byteLength % CRUSADER_UNIT_SIZE !== 0) {
    console.error('Current GUI does not support non Crusader maps')
    return new DataView(new Uint8Array().buffer)
  }

  return new DataView(new Uint8ClampedArray(unitsData).buffer)
})

const UnitsTab = () => {
  const [unitsData] = useAtom(unitsDataAtom)
  const [activeUnitDataFields] = useAtom(activeUnitDataFieldsAtom)

  return (
    <>
      <UnitsTable unitFields={activeUnitDataFields} unitsData={unitsData} />
      <SelectFieldsModal/>
    </>
  )
}

export default UnitsTab
