import binascii
import struct

from sourcehold import compression
from sourcehold.maps import Structure, Variable
from sourcehold.maps.sections.tools import cut
from sourcehold.maps import CompressedMapSection
from sourcehold.maps import MapSection


class TileStructure(object):
    _TYPE_ = 'B'
    _CLASS_ = int

    def _get_data(self):
        raise NotImplementedError()

    def _set_data(self, data):
        raise NotImplementedError()

    def get_tiles(self):
        d = self._get_data()
        dcut = cut(d, self._TYPE_, 198)
        for i in range(len(dcut)):
            for j in range(len(dcut[i])):
                dcut[i][j] = self._CLASS_(dcut[i][j])
        return dcut

    def get_tiles_flattened(self):
        return [a for b in self.get_tiles() for a in b]


class TileMapSection(TileStructure, MapSection):

    def _get_data(self):
        return self.get_data()

    def _set_data(self, data):
        return self.set_data(data)


class TileCompressedMapSection(TileStructure, CompressedMapSection):

    def _get_data(self):
        return self.get_data()

    def _set_data(self, data):
        return self.set_data(data)


class KeyValueStructure(object):
    _MAPPING_ = {}  # TODO: I guess mapping could be an array as well...
    _TYPE_ = 'B'
    _CLASS_ = bool

    def _get_data(self):
        raise NotImplementedError()

    def _set_data(self, data):
        raise NotImplementedError()

    def __getitem__(self, item):
        return self.get_field(item)

    def __setitem__(self, key, value):
        return self.set_field(key, value)

    def __getattr__(self, item):
        if item in self._MAPPING_.keys():
            return self.get_field(item)
        return super().__getattribute__(item)

    def __setattr__(self, key, value):
        if key in self._MAPPING_.keys():
            return self.set_field(key, value)
        return super().__setattr__(key, value)

    def __dir__(self):
        for key in self._MAPPING_.keys():
            yield key

    def set_field(self, field, value):
        if type(value) != self._CLASS_:
            value = self._CLASS_(value)

        packed = struct.pack(self._TYPE_, value)

        index = self._MAPPING_[field]
        pos = index * struct.calcsize(self._TYPE_)
        posa = (index + 1) * struct.calcsize(self._TYPE_)

        d = self._get_data()
        dn = d[:pos] + packed + d[posa:]

        assert len(d) == len(dn)

        self._set_data(dn)

    def _unpack(self):
        d = self._get_data()
        size = struct.calcsize(self._TYPE_)
        amount = len(d) // size
        fmt = str(amount) + self._TYPE_
        unpacked = struct.unpack(fmt, d)

        return unpacked

    def get_field(self, field):

        index = self._MAPPING_[field]

        value = self._unpack()[index]

        if type(value) != self._CLASS_:
            value = self._CLASS_(value)

        return value

    def list_fields(self):
        return self._MAPPING_.keys()





class KeyValueMapSection(KeyValueStructure, MapSection):

    def _get_data(self):
        return self.get_data()

    def _set_data(self, data):
        return self.set_data(data)


class Section1073(KeyValueMapSection):
    # Building availability, excluding units. The empty spots at 1 and 3 are probably the stronghold buildlings from SH.
    KEY = "building_availability"
    _MAPPING_ = {
        'manor_house': 0, '': -1, 'stone_keep': 2, '': -1, 'stronghold': 4,
        'look_out_tower': 5, 'perimeter_turret': 6, 'defense_turret': 7, 'square_tower': 8, 'round_tower': 9,
        'stone_wall': 10, 'low_wall': 11, 'mercenary_post': 12, 'barracks': 13, 'armory': 14,
        'small_wooden_gatehouse': 15, 'small_stone_gatehouse': 16, 'large_stone_gatehouse': 17, 'dig_moat': 18, 'drawbridge': 19,
        'brazier': 20, 'killings_pits': 21, 'pitch_ditch': 22, 'caged_war_dogs': 23, 'stables': 24,
        'engineers_guild': 25, 'tunnelers_guild': 26, 'oil_smelter': 27, 'well': 28, 'water pot': 29,
        'catapult': 30, 'trebuchet': 31, 'siege_tower': 32, 'battering_ram': 33, 'portable_shield': 34,
        'mangonel': 35, 'ballista': 36, 'stockpile': 37, 'quarry': 38, 'iron_mine': 39,
        'pitch_rig': 40, 'marketplace': 41, 'blacksmiths_workshop': 42, 'armorers_workshop': 43, 'tanners_workshop': 44,
        'fletchers_workshop': 45, 'poleturners_workshop': 46, 'hunters_post': 47, 'wheat_farm': 48, 'apple_orchard': 49,
        'hops_farm': 50, 'dairy_farm': 51, 'granary': 52, 'mill': 53, 'bakery': 54,
        'brewery': 55, 'inn': 56, 'woodcutter': 57, 'hovel': 58, 'apothecary': 59,
        'chapel': 60, 'church': 61, 'cathedral': 62, 'good_things': 63, 'bad_things': 64,
        'fire_ballista': 65, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
    }
    _TYPE_ = "H"
    _CLASS_ = bool



