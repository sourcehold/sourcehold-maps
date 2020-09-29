## Example:

from sourcehold.debugtools.memory.common.access import AccessContext
from sourcehold.debugtools.memory.common.manipulation import LiveSection1015, LiveSection1013, LiveSection1022

process = AccessContext()
units = LiveSection1015(process)
units.unpack_items()

with units.cache():
    print(units[1].location_tile_index)

buildings = LiveSection1013(process)
buildings.unpack_items()

player_data = LiveSection1022(process)
player_data.unpack_items()
