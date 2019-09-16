import struct
import subprocess
import sys


def _int_array_to_bytes(array):
    return b''.join(struct.pack("B", v) for v in array)


class AbstractCompressor(object):

    def __init__(self):
        pass

    def _sanitize(self, data):
        if data.__class__ == list:
            if len(data) > 0:
                if data[0].__class__ == int:
                    return _int_array_to_bytes(data)
        elif data.__class__ == bytes:
            return data

        raise Exception("Unable to sanitize input")

    def compress(self, data):
        raise NotImplementedError()

    def decompress(self, data):
        raise NotImplementedError()


class DirectCompression(AbstractCompressor):

    def __init__(self):
        super().__init__()
        import compression.compressionlib_interface as handle
        self.handle = handle

    def compress(self, data):
        return self.handle.compress(self._sanitize(data))

    def decompress(self, data):
        return self.handle.decompress(self._sanitize(data))


class SubprocessCompression(AbstractCompressor):

    def __init__(self):
        super().__init__()

    def decompress(self, data):
        result = subprocess.run(["python", "compression/compressionlib_interface.py", "decompress"],
                                input=self._sanitize(data),
                                stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout

    def compress(self, data):
        result = subprocess.run(["python", "compression/compressionlib_interface.py", "compress"],
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

    def compress(self, data):
        raise NotImplementedError()


if sys.platform == "win32":
    COMPRESSION = DirectCompression()
else:
    raise NotImplementedError()

COMPRESSION = DirectCompression()
