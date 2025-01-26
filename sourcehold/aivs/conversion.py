import sys
try:
  import sourcehold
except:
  import os, pathlib
  sys.path.insert(0, str(pathlib.Path(".").parent))

import sourcehold.aivs
from sourcehold.aivs import AIV

# from matplotlib import pyplot

import struct

import numpy as np

import json


def to_json(aiv=None, path: str=''):
  if aiv == None and not path:
    raise Exception()
  if aiv == None:
    aiv = AIV().from_file(path)

  select_all = np.ones((100,100), 'bool')

  constructions = np.zeros((100, 100), dtype='uint16')
  constructions[select_all] = struct.unpack(f"<{100*100}H", aiv.directory[2007].get_data())


  steps = np.zeros((100, 100), dtype='uint32')
  steps[select_all] = struct.unpack(f"<{100*100}I", aiv.directory[2008].get_data())

# This value can lie!
  step_count = struct.unpack("<I", aiv.directory[2010].get_data())[0]
  step_count_max = steps.max().item()
  if step_count < step_count_max:
    print(f"WARNING: step count ({step_count}) is lower than max step value from steps matrix ({step_count_max}), taking max step value as truth")
    step_count = step_count_max

  pauses = list(struct.unpack("<50i", aiv.directory[2011].get_data()))

  units = np.reshape(list(struct.unpack(f"<{24*10}i", aiv.directory[2012].get_data())), (24, 10))

  pauseDelayAmount = struct.unpack("<1i", aiv.directory[2014].get_data())[0]

  output = {}
  frames = [None] * (step_count+1)
  miscItems = []

  output["frames"] = frames
  output["miscItems"] = miscItems
  output["pauseDelayAmount"] = pauseDelayAmount

  processed = {}

  offset = -1
  for i in range(100):
    for j in range(100):
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
      
      buildingType = construction # Needs conversion from something to a Mapper or not yet?
      
      if buildingType in [25, 46, 26, 35, 106, 99]:
        continue # not processed yet
      
      processed[offset] = True
      
      if step > len(frames):
        raise Exception(f"step size too high at ({i}, {j}, {offset}): {step} => {len(frames)}")
      if frames[step] is None:
        shouldPause = step in pauses
        frames[step] = {'itemType': buildingType, 'tilePositionOfsets': [offset], 'shouldPause': shouldPause}

  offset = -1
  for i in range(100):
    for j in range(100):
      offset += 1
      if offset not in processed:
        # do all the special stuff
        construction = constructions[i, j].item()
        step = steps[i, j].item()
        buildingType = construction
        shouldPause = step in pauses
        if frames[step] is None:
          frames[step] = {'itemType': buildingType, 'tilePositionOfsets': [], 'shouldPause': shouldPause}
        frames[step]['tilePositionOfsets'].append(offset)

  for unitType in range(24):
    for entry in range(10):
      location = units[unitType, entry].item()
      if location == 0:
        continue
      miscItems.append({'itemType': unitType, 'positionOfset': location, 'number': entry})

  emptyFrames = [index for index, frame in enumerate(output['frames']) if not frame]
  knownEmptyFrames = [0,1]
  unexpectedEmptyFrames = list(index for index in emptyFrames if index not in knownEmptyFrames)
  if len(unexpectedEmptyFrames) > 0:
    print(f"WARNING: unexpected count of empty frames, expected one (the first), but there were: {len(unexpectedEmptyFrames)} more: {','.join(str(v) for v in unexpectedEmptyFrames)}")
  output['frames'] = [frame for frame in output['frames'] if frame]

  return json.dumps(output, indent=2)