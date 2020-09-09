
from .types import KeyValueMapSection


class Section1073(KeyValueMapSection):
    # Building availability, excluding units. The empty spots at 1 and 3 are probably the stronghold buildlings from SH.
    KEY = "building_availability"
    _MAPPING_ = {
        'manor_house': 0, '': -1, 'stone_keep': 2, '': -1, 'stronghold': 4,
        'look_out_tower': 5, 'perimeter_turret': 6, 'defense_turret': 7, 'square_tower': 8, 'round_tower': 9,
        'stone_wall': 10, 'low_wall': 11, 'mercenary_post': 12, 'barracks': 13, 'armory': 14,
        'small_wooden_gatehouse': 15, 'small_stone_gatehouse': 16, 'large_stone_gatehouse': 17, 'dig_moat': 18, 'drawbridge': 19,
        'brazier': 20, 'killings_pits': 21, 'pitch_ditch': 22, 'caged_war_dogs': 23, 'stables': 24,
        'engineers_guild': 25, 'tunnelers_guild': 26, 'oil_smelter': 27, 'well': 28, 'water pot': 29,
        'catapult': 30, 'trebuchet': 31, 'siege_tower': 32, 'battering_ram': 33, 'portable_shield': 34,
        'mangonel': 35, 'ballista': 36, 'stockpile': 37, 'quarry': 38, 'iron_mine': 39,
        'pitch_rig': 40, 'marketplace': 41, 'blacksmiths_workshop': 42, 'armorers_workshop': 43, 'tanners_workshop': 44,
        'fletchers_workshop': 45, 'poleturners_workshop': 46, 'hunters_post': 47, 'wheat_farm': 48, 'apple_orchard': 49,
        'hops_farm': 50, 'dairy_farm': 51, 'granary': 52, 'mill': 53, 'bakery': 54,
        'brewery': 55, 'inn': 56, 'woodcutter': 57, 'hovel': 58, 'apothecary': 59,
        'chapel': 60, 'church': 61, 'cathedral': 62, 'good_things': 63, 'bad_things': 64,
        'fire_ballista': 65,
        # These just seem empty and unused!
        '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
        '': -1, '': -1, '': -1, '': -1, '': -1,
    }
    _TYPE_ = "H"
    _CLASS_ = bool
