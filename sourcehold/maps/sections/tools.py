import struct

from sourcehold.iotools import Buffer
from sourcehold.iotools import unpack




def cut_strict(data, type, rows):
    data = Buffer(data)
    if type.__class__ == int:
        type = type + "B"
    size = struct.calcsize(type)
    header = data.read(size * 2)

    headers = set()
    footers = set()

    if header not in headers:
        print("header: {}".format(header))
        headers.add(header)

    chunks = []

    for i in range(0, rows + 1, 1):
        header = data.read(size * 2)

        if header not in headers:
            print("header: {}".format(header))
            headers.add(header)

        chunk = [unpack(type, data.read(size)) for v in range(i * 2)]
        chunks.append(chunk)
        footer = data.read(size * 2)

        if footer not in footers:
            print("footer: {}".format(footer))
            footers.add(footer)

    for i in range(rows, -1, -1):
        header = data.read(size * 2)

        if header not in headers:
            print("header: {}".format(header))
            headers.add(header)

        chunk = [unpack(type, data.read(size)) for v in range(i * 2)]
        chunks.append(chunk)
        footer = data.read(size * 2)

        if footer not in footers:
            print("footer: {}".format(footer))
            footers.add(footer)

    footer = data.read(size * 2)

    if footer not in footers:
        print("footer: {}".format(footer))
        footers.add(footer)

    assert data.remaining() == 0

    return chunks[1:-1]


def cut(data, type, rows):
    data = Buffer(data)
    if type.__class__ == int:
        type = type + "B"
    size = struct.calcsize(type)
    header = data.read(size * 2)

    chunks = []

    for i in range(0, rows + 1, 1):
        header = data.read(size * 2)
        chunk = [unpack(type, data.read(size)) for v in range(i * 2)]
        chunks.append(chunk)
        footer = data.read(size * 2)

    for i in range(rows, -1, -1):
        header = data.read(size * 2)
        chunk = [unpack(type, data.read(size)) for v in range(i * 2)]
        chunks.append(chunk)
        footer = data.read(size * 2)

    footer = data.read(size * 2)

    assert data.remaining() == 0

    return chunks[1:-1]


# Only applies when rows is even.

def translate_diamond_to_checkerboard(data):
    sq1 = data

    rows = len(sq1)

    assert rows % 2 == 0

    cutpoint = rows // 2

    width = rows
    height = rows

    out = []
    for i in range(width + 1):
        col = []
        for j in range(height + 1):
            col.append(None)
        out.append(col)

    for i in range(len(sq1)):
        for j in range(len(sq1[i])):
            ti, tj = iso_xy_to_image_xy((i, j), rows)
            out[width - ti][tj] = sq1[i][j]

    return out


def create_image(data1, palette):
    sq1 = data1

    rows = len(sq1)

    assert rows % 2 == 0

    cutpoint = rows // 2

    width = rows
    height = rows

    from PIL import Image, ImageColor
    im = Image.new('RGB', (width + 1, height + 1), ImageColor.getcolor('black', 'RGB'))

    for i in range(len(sq1)):
        for j in range(len(sq1[i])):
            ti, tj = iso_xy_to_image_xy((i, j), rows)
            im.putpixel((width - ti, tj), palette(sq1[i][j]))

    return im


def create_comparison_image(data1, data2):
    sq1 = data1
    sq2 = data2

    rows = len(sq1)

    assert rows % 2 == 0

    cutpoint = rows // 2

    width = rows
    height = rows

    from PIL import Image, ImageColor
    im = Image.new('RGB', (width + 1, height + 1), ImageColor.getcolor('black', 'RGB'))

    for i in range(len(sq1)):
        for j in range(len(sq1[i])):
            ti, tj = iso_xy_to_image_xy((i, j), rows)
            if sq1[i][j] != sq2[i][j]:
                im.putpixel((width - ti, tj), ImageColor.getcolor('red', 'RGB'))
            else:
                im.putpixel((width - ti, tj), ImageColor.getcolor('white', 'RGB'))

    return im


def interpret(data, type, opening, closing):
    buf = Buffer(data)
    depth = 0

    chunks = []

    chunk = b''

    while buf.remaining() >= max(len(opening), len(closing)):

        if buf.peek(len(opening)) == opening:
            depth += 1
            chunk = b''
            buf.read(len(opening))
        elif buf.peek(len(closing)) == closing:
            depth -= 1
            chunks.append(chunk)
            buf.read(len(closing))
        else:
            chunk += buf.read(1)

    mapdata = []

    s = struct.calcsize(type)

    for c in chunks:
        if len(c) == 0:
            continue

        buf = Buffer(c)
        ints = []
        while True:
            ints.append(struct.unpack(type, buf.read(s))[0])

            if buf.remaining() >= s:
                continue
            elif buf.remaining() == 0:
                break
            else:
                raise Exception("data left in buffer of size {}".format(buf.remaining()))

        mapdata.append(ints)

    return mapdata


def iso_xy_to_image_xy(coord, rows):
    assert rows % 2 == 0

    cut = rows // 2

    x = coord[0]
    y = coord[1]

    if x < cut:
        tx = (x * 2) + 1 - y
    else:
        tx = rows - y

    if x < cut:
        ty = y
    else:
        ty = (x - cut) * 2 + 1 + y

    return (tx, ty)


class DiamondSystem(object):

    def __init__(self, rows=198):
        if not rows % 2 == 0:
            raise Exception("row count should be even")
        self.rows = rows

    def to_screen_system(self, ij_index):
        rows = self.rows

        cut = rows // 2

        x, y = ij_index

        if x < cut:
            tx = (x * 2) + 1 - y
        else:
            tx = rows - y

        if x < cut:
            ty = y
        else:
            ty = (x - cut) * 2 + 1 + y

        return (tx, ty)

    def to_file_system(self, xy):
        tx, ty = xy

        cut = self.rows // 2

        raise NotImplementedError()

    def get_size_of_row(self, i):
        if i < (self.rows//2):
            return (i * 2) + 2
        else:
            return (((self.rows//2) - (i - (self.rows//2)) - 1) * 2) + 2

    def retrieve_diamond_indices(self, top_ij_coord, size):
        si, sj = top_ij_coord
        ssize = self.get_size_of_row(si)

        indices = []

        for i in range(size):
            for j in range(size):

                ni = si + i
                nj = sj + j

                if ni > self.rows:
                    raise Exception("i is out of bounds: ({}, {})".format(ni, nj))

                ni_size = self.get_size_of_row(ni)

                size_diff = ni_size - ssize

                nj += (size_diff // 2)

                if nj > ni_size:
                    raise Exception("j is out of bounds: ({}, {})".format(ni, nj))

                indices.append((ni, nj))

        return indices


class TiledDiamondSystem(DiamondSystem):

    def __init__(self, tilewidth=32, tileheight=16, rows=198, xoffset=15, yoffset=0):
        self.tilewidth = tilewidth
        self.tileheight = tileheight
        self.rows = rows
        self.xoffset = xoffset
        self.yoffset = yoffset

    def to_screen_system(self, ij_index):
        i, j = super().to_screen_system(ij_index)
        return (i * (self.tilewidth // 2), j * (self.tileheight // 2))

    def system_tile_coordinates(self, ij_index):
        i, j = self.to_screen_system(ij_index)
        xoff = i + self.xoffset
        yoff = j + self.yoffset
        width = self.tilewidth
        height = self.tileheight
        return [(xoff, yoff), (xoff + width // 2, yoff + height // 2), (xoff, yoff + height),
                (xoff - width // 2, yoff + height // 2)]