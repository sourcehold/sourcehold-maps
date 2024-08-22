# python -m pip install Pillow
import struct, numpy
from sourcehold.world import create_selection_matrix
import cv2 as cv
import tkinter.filedialog

img_path = tkinter.filedialog.askopenfilename()

img = cv.imread(img_path)
img = 255 - cv.cvtColor(img, cv.COLOR_BGR2GRAY)

selection = create_selection_matrix()

from sourcehold.debugtools.memory.access import SHC

process = SHC()

# (Little endian) unsigned bytes
def get_raw_logical():
  return struct.unpack("<80400I", process.read_section('1003'))

def set_raw_logical(data):
  serialized = struct.pack("<80400I", *data)
  # Logical terrain height layer
  process.write_section('1003', serialized)

matrix = numpy.zeros((400, 400), dtype='uint32')
matrix[selection] = get_raw_logical()

matrix[img > 255//128] |= 0x20000 # boulder flag?

set_raw_logical(matrix[selection].flat)