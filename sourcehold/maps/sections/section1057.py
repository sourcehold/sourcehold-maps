from .types import KeyValueMapSection


class Section1057(KeyValueMapSection):
    KEY = "MONTH"
    _MAPPING_ = {
        'month': 0
    }
    _TYPE_ = "I"
    _CLASS_ = int
