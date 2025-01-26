import sys
try:
  import sourcehold
except:
  import os, pathlib
  sys.path.insert(0, str(pathlib.Path(".").parent))

import sourcehold.aivs
from sourcehold.aivs import AIV

from matplotlib import pyplot

import struct

import numpy as np

import json


aiv = AIV().from_file("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Stronghold Crusader Extreme\\aiv\\saladin1.aiv")


select_all = np.ones((100,100), 'bool')

constructions = np.zeros((100, 100), dtype='uint16')
constructions[select_all] = struct.unpack(f"<{100*100}H", aiv.directory[2007].get_data())


steps = np.zeros((100, 100), dtype='uint32')
steps[select_all] = struct.unpack(f"<{100*100}I", aiv.directory[2008].get_data())

step_count = struct.unpack("<I", aiv.directory[2010].get_data())[0]

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

print(json.dumps(output, indent=2))