class Section1023(KeyValueMapSection):
    KEY = "TIME1" #TODO: incomplete
    _MAPPING_ = {
        'month': 808//4,
        'year': 812//4
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1056(KeyValueMapSection):
    KEY = "YEAR"
    _MAPPING_ = {
        'year': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1057(KeyValueMapSection):
    KEY = "MONTH"
    _MAPPING_ = {
        'month': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1085(KeyValueMapSection):
    KEY = "UNITS"
    _MAPPING_ = {
        'archer': 0,
        'spearman': 1,
        'maceman': 2,
        'crossbowman': 3,
        'pikeman': 4,
        'swordsman': 5,
        'knight': 6,
    }
    _TYPE_ = "H"
    _CLASS_ = bool


class Section1086(KeyValueMapSection):
    KEY = "CROSSBOW"
    _MAPPING_ = {
        'crossbow': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool


class Section1088(KeyValueMapSection):
    KEY = "PIKE"
    _MAPPING_ = {
        'pike': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool


class Section1087(KeyValueMapSection):
    KEY = "SWORD"
    _MAPPING_ = {
        'sword': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool


class Section1111(KeyValueMapSection):
    KEY = "BOW"
    _MAPPING_ = {
        'bow': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool


class Section1113(KeyValueMapSection):
    KEY = "SPEAR"
    _MAPPING_ = {
        'spear': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool


class Section1112(KeyValueMapSection):
    KEY = "MACE"
    _MAPPING_ = {
        'mace': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool


class Section1102(KeyValueMapSection):
    KEY = "ARAB_UNITS"
    _MAPPING_ = {
        'arab_archer': 0,
        'slave': 1,
        'slinger': 2,
        'assassin': 3,
        'horse_archer': 4,
        'arab_swordsman': 5,
        'fire_thrower': 6,
    }
    _TYPE_ = "H"
    _CLASS_ = bool


class Section1061(KeyValueMapSection):
    KEY = "POPULARITY"
    _MAPPING_ = {
        'popularity': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1065(KeyValueMapSection):
    KEY = "MARKET_AVAILABILITY"
    _MAPPING_ = {
        '': 0, '': 1, 'wood': 2, 'hop': 3, 'stone': 4,
        '': 5, 'iron': 6, '': 7, 'pitch': 8, 'wheat': 9,
        'bread': 10, 'cheese': 11, 'meat': 12, 'fruit': 13, 'ale': 14,
        '': 15, 'flour': 16, 'bow': 17, 'crossbow': 18, 'spear': 19,
        'pike': 20, 'mace': 21, 'sword': 22, 'leather_armor': 23, 'steel_armor': 24,
    }
    _TYPE_ = "I"
    _CLASS_ = bool


class Section1058(KeyValueMapSection):
    KEY = "STARTING_GOODS"
    _MAPPING_ = {
        '': 0, '': 1, 'wood': 2, 'hop': 3, 'stone': 4,
        '': 5, 'iron': 6, '': 7, 'pitch': 8, 'wheat': 9,
        'bread': 10, 'cheese': 11, 'meat': 12, 'fruit': 13, 'ale': 14,
        'gold': 15, '': 16, 'bow': 17, 'crossbow': 18, 'spear': 19,
        'pike': 20, 'mace': 21, 'sword': 22, 'leather_armor': 23, 'steel_armor': 24,
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1001(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1002(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1003(TileCompressedMapSection):
    _TYPE_ = "I"
    _CLASS_ = int


class Section1004(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1005(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1006(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1007(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1008(TileMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1009(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1010(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1012(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1020(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1021(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1026(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1028(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1029(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1030(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1033(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1036(TileCompressedMapSection):
    _TYPE_ = "H"
    _CLASS_ = int


class Section1037(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1043(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1045(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1049(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1103(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1104(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1105(TileCompressedMapSection):
    _TYPE_ = "9B"
    _CLASS_ = list


class Section1118(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


import re
pattern = re.compile("Section[0-9]{4}")

REGISTERED = {key: value for key, value in globals().items() if pattern.match(key) is not None}

def find_section_for_index(index):
    key = "Section" + str(index)
    if key in REGISTERED:
        return REGISTERED[key]
    return None
