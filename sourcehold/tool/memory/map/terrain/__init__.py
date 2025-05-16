MAP_SIZE = 400
TILE_COUNT = MAP_SIZE * ((MAP_SIZE // 2) + 1 )
# python -m pip install Pillow
import struct, numpy
from sourcehold.tool.memory.map.common import get_process_handle, validate_path
from sourcehold.world import create_selection_matrix
import cv2 as cv # type: ignore


def get_image_data(img_path):
  img = cv.imread(img_path)
  #img = 255 - cv.cvtColor(img, cv.COLOR_BGR2GRAY)
  return img

selection = create_selection_matrix(size=MAP_SIZE)

# (Little endian) unsigned bytes
def get_raw_logical(process):
  return struct.unpack(f"<{TILE_COUNT}I", process.read_section('1003'))

def set_raw_logical(process, data):
  serialized = struct.pack(f"<{TILE_COUNT}I", *data)
  # Logical terrain height layer
  process.write_section('1003', serialized)


# 16 is used for the inaccessible parts of the map, including the outer border of the 800x800 space, and 32 is used for a border just within that

def set_terrain(args):
  #' returns None in case of non applicable
  if args.what != 'terrain':
    return None
  
  if args.action != "set":
     return None  

  img_path = args.input
  validate_path(img_path)
  img = get_image_data(img_path)

  process = get_process_handle(args.game)

  matrix = numpy.zeros((400, 400), dtype='uint32')
  matrix[selection] = get_raw_logical(process)

  # matrix[img > 255//128] |= 0x20000 # boulder flag?

  set_raw_logical(process, matrix[selection].flat)

  return True