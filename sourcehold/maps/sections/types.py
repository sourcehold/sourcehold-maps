
from sourcehold.maps import CompressedMapSection
from sourcehold.maps import MapSection
from sourcehold.maps.sections.tools import cut
from sourcehold.maps.sections.tools import make_image_of_data
import struct


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

        if type(data) == bytes or type(data) == bytearray:
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
        self._dirty = True

    def _get_data(self):
        raise NotImplementedError()

    def _set_data(self, data):
        raise NotImplementedError()

    def __len__(self):
        return len(self.items.keys())

    def __getitem__(self, item):
        if self.items is None:
            self.unpack(True)
        return self.items[item]

    def __setitem__(self, key, value):
        if self.items is None:
            self.unpack(True)
        self.items[key] = value
        self._dirty = True

    def unpack(self, force=False):
        # if self._dirty or force:
        #     self.items = {}
        #     buf = Buffer(self._get_data())
        #     for i in range(self._LENGTH_):
        #         peek = buf.peek(self._TYPE_.size_of())
        #         if set(peek) == {0}:
        #             #  Skip this entry, because it is empty
        #             buf.read(self._TYPE_.size_of())
        #         else:
        #             self.items[i] = self._TYPE_(parent=self, offset=self._TYPE_.size_of()*i)
        self.items = {}
        for i in range(self._LENGTH_):
            self.items[i] = self._TYPE_(parent=self, offset=self._TYPE_.size_of() * i)

    def pack(self, force=False):
        pass
        # if self._dirty or force:
        #     buf = Buffer()
        #
        #     # TODO: what do we do when this section is never unpacked? for now, let's leave things unchanged.
        #     if self.items is None:
        #         return
        #
        #     # TODO: Are there still use cases for this?
        #     # for i in range(self._LENGTH_):
        #     #     if i in self.items:
        #     #         self.items[i].serialize_to_buffer(buf)
        #     #     else:
        #     #         buf.write(b'\x00'*self._TYPE_.size_of())
        #     #
        #     # self._set_data(buf.getvalue())
        #     self._dirty = False


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
            self.pack_items()

    def unpack(self, force=False):
        if force or self._dirty:
            CompressedMapSection.unpack(self, force)
            self.unpack_items()

    def unpack_items(self):
        ArrayMapStructure.unpack(self, True)

    def pack_items(self):
        ArrayMapStructure.pack(self, True)