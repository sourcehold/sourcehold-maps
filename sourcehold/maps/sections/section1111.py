from .types import KeyValueMapSection


class Section1111(KeyValueMapSection):
    KEY = "BOW"
    _MAPPING_ = {
        'bow': 0
    }
    _TYPE_ = 'H'
    _CLASS_ = bool