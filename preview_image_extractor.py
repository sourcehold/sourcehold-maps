import argparse
import logging
import os
import io
from pathlib import PurePath

from PIL import Image

from sourcehold import structure_tools, maps, palette

palette_size = 512


def extract_preview(data):
    buff = io.BytesIO(data)

    size = len(data)
    image_size = size - palette_size
    width = height = int(image_size ** 0.5)

    buff.seek(0)
    p = palette.build_serial_palette(buff)
    data = list(buff.read(image_size))

    img = Image.new("P", (width, height))
    img.putpalette(p)
    img.putdata(data)

    return img


if __name__ == "__main__":
    logging.basicConfig(level=logging.DEBUG)

    # if len(sys.argv) == 1:
    #     sys.argv.append("resources/MxM_unseen_1.map")
    #     # raise Exception("Too few arguments. No inputfile and optional outputfile specified")
    # inputfile = outputfile = None
    # if len(sys.argv) >= 2:
    #     inputfile = sys.argv[1]
    # if len(sys.argv) == 3:
    #     outputfile = sys.argv[2]

    arg_parser = argparse.ArgumentParser(description="Extract the preview image from a Stronghold .map file.")
    arg_parser.add_argument("-map", dest="map_file", action="store", metavar="MyMap.map",
                            required=True,
                            help="A Crusader .map file")
    arg_parser.add_argument("-out", dest="out_file", action="store", metavar="preview.png",
                            required=False,
                            help="A filename to save the preview image")

    args = arg_parser.parse_args()

    map_file = args.map_file
    out_file = args.out_file

    if PurePath(map_file).suffix != ".map":
        logging.error("Map file must end with '.map'")
        exit(1)

    if out_file is None:
        logging.info("No output filename specified, using map name")
        out_file = PurePath(map_file).stem + ".png"

    with open(os.path.join(os.path.dirname(__file__), map_file), "rb") as f:
        buf = structure_tools.Buffer(f.read())

    m = maps.Map().from_buffer(buf)
    image = extract_preview(m.preview.get_data())
    image.save(out_file)
