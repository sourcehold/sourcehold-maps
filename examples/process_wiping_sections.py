
import os, sys

from sourcehold.debugtools.memory.access import AccessContext

#sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), os.path.pardir)))

PACKAGE_PARENT = '..'
SCRIPT_DIR = os.path.dirname(os.path.realpath(os.path.join(os.getcwd(), os.path.expanduser(__file__))))
sys.path.append(os.path.normpath(os.path.join(SCRIPT_DIR, PACKAGE_PARENT)))


import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--section", required=True, type=int)
parser.add_argument("--value", required=True, type=int, help="hexadecimal representation", default="00")
args = parser.parse_args()

process = AccessContext(process_name="Stronghold Crusader.exe")

process.write_section(str(args.section), offset=0, data=b'\x00', recycle=True)
