from .types import ArrayMapCompressedSection
from .objects import Unit


# TODO: does not work for SH, only for SHC
class Section1015(ArrayMapCompressedSection):
    _TYPE_ = Unit
    _LENGTH_ = 2500
