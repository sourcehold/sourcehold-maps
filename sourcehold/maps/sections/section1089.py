
from ..CompressedMapSection import CompressedMapSection


class Section1089(CompressedMapSection):

    def get_string(self):
        v = self.get_data().decode('ascii')
        i = v.index('\x00')
        return v[:i]

    def set_string(self, s):
        v = s.encode('ascii')
        remaining = 128 - len(v)
        if remaining < 0:
            raise Exception(f"string should be max 128 bytes in size, is {len(v)}")

        self.set_data(v + b'\x00' * remaining)
