from sourcehold import compression
from sourcehold.structure_tools.Field import Field
from sourcehold.structure_tools.Structure import Structure


import binascii


class CompressedSection(Structure):
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
            self.data = compression.COMPRESSION.compress(self.uncompressed, self.compression_level)
            self.hash = binascii.crc32(self.uncompressed)
            self.uncompressed_size = len(self.uncompressed)
            self.compressed_size = len(self.data)
            self._dirty = False

    def unpack(self, force = False):
        if self._dirty or force:
            self.compression_level = self.data[1]
            self.uncompressed = compression.COMPRESSION.decompress(self.data)
            assert len(self.data) == self.compressed_size
            assert len(self.uncompressed) == self.uncompressed_size
            assert binascii.crc32(self.uncompressed) == self.hash
            self._dirty = False

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack(force=True)
        return self.uncompressed

    def set_data(self, data):
        self.uncompressed = data
        self._dirty = True

    def size_of(self):
        return self.compressed_size + 4 + 4 + 4