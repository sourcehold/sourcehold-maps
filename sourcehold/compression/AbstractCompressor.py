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