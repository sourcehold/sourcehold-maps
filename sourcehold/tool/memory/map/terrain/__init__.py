MAP_SIZE = 400
TILE_COUNT = MAP_SIZE * ((MAP_SIZE // 2) + 1 )
# python -m pip install Pillow
import struct, numpy
from sourcehold.tool.memory.map.common import get_process_handle, validate_input_path
from sourcehold.world import create_selection_matrix
import cv2 as cv # type: ignore
from .logics import logic1, logic1_vk, logic2, logic2_vk
from .colors import DEFAULT_PALETTE, monsterfish1_bgr, bgr_monsterfish1
import sys

def get_image_data(img_path):
  img = cv.imread(img_path)
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
  
  if args.palette:
    palette = colors.Palette(args.palette)
  else:
    palette = DEFAULT_PALETTE

  img_path = args.input
  validate_input_path(img_path)
  img = get_image_data(img_path)

  process = get_process_handle(args.game)

  logic1matrix = numpy.zeros((400, 400), dtype='uint32')
  borderlogic1matrix = numpy.zeros((400, 400), dtype='uint32')
  borderlogic1matrix[selection] = get_raw_logic1(process) # We load it here to get the map borders only...
  logic1matrix[borderlogic1matrix & logic1['border'] != 0] |= logic1['border']
  logic1matrix[borderlogic1matrix & logic1['border_edge'] != 0] |= logic1['border_edge']
  logic1matrix[borderlogic1matrix == 0] = 0 

  logic2matrix = numpy.zeros((400, 400), dtype='uint8')
  # logic2matrix[selection] = get_raw_logic2(process)

  for color, name in palette.bgr_palette.items():
    where = (img == color).all(2)
    logic1matrix[where] |= logic1[name]
    if name in logic2:
      logic2matrix[where] = logic2[name]

  set_raw_logic1(process, logic1matrix[selection].flat)
  set_raw_logic2(process, logic2matrix[selection].flat)

  return True

def get_terrain(args):
  #' returns None in case of non applicable
  if args.what != 'terrain':
    return None
  
  if args.action != "get":
     return None  
  
  if args.palette:
    palette = colors.Palette(args.palette)
  else:
    palette = DEFAULT_PALETTE

  process = get_process_handle(args.game)

  logic1matrix = numpy.zeros((400, 400), dtype='uint32')
  logic1matrix[selection] = get_raw_logic1(process)

  logic2matrix = numpy.zeros((400, 400), dtype='uint8')
  logic2matrix[selection] = get_raw_logic2(process)

  img = numpy.zeros((400,400,3), dtype='uint8')

  if args.debug:
    print("logic1")
  for flag, name in logic1_vk.items():
    color = (0, 0, 0)
    if name in palette.palette_bgr:
      color = palette.palette_bgr[name]
    else:
      if args.debug:
        print(f"skipping color for: {name}")
    img[logic1matrix & flag != 0] = color
    if args.debug:
      print(f"set '{name}' {img[logic1matrix & flag != 0].sum()} times to color: {palette.bgr_palette[color]}")

  if args.debug:
    print("logic2")
  for flag, name in logic2_vk.items():
    if name == 'none':
      continue
    color = (0, 0, 0)
    where = (logic1matrix & logic1['default_earth_or_texture']) != 0
    if name in palette.palette_bgr:
      color = palette.palette_bgr[name]
    else:
      if args.debug:
        print(f"skipping color for: {name}")
    img[where & (logic2matrix == flag)] = color
    if args.debug:
      print(f"set '{name}' {img[where & (logic2matrix == flag)].sum()} times to color: {palette.bgr_palette[color]}")

  if not args.output:
    if args.debug:
      print(args.output_format)
    sys.stdout.buffer.write(cv.imencode(f".{args.output_format}", img)[1].tobytes())
  else:
    cv.imwrite(args.output, img=img)

  return True