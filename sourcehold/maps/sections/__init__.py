import binascii

from sourcehold import compression
from sourcehold.maps import Structure, Variable
from sourcehold.maps.sections.tools import cut

import struct


class KeyValueStructure(object):
    _MAPPING_ = {}  # TODO: I guess mapping could be an array as well...
    _TYPE_ = 'B'
    _CLASS_ = bool

    def _get_data(self):
        raise NotImplementedError()

    def _set_data(self, data):
        raise NotImplementedError()

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


from sourcehold.maps import MapSection


class KeyValueMapSection(KeyValueStructure, MapSection):

    def _get_data(self):
        return self.get_data()

    def _set_data(self, data):
        return self.set_data(data)


class Section1073(KeyValueMapSection):
    # Object availability
    _MAPPING_ = {
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
    }
    _TYPE_ = "H"
    _CLASS_ = bool


class Section1061(KeyValueMapSection):
    # Popularity
    _MAPPING_ = {
        'popularity': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1065(KeyValueMapSection):
    # Trade availability
    _MAPPING_ = {
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, 'bread': 10,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
    }
    _TYPE_ = "I"
    _CLASS_ = bool


class Section1058(KeyValueMapSection):
    # Starting goods
    _MAPPING_ = {
        '': -1, '': -1, 'wood': 2, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        'gold': 15, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
    }
    _TYPE_ = "I"
    _CLASS_ = int


class Section1001(Structure):
    uncompressed_size = Variable("us", "I")
    compressed_size = Variable("cs", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = compression.COMPRESSION.compress(self.uncompressed)
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def interpret(self):
        return cut(self.uncompressed, "H", 198)


class Section1003(Structure):
    uncompressed_size = Variable("us", "I")
    compressed_size = Variable("cs", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = compression.COMPRESSION.compress(self.uncompressed)
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def interpret(self):
        return cut(self.uncompressed, "I", 198)


class Section1002(Structure):
    uncompressed_size = Variable("us", "I")
    compressed_size = Variable("cs", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = compression.COMPRESSION.compress(self.uncompressed)
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def interpret(self):
        return cut(self.uncompressed, "H", 198)


REGISTERED = [Section1001, Section1002, Section1003, Section1058, Section1061, Section1065, Section1073]


def find_section_for_index(index):
    for cls in REGISTERED:
        if str(index) in cls.__name__:
            return cls
    return None
