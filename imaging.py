from PIL import Image, ImageDraw


class DiamondSystem(object):

    def __init__(self, rows=198):
        if not rows % 2 == 0:
            raise Exception("row count should be even")
        self.rows = rows

    def to_system(self, i, j):
        rows = self.rows

        cut = rows // 2

        x = i
        y = j

        if x < cut:
            tx = (x * 2) + 1 - y
        else:
            tx = rows - y

        if x < cut:
            ty = y
        else:
            ty = (x - cut) * 2 + 1 + y

        return (tx, ty)


# TODO: implement fact that tileset.png is mappable to datum. tiles are indexed from bottom to top.


class TiledDiamondSystem(DiamondSystem):

    def __init__(self, tilewidth=32, tileheight=16, rows=198, xoffset=15, yoffset=0):
        self.tilewidth = tilewidth
        self.tileheight = tileheight
        self.rows = rows
        self.xoffset = xoffset
        self.yoffset = yoffset

    def to_system(self, i, j):
        i, j = super().to_system(i, j)
        return (i * (self.tilewidth // 2), j * (self.tileheight // 2))

    def system_tile_coordinates(self, i, j):
        i, j = self.to_system(i, j)
        xoff = i + self.xoffset
        yoff = j + self.yoffset
        width = self.tilewidth
        height = self.tileheight
        return [(xoff, yoff), (xoff + width // 2, yoff + height // 2), (xoff, yoff + height),
                (xoff - width // 2, yoff + height // 2)]


def make_image_of_data(dt, system: TiledDiamondSystem):
    width = int(system.rows * system.tilewidth * 0.5)
    height = int(system.rows * system.tileheight * 0.5)
    im = Image.new('RGBA', (width, height))
    draw = ImageDraw.Draw(im)
    mapping, pal = build_palette(dt)

    for i in range(len(dt)):
        for j in range(len(dt[i])):
            coords = system.system_tile_coordinates(i, j)
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
        d = cut(read_file("{}/sections/{}".format(unpacked_map_folder, section)), s, 198)
        im = make_image_of_data(d, system=TiledDiamondSystem(rows=len(d), tilewidth=32, tileheight=16))
        im.save("{}/{}.png".format(destination, section))

        write_to_file("{}/{}.spec".format(destination, section), dump_spec(d))


from sourcehold import palette
from sourcehold.iotools import read_file, write_to_file
from sourcehold.maps.sections import cut

hexformat = "#{0:02x}{1:02x}{2:02x}"
datumhexformat = "{:016x}"
datumintformat = "{:16d}"
hexform = "{:02x}"

import argparse

parser = argparse.ArgumentParser(description="Export images of imageable map sections")
parser.add_argument("src", help="unpacked map folder", nargs=1)
parser.add_argument("dst", help="destination folder for images", nargs=1)

import sys

if __name__ == "__main__":
    args = parser.parse_args(sys.argv[1:])

    export_images(args.src[0], args.dst[0])
