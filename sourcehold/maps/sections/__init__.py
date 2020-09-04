import struct

from sourcehold.maps import CompressedMapSection
from sourcehold.maps import MapSection
from sourcehold.maps.sections.tools import cut
from sourcehold.maps.sections.tools import make_image_of_data


class TileSystemRow(object):

    def __init__(self):
        self.header = None
        self.footer = None
        self.data = []

    def __len__(self):
        return len(self.data)

    def __getitem__(self, item):
        return self.data[item]

    def __setitem__(self, key, value):
        self.data[key] = value


from ...iotools import Buffer



def bytes_to_tiles(x: Buffer, rows = 401, fmt = "B"):
    fmt_size = struct.calcsize(fmt)

    data = []
    for i in range(1, rows+1, 1):
        if i <= rows//2:
            data.append([struct.unpack(fmt, x.read(fmt_size))[0] for j in range(i*2)])
        else:
            data.append([struct.unpack(fmt, x.read(fmt_size))[0] for j in range((rows-i)*2)])
    return data


class TileSystem(object):

    def __init__(self):
        self.rows = []
        self.header = None
        self.footer = None
        self.fmt = None

    def tiles(self):
        count = -1
        for i in range(len(self)):
            for j in range(len(self[i])):
                count += 1
                yield i, j, count, self[i][j]

    def __getitem__(self, item):
        return self.rows[item]

    def __setitem__(self, key, value):
        self.rows[key] = value

    def __len__(self):
        return len(self.rows)

    def __sub__(self, other):
        if len(self.rows) != len(other.rows):
            raise Exception()
        system = TileSystem()
        for row in range(len(self.rows)):
            r = TileSystemRow()
            for col in range(len(self.rows[row].data)):
                r.data.append(self.rows[row].data[col] - other.rows[row].data[col])
            system.rows.append(r)
        return system

    def get_index_for_tile_number(self, number, game_adjusted = False):
        i = 0
        j = 0
        v = 0
        for i in range(len(self.rows)):
            for j in range(len(self.rows[i])):
                if v >= number:
                    return i, (j + (abs(199-i) if i < 200 else abs(200-i))) if game_adjusted else j
                v += 1
        raise Exception("number does not exist {}".format(number))

    def get_tile_number_for_index(self, ij, game_adjusted = False):
        v = 0
        i, j = ij
        ij = i, (j - (abs(199-i) if i < 200 else abs(200-i))) if game_adjusted else j
        for i in range(len(self.rows)):
            for j in range(len(self.rows[i])):
                if i == ij[0]:
                    if j == ij[1]:
                        return v
                v += 1
        raise Exception("ij pair does not exist {}".format(ij))

    def create_image(self):
        return make_image_of_data(self.get_tiles())

    def get_tiles(self):
        return [row.data for row in self.rows]

    def from_bytes(self, data, fmt, rows=199):
        self.fmt = fmt
        self.rows.clear()

        if type(data) == bytes:
            data = Buffer(data)
        size = struct.calcsize(fmt)
        #rows = 199

        typ = fmt
        self.header = []
        #self.header = [struct.unpack(typ, data.read(size))[0] for v in range(2)]
        # TODO: bit of a hack like it is written now.

        for i in range(0, rows + 1, 1):
            row = TileSystemRow()
            row.header = [struct.unpack(typ, data.read(size))[0] for v in range(1)]
            row.data = [struct.unpack(typ, data.read(size))[0] for v in range(i * 2)]
            row.footer = [struct.unpack(typ, data.read(size))[0] for v in range(1)]
            row.data = row.header + row.data + row.footer
            row.header = []
            row.footer = []
            self.rows.append(row)

        for i in range(rows, -1, -1):
            row = TileSystemRow()
            row.header = [struct.unpack(typ, data.read(size))[0] for v in range(1)]
            row.data = [struct.unpack(typ, data.read(size))[0] for v in range(i * 2)]
            row.footer = [struct.unpack(typ, data.read(size))[0] for v in range(1)]
            row.data = row.header + row.data + row.footer
            row.header = []
            row.footer = []
            self.rows.append(row)

        #self.footer = [struct.unpack(typ, data.read(size))[0] for v in range(2)]

        # The first and last row are empty

        self.footer = []

        assert data.remaining() == 0

        return self

    def to_bytes(self):
        data = Buffer()
        data.write(b''.join(struct.pack(self.fmt, v) for v in self.header))

        for row in self.rows:
            data.write(b''.join(struct.pack(self.fmt, v) for v in row.header))
            data.write(b''.join(struct.pack(self.fmt, v) for v in row.data))
            data.write(b''.join(struct.pack(self.fmt, v) for v in row.footer))

        data.write(b''.join(struct.pack(self.fmt, v) for v in self.footer))

        return data.getvalue()


