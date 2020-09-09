from .types import KeyValueMapSection


class Section1113(KeyValueMapSection):
    KEY = "SPEAR"
    _MAPPING_ = {
        'spear': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool