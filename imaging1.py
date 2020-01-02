import os

from sourcehold import palette
from sourcehold.iotools import read_file, write_to_file
from sourcehold.maps.sections import cut
from sourcehold.maps.sections.tools import create_image

hexformat = "#{0:02x}{1:02x}{2:02x}"
datumhexformat = "{:016x}"
datumintformat = "{:16d}"
hexform = "{:02x}"


def rgb_to_hex(r, g, b):
    return hexformat.format(r, g, b)


def build_palette(data):
    uniq = set(x for y in data for x in y)

    mapping = sorted(list(uniq))
    pal = palette.create_palette(len(mapping))

    return (mapping, pal)


def produce_image(data):
    mapping, pal = build_palette(data)

    def lookup(v):
        return pal[mapping.index(v)]

    im = create_image(data, lookup)
    return im


from PIL import Image

SAND_RAISED_LAND = list(range(0, 16))


def make_image_of_values(dt, values):
    im = Image.new('RGBA', (len(dt), len(dt[0])))
    da = im.load()
    for i in range(len(dt)):
        for j in range(len(dt[i])):
            if not dt[i][j] in values:
                da[i, j] = (255, 255, 255, 0)
            else:
                da[i, j] = (0, 0, 0, 1)
    return im


def dump_spec(data):
    mapping, pal = build_palette(data)
    linesep = '\r\n'
    valuesep = '\t'

    result = "color" + valuesep + "datum" + linesep

    for i in range(len(mapping)):
        result += hexformat.format(*pal[i]) + valuesep + hexform.format(mapping[i]) + linesep

    return result.encode('ascii')


imageable_sections = ['1001', '1002', '1003', '1004', '1005', '1006', '1007', '1008', '1009', '1010', '1012', '1020',
                      '1021', '1026', '1028', '1029', '1030', '1033', '1036', '1037', '1043', '1045', '1049', '1103',
                      '1104', '1105', '1118']
# imageable_sections.remove("1105")

imageable_sections = {'1001': 160800, '1002': 160800, '1003': 321600, '1004': 160800, '1005': 80400, '1006': 80400,
                      '1007': 160800, '1008': 160800, '1009': 160800, '1010': 160800, '1012': 160800, '1020': 80400,
                      '1021': 160800, '1026': 160800, '1028': 80400, '1029': 80400, '1030': 80400, '1033': 160800,
                      '1036': 160800, '1037': 80400, '1043': 80400, '1045': 80400, '1049': 80400, '1103': 80400,
                      '1104': 80400, '1105': 723600, '1118': 80400}

size_mapping = {160800: "H", 80400: "B", 321600: "I", 723600: "9B"}


def export_images(unpacked_map_folder, destination):
    if not os.path.exists(destination):
        os.makedirs(destination)

    for section, size in imageable_sections.items():
        if size == 80400 * 9:  # skip 1105
            continue
        print("Imaging section {}".format(section))
        s = size_mapping[size]
        d = cut(read_file("{}/sections/{}".format(unpacked_map_folder, section)), s, 198)
        im = produce_image(d)
        im.save("{}/{}.png".format(destination, section))

        write_to_file("{}/{}.spec".format(destination, section), dump_spec(d))


def lowest_in_range(dc, ifrom, ito, jfrom, jto):
    lowest = None
    for i in range(ifrom, ito):
        for j in range(jfrom, jto):
            if dc[i][j] == None:
                continue
            if lowest == None:
                lowest = dc[i][j]
            if dc[i][j] < lowest:
                lowest = dc[i][j]
    return lowest


def highest_in_range(dc, ifrom, ito, jfrom, jto):
    highest = None
    for i in range(ifrom, ito):
        for j in range(jfrom, jto):
            if dc[i][j] == None:
                continue
            if highest == None:
                highest = dc[i][j]
            if dc[i][j] > highest:
                highest = dc[i][j]
    return highest


import argparse

parser = argparse.ArgumentParser(description="Export images of imageable map sections")
parser.add_argument("src", help="unpacked map folder", nargs=1)
parser.add_argument("dst", help="destination folder for images", nargs=1)

import sys

if __name__ == "__main__":
    args = parser.parse_args(sys.argv[1:])

    export_images(args.src[0], args.dst[0])
