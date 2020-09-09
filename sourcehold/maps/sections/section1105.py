from .types import TileMapSection
from .types import ArrayMapCompressedSection


class TileMap(TileMapSection):
    _TYPE_ = "B"
    _CLASS_ = int

    def from_buffer(self, buf, **kwargs):
        return super().from_buffer(buf, length=80400)

    @classmethod
    def size_of(cls):
        return 80400


class Section1105(ArrayMapCompressedSection):
    _TYPE_ = TileMap
    _LENGTH_ = 9