from sourcehold.world import TileLocationTranslator
world = TileLocationTranslator()


class TileStructure(object):
    _TYPE_ = 'B'
    _CLASS_ = int

    def __getitem__(self, item):
        if type(item) == tuple:
            return self.__getitem__(world.SerializedTilePoint(i=item[0], j=item[1]))

        if type(item) == world.SerializedTilePoint:
            return self.__getitem__(item.to_serialized_tile_index().index)

        if type(item) == int:
            size = struct.calcsize(self._TYPE_)
            return struct.unpack(self._TYPE_, self.get_data()[(item * size):(
                        (item + 1) * size)])[0]

        if type(item) == slice:
            size = struct.calcsize(self._TYPE_)
            indices = list(range(*item.indices()))
            return [struct.unpack(self._TYPE_, self.get_data()[(index * size):(
                    (index + 1) * size)])[0] for index in indices]

        raise NotImplementedError(f"getitem not implemented for type: {type(item)}")

    def __setitem__(self, key, value):
        if type(key) == tuple:
            return self.__setitem__(world.SerializedTilePoint(i=key[0], j=key[1]), value)

        if type(key) == world.SerializedTilePoint:
            return self.__setitem__(key.to_serialized_tile_index().index, value)

        if type(key) == int:
            size = struct.calcsize(self._TYPE_)
            obj = struct.pack(self._TYPE_, value)
            data = self.get_data()
            data[(key * size):((key + 1) * size)] = obj
            return self.set_data(data)

        if type(key) == slice:
            size = struct.calcsize(self._TYPE_)
            indices = list(range(*key.indices()))
            objs = [struct.pack(self._TYPE_, v) for v in value]
            assert len(objs) == len(indices)
            data = self.get_data()
            for i, index in enumerate(indices):
                data[(index * size):((index + 1) * size)] = objs[i]
            return self.set_data(data)

        raise NotImplementedError(f"getitem not implemented for type: {type(key)}")

    def get_data(self):
        raise NotImplementedError()

    def set_data(self, data):
        raise NotImplementedError()

    def get_tiles(self):
        return TileSystem().from_bytes(self.get_data(), self._TYPE_)

        ## TODO: validate the above to be the same as this:
        # d = self._get_data()
        # dcut = cut(d, self._TYPE_, 198)
        # for i in range(len(dcut)):
        #     for j in range(len(dcut[i])):
        #         dcut[i][j] = self._CLASS_(dcut[i][j])
        # return dcut

    def get_tiles_flattened(self):
        return [a for b in self.get_tiles() for a in b]

    def create_image(self):
        return self.get_system().create_image()

    def get_system(self):
        return TileSystem().from_bytes(self.get_data(), self._TYPE_)

    def compare_tiles(self, other):
        t0 = self.get_tiles()
        t1 = other.get_tiles()
        n0 = len(t0)
        n1 = len(t1)
        if n0 != n1:
            yield "unequal length of tiles: {}, {}".format(n0, n1)
        for i in range(n0):
            for j in range(len(t0[i])):
                if t0[i][j] != t1[i][j]:
                    yield "unequal values for index (i, j) {}, {}. values: {}, {}".format(i, j, t0[i][j], t1[i][j])

    def __sub__(self, other):
        t0 = self.get_tiles()
        t1 = other.get_tiles()
        n0 = len(t0)
        n1 = len(t1)
        ni = min(n0, n1)
        for i in range(ni):
            for j in range(min(len(t0[i]), len(t1[i]))):
                yield t0[i][j] - t1[i][j]


