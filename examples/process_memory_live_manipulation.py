## Example:

from sourcehold.debugtools.memory.common.access import AccessContext
from sourcehold.debugtools.memory.common.manipulation import LiveSection1015, LiveSection1013, LiveSection1022

process = AccessContext()
units = LiveSection1015(process)
units.unpack_items()

with units.cache():
    all_units = [unit for unit in units.items.values() if unit.unit_type != 0]

buildings = LiveSection1013(process)
buildings.unpack_items()

player_data = LiveSection1022(process)
player_data.unpack_items()
