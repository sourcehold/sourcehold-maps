import os
import sys

PACKAGE_PARENT = '..'
SCRIPT_DIR = os.path.dirname(os.path.realpath(os.path.join(os.getcwd(), os.path.expanduser(__file__))))
sys.path.append(os.path.normpath(os.path.join(SCRIPT_DIR, PACKAGE_PARENT)))

from sourcehold import structure_tools, maps

import argparse

parser = argparse.ArgumentParser(description="Unpack or pack .map files")
parser.add_argument("--unpack", action='store_const', const=True, default=False, help="unpack a .map file to a folder")
parser.add_argument("--pack", action='store_const', const=True, default=False, help="pack a folder into a .map file")
parser.add_argument("files", help=".map files (paths) or folders to pack", nargs='+')
parser.add_argument("--dest", help="a folder to (un)pack a map file to")

if __name__ == "__main__":
    args = parser.parse_args()

    if not args.files:
        raise Exception("The following arguments are required: files")

    import os

    existence = [file for file in args.files if not os.path.exists(file)]
    if len(existence) > 0:
        raise Exception("Some files or paths do not exist: {}".format('\n'.join(existence)))

    dest = args.dest
    if not args.dest:
        dest = os.getcwd()

    if args.unpack:

        for file in args.files:
            with open(file, 'rb') as f:
                buf = structure_tools.Buffer(f.read())

            name = os.path.basename(file)

            while name.endswith(".map"):
                name = name[:-4]

            map = maps.Map().from_buffer(buf)

            map.dump_to_folder(os.path.join(dest, name))

    if args.pack:
        for file in args.files:
            while file.endswith('/') or file.endswith('\\'):
                file = file[:-1]

            map = maps.Map().load_from_folder(file)

            name = os.path.basename(file)

            buf = structure_tools.Buffer()

            map.serialize_to_buffer(buf)

            with open(os.path.join(dest, name + ".map"), 'wb') as f:
                f.write(buf)

    if not args.pack and not args.unpack:
        print("Must either use --pack or --unpack")
