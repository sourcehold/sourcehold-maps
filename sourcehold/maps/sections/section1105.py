from .types import TileMapSection
from .types import ArrayMapCompressedSection
from .objects import ChildStructure
import struct
from sourcehold.world.TileLocationTranslator import TileLocationTranslator
world = TileLocationTranslator()


class TileMap(ChildStructure, TileMapSection):
    _TYPE_ = "B"
    _CLASS_ = int

    def __init__(self, parent, offset):
        super().__init__(parent, offset)

    def from_buffer(self, buf, **kwargs):
        return super().from_buffer(buf, length=80400)

    @classmethod
    def size_of(cls):
        return 80400

    def get_data(self):
        # TODO: stubbing! This is a read only section for now
        return super().get_data()[self._offset:self._offset + 80400]


class Section1105(ArrayMapCompressedSection):
    _TYPE_ = TileMap
    _LENGTH_ = 9
