import colorsys


def create_palette(n):
    ma = 324 / 360
    s = 0.9 / n
    i = 0
    pal = []
    for i in range(n):
        col = colorsys.hsv_to_rgb(i * s, 1, 255)
        r, g, b = round(col[0]), round(col[1]), round(col[2])
        pal.append((r, g, b))
    return pal


def rgb15bitto32bit(i):
    b = i & 0x1F
    b = (b >> 2) | (b << 3)

    g = (i >> 5) & 0x1F
    g = (g >> 2) | (g << 3)

    r = (i >> 10) & 0x1F
    r = (r >> 2) | (r << 3)

    return (r, g, b)


def conv32bittorgb15bit(r, g, b):
    r = (r & 0x7) << 2 | ((r >> 3) & 0x3)
    ir = (r & 0x1F) << 10

    g = (g & 0x7) << 2 | ((g >> 3) & 0x3)
    ig = (g & 0x1F) << 5

    b = (b & 0x7) << 2 | ((b >> 3) & 0x3)
    ib = (b & 0x1F)

    return ir | ig | ib


assert conv32bittorgb15bit(*rgb15bitto32bit(8888)) == 8888

import struct

import io

import PIL


def image_from_data(data: bytes):
    palette = data[:512]
    pixels = data[512:]

    image = PIL.Image.new('P', (200, 200))
    image.putpalette(palette, rawmode="BGR;15")
    image.putdata(pixels)

    return image


def pack_palette_to_stream(pal: list):
    stream = io.BytesIO()

    for i in range(0, len(pal), 3):
        d = conv32bittorgb15bit(pal[i], pal[i + 1], pal[i + 2])
        v = struct.pack("<H", d)
        stream.write(v)

    return stream.getvalue()


def build_serial_palette(stream):
    palette = []
    for i in range(0x100):
        v = struct.unpack("<H", stream.read(2))[0]
        palette.extend(rgb15bitto32bit(v))

    return palette


def build_palette(stream):
    palette = []
    for i in range(0x100):
        v = struct.unpack("<H", stream.read(2))[0]
        palette.append(rgb15bitto32bit(v))

    return palette


def build_image(palette, stream):
    image = []

    d = stream.read(1)
    # while d == b'\x00':
    #     d = stream.read(1)

    while True:
        # while d == b'\x00':
        #    d = stream.read(1)

        if d == b'':
            break

        i = struct.unpack("B", d)[0]
        color = palette[i]
        image.append(color)

        d = stream.read(1)

    return image
