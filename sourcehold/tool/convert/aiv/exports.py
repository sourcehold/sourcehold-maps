import sys

from sourcehold.tool.convert.aiv.info import *
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


def translate_offset(offset, invert_x, invert_y):
  x = offset % AIV_WIDTH
  y = offset // AIV_HEIGHT
  if invert_x:
    x = (AIV_WIDTH - 1) - x
  if invert_y:
    y = (AIV_HEIGHT - 1) - y
  return (y * AIV_HEIGHT) + x


def to_json(aiv=None, path: str='', f=None, include_extra=False, invert_y=False, invert_x=True, skip_keep=False, report=False):
  if not aiv and not path and not f:
    raise Exception()
  if aiv == None:
    if path:
      aiv = AIV().from_file(path)
    else:
      aiv = AIV().from_buffer(f) # type: ignore

  if report:
    print(f"INFO: aiv has version: {aiv.directory.version_number}")

  select_all = np.ones((100,100), 'bool')

  constructions = get_constructions_matrix()
  constructions[select_all] = struct.unpack(CONSTRUCTIONS_STRUCT_FORMAT, aiv.directory[INDEX_CONSTRUCTIONS].get_data())

  steps = get_steps_matrix()
  steps[select_all] = struct.unpack(STEPS_STRUCT_FORMAT, aiv.directory[INDEX_STEPS].get_data())

# This value can lie!
  step_count = struct.unpack(STEP_COUNT_STRUCT_FORMAT, aiv.directory[INDEX_STEP_COUNT].get_data())[0]
  step_count_max = steps.max().item()
  if step_count < step_count_max:
    print(f"WARNING: step count ({step_count}) is lower than max step value from steps matrix ({step_count_max}), taking max step value as truth", file=sys.stderr)
    step_count = step_count_max

  pauses_raw = aiv.directory[INDEX_PAUSES].get_data()
  if len(pauses_raw) != 50 * 4:
    print(f"WARNING: pauses is not expected size of {50*4} but {len(pauses_raw)}, adjusting", file=sys.stderr)
    pauses = list(struct.unpack(PAUSES_STRUCT_FORMAT_10, pauses_raw))  
  else:
    pauses = list(struct.unpack(PAUSES_STRUCT_FORMAT_50, pauses_raw))  

  units = get_units_matrix(list(struct.unpack(f"<{24*10}i", aiv.directory[INDEX_MISC].get_data())))

  pauseDelayAmount = struct.unpack(PAUSE_DELAY_AMOUNT_STRUCT_FORMAT, aiv.directory[INDEX_PAUSE].get_data())[0]

  output = {}
  frames = [None] * step_count # + 1 is already stored in the aiv format
  miscItems = []

  output["pauseDelayAmount"] = pauseDelayAmount
  output["frames"] = frames
  output["miscItems"] = miscItems

  processed = {}

  buildings = 0
  offset = -1
  for i in y_range(invert_y=False):
    for j in x_range(invert_x=False):
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
      
      elif skip_keep and construction == 38: #keep2
        processed[offset] = True
        continue
      
      buildingType = convertAIVEnumToMapperEnum(v = construction)
      
      if buildingType in [25, 46, 26, 35, 106, 99]: # [10, 11, 12, 13, 20, 21, 22, 23, 24]:
        continue # not processed yet
      
      processed[offset] = True
      
      if step >= len(frames):
        raise Exception(f"step size too high at ({i}, {j}, {offset}): {step} => {len(frames)}")
      if frames[step] is None:
        buildings += 1
        shouldPause = step in pauses
        offset_t = translate_offset(offset, invert_x, invert_y)
        frames[step] = {'itemType': buildingType, 'tilePositionOfsets': [offset_t], 'shouldPause': shouldPause}

  if report:
    print(f"INFO: buildings: {buildings}")

  nonbuildings = 0

  offset = -1
  for i in y_range(invert_y=False):
    for j in x_range(invert_x=False):
      offset += 1
      if offset not in processed:
        # do all the special stuff
        construction = constructions[i, j].item()
        step = steps[i, j].item()
        buildingType = convertAIVEnumToMapperEnum(v = construction)
        shouldPause = step in pauses
        if frames[step] is None:
          frames[step] = {'itemType': buildingType, 'tilePositionOfsets': [], 'shouldPause': shouldPause}
        offset_t = translate_offset(offset, invert_x, invert_y)
        frames[step]['tilePositionOfsets'].append(offset_t)
        nonbuildings += 1
  
  if report:
    print(f"INFO: walls | pitch | moat: {nonbuildings}")

  misc = 0
  for unitType in range(24):
    number = 0
    for entry in range(10):
      location = units[unitType, entry].item()
      if location == 0:
        continue
      offset_t = translate_offset(location, invert_x, invert_y)
      misc += 1
      miscItems.append({ 'positionOfset': offset_t, 'itemType': unitType,'number': number})
      number += 1

  if report:
    print(f"INFO: units | flags | brazier | misc: {misc}")

  emptyFrames = [index for index, frame in enumerate(output['frames']) if not frame]
  knownEmptyFrames = [0,1]
  unexpectedEmptyFrames = list(index for index in emptyFrames if index not in knownEmptyFrames)
  if len(unexpectedEmptyFrames) > 0:
    print(f"WARNING: unexpected count of empty frames, expected one (the first), but there were: {len(unexpectedEmptyFrames)} more: {','.join(str(v) for v in unexpectedEmptyFrames)}", file=sys.stderr)
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

