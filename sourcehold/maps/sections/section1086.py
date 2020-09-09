from .types import KeyValueMapSection


class Section1086(KeyValueMapSection):
    KEY = "CROSSBOW"
    _MAPPING_ = {
        'crossbow': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool