import binascii

from sourcehold import compression
from sourcehold.iotools import unpack
from sourcehold.maps import Structure, Variable
from sourcehold.structure_tools import Buffer


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

from sourcehold.maps import MapSection

class Section1073(MapSection):
    # Object availability

    def list_objects(self):
        return []

    def set_available(self, object, available):
        if object == 'all':
            d = b'\x00\x00' if not available else b'\x01\x00'
            self.data = d * (len(self.data)/2)
        else:
            self.data[object] = b'\x01' if available else b'\x00'

    def is_available(self, object):
        return self.data[object] == 1



class Section1001(Structure):
    uncompressed_size = Variable("us", "I")
    compressed_size = Variable("cs", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = compression.COMPRESSION.compress(self.uncompressed)
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def interpret(self):
        return cut(self.uncompressed, "H", 198)


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


# Only applies when rows is even.
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



import struct


class Section1003(Structure):
    uncompressed_size = Variable("us", "I")
    compressed_size = Variable("cs", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = compression.COMPRESSION.compress(self.uncompressed)
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def interpret(self):
        return cut(self.uncompressed, "I", 198)


class Section1002(Structure):
    uncompressed_size = Variable("us", "I")
    compressed_size = Variable("cs", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = compression.COMPRESSION.compress(self.uncompressed)
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def interpret(self):
        return cut(self.uncompressed, "H", 198)
