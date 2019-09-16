import logging

logging.basicConfig(level=logging.WARNING)

import maps
import structure_tools
import sys
import tempfile

if __name__ == "__main__":
    if len(sys.argv) == 1:
        sys.argv.append("resources/MxM_unseen_1.map")

    dir = tempfile.TemporaryDirectory()
    path = dir.name

    with open(sys.argv[1], 'rb') as f:
        buf = structure_tools.Buffer(f.read())

    map = maps.Map(buf)

    map.dump_to_folder(path)

    print("Dumped map {} to directory {}".format(sys.argv[1], path))
