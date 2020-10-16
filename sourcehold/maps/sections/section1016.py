from .types import ArrayMapCompressedSection
from .objects import ChildStructure, DataProperty


class Stub1016(ChildStructure):
    data = DataProperty("B", start=0, array_size=820)

    @classmethod
    def size_of(cls):
        return 820


class Section1016(ArrayMapCompressedSection):

    _TYPE_ = Stub1016
    _LENGTH_ = 1250
