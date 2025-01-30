import sys
try:
  import sourcehold
except:
  import os, pathlib
  sys.path.insert(0, str(pathlib.Path(".").parent))

import sourcehold.aivs
from sourcehold.aivs.AIV import AIV

# from matplotlib import pyplot

import struct

import numpy as np

import json
# 2001, 2002, 2003, 2004, 2005, 2013, 2006, 2009
# 2007, 2008, 2010, 2011, 2012, 2014
INDEX_CONSTRUCTIONS = 2007
INDEX_STEPS = 2008
INDEX_STEP_COUNT = 2009
INDEX_VERSION = 2010
INDEX_PAUSES = 2011
INDEX_MISC = 2012
INDEX_PAUSE = 2014


def xrange():
  return range(100)

def yrange(invert_y=False):
  if invert_y:
    return range(100-1, -1, -1)
  else:
    return range(100)

def to_json(aiv=None, path: str='', include_extra=False, invert_y=True):
  if aiv == None and not path:
    raise Exception()
  if aiv == None:
    aiv = AIV().from_file(path)

  print(f"INFO: aiv has version: {aiv.directory.version_number}")

  select_all = np.ones((100,100), 'bool')

  constructions = np.zeros((100, 100), dtype='uint16')
  constructions[select_all] = struct.unpack(f"<{100*100}H", aiv.directory[INDEX_CONSTRUCTIONS].get_data())


  steps = np.zeros((100, 100), dtype='uint32')
  steps[select_all] = struct.unpack(f"<{100*100}I", aiv.directory[INDEX_STEPS].get_data())

# This value can lie!
  step_count = struct.unpack("<I", aiv.directory[INDEX_STEP_COUNT].get_data())[0]
  step_count_max = steps.max().item()
  if step_count < step_count_max:
    print(f"WARNING: step count ({step_count}) is lower than max step value from steps matrix ({step_count_max}), taking max step value as truth")
    step_count = step_count_max

  pauses_raw = aiv.directory[INDEX_PAUSES].get_data()
  if len(pauses_raw) != 50 * 4:
    print(f"WARNING: pauses is not expected size of {50*4} but {len(pauses_raw)}, adjusting")
    pauses = list(struct.unpack(f"<10i", pauses_raw))  
  else:
    pauses = list(struct.unpack("<50i", pauses_raw))  

  units = np.reshape(list(struct.unpack(f"<{24*10}i", aiv.directory[INDEX_MISC].get_data())), (24, 10))

  pauseDelayAmount = struct.unpack("<1i", aiv.directory[INDEX_PAUSE].get_data())[0]

  output = {}
  frames = [None] * step_count # + 1 is already stored in the aiv format
  miscItems = []

  output["frames"] = frames
  output["miscItems"] = miscItems
  output["pauseDelayAmount"] = pauseDelayAmount

  processed = {}

  buildings = 0
  offset = -1
  for i in xrange():
    for j in yrange(invert_y=invert_y):
      offset += 1
      
      if offset in processed:
        continue

      construction = constructions[i, j].item()
      step = steps[i, j].item()

      if construction == 0:
        processed[offset] = True
        continue

      # Not in source code, but added here
      elif construction == 1:
        processed[offset] = True
        continue
      
      elif construction == 2:
        processed[offset] = True
        continue
      
      elif construction == 38: #keep2
        processed[offset] = True
        continue
      
      buildingType = convertAIVEnumToMapperEnum(v = construction)
      
      if buildingType in [25, 46, 26, 35, 106, 99]: # [10, 11, 12, 13, 20, 21, 22, 23, 24]:
        continue # not processed yet
      
      processed[offset] = True
      
      if step > len(frames):
        raise Exception(f"step size too high at ({i}, {j}, {offset}): {step} => {len(frames)}")
      if frames[step] is None:
        buildings += 1
        shouldPause = step in pauses
        frames[step] = {'itemType': buildingType, 'tilePositionOfsets': [offset], 'shouldPause': shouldPause}

  print(f"INFO: buildings: {buildings}")

  nonbuildings = 0

  offset = -1
  for i in xrange():
    for j in yrange(invert_y=invert_y):
      offset += 1
      if offset not in processed:
        # do all the special stuff
        construction = constructions[i, j].item()
        step = steps[i, j].item()
        buildingType = convertAIVEnumToMapperEnum(v = construction)
        shouldPause = step in pauses
        if frames[step] is None:
          frames[step] = {'itemType': buildingType, 'tilePositionOfsets': [], 'shouldPause': shouldPause}
        frames[step]['tilePositionOfsets'].append(offset)
        nonbuildings += 1

  print(f"INFO: walls | pitch | moat: {nonbuildings}")

  misc = 0
  for unitType in range(24):
    for entry in range(10):
      location = units[unitType, entry].item()
      if location == 0:
        continue
      misc += 1
      miscItems.append({'itemType': unitType, 'positionOfset': location, 'number': entry})
  print(f"INFO: units | flags | brazier | misc: {misc}")

  emptyFrames = [index for index, frame in enumerate(output['frames']) if not frame]
  knownEmptyFrames = [0,1]
  unexpectedEmptyFrames = list(index for index in emptyFrames if index not in knownEmptyFrames)
  if len(unexpectedEmptyFrames) > 0:
    print(f"WARNING: unexpected count of empty frames, expected one (the first), but there were: {len(unexpectedEmptyFrames)} more: {','.join(str(v) for v in unexpectedEmptyFrames)}")
  output['frames'] = [frame for frame in output['frames'] if frame]

  if include_extra:
    output['extra'] = {
      'version' : aiv.directory.version_number,
      'directory_size' : aiv.directory.directory_size,
      'size' : aiv.directory.size,
      'u1' : aiv.directory.directory_u1,
      'u7' : aiv.directory.directory_u7,
      'sections': [i for i in aiv.directory.section_indices if i],
      # 'rng': aiv.directory[2003].get_data() # RNG
      '2001': int.from_bytes(aiv.directory[2001].get_data(), 'little'),
      '2002': int.from_bytes(aiv.directory[2001].get_data(), 'little'),
      'recent_selected_step_in_editor': int.from_bytes(aiv.directory[2010].get_data(), 'little'), # Last selected step in editor?
      'step_count': step_count,
      # 'typeData': np.frombuffer(aiv.directory[2004].get_data(), dtype = 'uint8').reshape((100,100)),
      # '2005': # wall edges or something?
      # '2006' : texture noise
      # '2013' : misc and unit locations in tilemap form?
    }


  return json.dumps(output, indent=2)


