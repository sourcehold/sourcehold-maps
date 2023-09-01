import { DisplayField } from './DisplayField'
import { OwnerEnumInformation } from './OwnerEnumInformation'
import UnitTypeEnum from './UnitTypeEnum'

export const DefaultUnitFields = [
  new DisplayField('UID', 0x98, 'int'),
  new DisplayField('TYPE', 0x8E, 'enumShort', UnitTypeEnum),
  new DisplayField('OWNER', 0x96, 'enumShort', OwnerEnumInformation),
  new DisplayField('X', 0xc4, 'short'),
  new DisplayField('Y', 0xc6, 'short'),
  new DisplayField('HEALTH', 0x3C8, 'int'),
  new DisplayField('MAX_HEALTH', 0x3CC, 'int')
]
