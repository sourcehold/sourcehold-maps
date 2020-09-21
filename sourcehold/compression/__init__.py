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

    def compress(self, data, level):
        raise NotImplementedError()

    def decompress(self, data):
        raise NotImplementedError()


class DirectCompression2(AbstractCompressor):

    def __init__(self):
        super().__init__()

        import importlib
        handle = importlib.import_module("sourcehold.compressionlib")
        #import sourcehold.compressionlib as handle
        self.handle = handle
        self.buffer = bytearray(b'\x00' * 1000 * 1000 * 32)

    def compress(self, data, level=6):
        n = self.handle.implode(bytearray(data), self.buffer, level)
        return bytes(self.buffer[:n])

    def decompress(self, data):
        n = self.handle.explode(bytearray(data), self.buffer)
        return bytes(self.buffer[:n])


class DirectCompression(AbstractCompressor):

    def __init__(self):
        super().__init__()

        import sourcehold.compression.compressionlib_interface_nocb as handle
        self.handle = handle

    def compress(self, data, level=6):
        return self.handle.compress(self._sanitize(data), level)

    def decompress(self, data):
        return self.handle.decompress(self._sanitize(data))


class SubprocessCompression(AbstractCompressor):

    def __init__(self):
        super().__init__()

    def decompress(self, data):
        result = subprocess.run(["python", "sourcehold/compression/compressionlib_interface.py", "decompress"],
                                input=self._sanitize(data),
                                stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout

    def compress(self, data, level):
        result = subprocess.run(["python", "sourcehold/compression/compressionlib_interface.py", "compress"],
                                input=self._sanitize(data),
                                stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout


class BlastDecompression(AbstractCompressor):

    def __init__(self, blastpath="bin/blast.exe"):
        super().__init__()
        self._path = blastpath

    def decompress(self, data):
        result = subprocess.run(self._path, input=self._sanitize(data), stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout

    def compress(self, data, level):
        raise NotImplementedError()


COMPRESSION = DirectCompression2()
