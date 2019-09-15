import subprocess
import sys


class AbstractCompressor(object):

    def __init__(self):
        pass

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
        return self.handle.compress(data)

    def decompress(self, data):
        return self.handle.decompress(data)


class SubprocessCompression(AbstractCompressor):

    def __init__(self):
        super().__init__()

    def decompress(self, data):
        result = subprocess.run(["python", "compression/compressionlib_interface.py", "decompress"], input=data,
                                stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout

    def compress(self, data):
        result = subprocess.run(["python", "compression/compressionlib_interface.py", "compress"], input=data,
                                stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout


class BlastDecompression(AbstractCompressor):

    def __init__(self, blastpath="bin/blast.exe"):
        super().__init__()
        self._path = blastpath

    def decompress(self, data):
        result = subprocess.run(self._path, input=data, stdout=subprocess.PIPE)
        result.check_returncode()
        return result.stdout

    def compress(self, data):
        raise NotImplementedError()


if sys.platform == "win32":
    COMPRESSION = DirectCompression()
else:
    raise NotImplementedError()

COMPRESSION = DirectCompression()
