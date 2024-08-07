import struct
import subprocess
import sys


class AbstractCompressor(object):

    def __init__(self):
        pass

    def _sanitize(self, data):
        try:
            return bytes(bytearray(data))
        except Exception as e:
            raise Exception("Unable to sanitize input of type: " + str(type(data)))

    def compress(self, data, level = 6):
        raise NotImplementedError()

    def decompress(self, data):
        raise NotImplementedError()


import dclimplode

class DCL(AbstractCompressor):
    
    def __init__(self):
        super().__init__()

    def compress(self, data, level = 6):
        if level == 6:
          obj = dclimplode.compressobj(dclimplode.CMP_BINARY, 4096)
          obj.compress(self._sanitize(data))
          return obj.flush()
        raise NotImplementedError(f"Compression level not implemented: {level}")
    
    def decompress(self, data):
        obj = dclimplode.decompressobj()
        obj.decompress(self._sanitize(data))
        return obj.flush()

COMPRESSION = DCL()
