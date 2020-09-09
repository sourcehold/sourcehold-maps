from .types import KeyValueMapSection


class Section1065(KeyValueMapSection):
    KEY = "MARKET_AVAILABILITY"
    _MAPPING_ = {
        '': 0, '': 1, 'wood': 2, 'hop': 3, 'stone': 4,
        '': 5, 'iron': 6, '': 7, 'pitch': 8, 'wheat': 9,
        'bread': 10, 'cheese': 11, 'meat': 12, 'fruit': 13, 'ale': 14,
        '': 15, 'flour': 16, 'bow': 17, 'crossbow': 18, 'spear': 19,
        'pike': 20, 'mace': 21, 'sword': 22, 'leather_armor': 23, 'steel_armor': 24,
    }
    _TYPE_ = "I"
    _CLASS_ = bool
