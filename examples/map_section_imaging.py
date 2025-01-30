from PIL import Image, ImageDraw

import os, sys

from sourcehold.maps.sections.types import TileSystem

#sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), os.path.pardir)))

PACKAGE_PARENT = '..'
SCRIPT_DIR = os.path.dirname(os.path.realpath(os.path.join(os.getcwd(), os.path.expanduser(__file__))))
sys.path.append(os.path.normpath(os.path.join(SCRIPT_DIR, PACKAGE_PARENT)))

# TODO: implement fact that tileset.png is mappable to datum. tiles are indexed from bottom to top.
from sourcehold.maps.sections.tools import TiledDiamondSystem


def make_image_of_data(dt, system: TiledDiamondSystem):
    width = int(system.rows * system.tilewidth * 0.5)
    height = int(system.rows * system.tileheight * 0.5)
    im = Image.new('RGBA', (width, height))
    draw = ImageDraw.Draw(im)
    mapping, pal = build_palette(dt)

    for i in range(len(dt)):
        for j in range(len(dt[i])):
            coords = system.system_tile_coordinates((i, j))
            coords = [(im.width - coord[0], coord[1]) for coord in coords]
            draw.polygon(coords, outline=None, fill=pal[mapping.index(dt[i][j])])

    return im


def rgb_to_hex(r, g, b):
    return hexformat.format(r, g, b)


def build_palette(data):
    uniq = set(x for y in data for x in y)

    mapping = sorted(list(uniq))
    pal = palette.create_palette(len(mapping))

    return (mapping, pal)


# imageable_sections = ['1001', '1002', '1003', '1004', '1005', '1006', '1007', '1008', '1009', '1010', '1012', '1020',
#                       '1021', '1026', '1028', '1029', '1030', '1033', '1036', '1037', '1043', '1045', '1049', '1103',
#                       '1104', '1105', '1118']
# imageable_sections.remove("1105")

#TODO: 1001, 1002, and 1003 have a header at the start, and another header for each row, the others have only one header. Maybe because data is not there (empty map). Come back to this later. Test with a save game?
#TODO: In a .sav game, section 1045 also has separate row headers, section 1037 just a separate footer, section 1036 also has many headers and footers.
#TODO: 1008 is so random, it is probably not supposed to be cut.
imageable_sections = {'1001': 160800, '1002': 160800, '1003': 321600, '1004': 160800, '1005': 80400, '1006': 80400,
                      '1007': 160800, '1008': 160800, '1009': 160800, '1010': 160800, '1012': 160800, '1020': 80400,
                      '1021': 160800, '1026': 160800, '1028': 80400, '1029': 80400, '1030': 80400, '1033': 160800,
                      '1036': 160800, '1037': 80400, '1043': 80400, '1045': 80400, '1049': 80400, '1103': 80400,
                      '1104': 80400, '1105': 723600, '1118': 80400}

size_mapping = {160800: "H", 80400: "B", 321600: "I", 723600: "9B"}


def unpack_big_integer(data, fmt="uintle:72"):
    from bitstring import BitStream # type: ignore
    return BitStream(bytes=data).unpack(fmt)




import os


def dump_spec(data):
    mapping, pal = build_palette(data)
    linesep = '\r\n'
    valuesep = '\t'

    result = "color" + valuesep + "datum" + linesep

    for i in range(len(mapping)):
        result += hexformat.format(*pal[i]) + valuesep + hexform.format(mapping[i]) + linesep

    return result.encode('ascii')


tw, th = (32, 16)


def export_images(unpacked_map_folder, destination):
    if not os.path.exists(destination):
        os.makedirs(destination)

    for section, size in imageable_sections.items():
        if size == 80400 * 9:  # skip 1105
            continue
        print("Imaging section {}".format(section))
        s = size_mapping[size]
        #d = cut_strict(read_file("{}/sections/{}".format(unpacked_map_folder, section)), s, 198)
        #d = TileSystem().from_bytes(read_file("{}/sections/{}".format(unpacked_map_folder, section), fmt=s)).get_tiles()
        #im = make_image_of_data(d, system=TiledDiamondSystem(rows=len(d), tilewidth=32, tileheight=16))
        im = TileSystem().from_bytes(data=read_file("{}/sections/{}".format(unpacked_map_folder, section)), fmt=s).create_image()
        im.save("{}/{}.png".format(destination, section))

        # write_to_file("{}/{}.spec".format(destination, section), dump_spec(d))


def export_images_from_map(map, destination):

    if not os.path.exists(destination):
        os.makedirs(destination)

    for i, index in enumerate(map.directory.section_indices):
        if index == 0:
            continue

        if map.directory.section_uncompressed_lengths[i] == 80400 * 9:  # skip 1105
            pass

        if map.directory.section_uncompressed_lengths[i] % 80400 != 0:
            continue

        print("Imaging section {}".format(index))
        # d = cut_strict(read_file("{}/sections/{}".format(unpacked_map_folder, section)), s, 198)
        # d = TileSystem().from_bytes(read_file("{}/sections/{}".format(unpacked_map_folder, section), fmt=s)).get_tiles()
        # im = make_image_of_data(d, system=TiledDiamondSystem(rows=len(d), tilewidth=32, tileheight=16))
        im = map.directory[index].create_image()
        im.save("{}/{}.png".format(destination, index))
        #
        # write_to_file("{}/{}.spec".format(destination, index), dump_spec(d))


from sourcehold import palette
from sourcehold.iotools import read_file, write_to_file
from sourcehold.maps.sections.tools import cut_strict, TiledDiamondSystem

hexformat = "#{0:02x}{1:02x}{2:02x}"
datumhexformat = "{:016x}"
datumintformat = "{:16d}"
hexform = "{:02x}"

import argparse

parser = argparse.ArgumentParser(description="Export images of imageable map sections")
parser.add_argument("src", help="unpacked map folder", nargs=1)
parser.add_argument("dst", help="destination folder for images", nargs=1)

import sys

from sourcehold import load_map

if __name__ == "__main__":
    args = parser.parse_args(sys.argv[1:])

    if args.src[0].endswith(".map") or args.src[0].endswith(".sav"):
        export_images_from_map(load_map(args.src[0]), args.dst[0])
    else:
        export_images(args.src[0], args.dst[0])
