import json
import struct
from turtle import position
from typing import Dict
import numpy as np
from sourcehold.aivs.AIV import AIV
from sourcehold.tool.convert.aiv.info import AIV_HEIGHT, AIV_WIDTH, CONSTRUCTIONS_STRUCT_FORMAT, INDEX_CONSTRUCTIONS, INDEX_MISC, INDEX_PAUSE, INDEX_PAUSES, INDEX_STEP_COUNT, INDEX_STEPS, MAPPER_BUILDING_SIZES, MAPPERS_SH1_VK, PAUSES_STRUCT_FORMAT_50, STEPS_STRUCT_FORMAT, UNITS_STRUCT_FORMAT, convertMapperEnumToAIVEnum, get_constructions_matrix, get_steps_matrix, get_units_matrix, x_range, y_range

mapping_xyinversed_offset = np.zeros(shape=(AIV_WIDTH, AIV_HEIGHT), dtype='uint32')
mapping_xy_offset = np.zeros(shape=(AIV_WIDTH, AIV_HEIGHT), dtype='uint32')

offset = -1
for x in x_range():
  for y in y_range(invert_y=False):
    offset += 1
    mapping_xy_offset[x, y] = offset

offset = -1
for x in x_range():
  for y in y_range(invert_y=True):
    offset += 1
    mapping_xyinversed_offset[x, y] = offset

def convert_offset(offset, invert_y=False):
  return (offset // AIV_WIDTH, offset % AIV_HEIGHT if not invert_y else (AIV_HEIGHT - 1) - (offset % AIV_HEIGHT))

def convert_offsets(offsets, invert_y=False):
  for loc in offsets:
    yield convert_offset(loc, invert_y=invert_y)

def from_json(path = None, data: Dict | None = None, invert_y = True, report = False):
  if not path and not data:
    raise Exception()
  
  if path and not data:
    with open(path, 'rb') as f:
      data = json.load(f)
  
  if data == None:
    raise Exception()
  
  pauses = []
  pauseDelayAmount = data['pauseDelayAmount']
  constructions = get_constructions_matrix()
  steps = get_steps_matrix()
  frames = data['frames']
  units = get_units_matrix()
  for stepMin1, frame in enumerate(frames):
    step = stepMin1 + 1
    shouldPause = frame['shouldPause']
    if shouldPause:
      pauses.append(step)
    mapperID = frame['itemType']
    mapperName = MAPPERS_SH1_VK[mapperID]

    if mapperID in [25, 46, 26, 35, 106, 99]:
      # Special type
      aivID = convertMapperEnumToAIVEnum(v = mapperID)
      locations = frame['tilePositionOfsets']
      for x, y in convert_offsets(locations, invert_y=invert_y):
        constructions[x, y] = aivID
        steps[x, y] = step
    else:
      # Buildings  
      aivID = convertMapperEnumToAIVEnum(v = mapperID)
      if not mapperName in MAPPER_BUILDING_SIZES:
        raise Exception(f"unsupported mapper size: {mapperName}")
      size = MAPPER_BUILDING_SIZES[mapperName]
      if len(frame['tilePositionOfsets']) > 1:
        raise Exception(f'too many locations for a building: {frame['tilePositionOfsets']}')
      location = frame['tilePositionOfsets'][0]
      x, y = convert_offset(location, invert_y=invert_y)
      constructions[x:(x+size),y:(y+size)] = aivID
      steps[x:(x+size),y:(y+size)] = step
  for miscItem in data['miscItems']:
    itemType = miscItem['itemType']
    number = miscItem['number']
    positionOffset = miscItem['positionOfset']
    units[itemType, number] = positionOffset

  pauses = sorted(pauses)
  if len(pauses) < 50:
    pauses += [0] * (50 - len(pauses))
  
  select_all = np.ones((100,100), 'bool')
  aiv = AIV().from_file("resources/aiv/empty.aiv")
  aiv.directory[INDEX_CONSTRUCTIONS].set_data(struct.pack(CONSTRUCTIONS_STRUCT_FORMAT, *constructions[select_all]))
  aiv.directory[INDEX_STEPS].set_data(struct.pack(STEPS_STRUCT_FORMAT, *steps[select_all]))
  aiv.directory[INDEX_STEP_COUNT].set_data(struct.pack("<i", len(frames) + 1))
  aiv.directory[INDEX_PAUSES].set_data(struct.pack(PAUSES_STRUCT_FORMAT_50, *pauses))
  aiv.directory[INDEX_PAUSE].set_data(struct.pack("<i", pauseDelayAmount))
  select_all_misc = np.ones((24, 10), 'bool')
  aiv.directory[INDEX_MISC].set_data(struct.pack(UNITS_STRUCT_FORMAT, *units[select_all_misc]))
  return aiv
  

