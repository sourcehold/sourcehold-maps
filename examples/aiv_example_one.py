import sourcehold.aivs
from sourcehold.aivs import AIV

aiv = AIV().from_file("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Stronghold Crusader Extreme\\aiv\\rat1.aiv")

import matplotlib
from matplotlib import pyplot

import struct

import numpy as np

matrix = np.zeros((100, 100), 'byte')
data = struct.unpack(f"<{100*100}B", aiv.directory[2004].get_data())
matrix[np.ones((100,100), 'bool')] = data
pyplot.imshow(matrix)