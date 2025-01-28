
from sourcehold.structure_tools.Field import Field
from sourcehold.structure_tools.DataProperty import DataProperty
from sourcehold.structure_tools.Structure import Structure


class ChildStructure(Structure):

    def __init__(self, parent, offset):
        super().__init__()
        self._offset = offset
        self._parent = parent

    def get_data(self):
        return self._parent.get_data()

    def set_data(self, data):
        raise Exception("you should not call this")


class Tree(ChildStructure):
    data = DataProperty("B", array_size=156)

    @classmethod
    def size_of(cls):
        return 156


class Unit(ChildStructure):
    data = Field("data", "B", array_size=1168)

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

    # Popularity level. Starting popularity is 10000.
    popularity = DataProperty("H", start=96)

    # Possible values are 0 until 5. If set to 5, popularity bonus is +10, and a monk appears as the image.
    rations = DataProperty("B", start=8588)


    # 0: floor(inhabitants/2)*2 (factor -1)
    # 1: inhabitants/72 * 57 (factor -0.8)
    # 2: inhabitants/72 * 43 (factor -0.6)
    # 3: 0                   (factor 0)
    # 4: inhabitants/72 * 43 (factor 0.6)
    # 5: inhabitants/72 * 57 (factor 0.8)
    # 6: floor(inhabitants/2)*2 , or: inhabitants/72 * 72 (factor 1)
    # 7: inhabitants/72 * 86 (factor 1.2)
    # 8: inhabitants/72 * 100 (factor 1.4)
    # 9: inhabitants/72 * 115 (factor 1.6)
    # 10: inhabitants/72 * 129 (factor 1.8)
    # 11: inhabitants/72 * 144 (factor 2)
    # 12: factor 2.2
    # 13: factor 2.4
    # 14: factor 2.6
    # 15: factor 2.8
    # 16: factor 3
    # 99: inhabitants/72 * 1411
    # 100: inhabitants/72 * 1425
    # 121: inhabitants/72 * 1728 (factor 24)
    # 1331: inhabitants/72 * 19152 (factor 266)
    # 9000: inhabitants/72 * 129585
    # 14641: inhabitants/72 * 210816 (factor 2928)
    # So, the factor increases by 0.2 for every 1 increase in tax setting.
    #

    # a value from 0 until 12, indicating the tax setting. default is 3. Setting it to 12 produces "army wages" with +121 popularity. 13 -> "Inn", 14 -> "Turn Off X"
    tax_setting = DataProperty("B", start=8584)

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
    ARCHER = 6
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