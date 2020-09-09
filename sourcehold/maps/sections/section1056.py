from .types import KeyValueMapSection


class Section1056(KeyValueMapSection):
    KEY = "YEAR"
    _MAPPING_ = {
        'year': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int
