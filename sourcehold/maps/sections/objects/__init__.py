from .. import KeyValueStructure
from struct import unpack, pack


class Unit(KeyValueStructure):
    _MAPPING_ = {
                 'player': 8,
                    'player_2': 64,  # TODO: same data!?
        'player_3': 75,  # TODO: same data!?
                 'location_i': 112,
                 'location_j': 113,
                 'location_number': 114,
                 'health_hypothesis1': 12,
                 'health_hypothesis2': 13,
                 'health_hypothesis3': 362,
        'id': 363,
        'id_2': 364,  # TODO: same data?
    }
    _TYPE_ = 'H'
    _CLASS_ = int


class Building(KeyValueStructure):
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