BUILDING_TYPE_AIV_FILES_KV = {
  "HIGH_WALL" : 10,
  "LOW_WALL" : 11,
  "HIGH_CRENAL" : 12,
  "LOW_CRENAL" : 13,
  "STAIRS_1" : 14,
  "STAIRS_2" : 15,
  "STAIRS_3" : 16,
  "STAIRS_4" : 17,
  "STAIRS_5" : 18,
  "STAIRS_6" : 19,
  "MOAT_a" : 20,
  "MOAT_b" : 21,
  "MOAT_c" : 22,
  "MOAT_d" : 23,
  "PITCHDITCH_2" : 24,
  "UNUSED_5" : 25,
  "TOWER1" : 30,
  "TOWER2" : 31,
  "TOWER3" : 32,
  "TOWER4" : 33,
  "TOWER5" : 34,
  "OIL_SMELTER" : 35,
  "DOG_CAGE" : 36,
  "KILLING_PIT" : 37,
  "KEEP2" : 38,
  "MERCENARY_POST" : 39,
  "GATEHOUSE_SMALL_A" : 40,
  "GATEHOUSE_SMALL_B" : 41,
  "GATEHOUSE_LARGE_A" : 42,
  "GATEHOUSE_LARGE_B" : 43,
  "DRAWBRIDGE" : 44,
  "POLETURNER" : 50,
  "FLETCHER" : 51,
  "BLACKSMITH" : 52,
  "TANNER" : 53,
  "ARMOURER" : 54,
  "BARRACKS" : 55,
  "ARMOURY" : 56,
  "ENGINEERS_GUILD" : 57,
  "TUNNELERS_GUILD" : 58,
  "STABLES" : 59,
  "STOCKPILE" : 60,
  "WOODCUTTERSHUT" : 61,
  "QUARRY" : 62,
  "OXTETHER" : 63,
  "IRONMINE" : 64,
  "PITCHRIG" : 65,
  "MARKETPLACE" : 66,
  "GRANARY" : 70,
  "APPLEFARM" : 71,
  "CATTLEFARM" : 72,
  "WHEATFARM" : 73,
  "HUNTER" : 74,
  "HOPSFARM" : 75,
  "MILL" : 76,
  "BAKER" : 77,
  "BREWER" : 78,
  "INN" : 79,
  "HOVEL" : 80,
  "CHAPEL" : 81,
  "CHURCH" : 82,
  "CATHEDRAL" : 83,
  "HEALER" : 84,
  "WELL" : 85,
  "WATERPOT" : 86,
  "MAYPOLE" : 90,
  "DANCING_BEAR" : 91,
  "STATUE1" : 92,
  "SHRINE1" : 93,
  "TOWN_GARDEN10" : 94,
  "GARDEN07" : 95,
  "POND_1" : 96,
  "LARGE_POND_3" : 97,
  "GALLOWS" : 100,
  "CESSPIT" : 101,
  "STOCKS" : 102,
  "BURNING_STAKE" : 103,
  "DUNGEON" : 104,
  "STRETCHING_RACK" : 105,
  "GIBBET" : 106,
  "CHOPPING_BLOCK" : 107,
  "DUNKINGSTOOL" : 108,
}

