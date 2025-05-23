


# python -m pip install Pillow
import pathlib
import struct
from sourcehold.tool.memory.map.common import get_process_handle, validate_input_path
from sourcehold.world import create_selection_matrix
import cv2 as cv # type: ignore

def get_image_data_grayscale(img_path):
  img = cv.imread(img_path)
  img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
  return img

selection = create_selection_matrix()

# (Little endian) unsigned bytes
def get_raw_height(process):
  return struct.unpack("<80400B", process.read_section('1045'))

def set_raw_height(process, data):
  bytes_data = struct.pack("<80400B", *data)
  # ChangedLayer
  process.write_bytes(0x01c5ad88, b'\x02' * 80400) # TODO: fix
  # Logical terrain height layer: DefaultHeightLayer
  process.write_section('1045', bytes_data)
  # Visual height layer, I think also includes walls and towers: HeightLayer
  process.write_section('1005', bytes_data)
  # LogicLayer
  process.write_section('1003', struct.pack("<80400I", *((v & 0xffffff7f) for v in struct.unpack("<80400I", process.read_section('1003')))))
  # Logic2Layer
  process.write_section('1037', b'\x04' * 80400)

# def post_process_raw_height():
#   # MiscDisplayLayer
#   process.write_section('1007', struct.pack("<80400H", *(((v & 0xffdf) & 0xf83f) for v in struct.unpack("<80400H", process.read_section('1007')))))
#   # LogicLayer, what a hot mess, probably not all required
#   process.write_section('1003', struct.pack("<80400I", *(((((v & 0x5f81c436) & 0xffffff7f) & 0xbfffbfff) | 32768) for v in struct.unpack("<80400I", process.read_section('1003')))))
#   # Logic2Layer
#   process.write_section('1037', b'\x04' * 80400)
#   # TODO: wall owner layer, and special logic2layer set to 4 or 8 depending on plateau
#   # ChangedLayer
#   process.write_bytes(0x01c5ad88, b'\x02' * 80400)


# post_process_raw_height()


def set_height(args):
  #' returns None in case of non applicable
  if args.what != 'height':
    return None
  
  if args.action != "set":
     return None
  
  img_path = args.input
  validate_input_path(img_path)

  img = get_image_data_grayscale(img_path)

  process = get_process_handle(args.game)

  set_raw_height(process, img[selection].flat)

  return True