from .types import ArrayMapCompressedSection
from .objects import Building


# TODO: does not work for SH, only for SHC
class Section1013(ArrayMapCompressedSection):
    _TYPE_ = Building
    _LENGTH_ = 2000
