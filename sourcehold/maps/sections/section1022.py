
from .types import ArrayMapCompressedSection
from .objects import PlayerData


class Section1022(ArrayMapCompressedSection):
    _TYPE_ = PlayerData
    _LENGTH_ = 9
