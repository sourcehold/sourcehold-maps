MAP_SIZE = 400
TILE_COUNT = MAP_SIZE * ((MAP_SIZE // 2) + 1 )
# python -m pip install Pillow
import struct, numpy
from sourcehold.tool.memory.map.common import get_process_handle, validate_input_path
from sourcehold.world import create_selection_matrix
import cv2 as cv # type: ignore
from .logics import logic1, logic1_vk, logic2, logic2_vk
from .colors import monsterfish1_bgr, bgr_monsterfish1

def get_image_data(img_path):
  img = cv.imread(img_path)
  #img = 255 - cv.cvtColor(img, cv.COLOR_BGR2GRAY)
  return img

selection = create_selection_matrix(size=MAP_SIZE)

# (Little endian) unsigned bytes
def get_raw_logic1(process):
  return struct.unpack(f"<{TILE_COUNT}I", process.read_section('1003'))

def set_raw_logic1(process, data):
  serialized = struct.pack(f"<{TILE_COUNT}I", *data)
  # Logical terrain height layer
  process.write_section('1003', serialized)

def get_raw_logic2(process):
  return struct.unpack(f"<{TILE_COUNT}B", process.read_section('1037'))

def set_raw_logic2(process, data):
  serialized = struct.pack(f"<{TILE_COUNT}B", *data)
  # Logical terrain height layer
  process.write_section('1037', serialized)


# 16 is used for the inaccessible parts of the map, including the outer border of the 800x800 space, and 32 is used for a border just within that

def set_terrain(args):
  #' returns None in case of non applicable
  if args.what != 'terrain':
    return None
  
  if args.action != "set":
     return None  

  img_path = args.input
  validate_input_path(img_path)
  img = get_image_data(img_path)

  process = get_process_handle(args.game)

  matrix = numpy.zeros((400, 400), dtype='uint32')
  matrix[selection] = get_raw_logic1(process)

  # matrix[img > 255//128] |= 0x20000 # boulder flag?

  set_raw_logic1(process, matrix[selection].flat)

  return True

def get_terrain(args):
  #' returns None in case of non applicable
  if args.what != 'terrain':
    return None
  
  if args.action != "get":
     return None  
  
  img_path = args.output
  
  process = get_process_handle(args.game)

  logic1matrix = numpy.zeros((400, 400), dtype='uint32')
  logic1matrix[selection] = get_raw_logic1(process)

  logic2matrix = numpy.zeros((400, 400), dtype='uint8')
  logic2matrix[selection] = get_raw_logic2(process)

  colorlogic1 = numpy.zeros((400,400,3), dtype='uint8')
  colorlogic2 = numpy.zeros((400,400,3), dtype='uint8')

  for flag, name in logic1_vk.items():
    color = (0, 0, 0)
    if name in monsterfish1_bgr:
      color = monsterfish1_bgr[name]
    else:
      print(f"skipping color for: {name}")
    colorlogic1[logic1matrix & flag != 0] = color
    print(f"set '{name}' {colorlogic1[logic1matrix & flag != 0].sum()} times to color: {bgr_monsterfish1[color]}")
  
  for flag, name in logic2_vk.items():
    if name == 'none':
      continue
    color = (0, 0, 0)
    where = logic1matrix == logic1['default_earth_or_texture']
    if name in monsterfish1_bgr:
      color = monsterfish1_bgr[name]
    else:
      print(f"skipping color for: {name}")
    colorlogic1[where & (logic2matrix == flag)] = color
    print(f"set '{name}' {colorlogic1[logic2matrix == flag].sum()} times to color: {bgr_monsterfish1[color]}")

  cv.imshow('result', colorlogic1)
  cv.waitKey(0)

  return True