import React from 'react'
import { DisplayField } from './DisplayField'
import { CRUSADER_UNIT_SIZE } from '../../sourcehold/architecture/units/Constants'

export const UnitRow = (dv: DataView, unitOffset: number, fields: DisplayField[]) => {
  const values = [
    unitOffset / CRUSADER_UNIT_SIZE,
    ...fields.map((f) => f.value(dv, unitOffset))
  ]

  const UIDfield = fields.filter((f) => f.name === 'UID')
  if (UIDfield.length === 1) {
    const uid = UIDfield[0].value(dv, unitOffset)
    if (uid === 0) {
      return undefined
    }
  }

  return (
    <tr key={`row-unit-${unitOffset}`}>
      {
        values.map((v: number | string, index) => (
          <td key={`value-unit-${unitOffset}-${index}`}>
            {v}
          </td>
        ))
      }
    </tr>
  )
}

export const UnitHeader = (fields: DisplayField[]) => {
  return (
    <thead>
      <tr>
        {
          ['ARRAY ID', ...fields.map((f) => f.name)].map((v) => <th key={`header-units-${v}`}>{v}</th>)
        }
      </tr>
    </thead>
  )
}

const UnitsTable = (props: {unitsData: DataView | undefined, unitFields: DisplayField[]}) => {
  const { unitsData, unitFields } = props
  if (unitsData === undefined || unitsData === null) {
    return (
    <table className='w-100 bg-secondary'>
      {UnitHeader(unitFields)}
      <tbody>
      </tbody>
    </table>
    )
  }

  return (
    <table className='w-100 bg-secondary'>
      {UnitHeader(unitFields)}
      <tbody className='bg-light text-dark'>
        {
          // Lets do the first 10 units for now...
          Array(unitsData.byteLength / CRUSADER_UNIT_SIZE).fill(0).map((_, index) => {
            console.log(`Processing unit: ${index}`)
            return UnitRow(unitsData, index * CRUSADER_UNIT_SIZE, unitFields)
          }).filter((v) => v !== undefined)
        }
      </tbody>
    </table>
  )
}

export default UnitsTable
