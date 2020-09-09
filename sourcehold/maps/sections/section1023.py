from .types import KeyValueMapSection


class Section1023(KeyValueMapSection):
    KEY = "TIME1" #TODO: incomplete
    _MAPPING_ = {
        'month': 808//4,
        'year': 812//4
    }
    _TYPE_ = "I"
    _CLASS_ = int
