from sourcehold.compression.AbstractCompressor import AbstractCompressor


import dclimplode


class DCL(AbstractCompressor):

    def __init__(self):
        super().__init__()

    def compress(self, data, level = 6):
        if level == 6:
          obj = dclimplode.compressobj(dclimplode.CMP_BINARY, 4096)
          return obj.compress(self._sanitize(data)) + obj.flush()
        raise NotImplementedError(f"Compression level not implemented: {level}")

    def decompress(self, data):
        obj = dclimplode.decompressobj()
        return obj.decompress(self._sanitize(data))