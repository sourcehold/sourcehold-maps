import os
import sys

PACKAGE_PARENT = '..'
SCRIPT_DIR = os.path.dirname(os.path.realpath(os.path.join(os.getcwd(), os.path.expanduser(__file__))))
sys.path.append(os.path.normpath(os.path.join(SCRIPT_DIR, PACKAGE_PARENT)))

from sourcehold.maps import Map

import argparse
import PIL
import PIL.Image

parser = argparse.ArgumentParser(description="Extract, replace map preview image")
parser.add_argument('command', help='either extract, or replace')
parser.add_argument('input', help='input .map file')
parser.add_argument("--replacement", help="path to a replacement .png file")
parser.add_argument("output", help="file to write the new map or extracted png image to")

if __name__ == "__main__":
    args = parser.parse_args()

    if args.command == 'extract':
        map_file = Map.Map().from_file(args.input)
        map_file.unpack()

        image_file = args.output

        map_file.preview.get_image().save(image_file, format='png')

    elif args.command == 'replace':
        map_file = Map.Map().from_file(args.input)
        map_file.unpack()

        image_file = args.input + ".png"
        if args.replacement:
            image_file = args.replacement

        map_file.preview.set_image(PIL.Image.open(image_file))

        map_file.to_file(args.output)

    else:
        print('unknown command: {}'.format(args.command), file=sys.stderr)
