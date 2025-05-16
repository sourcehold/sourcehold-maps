logic1 = {
  'none': 0,
  'ocean': 0x1,
  'plain1': 0x4, # 0x8000
  'plain2': 0x8, # 0x8000
  'swamp': 0x20000000,
  'moat_dug': 0x4000,
  'moat': 0x40000000,
  'pitch': 0x80000000,
  # max_height_related = 0x8000, #TODO: not right
  'stone': 0x20000,
  'gravel': 0x40000, # TODO: what is this even?
  'rocks': 0x80,
  'iron': 0x80000,
  'ford': 0x200000,
  'river': 0x100000,
  'oasis': 0x8000, # special
  'thick_scrub': 0x8000, # special
  'light_scrub': 0x8000, # special
  'earth_and_stones': 0, # '#7c7059',
  'earth': 0, #'#ae9467',
  'dunes': 0x8000 # special '#b79453',
  'beach': 0x8000 # special '#deb977',
}

logic2 = {
  'none': 0,
  'thick_scrub': 0x80,
  'stones_or_driven_sand': 0x40, # don't know
  'beach': 0x20,
  'grass': 0x10,
  'plateau_high': 0x8,
  'plateau_low': 0x4,
  'moat_undug': 0x3,
  'scrub': 0x1,
  ''
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