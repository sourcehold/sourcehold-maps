from sourcehold.maps import Map, Buffer
from sourcehold.iotools import read_file

map = Map().from_buffer(Buffer(read_file("resources/MxM_unseen_1.map")))

from PIL import Image, ImageDraw

from sourcehold.palette import build_serial_palette

im = Image.new('P', (400,400))

pal1 = build_serial_palette(Buffer(map.preview.get_data()))
im.putpalette(pal1)
im.putdata(map.preview.get_data()[512:])


draw = ImageDraw.Draw(im, 'P')

draw.polygon(xy = [0,0,200,0,200,200,0,200], fill = 1, outline = None)
draw.polygon(xy = [100,0,200,100,100,200,0,100], fill = 2, outline = None)
draw.polygon(xy = [50,50,150,50,150,150,50,150], fill = 3, outline = None)


packed_palette = im.getpalette()
# we need to invert the color process in palette.py

import struct

map.preview.uncompressed =struct.pack("B"*len(im.getpalette()), *im.getpalette()) + struct.pack("B"*len(im.getdata()), *im.getdata())