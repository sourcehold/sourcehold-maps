from sourcehold import compression
from sourcehold.structure_tools.Field import Field
from sourcehold.structure_tools.Structure import Structure


import binascii


class Description(Structure):
    size = Field("size", "I")  # This structure in size, + compressed size
    use_string_table = Field("use_string_table", "I")  # TODO: serialize this to a .meta file
    string_table_index = Field("string_table_index", "I")
    uncompressed_size = Field("uncompressed_size", "I")
    compressed_size = Field("compressed_size", "I")
    hash = Field("hash", "I")
    data = Field("data", "B", compressed_size)

    def __init__(self):
        super().__init__()
        self._dirty = False

    def pack(self, force = False):
        if self._dirty or force:
            if not hasattr(self, "compression_level"):
                self.compression_level = 6
            if not hasattr(self, "use_string_table"):
                self.use_string_table = 0
            if not hasattr(self, "string_table_index"):
                self.string_table_index = 0
            self.data = compression.COMPRESSION.compress(self.uncompressed, self.compression_level)
            self.hash = binascii.crc32(self.uncompressed)
            self.uncompressed_size = len(self.uncompressed)
            self.compressed_size = len(self.data)
            self.size = self.compressed_size + (5 * 4)

    def set_description(self, string: str):
        bstring = string.encode('ascii')
        if len(bstring) >= 1000:
            raise Exception("description text too long: {}".format(len(bstring)))

        padded = bstring + b'\x00' * (1000 - len(bstring))
        self.uncompressed = padded
        self.uncompressed = self.uncompressed[:212] + b'\x04\x00?\x00????8?8? ??' + self.uncompressed[227:]
        # self.description_size = len(bstring)

    def get_description(self):
        j = len(self.uncompressed)

        while j > 0:
            j -= 1
            v = self.uncompressed[j]
            if v != 0:
                break

        return self.uncompressed[:j].decode('ascii')

    def unpack(self, force = False):
        if self._dirty or force:
            self.compression_level = self.data[1]
            self.uncompressed = compression.COMPRESSION.decompress(self.data)
            assert len(self.data) == self.compressed_size
            assert len(self.uncompressed) == self.uncompressed_size
            assert binascii.crc32(self.uncompressed) == self.hash
            assert self.compressed_size + (5 * 4) == self.size

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack(force=True)
        return self.uncompressed

    def set_data(self, data):
        self.uncompressed = data

    def size_of(self):
        return self.compressed_size + (6 * 4)