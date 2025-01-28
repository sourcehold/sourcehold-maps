from ...structure_tools.DataProperty import DataProperty
from .types import ArrayMapCompressedSection
from .objects import ChildStructure


class Stub1025(ChildStructure):

    data = DataProperty("B", start=0, array_size=232)

    def __init__(self, parent, offset):
        super().__init__(parent, offset)

    @classmethod
    def size_of(cls):
        return 232


class Section1025(ArrayMapCompressedSection):
    _TYPE_ = Stub1025
    _LENGTH_ = 3000
