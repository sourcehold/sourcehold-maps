from .types import KeyValueMapSection


class Section1112(KeyValueMapSection):
    KEY = "MACE"
    _MAPPING_ = {
        'mace': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool

