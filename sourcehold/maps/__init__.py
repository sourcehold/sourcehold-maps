import binascii
import io
import logging
import struct

from PIL import Image

from sourcehold import compression, palette
from sourcehold.iotools import read_file, write_to_file
from sourcehold.structure_tools import Structure, Field
from sourcehold.structure_tools import DataProperty


class SimpleSection(Structure):
    size = Field("size", "I")
    data = Field("data", "B", size)

    def pack(self, force=False):
        self.size = len(self.data)

    def unpack(self, force=False):
        assert len(self.data) == self.size

    def size_of(self):
        return self.size + 4


class U1(SimpleSection):

    int0 = DataProperty("I", start=0)
    int1 = DataProperty("I", start=4)


class U2(SimpleSection):

    map_type = DataProperty("I", start=0)
    middle = DataProperty("B", start=4, array_size=20)
    players_count = DataProperty("I", start=24)


class U3(SimpleSection):

    int0 = DataProperty("I", start=0)
    int1 = DataProperty("I", start=4)
    # TODO: value is in {0, 1, 2}. What does 2 mean?
    map_locked = DataProperty("I", start=8)
    rest = DataProperty("B", start=12, array_size=lambda obj: obj.size - 12)


class U4(SimpleSection):

    int0 = DataProperty("I", start=0)
    int1 = DataProperty("I", start=4)
    int2 = DataProperty("I", start=8)
    unbalanced = DataProperty("I", start=12)
    rest = DataProperty("B", array_size=64, start=16)

    def get_unbalanced_flag(self):
        return self.unbalanced == 1

    def set_unbalanced_flag(self, value: bool):
        self.unbalanced = 1 if value else 0


class CompressedSection(Structure):
    uncompressed_size = Field("uncompressed_size", "I")
    compressed_size = Field("compressed_size", "I")
    hash = Field("hash", "I")
    data = Field("data", "B", compressed_size)

    def __init__(self):
        super().__init__()
        self._dirty = False

    def pack(self, force = False):
        if self._dirty or force:
            if not hasattr(self, "compression_level"):
                self.compression_level = 6
            self.data = [i for i in compression.COMPRESSION.compress(self.uncompressed, self.compression_level)]
            self.hash = binascii.crc32(self.uncompressed)
            self.uncompressed_size = len(self.uncompressed)
            self.compressed_size = len(self.data)
            self._dirty = False

    def unpack(self, force = False):
        if self._dirty or force:
            self.compression_level = self.data[1]
            self.uncompressed = compression.COMPRESSION.decompress(self.data)
            assert len(self.data) == self.compressed_size
            assert len(self.uncompressed) == self.uncompressed_size
            assert binascii.crc32(self.uncompressed) == self.hash
            self._dirty = False

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack(force=True)
        return self.uncompressed

    def set_data(self, data):
        self.uncompressed = data
        self._dirty = True

    def size_of(self):
        return self.compressed_size + 4 + 4 + 4


class Preview(CompressedSection):

    def get_image(self) -> Image:
        palette_size = 512

        buff = io.BytesIO(self.uncompressed)
        size = len(self.uncompressed)
        image_size = size - palette_size
        width = height = int(image_size ** 0.5)

        buff.seek(0)
        p = palette.build_serial_palette(buff)
        data = list(buff.read(image_size))

        img = Image.new("P", (width, height))
        img.putpalette(p)
        img.putdata(data)

        return img

    def set_image(self, image: Image):
        palette_size = 512

        width, height = 200, 200

        if image.mode != 'P':
            image = image.convert('P')
        if image.size != (width, height):
            image = image.resize((width, height))

        if (len(image.getpalette()) / 3) * 2 != 512:
            # raise Exception("Used too many colors, please stick to 256 colors")
            image = image.quantize(256)  # TODO: mode P conversion may be redundant

        pal = palette.pack_palette_to_stream(image.getpalette())
        if len(pal) != 512:
            raise Exception("Invalid length: {}".format(len(pal)))

        self.uncompressed = pal + image.tobytes()


class Description(Structure):
    size = Field("size", "I")  # This structure in size, + compressed size
    use_string_table = Field("use_string_table", "I")  # TODO: serialize this to a .meta file
    string_table_index = Field("string_table_index", "I")
    uncompressed_size = Field("uncompressed_size", "I")
    compressed_size = Field("compressed_size", "I")
    hash = Field("hash", "I")
    data = Field("data", "B", compressed_size)

    def __init__(self):
        super().__init__()
        self._dirty = False

    def pack(self, force = False):
        if self._dirty or force:
            if not hasattr(self, "compression_level"):
                self.compression_level = 6
            if not hasattr(self, "use_string_table"):
                self.use_string_table = 0
            if not hasattr(self, "string_table_index"):
                self.string_table_index = 0
            self.data = [i for i in compression.COMPRESSION.compress(self.uncompressed, self.compression_level)]
            self.hash = binascii.crc32(self.uncompressed)
            self.uncompressed_size = len(self.uncompressed)
            self.compressed_size = len(self.data)
            self.size = self.compressed_size + (5 * 4)

    def set_description(self, string: str):
        bstring = string.encode('ascii')
        if len(bstring) >= 1000:
            raise Exception("description text too long: {}".format(len(bstring)))

        padded = bstring + b'\x00' * (1000 - len(bstring))
        self.uncompressed = padded
        self.uncompressed = self.uncompressed[:212] + b'\x04\x00?\x00????8?8? ??' + self.uncompressed[227:]
        # self.description_size = len(bstring)

    def get_description(self):
        j = len(self.uncompressed)

        while j > 0:
            j -= 1
            v = self.uncompressed[j]
            if v != 0:
                break

        return self.uncompressed[:j].decode('ascii')

    def unpack(self, force = False):
        if self._dirty or force:
            self.compression_level = self.data[1]
            self.uncompressed = compression.COMPRESSION.decompress(self.data)
            assert len(self.data) == self.compressed_size
            assert len(self.uncompressed) == self.uncompressed_size
            assert binascii.crc32(self.uncompressed) == self.hash
            assert self.compressed_size + (5 * 4) == self.size

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack(force=True)
        return self.uncompressed

    def set_data(self, data):
        self.uncompressed = data

    def size_of(self):
        return self.compressed_size + (6 * 4)


class MapSection(Structure):

    def __init__(self):
        super().__init__()

    def size_of(self):
        return self.length

    def from_buffer(self, buf, **kwargs):
        super().from_buffer(buf, **kwargs)
        if 'length' not in kwargs:
            raise KeyError()
        self.length = kwargs.get('length')
        self.data = buf.read(self.length)
        return self

    def pack(self, force = False):
        self.length = len(self.data)

    def serialize_to_buffer(self, buf):
        self.pack()

        # note: we do not serialize length!
        prop = "data"
        bef = buf.tell()
        buf.write(self.data)
        aft = buf.tell()
        l = aft - bef
        logging.debug("serialized {:16s}. length: {:10d} before: {:10d},  after: {:10d}".format(
            prop,
            l,
            bef,
            aft
        ))


class CompressedMapSection(CompressedSection):
    pass


from sourcehold.maps.sections import find_section_for_index

import csv
from sourcehold.structure_tools import ints_to_byte_array, bytes_to_int_array, Buffer


def get_section_for_index(index, compressed):
    cls = find_section_for_index(index)
    if cls:
        if issubclass(cls, CompressedMapSection) and not compressed:
            return MapSection
        return cls

    if compressed is True:
        return CompressedMapSection
    else:
        return MapSection


def determine_version(obj):
    return 150 if obj.directory_u1[0] >= 161 else 100


import re

SECTION_PATH_re = re.compile("^[0-9]+$")
import pathlib


class Directory(Structure):
    # Stronghold crusader has values 161, 168, or 170, or 172 if custom Stronghold
    # The version differ in the amount of sections, 150 or 100.
    _MAX_SECTIONS_COUNT = determine_version
    directory_size = Field("directory_size", "I")
    size = Field("size", "I")
    sections_count = Field("sections_count", "I")
    directory_u1 = Field("directory_u1", "I", 5)
    section_uncompressed_lengths = Field("uncompressed_lengths", "I", _MAX_SECTIONS_COUNT)
    section_lengths = Field("section_lengths", "I", _MAX_SECTIONS_COUNT)
    section_indices = Field("section_indices", "I", _MAX_SECTIONS_COUNT)  # Beware that this contains null values (0's)
    section_compressed = Field("section_compressed", "I", _MAX_SECTIONS_COUNT)
    section_offsets = Field("section_offsets", "I", _MAX_SECTIONS_COUNT)
    directory_u7 = Field("directory_u7", "I")

    def keys(self):
        def all_keys():
            if hasattr(self, "sections"):
                for section in self.sections:
                    if hasattr(section, "KEY"):
                        yield section.KEY

        return list(all_keys())

    def from_buffer(self, buf: Buffer, **kwargs):
        super().from_buffer(buf, **kwargs)
        self.sections = []
        for i in range(self.sections_count):
            logging.debug("processing section {}".format(i))
            compressed = self.section_compressed[i] == 1
            length = self.section_lengths[i]
            index = self.section_indices[i]
            type = get_section_for_index(index, compressed)
            self.sections.append(type().from_buffer(self._buf, length=length))

        return self

    def indices(self):
        indices = []
        for i in self.section_indices:
            if i != 0:
                indices.append(i)
        return indices

    def __getitem__(self, item):
        if type(item) == str:
            for section in self.sections:
                if hasattr(section, "KEY"):
                    if item == section.KEY:
                        return section
        # access directory item by index
        if not item in self.section_indices:
            raise KeyError(item)
        i = self.section_indices.index(item)
        return self.sections[i]

    def __setitem__(self, key, value):
        if type(key) == str:
            for section in self.sections:
                if hasattr(section, "KEY"):
                    if key == section.KEY:
                        i = self.section_indices.index(section)
                        self.sections[i] = value
                        return
        # access directory item by index
        if not key in self.section_indices:
            raise KeyError(key)
        i = self.section_indices.index(key)
        self.sections[i] = value

    def unpack(self, force = False):
        for section in self.sections:
            section.unpack(force)

    def get_data(self):
        # TODO: more appropriate stub for yield_inequalities
        return None

    def pack(self, force = False):
        for section in self.sections:
            section.pack(force)

        # Lets keep things simple for now and not assume change in compressed and indices
        zeroes = Directory._MAX_SECTIONS_COUNT(self) - len(self.sections)

        accum = 0

        self.sections_count = len(self.sections)
        for i in range(self.sections_count):
            s = self.sections[i]
            if isinstance(s, MapSection):
                self.section_uncompressed_lengths[i] = s.size_of()
                self.section_lengths[i] = s.size_of()
                self.section_compressed[i] = 0
            elif isinstance(s, CompressedMapSection):
                self.section_uncompressed_lengths[i] = s.uncompressed_size
                self.section_lengths[i] = s.size_of()
                self.section_compressed[i] = 1

            self.section_offsets[i] = accum
            accum += int(self.section_lengths[i])

        for i in range(self.sections_count, Directory._MAX_SECTIONS_COUNT(self)):
            self.section_lengths[i] = 0
            self.section_uncompressed_lengths[i] = 0
            self.section_compressed[i] = 0
            self.section_indices[i] = 0
            self.section_offsets[i] = 0  # TODO check this

        self.size = accum
        self.directory_size = 3036 if self._MAX_SECTIONS_COUNT() == 150 else 2036

    def serialize_to_buffer(self, buf):
        self.pack()  # TODO: why is this here?

        super().serialize_to_buffer(buf)

        for i in range(len(self.sections)):  # TODO: should this not be section count?
            section = self.sections[i]
            logging.debug("serializing section {} with size {}".format(i, self.section_lengths[i]))
            section.serialize_to_buffer(buf)

    def _dump_spec(self):
        buf = csv.StringIO()

        writer = csv.DictWriter(buf, fieldnames=["uncompressed_length", "section_length", "section_index", "compressed",
                                                 "section_offset"])
        writer.writeheader()
        for i in range(len(self.sections)):
            writer.writerow(
                {"uncompressed_length": self.section_uncompressed_lengths[i], "section_length": self.section_lengths[i],
                 "section_index": self.section_indices[i], "compressed": self.section_compressed[i],
                 "section_offset": self.section_offsets[i]})

        return buf.getvalue().encode('ascii')

    def _load_spec(self, data: str):
        buf = csv.StringIO(data)

        reader = csv.DictReader(buf)
        i = 0
        for line in reader:
            self.section_uncompressed_lengths[i] = int(line['uncompressed_length'])
            self.section_lengths[i] = int(line['section_length'])
            self.section_indices[i] = int(line['section_index'])
            self.section_compressed[i] = int(line['compressed'])
            self.section_offsets[i] = int(line['section_offset'])
            i += 1

        self.sections_count = i

    def dump_to_folder(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

        write_to_file(os.path.join(path, "spec"), self._dump_spec())

        for i in range(len(self.sections)):
            write_to_file(os.path.join(path, str(self.section_indices[i])), self.sections[i].get_data())

        write_to_file(os.path.join(path, "directory_u1"), ints_to_byte_array(self.directory_u1))
        write_to_file(os.path.join(path, "directory_u7"), struct.pack("I", self.directory_u7))

    def load_from_folder(self, path):

        self.directory_u1 = list(bytes_to_int_array(read_file(os.path.join(path, "directory_u1"))))
        self.directory_u7 = list(bytes_to_int_array(read_file(os.path.join(path, "directory_u7"))))[0]

        self.section_uncompressed_lengths = [0] * self._MAX_SECTIONS_COUNT()
        self.section_lengths = [0] * self._MAX_SECTIONS_COUNT()
        self.section_indices = [0] * self._MAX_SECTIONS_COUNT()
        self.section_compressed = [0] * self._MAX_SECTIONS_COUNT()
        self.section_offsets = [0] * self._MAX_SECTIONS_COUNT()

        self._load_spec((pathlib.Path(path) / "spec").read_text('ascii'))

        self.sections = []
        for i in range(self.sections_count):
            sp = os.path.join(path, str(self.section_indices[i]))

            cls = get_section_for_index(self.section_indices[i], self.section_compressed[i] == 1)

            obj = cls()
            obj.set_data(read_file(sp))

            self.sections.append(obj)

        assert len(self.sections) == self.sections_count

        self.pack()

        return self

        #TODO: add pack() call to ensure validity of side-variables like size, crc32, and compressed_size?

    def yield_inequalities(self, other, with_pack=False, ignore_keys=None):
        # for ineq in super().yield_inequalities(other, with_pack, ignore_keys):
        #     yield ineq

        if self.section_indices == other.section_indices:
            for i in range(self.sections_count):
                da = self.sections[i].get_data()
                db = other.sections[i].get_data()
                n = min(len(da), len(db))
                diffs = [i for i in range(n) if da[i] != db[i]]
                if len(diffs) > 0:
                    yield "unequal values ({}/{} = {}) for section: {} in\n\tself: \n{}\n\tand other: \n{}".format(
                        len(diffs), n, round(len(diffs)/n, 2),
                        self.section_indices[i], '', '')

    def different_sections(self, other):
        if self.section_indices == other.section_indices:
            for i in range(self.sections_count):
                da = self.sections[i].get_data()
                db = other.sections[i].get_data()
                n = min(len(da), len(db))
                diffs = [i for i in range(n) if da[i] != db[i]]
                if len(diffs) > 0:
                    yield self.section_indices[i]
        else:
            return "ALL"


import os


class Map(Structure):
    magic = Field("magic", "I")
    preview_size = Field("preview_size",
                         "I")  # Not sure whether to move this in Preview, or leave it here. makes sense in preview from a manipulation perspective.
    preview = Field("preview", Preview)
    description = Field("description", Description)
    u1 = Field("u1", U1)
    u2 = Field("u2", U2)
    u3 = Field("u3", U3)
    u4 = Field("u4", U4)
    ud = Field("ud", "B", 4)

    directory = Field("directory", Directory)

    def unpack(self, force = False):
        self.preview.unpack(force)
        self.description.unpack(force)
        self.directory.unpack(force)
        self.u1.unpack(force)
        self.u2.unpack(force)
        self.u3.unpack(force)
        self.u4.unpack(force)

    def pack(self, force = False):
        self.magic = 0xFFFFFFFF
        self.preview.pack(force)
        self.preview_size = self.preview.size_of()
        self.description.pack(force)
        # self.description_size = self.preview.compressed_size + 4 + 4 + 4 + 8
        self.directory.pack(force)
        # self.directory_size = self.directory.length + 4
        self.u1.pack(force)
        self.u2.pack(force)
        self.u3.pack(force)
        self.u4.pack(force)

    def dump_to_folder(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

        write_to_file(os.path.join(path, "preview"), self.preview.get_data())
        write_to_file(os.path.join(path, "description"), self.description.get_data())
        write_to_file(os.path.join(path, "u1"), self.u1.get_data_as_bytearray())
        write_to_file(os.path.join(path, "u2"), self.u2.get_data_as_bytearray())
        write_to_file(os.path.join(path, "u3"), self.u3.get_data_as_bytearray())
        write_to_file(os.path.join(path, "u4"), self.u4.get_data_as_bytearray())
        write_to_file(os.path.join(path, "ud"), bytes(bytearray(self.ud)))
        self.directory.dump_to_folder(os.path.join(path, "sections"))

    def load_from_folder(self, path):
        self.preview = Preview()
        self.preview.set_data(read_file(os.path.join(path, "preview")))

        self.description = Description()
        self.description.set_data(read_file(os.path.join(path, "description")))

        self.u1 = U1()
        self.u1.set_data([v for v in read_file(os.path.join(path, "u1"))])

        self.u2 = U2()
        self.u2.set_data([v for v in read_file(os.path.join(path, "u2"))])

        self.u3 = U3()
        self.u3.set_data([v for v in read_file(os.path.join(path, "u3"))])

        self.u4 = U4()
        self.u4.set_data([v for v in read_file(os.path.join(path, "u4"))])

        self.ud = [v for v in read_file(os.path.join(path, "ud"))]

        self.directory = Directory()
        self.directory.load_from_folder(os.path.join(path, "sections"))

        return self

    def from_file(self, fp: str):
        with open(fp, 'rb') as f:
            return self.from_buffer(Buffer(f.read()))

    def to_file(self, fp: str):
        b = Buffer()
        self.serialize_to_buffer(b)
        with open(fp, 'wb') as f:
            f.write(b.getvalue())
