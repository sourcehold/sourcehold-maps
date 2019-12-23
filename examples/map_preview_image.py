
import sys
import os

PACKAGE_PARENT = '..'
SCRIPT_DIR = os.path.dirname(os.path.realpath(os.path.join(os.getcwd(), os.path.expanduser(__file__))))
sys.path.append(os.path.normpath(os.path.join(SCRIPT_DIR, PACKAGE_PARENT)))

from sourcehold import structure_tools
from sourcehold import maps

import argparse

parser = argparse.ArgumentParser(description="Display map preview image")
parser.add_argument("path", help="path to a .map file")
# parser.add_argument("--pack", action='store_const', const=True, default=False, help="pack a folder into a .map file")
# parser.add_argument("files", help=".map files (paths)", nargs='+')
# parser.add_argument("--dest", help="a folder to (un)pack file to")
# parser.add_argument("--test", action='store_const', const=True, default=False, help="do a test run of this program")

if __name__ == "__main__":
    args = parser.parse_args()

    map_file = args.path
    image_file = map_file[:-3] + "png"

    m = maps.Map().from_file(map_file)
    m.unpack()

    test_image = m.preview.create_image()
    test_image.save(fp = image_file, format = "png")