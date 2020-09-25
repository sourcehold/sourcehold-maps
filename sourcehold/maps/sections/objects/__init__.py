
from sourcehold.structure_tools import Structure, Field, DataProperty


class ChildStructure(Structure):

    def __init__(self, parent, offset):
        super().__init__()
        self._offset = offset
        self._parent = parent

    def get_data(self):
        return self._parent.get_data()

    def set_data(self, data):
        raise Exception("you should not call this")


class Unit(ChildStructure):
    #data = Field("data", "B", array_size=1168)

    owner = DataProperty("I", start=128)
    location_j = DataProperty("H", start=224)
    location_i = DataProperty("H", start=226)
    location_tile_number = DataProperty("H", start=228)
    # identifier = DataProperty("H", start=726)
    # identifier_2 = DataProperty("H", start=728)
    unit_type = DataProperty("B", start=142)

    def __init__(self, parent, offset):
        super().__init__(parent, offset)

    @classmethod
    def size_of(cls):
        return 1168


class Building(ChildStructure):
    # data = Field("data", "B", array_size=812)

    # building_type = DataProperty("H", start=0)
    # building_type_or_cost = DataProperty("I", start=144)
    building_type_id = DataProperty("H", start=210)  # Succesfully changes type when clicked, but skin is not changed well.
    owner = DataProperty("H", start=214)
    building_uid = DataProperty("H", start=216)
    location_j_adjusted = DataProperty("H", start=238)
    location_i = DataProperty("H", start=240)
    location_serialized_tile_index = DataProperty("I", start=244)  # Most north-west tile
    width = DataProperty("H", start=248)  # Also the height.
    health = DataProperty("H", start=268)
    hitpoints = DataProperty("H", start=270)
    time_in_existence = DataProperty("H", start=636)
    locations = DataProperty("I", start=456, array_size=6*6)  # Even if cathedral (13x13), thi is still

    def __init__(self, parent, offset):
        super().__init__(parent, offset)

    @classmethod
    def size_of(cls):
        return 812

