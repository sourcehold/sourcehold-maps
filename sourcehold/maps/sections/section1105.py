from .types import TileMapSection
from .types import ArrayMapCompressedSection
from .objects import ChildStructure


class TileMap(ChildStructure, TileMapSection):
    _TYPE_ = "B"
    _CLASS_ = int

    def __init__(self, parent, offset):
        super().__init__(parent, offset)
        # TODO: stubbing! This is a read only section for now

    def from_buffer(self, buf, **kwargs):
        return super().from_buffer(buf, length=80400)

    @classmethod
    def size_of(cls):
        return 80400


class Section1105(ArrayMapCompressedSection):
    _TYPE_ = TileMap
    _LENGTH_ = 9
