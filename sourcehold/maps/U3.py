from sourcehold.maps.SimpleSection import SimpleSection
from sourcehold.structure_tools.DataProperty import DataProperty


class U3(SimpleSection):

    int0 = DataProperty("I", start=0) # always 2?
    int1 = DataProperty("I", start=4) # 3 for castle builders, and 1 for crusader/scenario, 0 for siege
    # TODO: value is in {0, 1, 2}. What does 2 mean?
    map_locked = DataProperty("I", start=8)
    rest = DataProperty("B", start=12, array_size=lambda obj: obj.size - 12)