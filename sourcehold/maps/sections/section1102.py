from .types import KeyValueMapSection


class Section1102(KeyValueMapSection):
    KEY = "ARAB_UNITS"
    _MAPPING_ = {
        'arab_archer': 0,
        'slave': 1,
        'slinger': 2,
        'assassin': 3,
        'horse_archer': 4,
        'arab_swordsman': 5,
        'fire_thrower': 6,
    }
    _TYPE_ = "H"
    _CLASS_ = bool