BUILDING_TYPE_AIV_FILES_VK = dict((value, key) for key, value in BUILDING_TYPE_AIV_FILES_KV.items())

MAPPERS_SH1_KV = {
  "MAPPER_NULL" : 0x0,
  "MAPPER_AREA" : 0x1,
  "MAPPER_RAISE" : 0x2,
  "MAPPER_LOWER" : 0x3,
  "MAPPER_SEA" : 0x4,
  "MAPPER_LAND" : 0x5,
  "MAPPER_FOREST" : 0x6,
  "MAPPER_SCRUB" : 0x7,
  "MAPPER_BEACH" : 0x8,
  "MAPPER_SHALLOWS" : 0x9,
  "MAPPER_ROCKY" : 0xa,
  "MAPPER_STONES" : 0xb,
  "MAPPER_BOULDERS" : 0xc,
  "MAPPER_PEBBLES" : 0xd,
  "MAPPER_RIVER" : 0xe,
  "MAPPER_FORD" : 0xf,
  "MAPPER_IRON" : 0x10,
  "MAPPER_MARSH" : 0x11,
  "MAPPER_DIRT" : 0x12,
  "MAPPER_GRASS" : 0x13,
  "MAPPER_DOWN" : 0x14,
  "MAPPER_BIGROCKS" : 0x14,
  "MAPPER_MIN" : 0x15,
  "MAPPER_MAX" : 0x16,
  "MAPPER_EQUALISE" : 0x17,
  "MAPPER_PLATEAU" : 0x18,
  "MAPPER_WALL" : 0x19,
  "MAPPER_CRENAL" : 0x1a,
  "MAPPER_STAIR" : 0x1b,
  "MAPPER_TOWER" : 0x1c,
  "MAPPER_UP" : 0x1d,
  "MAPPER_EXIT" : 0x1f,
  "MAPPER_TOMAIN" : 0x20,
  "MAPPER_TOTEST" : 0x21,
  "MAPPER_PATROL" : 0x22,
  "MAPPER_PATH_END" : 0x23,
  "MAPPER_MOUNTAIN" : 0x24,
  "MAPPER_HILL" : 0x25,
  "MAPPER_AFFECT_TYPE" : 0x26,
  "MAPPER_DELETE" : 0x27,
  "MAPPER_CHESTNUT" : 0x28,
  "MAPPER_OAK" : 0x29,
  "MAPPER_PINE" : 0x2a,
  "MAPPER_BIRCH" : 0x2b,
  "MAPPER_UNDUGMOAT" : 0x2c,
  "MAPPER_DUGMOAT" : 0x2d,
  "MAPPER_WOODWALL" : 0x2e,
  "MAPPER_PLAIN1" : 0x2f,
  "MAPPER_PLAIN2" : 0x30,
  "MAPPER_OIL" : 0x31,
  "MAPPER_FLETCHER" : 0x32,
  "MAPPER_WOODSMAN" : 0x33,
  "MAPPER_STORES" : 0x34,
  "MAPPER_HOUSE" : 0x35,
  "MAPPER_HOVEL" : 0x36,
  "MAPPER_OXENBASE" : 0x37,
  "MAPPER_QUARRY" : 0x38,
  "MAPPER_TUNNEL" : 0x39,
  "MAPPER_CAMP_FIRE" : 0x3a,
  "MAPPER_SIGNPOST" : 0x3b,
  "MAPPER_KEEP1" : 0x3c,
  "MAPPER_KEEP2" : 0x3d,
  "MAPPER_KEEP3" : 0x3e,
  "MAPPER_KEEP4" : 0x3f,
  "MAPPER_KEEP5" : 0x40,
  "MAPPER_STABLES" : 0x41,
  "MAPPER_TUNNEL_CONSTRUCTION" : 0x42,
  "MAPPER_UNUSED_1" : 0x43,
  "MAPPER_UNUSED_2" : 0x44,
  "MAPPER_UNUSED_3" : 0x45,
  "MAPPER_WHEATFARM" : 0x46,
  "MAPPER_HOPSFARM" : 0x47,
  "MAPPER_APPLEFARM" : 0x48,
  "MAPPER_CATTLEFARM" : 0x49,
  "MAPPER_MILL" : 0x4a,
  "MAPPER_BAKER" : 0x4b,
  "MAPPER_BREWER" : 0x4c,
  "MAPPER_TRADEPOST" : 0x4d,
  "MAPPER_HUNTER" : 0x4e,
  "MAPPER_UNUSED_4" : 0x4f,
  "MAPPER_GRANARY" : 0x50,
  "MAPPER_ARMOURY" : 0x51,
  "MAPPER_POLETURNER" : 0x52,
  "MAPPER_BLACKSMITH" : 0x53,
  "MAPPER_ARMOURER" : 0x54,
  "MAPPER_TANNER" : 0x55,
  "MAPPER_BARRACKS_WOOD" : 0x56,
  "MAPPER_BARRACKS_STONE" : 0x57,
  "MAPPER_ENGINEERS_GUILD" : 0x58,
  "MAPPER_TUNNELERS_GUILD" : 0x59,
  "MAPPER_IRON_MINE" : 0x5a,
  "MAPPER_PITCH_WORKINGS" : 0x5b,
  "MAPPER_INN" : 0x5c,
  "MAPPER_HEALER" : 0x5d,
  "MAPPER_SIEGE_TOWER_BASE" : 0x5e,
  "MAPPER_CHURCH1" : 0x5f,
  "MAPPER_CHURCH2" : 0x60,
  "MAPPER_CHURCH3" : 0x61,
  "MAPPER_KILLING_PIT" : 0x62,
  "MAPPER_PITCH_DITCH" : 0x63,
  "MAPPER_GATEHOUSE" : 0x64,
  "MAPPER_GATE_MAIN" : 0x65,
  "MAPPER_GATE_INNER" : 0x66,
  "MAPPER_GATE_WOOD" : 0x67,
  "MAPPER_GATE_POSTERN" : 0x68,
  "MAPPER_DRAWBRIDGE" : 0x69,
  "MAPPER_MOAT" : 0x6a,
  "MAPPER_ANTIMOAT" : 0x6b,
  "MAPPER_UNUSED_5" : 0x6c,
  "MAPPER_UNUSED_6" : 0x6d,
  "MAPPER_TOWER1" : 0x6e,
  "MAPPER_TOWER2" : 0x6f,
  "MAPPER_TOWER3" : 0x70,
  "MAPPER_TOWER4" : 0x71,
  "MAPPER_TOWER5" : 0x72,
  "MAPPER_TOWER1_DESTROYED" : 0x73,
  "MAPPER_TOWER2_DESTROYED" : 0x74,
  "MAPPER_TOWER3_DESTROYED" : 0x75,
  "MAPPER_TOWER4_DESTROYED" : 0x76,
  "MAPPER_TOWER5_DESTROYED" : 0x77,
  "MAPPER_FLAG_TYPE0" : 0x78,
  "MAPPER_FLAG_TYPE1" : 0x79,
  "MAPPER_FLAG_TYPE2" : 0x7a,
  "MAPPER_FLAG_TYPE3" : 0x7b,
  "MAPPER_FLAG_TYPE4" : 0x7c,
  "MAPPER_FLAG_TYPE5" : 0x7d,
  "MAPPER_FLAG_TYPE6" : 0x7e,
  "MAPPER_FLAG_TYPE7" : 0x7f,
  "MAPPER_FLAG_TYPE8" : 0x80,
  "MAPPER_HEADS" : 0x81,
  "MAPPER_SHRUB1A" : 0x82,
  "MAPPER_SHRUB1B" : 0x83,
  "MAPPER_SHRUB1C" : 0x84,
  "MAPPER_SHRUB1D" : 0x85,
  "MAPPER_SHRUB1E" : 0x86,
  "MAPPER_SHRUB2A" : 0x87,
  "MAPPER_SHRUB2B" : 0x88,
  "MAPPER_SHRUB2C" : 0x89,
  "MAPPER_SHRUB2D" : 0x8a,
  "MAPPER_SHRUB2E" : 0x8b,
  "MAPPER_GATE_WOOD1A" : 0x8c,
  "MAPPER_GATE_WOOD1B" : 0x8d,
  "MAPPER_GATE_WOOD1C" : 0x8e,
  "MAPPER_GATE_WOOD1D" : 0x8f,
  "MAPPER_GATE_STONE1A" : 0x90,
  "MAPPER_GATE_STONE1B" : 0x91,
  "MAPPER_GATE_STONE2A" : 0x92,
  "MAPPER_GATE_STONE2B" : 0x93,
  "MAPPER_BRAZIER" : 0x94,
  "MAPPER_UNUSED_7" : 0x95,
  "MAPPER_FOAM" : 0x96,
  "MAPPER_RIPPLE" : 0x97,
  "MAPPER_TO_MAP_EDIT" : 0x98,
  "MAPPER_UNUSED_8" : 0x99,
  "MAPPER_UNUSED_9" : 0x9a,
  "MAPPER_UNUSED_10" : 0x9b,
  "MAPPER_UNUSED_11" : 0x9c,
  "MAPPER_UNUSED_12" : 0x9d,
  "MAPPER_UNUSED_13" : 0x9e,
  "MAPPER_UNUSED_14" : 0x9f,
  "MAPPER_GARDEN1" : 0xa0,
  "MAPPER_GARDEN2" : 0xa1,
  "MAPPER_GARDEN3" : 0xa2,
  "MAPPER_GARDEN4" : 0xa3,
  "MAPPER_GARDEN5" : 0xa4,
  "MAPPER_GARDEN6" : 0xa5,
  "MAPPER_GARDEN7" : 0xa6,
  "MAPPER_GARDEN8" : 0xa7,
  "MAPPER_GARDEN9" : 0xa8,
  "MAPPER_GARDEN10" : 0xa9,
  "MAPPER_GARDEN11" : 0xaa,
  "MAPPER_GARDEN12" : 0xab,
  "MAPPER_UNUSED_15" : 0xac,
  "MAPPER_UNUSED_16" : 0xad,
  "MAPPER_UNUSED_17" : 0xae,
  "MAPPER_MAYPOLE" : 0xaf,
  "MAPPER_GALLOWS" : 0xb0,
  "MAPPER_STOCKS" : 0xb1,
  "MAPPER_UNUSED_18" : 0xb2,
  "MAPPER_UNUSED_19" : 0xb3,
  "MAPPER_OIL_SMELTER" : 0xb4,
  "MAPPER_UNUSED_20" : 0xb5,
  "MAPPER_UNUSED_21" : 0xb6,
  "MAPPER_UNUSED_22" : 0xb7,
  "MAPPER_UNUSED_23" : 0xb8,
  "MAPPER_UNUSED_24" : 0xb9,
  "MAPPER_UNUSED_25" : 0xba,
  "MAPPER_UNUSED_26" : 0xbb,
  "MAPPER_UNUSED_27" : 0xbc,
  "MAPPER_UNUSED_28" : 0xbd,
  "MAPPER_CATAPULT" : 0xbe,
  "MAPPER_TREBUCHET" : 0xbf,
  "MAPPER_SIEGE_TOWER" : 0xc0,
  "MAPPER_BATTERING_RAM" : 0xc1,
  "MAPPER_PORTABLE_SHIELD" : 0xc2,
  "MAPPER_UNUSED_29" : 0xc3,
  "MAPPER_UNUSED_30" : 0xc4,
  "MAPPER_UNUSED_31" : 0xc5,
  "MAPPER_UNUSED_32" : 0xc6,
  "MAPPER_UNUSED_33" : 0xc7,
  "MAPPER_BACK" : 0xc8,
  "MAPPER_CHECK_BOX" : 0xc9,
  "MAPPER_TEST" : 0xca,
  "MAPPER_REBUILD" : 0xcb,
  "MAPPER_SNAP_TO" : 0xcc,
  "MAPPER_BIGROCK1" : 0xcd,
  "MAPPER_BIGROCK2" : 0xce,
  "MAPPER_BIGROCK3" : 0xcf,
  "MAPPER_BIGROCK4" : 0xd0,
  "MAPPER_BIGROCK5" : 0xd1,
  "MAPPER_MANGONEL" : 0xd2,
  "MAPPER_BALLISTA" : 0xd3,
  "MAPPER_UNUSED_34" : 0xd4,
  "MAPPER_UNUSED_35" : 0xd5,
  "MAPPER_UNUSED_36" : 0xd6,
  "MAPPER_UNUSED_37" : 0xd7,
  "MAPPER_UNUSED_38" : 0xd8,
  "MAPPER_UNUSED_39" : 0xd9,
  "MAPPER_UNUSED_40" : 0xda,
  "MAPPER_UNUSED_41" : 0xdb,
  "MAPPER_DEER" : 0xdc,
  "MAPPER_WOLF" : 0xdd,
  "MAPPER_RABBIT" : 0xde,
  "MAPPER_BEAR" : 0xdf,
  "MAPPER_CROW" : 0xe0,
  "MAPPER_SEAGULL" : 0xe1,
  "MAPPER_UNUSED_42" : 0xe2,
  "MAPPER_UNUSED_44" : 0xe3,
  "MAPPER_UNUSED_45" : 0xe4,
  "MAPPER_UNUSED_46" : 0xe5,
  "MAPPER_MAP_SIZE" : 0xe6,
  "MAPPER_SUB_MODE_HEIGHT" : 0xe7,
  "MAPPER_SUB_MODE_TYPE" : 0xe8,
  "MAPPER_SUB_MODE_OBJ" : 0xea,
  "MAPPER_SUB_MODE_ANIMAL" : 0xeb,
  "MAPPER_SUB_MODE_WATER" : 0xec,
  "MAPPER_SUB_MODE_FEATURE" : 0xed,
  "MAPPER_ESTUARY" : 0xee,
  "MAPPER_SUB_MODE_FEATURE_MP" : 0xef,
  "MAPPER_REPORT1" : 0xf0,
  "MAPPER_MP_KEEP1" : 0xf0,
  "MAPPER_REPORT2" : 0xf1,
  "MAPPER_MP_KEEP2" : 0xf1,
  "MAPPER_MP_KEEP3" : 0xf2,
  "MAPPER_REPORT3" : 0xf2,
  "MAPPER_MP_KEEP4" : 0xf3,
  "MAPPER_REPORT4" : 0xf3,
  "MAPPER_MP_KEEP5" : 0xf4,
  "MAPPER_REPORT5" : 0xf4,
  "MAPPER_MP_KEEP6" : 0xf5,
  "MAPPER_REPORT6" : 0xf5,
  "MAPPER_REPORT7" : 0xf6,
  "MAPPER_MP_KEEP7" : 0xf6,
  "MAPPER_REPORT8" : 0xf7,
  "MAPPER_MP_KEEP8" : 0xf7,
  "MAPPER_RUINS1" : 0xf8,
  "MAPPER_RUINS2" : 0xf9,
  "MAPPER_RUINS3" : 0xfa,
  "MAPPER_RUINS4" : 0xfb,
  "MAPPER_RUINS5" : 0xfc,
  "MAPPER_RUINS6" : 0xfd,
  "MAPPER_RUINS7" : 0xfe,
  "MAPPER_RUINS8" : 0xff,
  "MAPPER_RUINS9" : 0x100,
  "MAPPER_RUINS10" : 0x101,
  "MAPPER_RUINS11" : 0x102,
  "MAPPER_RUINS12" : 0x103,
  "MAPPER_RUINS13" : 0x104,
  "MAPPER_UNUSED_48" : 0x105,
  "MAPPER_UNUSED_49" : 0x106,
  "MAPPER_UNUSED_50" : 0x107,
  "MAPPER_UNUSED_51" : 0x108,
  "MAPPER_UNUSED_52" : 0x109,
  "MAPPER_UNUSED_53" : 0x10a,
  "MAPPER_UNUSED_54" : 0x10b,
  "MAPPER_UNUSED_55" : 0x10c,
  "MAPPER_UNUSED_56" : 0x10d,
  "MAPPER_PEOPLE_ARCHERS" : 0x10e,
  "MAPPER_PEOPLE_SPEARMEN" : 0x10f,
  "MAPPER_PEOPLE_PIKEMEN" : 0x110,
  "MAPPER_PEOPLE_MACEMEN" : 0x111,
  "MAPPER_PEOPLE_XBOWMEN" : 0x112,
  "MAPPER_PEOPLE_SWORDSMEN" : 0x113,
  "MAPPER_PEOPLE_KNIGHTS" : 0x114,
  "MAPPER_PEOPLE_LADDERMEN" : 0x115,
  "MAPPER_PEOPLE_ENGINEERS" : 0x116,
  "MAPPER_PEOPLE_ENGINEERS_POTS" : 0x117,
  "MAPPER_PEOPLE_MONKS" : 0x118,
  "MAPPER_PEOPLE_CATAPULTS" : 0x119,
  "MAPPER_PEOPLE_TREBUCHETS" : 0x11a,
  "MAPPER_PEOPLE_BATTERING_RAMS" : 0x11b,
  "MAPPER_PEOPLE_SIEGE_TOWERS" : 0x11c,
  "MAPPER_PEOPLE_PORTABLE_SHIELDS" : 0x11d,
  "MAPPER_PEOPLE_TUNNELERS" : 0x11e,
  "MAPPER_STANCE_STAND" : 0x11f,
  "MAPPER_STANCE_DEFENSIVE" : 0x120,
  "MAPPER_STANCE_AGGRESSIVE" : 0x121,
  "MAPPER_TROOP_STOP" : 0x122,
  "MAPPER_ENGINEER_BUILD" : 0x123,
  "MAPPER_BUILD_BACK" : 0x124,
  "MAPPER_BUY_AMMO" : 0x125,
  "MAPPER_UNUSED_57" : 0x126,
  "MAPPER_UNUSED_58" : 0x127,
  "MAPPER_UNUSED_59" : 0x128,
  "MAPPER_UNUSED_60" : 0x129,
  "MAPPER_UNUSED_61" : 0x12a,
  "MAPPER_UNUSED_62" : 0x12b,
  "MAPPER_UNUSED_63" : 0x12c,
  "MAPPER_CESS_PIT1" : 0x12d,
  "MAPPER_CESS_PIT2" : 0x12e,
  "MAPPER_CESS_PIT3" : 0x12f,
  "MAPPER_CESS_PIT4" : 0x130,
  "MAPPER_BURNING_STAKE" : 0x131,
  "MAPPER_GIBBET" : 0x132,
  "MAPPER_DUNGEON" : 0x133,
  "MAPPER_RACK_STRETCHING" : 0x134,
  "MAPPER_RACK_FLOGGING" : 0x135,
  "MAPPER_CHOPPING_BLOCK" : 0x136,
  "MAPPER_DUNKING_STOOL" : 0x137,
  "MAPPER_DOG_CAGE" : 0x138,
  "MAPPER_STATUE1" : 0x139,
  "MAPPER_STATUE2" : 0x13a,
  "MAPPER_STATUE3" : 0x13b,
  "MAPPER_STATUE4" : 0x13c,
  "MAPPER_STATUE5" : 0x13d,
  "MAPPER_SHRINE1" : 0x13e,
  "MAPPER_SHRINE2" : 0x13f,
  "MAPPER_SHRINE3" : 0x140,
  "MAPPER_SHRINE4" : 0x141,
  "MAPPER_SHRINE5" : 0x142,
  "MAPPER_BEE_HIVE" : 0x143,
  "MAPPER_DANCING_BEAR" : 0x144,
  "MAPPER_POND1" : 0x145,
  "MAPPER_POND2" : 0x146,
  "MAPPER_POND3" : 0x147,
  "MAPPER_POND4" : 0x148,
  "MAPPER_BEAR_CAVE" : 0x149,
  "MAPPER_WELL" : 0x14a,
  "MAPPER_AREA_BACK" : 0x14b,
  "MAPPER_PLACE_ASSEMBLY_POINT1" : 0x14c,
  "MAPPER_PLACE_ASSEMBLY_POINT2" : 0x14d,
  "MAPPER_PLACE_ASSEMBLY_POINT3" : 0x14e,
  "MAPPER_PLACE_ASSEMBLY_POINT4" : 0x14f,
  "MAPPER_PLACE_ASSEMBLY_POINT5" : 0x150,
  "MAPPER_PLACE_ASSEMBLY_POINT6" : 0x151,
  "MAPPER_PLACE_ASSEMBLY_POINT7" : 0x152,
  "MAPPER_SUB_MENU_TOWERS" : 0x154,
  "MAPPER_SUB_MENU_MILITARY" : 0x155,
  "MAPPER_SUB_MENU_GATEHOUSES" : 0x156,
  "MAPPER_SUB_MENU_KEEPS" : 0x157,
  "MAPPER_SUB_MENU_GATEHOUSES_WOOD" : 0x158,
  "MAPPER_SUB_MENU_GATEHOUSES_STONESMALL" : 0x159,
  "MAPPER_SUB_MENU_GATEHOUSES_STONELARGE" : 0x15a,
  "MAPPER_SUB_MENU_GOOD" : 0x15b,
  "MAPPER_SUB_MENU_BAD" : 0x15c,
  "MAPPER_DELETE_EDITOR" : 0x15d,
  "MAPPER_MARKER_POINT1" : 0x15e,
  "MAPPER_MARKER_POINT2" : 0x15f,
  "MAPPER_MARKER_POINT3" : 0x160,
  "MAPPER_MARKER_POINT4" : 0x161,
  "MAPPER_MARKER_POINT5" : 0x162,
  "MAPPER_MARKER_POINT6" : 0x163,
  "MAPPER_MARKER_POINT7" : 0x164,
  "MAPPER_MARKER_POINT8" : 0x165,
  "MAPPER_MARKER_POINT9" : 0x166,
  "MAPPER_MARKER_POINT10" : 0x167,
  "MAPPER_MENU_RETURN_TOWERS" : 0x168,
  "MAPPER_MENU_RETURN_GATEHOUSES" : 0x169,
  "MAPPER_MENU_RETURN_MILITARY" : 0x16a,
  "MAPPER_MENU_RETURN_KEEPS" : 0x16b,
  "MAPPER_MENU_RETURN_GOOD" : 0x16c,
  "MAPPER_MENU_RETURN_BAD" : 0x16d,
  "MAPPER_PLACE_ASSEMBLY_POINTE1" : 0x16f,
  "MAPPER_PLACE_ASSEMBLY_POINTE2" : 0x170,
  "MAPPER_PLACE_ASSEMBLY_POINTT1" : 0x171,
}

