from sourcehold.maps.SimpleSection import SimpleSection
from sourcehold.structure_tools.DataProperty import DataProperty


class U2(SimpleSection):

    map_type = DataProperty("I", start=0) # crusader (multi) = 1, scenario/castle-builder/siege (single) = 0
    middle = DataProperty("B", start=4, array_size=20)
    players_count = DataProperty("I", start=24)