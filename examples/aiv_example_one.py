import sourcehold.aivs
from sourcehold.aivs import AIV

aiv = AIV().from_file("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Stronghold Crusader Extreme\\aiv\\saladin1.aiv")

from matplotlib import pyplot

import struct

import numpy as np

select_all = np.ones((100,100), 'bool')

# matrix = np.zeros((100, 100), 'byte')
# data = struct.unpack(f"<{100*100}B", aiv.directory[2004].get_data())
# matrix[select_all] = data
# pyplot.imshow(matrix)

constructions = np.zeros((100, 100), dtype='uint16')
constructions[select_all] = struct.unpack(f"<{100*100}H", aiv.directory[2007].get_data())

GateNS = (40, 5) # id, size
GateEW = (41, 5) # id, size

x = np.zeros((100, 100), dtype='uint8')
x[select_all] = [i for i in range(100)] * 100

y = np.zeros((100, 100), dtype='uint8')
y[select_all] = [i for i in range(100)] * 100
y = np.transpose(y)

possibles_x, possibles_y = np.where((constructions == 40) | (constructions == 41))
xs = [possibles_x[i].item() for i in range(0, len(possibles_x), 25)]
ys = [possibles_y[i].item() for i in range(0, len(possibles_x), 25)]

import cv2 as cv

haystack = ((constructions == 40) | (constructions == 41)).astype('uint8')
lens = np.ones((5, 5), dtype='uint8')
needles = cv.filter2D(haystack, -1, lens, borderType=cv.BORDER_CONSTANT)

gates_middle_x, gates_middle_y = np.where(needles == (5*5))

# gate_types
gate_types = constructions[needles == (5*5)]

# Middle of gate counts as walkable I think?
clear_paths = (constructions <= 2)

for middle_x in gates_middle_x:
  for middle_y in gates_middle_y:
    if constructions[middle_x, middle_y] == 41:
      for i in range(-(5//2), (5//2) + 1):
        clear_paths[middle_x, middle_y + i] = True
    elif constructions[middle_x, middle_y] == 40:
      for i in range(-(5//2), (5//2) + 1):
        clear_paths[middle_x + i, middle_y] = True

# Next step:
# Which buildings need path access and don't have it?


