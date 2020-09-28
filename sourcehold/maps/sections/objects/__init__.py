
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


class UnitAivLocations(ChildStructure):

    # TODO: this is a child of a childstructure, how to handle inheritance of parent and offset?

    @classmethod
    def size_of(cls):
        return 4 * 10 * 21


for i in range(21):
    for j in range(10):
        setattr(UnitAivLocations, f"type{i}_location{j}", DataProperty("I", start=(i*10*4) + (j*4)))


class PlayerData(ChildStructure):

    data = DataProperty("B", start=0, array_size=14836)

    #unit_aiv_locations = DataProperty(UnitAivLocations, start=11588)

    def __init__(self, parent, offset):
        super().__init__(parent, offset)

    @classmethod
    def size_of(cls):
        return 14836


from enum import IntEnum


class AivUnitType(IntEnum):
    # Misc
    OILMAN = 1
    MANGONEL = 2
    BALLISTA = 3
    TREBUCHET = 4
    FIRE_BALLISTA = 5
    BOWMAN = 6
    CROSSBOWMAN = 7
    SPEARMAN = 8
    PIKEMAN = 9
    MACEMAN = 10
    SWORDSMAN = 11
    KNIGHT = 12
    SLAVE = 13
    SLINGER = 14
    ASSASSIN = 15
    ARABIAN_ARCHER = 16
    HORSE_ARCHER = 17
    ARABIAN_SWORDSMAN = 18
    FIRE_THROWER = 19
    BRAZIER = 20
    FLAG = 21


for i in range(21):
    for j in range(10):
        setattr(PlayerData, f"{AivUnitType(i+1).name}_location{j}", DataProperty("I", start=11588 + ((i*10*4) + (j*4))))