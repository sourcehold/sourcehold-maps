from sourcehold.structure_tools.UnderflowException import UnderflowException


import io


class Buffer(io.BytesIO):

    def __init__(self, initial_bytes=b''):
        super().__init__(initial_bytes)
        self.bytes_length = len(initial_bytes)

    def read(self, size=-1):
        d = super().read(size)
        if len(d) < size:
            raise UnderflowException("Data underflow. Expected {} bytes, but got {}".format(size, len(d)))
        return d

    def write(self, b):
        diff = len(b) - (self.bytes_length - self.tell())
        if diff > 0:
            self.bytes_length += diff
        return super().write(b)

    def remaining(self):
        return self.bytes_length - self.tell()

    def peek(self, size=1):
        d = self.read(size)
        self.seek(self.tell() - len(d))
        return d

    def eof(self):
        return self.remaining() == 0

    def assert_eof(self):
        assert self.remaining() == 0