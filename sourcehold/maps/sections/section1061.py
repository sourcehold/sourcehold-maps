from .types import KeyValueMapSection


class Section1061(KeyValueMapSection):
    KEY = "POPULARITY"
    _MAPPING_ = {
        'popularity': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int