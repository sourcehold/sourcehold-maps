from .. import KeyValueStructure
from struct import unpack, pack

from sourcehold.structure_tools import Structure, Field, DataProperty


class Unit(Structure):
    data = Field("data", "B", array_size=1168)

    owner = DataProperty("I", start=16)
    owner_2 = DataProperty("I", start=128)
    location_j = DataProperty("H", start=224)
    location_i = DataProperty("H", start=226)
    location_tile_number = DataProperty("H", start=228)
    identifier = DataProperty("H", start=726)
    identifier_2 = DataProperty("H", start=728)
    unit_type = DataProperty("B", start=142)

    @classmethod
    def size_of(cls):
        return cls.data.array_size


class Building(Structure):
    data = Field("data", "B", array_size=812)

    building_type = DataProperty("H", start=0)
    building_type_or_cost = DataProperty("I", start=144)
    building_type_2 = DataProperty("B", start=210)
    owner = DataProperty("H", start=214)
    building_id = DataProperty("H", start=216)
    building_type_sub = DataProperty("H", start=644)
    locations = DataProperty("I", start=456, array_size=6*6)

    @classmethod
    def size_of(cls):
        return cls.data.array_size


class BuildingDeprecated(KeyValueStructure):
    _MAPPING_ = {
        'building_type': 0,
        'player': 107, # TODO: which player built a building.
        'building_id': 108,  # TODO: not sure if this makes sense. I feel it is a useless information piece.
        'building_type_sub': 322, # TODO: for different types of hovels.
                 'location_number_tile0': 228, 'location_number_tile0': 230,
        'health_hypothesis1': 134,
        'health_hypothesis2': 135, # TODO: This does not seem to hold up.
    }
    _TYPE_ = 'H'
    _CLASS_ = int

    def __init__(self):
        self.data = None

    def deserialize_from(self, buffer):
        self.data = buffer.read(812)
        #self.data = list(unpack("406H", data))
        return self

    def serialize_to(self, buffer):
        #data = pack("406H", self.data)
        buffer.write(self.data)
        return self

    def _get_data(self):
        return self.data

    def _set_data(self, data):
        self.data = data