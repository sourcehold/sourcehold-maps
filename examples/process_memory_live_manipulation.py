## Example:

from sourcehold.debugtools.memory.common.access import AccessContext
from sourcehold.debugtools.memory.common.manipulation import LiveSection1015


live = LiveSection1015(AccessContext())
live.unpack_items()
with live.cache():
    print(live[0].location_tile_index)