logic1 = {
  'none': 0,
  'default_earth_or_texture': 0x8000, #'#ae9467',

  'ocean': 0x1,
  # 'stockpile': 0x2,
  'plain1_and_farm': 0x4, # 0x8000
  'plain2_and_pitch': 0x8, # 0x8000
  
  'border': 0x10,
  'border_edge': 0x20,
  
  'rocks': 0x80,
  
  # 'wall_gatehouse_tower': 0x100,
  # 'crenel': 0x200,
  # 'building': 0x400,
  # 'stairs': 0x800,
  # 'tree': 0x1000,
  # 'tree_variation': 0x2000,
  'moat_dug': 0x4000,
  
  'oasis_grass': 0x8000, # special
  'thick_scrub': 0x8000, # special
  'scrub': 0x8000, # special
  'driven_sand': 0x8000, # special '#b79453',
  'beach': 0x8000, # special '#deb977',
  'plateau_high': 0x8000,
  'plateau_medium': 0x8000,
  'earth_and_stones': 0x8000,
  # 'unknown_wall_related': 0x10000,
  'boulders': 0x20000,
  'pebbles': 0x40000, # TODO: what is this even?
  'iron': 0x80000,
  'river': 0x100000,
  'ford': 0x200000,
  'crenel_variation': 0x400000,
  'marsh': 0x20000000,
  'moat': 0x40000000,
  'oil': 0x80000000,
  # max_height_related = 0x8000, #TODO: not right
  
}

logic1_vk = {v: k for k, v in logic1.items()}

logic1_vk[0x8000] = 'default_earth_or_texture'

logic2 = {
  'none': 0,
  'thick_scrub': 0x80,
  'driven_sand': 0x40, # don't know
  'beach': 0x20,
  'oasis_grass': 0x10,
  'plateau_high': 0x8,
  'plateau_medium': 0x4,
  'moat_undug': 0x3,
  'earth_and_stones': 0x2,
  'scrub': 0x1,
    # NONE=0,
    # SCRUB=1,
    # DIRT=2,
    # MOAT_UNDUG=3,
    # PLATEAU_MEDIUM=4,
    # PLATEAU_HIGH=8,
    # GRASS=16,
    # BEACH=32,
    # STONES_OR_DRIVEN_SAND?=64,
    # THICK_SCRUB=128
}

logic2_vk = {v: k for k, v in logic2.items()}

    # NONE=0,
    # SEA=1,
    # STOCKPILE?=2,
    # PLAIN1=4,
    # PLAIN2=8 /* also for pitch ditch */,
    # WALK_BORDER_RELATED1=16,
    # WALK_BORDER_RELATED2=32,
    # ROCKY=128,
    # WALL_OR_GATEHOUSE=256,
    # CRENEL=512,
    # BUILDING=1024,
    # STAIRS=2048,
    # TREE=4096,
    # TREE_VARIATION=8192,
    # MOAT_DUG_OR_PLANNED=16384,
    # MAX_HEIGHT_RELATED=32768,
    # UNKNOWN_WALL_RELATED=65536,
    # BOULDERS=131072,
    # PEBBLES=262144,
    # IRON=524288,
    # RIVER_FOAM_RIPPLE=1048576,
    # FORD=2097152,
    # CRENEL_VARIATION?=4194304,
    # FARM_WHEAT=16777216,
    # FARM_HOP=33554432,
    # FARM_APPLE=67108864,
    # FARM_DAIRY=134217728,
    # KEEP_NON_MANOR_HOUSE=268435456,
    # MARSH=536870912,
    # MOAT=1073741824,
    # OIL=2147483648

    # NONE=0,
    # SCRUB=1,
    # DIRT=2,
    # MOAT_UNDUG=3,
    # PLATEAU_MEDIUM=4,
    # PLATEAU_HIGH=8,
    # GRASS=16,
    # BEACH=32,
    # STONES_OR_DRIVEN_SAND?=64,
    # THICK_SCRUB=128