class TileMapSection(MapSection, TileStructure):
    pass


class TileCompressedMapSection(CompressedMapSection, TileStructure):
    pass


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


class ArrayMapStructure(object):
    _TYPE_ = None
    _LENGTH_ = 0

    def __init__(self):
        self.items = None
        self._dirty = False

    def _get_data(self):
        raise NotImplementedError()

    def _set_data(self, data):
        raise NotImplementedError()

    def __len__(self):
        return len(self.items.keys())

    def __getitem__(self, item):
        return self.items[item]

    def __setitem__(self, key, value):
        self.items[key] = value
        self._dirty = True

    def unpack(self, force=False):
        if self._dirty or force:
            self.items = {}
            buf = Buffer(self._get_data())
            for i in range(self._LENGTH_):
                peek = buf.peek(self._TYPE_.size_of())
                if set(peek) == {0}:
                    buf.read(self._TYPE_.size_of())
                else:
                    self.items[i] = self._TYPE_().from_buffer(buf)

    def pack(self, force=False):
        if self._dirty or force:
            buf = Buffer()

            # TODO: what do we do when this section is never unpacked? for now, let's leave things unchanged.
            if self.items is None:
                return

            for i in range(self._LENGTH_):
                if i in self.items:
                    self.items[i].serialize_to_buffer(buf)
                else:
                    buf.write(b'\x00'*self._TYPE_.size_of())

            self._set_data(buf.getvalue())
            self._dirty = True


class ArrayMapSection(ArrayMapStructure, MapSection):

    def _get_data(self):
        return self.get_data()

    def _set_data(self, data):
        return self.set_data(data)

    def pack(self, force=False):
        ArrayMapStructure.pack(self, force)
        MapSection.pack(self, force)

    def unpack(self, force=False):
        MapSection.unpack(self, force)
        ArrayMapStructure.unpack(self, force)


class ArrayMapCompressedSection(ArrayMapStructure, CompressedMapSection):

    def _get_data(self):
        return self.get_data()

    def _set_data(self, data):
        return self.set_data(data)

    def pack(self, force=False):
        if force or self._dirty:
            ArrayMapStructure.pack(self, force)
            CompressedMapSection.pack(self, force)

    def unpack(self, force=False):
        if force or self._dirty:
            CompressedMapSection.unpack(self, force)
            ArrayMapStructure.unpack(self, force)


from sourcehold.maps.sections.objects import Building, Unit


# TODO: does not work for SH, only for SHC
class Section1013(ArrayMapCompressedSection):
    _TYPE_ = Building
    _LENGTH_ = 2000


# TODO: does not work for SH, only for SHC
class Section1015(ArrayMapCompressedSection):
    _TYPE_ = Unit
    _LENGTH_ = 2500


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
        'fire_ballista': 65,
        # These just seem empty and unused!
        '': -1, '': -1, '': -1, '': -1,
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



class Section1017(KeyValueMapSection):
    KEY = "SECTION1017"
    _TYPE_ = "I"
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


class Section1089(CompressedMapSection):

    def get_string(self):
        v = self.get_data().decode('ascii')
        i = v.index('\x00')
        return v[:i]

    def set_string(self, s):
        v = s.encode('ascii')
        remaining = 128 - len(v)
        if remaining < 0:
            raise Exception(f"string should be max 128 bytes in size, is {len(v)}")

        self.set_data(v + b'\x00' * remaining)




class Section1103(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class Section1104(TileCompressedMapSection):
    _TYPE_ = "B"
    _CLASS_ = int


class TileMap(TileMapSection):
    _TYPE_ = "B"
    _CLASS_ = int

    def from_buffer(self, buf, **kwargs):
        return super().from_buffer(buf, length=80400)

    @classmethod
    def size_of(cls):
        return 80400


class Section1105(ArrayMapCompressedSection):
    _TYPE_ = TileMap
    _LENGTH_ = 9


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