MAPPERS_SH1_VK = dict((value, key) for key, value in MAPPERS_SH1_KV.items())

CONVERSION = [110, 111, 112, 113, 114, 180, 312, 98, 61, 86, 144, 145, 146, 147, 105, 0, 0, 0, 0, 0, 82, 50, 83, 85, 84, 87, 81, 88, 89, 65, 52, 51, 56, 55, 90, 91, 77, 0, 0, 0, 80, 72, 73, 70, 78, 71, 74, 75, 76, 92, 54, 95, 96, 97, 93, 330, 342, 0, 0, 0, 175, 324, 313, 318, 169, 166, 325, 327, 0, 0, 176, 301, 177, 305, 307, 308, 306, 310, 311]
def convertAIVEnumToMapperEnum(k=None, v=None):
  if k is None:
    if v is None:
      raise Exception()
    k = BUILDING_TYPE_AIV_FILES_VK[v]
  else:
    v = BUILDING_TYPE_AIV_FILES_KV[k]

  if k == "HIGH_WALL":
    return MAPPERS_SH1_KV["MAPPER_WALL"]
  if k == "LOW_WALL":
    return MAPPERS_SH1_KV["MAPPER_WOODWALL"]
  if k == "HIGH_CRENAL":
    return MAPPERS_SH1_KV["MAPPER_CRENAL"]
  if k == "LOW_CRENAL":
    return MAPPERS_SH1_KV["MAPPER_PATH_END"]
  if k == "STAIRS_1":
    return MAPPERS_SH1_KV["MAPPER_UNUSED_20"]
  if k == "STAIRS_2":
    return MAPPERS_SH1_KV["MAPPER_UNUSED_21"]
  if k == "STAIRS_3":
    return MAPPERS_SH1_KV["MAPPER_UNUSED_22"]
  if k == "STAIRS_4":
    return MAPPERS_SH1_KV["MAPPER_UNUSED_23"]
  if k == "STAIRS_5":
    return MAPPERS_SH1_KV["MAPPER_UNUSED_24"]
  if k == "STAIRS_6":
    return MAPPERS_SH1_KV["MAPPER_UNUSED_25"]
  if k == "MOAT_a":
    return MAPPERS_SH1_KV["MAPPER_MOAT"]
  if k == "MOAT_b":
    return MAPPERS_SH1_KV["MAPPER_MOAT"]
  if k == "MOAT_c":
    return MAPPERS_SH1_KV["MAPPER_MOAT"]
  if k == "MOAT_d":
    return MAPPERS_SH1_KV["MAPPER_MOAT"]
  if k == "PITCHDITCH_2":
    return MAPPERS_SH1_KV["MAPPER_PITCH_DITCH"]
  
  if v - 30 > 0x4F:
    return 108
  
  return CONVERSION[v - (120 // 4)]
