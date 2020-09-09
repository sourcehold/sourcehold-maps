from .types import KeyValueMapSection


class Section1085(KeyValueMapSection):
    KEY = "UNITS"
    _MAPPING_ = {
        'archer': 0,
        'spearman': 1,
        'maceman': 2,
        'crossbowman': 3,
        'pikeman': 4,
        'swordsman': 5,
        'knight': 6,
    }
    _TYPE_ = "H"
    _CLASS_ = bool