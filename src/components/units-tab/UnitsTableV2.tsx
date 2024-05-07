import React from 'react'
// eslint-disable-next-line no-unused-vars
import BootstrapTable, { BootstrapTableProps } from 'react-bootstrap-table-next'
// eslint-disable-next-line no-unused-vars
// import ToolkitProvider, { ColumnToggle, TableToolkitProps } from 'react-bootstrap-table2-toolkit'

// eslint-disable-next-line no-unused-vars
import filterFactory, { textFilter } from 'react-bootstrap-table2-filter'
import { DisplayField } from './DisplayField'
import { CRUSADER_UNIT_SIZE } from '../../sourcehold/architecture/units/Constants'

// eslint-disable-next-line no-unused-vars
// const { ToggleList } = ColumnToggle

type Unit = Record<string, number | string>;

// Currently broken, because: https://github.com/react-bootstrap-table/react-bootstrap-table2/pull/1506

// eslint-disable-next-line no-unused-vars
// const Table = (props: TableToolkitProps<Unit> | BootstrapTableProps<Unit>) => {
//   return (<ToolkitProvider columnToggle {...props} >
//   {
//     p => (
//       <div>
//         <ToggleList { ...p.columnToggleProps } />
//         <hr />
//         <BootstrapTable
//           { ...p.baseProps }
//           // filter={ filterFactory() }
//         />
//       </div>
//     )
//   }
// </ToolkitProvider>)
// }

const UnitsTable = (props: {unitsData: DataView | undefined, unitFields: DisplayField[]}) => {
  const { unitsData, unitFields } = props

  const columns = [{
    dataField: 'ID',
    text: 'ID',
    sort: true
  }, ...unitFields.map((f) => {
    return {
      dataField: `${f.name}`,
      text: `${f.name}`,
      sort: true
      // filter: textFilter()
    }
  })]

  if (unitsData === undefined) {
    return (
      <BootstrapTable keyField='UID' data={ [] } columns={ columns } bordered={ false }
      striped
      hover
      condensed />
    )
  }

  const data = Array(unitsData.byteLength / CRUSADER_UNIT_SIZE).fill(0).map((_, index) => {
    const UIDfield = unitFields.filter((f) => f.name === 'UID')

    let uid = 0

    if (UIDfield.length === 1) {
      uid = UIDfield[0].value(unitsData, index * CRUSADER_UNIT_SIZE) as number
      if (uid === 0) {
        return undefined
      }
    }

    const obj: Unit = { ID: index }

    unitFields.forEach((f) => {
      const value = f.value(unitsData, index * CRUSADER_UNIT_SIZE)

      obj[f.name] = value
    })

    return obj
  }).filter((v) => v !== undefined && v.UID !== 0) as Unit[]

  return (
    <BootstrapTable
      keyField='ID'
      data={ data }
      columns={ columns }
      bordered={ false }
      striped
      hover
      condensed />
  )
}

export default UnitsTable
