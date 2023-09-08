import { DataField } from './DataField'

export class DisplayField {
  field: DataField
  id: string
  columnIndex: number | undefined

  constructor (dataField: DataField, columnIndex?: number | undefined) {
    this.field = dataField
    this.id = dataField.name
    this.columnIndex = columnIndex
  }

  get isDisplayed () {
    return this.columnIndex !== undefined
  }
}
