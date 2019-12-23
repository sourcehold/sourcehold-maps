
import logging

logging.basicConfig(level=logging.WARNING)

from sourcehold import structure_tools, maps
import sys
import tempfile

import argparse

parser = argparse.ArgumentParser(description="Unpack .map files")
parser.add_argument("--unpack", action='store_const', const=True, default=False, help="unpack a .map file to a folder")
parser.add_argument("--pack", action='store_const', const=True, default=False, help="pack a folder into a .map file")
parser.add_argument("files", help=".map files (paths)", nargs='+')
parser.add_argument("--dest", help="a folder to (un)pack file to")
parser.add_argument("--test", action='store_const', const=True, default=False, help="do a test run of this program")

if __name__ == "__main__":
    args = parser.parse_args(sys.argv[1:])

    if not args.test and not args.files:
        raise Exception("The following arguments are required: files")

    if args.test:
        if len(sys.argv) == 1:
            sys.argv.append("resources/MxM_unseen_1.map")

        dir = tempfile.TemporaryDirectory()
        path = dir.name

        with open(sys.argv[1], 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        map = maps.Map().from_buffer(buf)

        map.dump_to_folder(path)

        print("Dumped map {} to directory {}".format(sys.argv[1], path))
    else:
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
