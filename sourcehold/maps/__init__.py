import binascii
import io
import logging
import struct

from PIL import Image

from sourcehold import compression, palette
from sourcehold.structure_tools import Structure, Variable


class SimpleSection(Structure):
    size = Variable("size", "I")
    data = Variable("data", "B", size)

    def pack(self):
        self.size = len(self.data)

    def unpack(self):
        assert len(self.data) == self.size


class CompressedSection(Structure):
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


class Preview(Structure):
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

    def create_image(self) -> Image:
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


class Description(Structure):
    unknown1 = Variable("u1", "B", 4)
    unknown2 = Variable("u2", "B", 4)
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


class MapSection(Structure):

    def __init__(self):
        super().__init__()

    def from_buffer(self, buf, **kwargs):
        super().from_buffer(buf, **kwargs)
        if not 'length' in kwargs:
            raise KeyError()
        self.length = kwargs.get('length')
        self.data = buf.read(self.length)
        return self

    def pack(self):
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


class CompressedMapSection(Structure):
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


from sourcehold.maps.sections import Section1001, Section1003, Section1002

import csv
from sourcehold.structure_tools import ints_to_byte_array, bytes_to_int_array, create_structure_from_buffer, Buffer


def get_section_for_index(index, compressed):
    if index == 1001:
        return Section1001
    if index == 1002:
        return Section1002
    elif index == 1003:
        return Section1003
    if compressed == True:
        return CompressedMapSection
    else:
        return MapSection

class Directory(Structure):
    _AMOUNT_OF_SECTIONS = 122
    length = Variable("length", "I")
    sections_count = Variable("sections_count", "I")
    directory_u1 = Variable("directory_u1", "I", 5)
    uncompressed_lengths = Variable("uncompressed_lengths", "I", _AMOUNT_OF_SECTIONS)
    directory_u2 = Variable("directory_u2", "I", 28)
    section_lengths = Variable("section_lengths", "I", _AMOUNT_OF_SECTIONS)
    directory_u3 = Variable("directory_u3", "I", 28)
    section_indices = Variable("section_indices", "I", _AMOUNT_OF_SECTIONS)
    directory_u4 = Variable("directory_u4", "I", 28)
    section_compressed = Variable("section_compressed", "I", _AMOUNT_OF_SECTIONS)
    directory_u5 = Variable("directory_u5", "I", 28)
    section_offsets = Variable("section_offsets", "I", _AMOUNT_OF_SECTIONS)
    directory_u6 = Variable("directory_u6", "I", 28)
    directory_u7 = Variable("directory_u7", "I")

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

    def __getitem__(self, item):
        # access directory item by index
        if not item in self.section_indices:
            raise KeyError(item)
        i = self.section_indices.index(item)
        return self.sections[i]

    def __setitem__(self, key, value):
        # access directory item by index
        if not key in self.section_indices:
            raise KeyError(key)
        i = self.section_indices.index(key)
        self.sections[i] = value

    def unpack(self):
        for section in self.sections:
            section.unpack()

    def get_data(self):
        raise NotImplementedError()

    def pack(self):
        for section in self.sections:
            section.pack()

        # Lets keep things simple for now and not change compressed and indices
        zeroes = Directory._AMOUNT_OF_SECTIONS - len(self.sections)

        accum = 0

        self.sections_count = len(self.sections)
        for i in range(self.sections_count):
            s = self.sections[i]
            if s.__class__ == MapSection:
                self.uncompressed_lengths[i] = s.length
                self.section_lengths[i] = s.length
                self.section_compressed[i] = 0
            if s.__class__ == CompressedMapSection:
                self.uncompressed_lengths[i] = s.uncompressed_size
                self.section_lengths[i] = s.compressed_size + 12  # important!
                self.section_compressed[i] = 1

            self.section_offsets[i] = accum
            accum += self.section_lengths[i]

        for i in range(self.sections_count, Directory._AMOUNT_OF_SECTIONS):
            self.section_lengths[i] = 0
            self.uncompressed_lengths[i] = 0
            self.section_compressed[i] = 0
            self.section_indices[i] = 0
            self.section_offsets[i] = 0  # TODO check this

    def serialize_to_buffer(self, buf):
        self.pack()

        super().serialize_to_buffer(buf)

        for i in range(len(self.sections)):
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
                {"uncompressed_length": self.uncompressed_lengths[i], "section_length": self.section_lengths[i],
                 "section_index": self.section_indices[i], "compressed": self.section_compressed[i],
                 "section_offset": self.section_offsets[i]})

        return buf.getvalue().encode('ascii')

    def _load_spec(self, data: bytes):
        buf = csv.StringIO(data.decode('ascii'))

        reader = csv.DictReader(buf, fieldnames=["uncompressed_length", "section_length", "section_index", "compressed",
                                                 "section_offset"])
        i = 0
        for line in reader:
            self.uncompressed_lengths[i] = line['uncompressed_length']
            self.section_lengths[i] = line['section_length']
            self.section_indices[i] = line['section_index']
            self.section_compressed[i] = line['compressed']
            self.section_offsets[i] = line['section_offset']
            i += 1

        self.sections_count = i

    def dump_to_folder(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

        write_to_file(os.path.join(path, "spec"), self._dump_spec())

        for i in range(len(self.sections)):
            write_to_file(os.path.join(path, str(self.section_indices[i])), self.sections[i].get_data())

        write_to_file(os.path.join(path, "directory_u1"), ints_to_byte_array(self.directory_u1))
        write_to_file(os.path.join(path, "directory_u2"), ints_to_byte_array(self.directory_u2))
        write_to_file(os.path.join(path, "directory_u3"), ints_to_byte_array(self.directory_u3))
        write_to_file(os.path.join(path, "directory_u4"), ints_to_byte_array(self.directory_u4))
        write_to_file(os.path.join(path, "directory_u5"), ints_to_byte_array(self.directory_u5))
        write_to_file(os.path.join(path, "directory_u6"), ints_to_byte_array(self.directory_u6))
        write_to_file(os.path.join(path, "directory_u7"), struct.pack("I", self.directory_u7))

    @staticmethod
    def load_from_folder(path):

        self = Directory()
        self._load_spec(read_file(os.path.join(path, "spec")))

        self.sections = []
        for i in range(self.sections_count):
            path = os.path.join(path, str(self.section_indices[i]))
            if self.section_compressed == 1:
                self.sections.append(create_structure_from_buffer(CompressedMapSection, Buffer(read_file(path))))
            else:
                buf = Buffer(read_file(path))
                m = create_structure_from_buffer(MapSection, buf)
                m.data = buf.read()
                m.length = len(m.data)
                self.sections.append(m)

        assert len(self.sections) == self.sections_count

        self.directory_u1 = bytes_to_int_array(read_file(os.path.join(path, "directory_u1")))
        self.directory_u2 = bytes_to_int_array(read_file(os.path.join(path, "directory_u2")))
        self.directory_u3 = bytes_to_int_array(read_file(os.path.join(path, "directory_u3")))
        self.directory_u4 = bytes_to_int_array(read_file(os.path.join(path, "directory_u4")))
        self.directory_u5 = bytes_to_int_array(read_file(os.path.join(path, "directory_u5")))
        self.directory_u6 = bytes_to_int_array(read_file(os.path.join(path, "directory_u6")))
        self.directory_u7 = bytes_to_int_array(read_file(os.path.join(path, "directory_u7")))[0]


import os


def read_file(path):
    with open(path, 'rb') as f:
        return f.read()

def write_to_file(path, data):
    with open(path, 'wb') as f:
        f.write(data)


def _int_array_to_bytes(array):
    return b''.join(struct.pack("B", v) for v in array)


class Map(Structure):
    magic = Variable("magic", "I")
    preview_size = Variable("preview_size", "I")
    preview = Variable("preview", Preview)
    description_size = Variable("description_size", "I")
    description = Variable("description", Description)
    u1 = Variable("u1", SimpleSection)
    u2 = Variable("u2", SimpleSection)
    u3 = Variable("u3", SimpleSection)
    u4 = Variable("u4", SimpleSection)
    ud = Variable("ud", "B", 4)
    directory_size = Variable("ds", "I")
    directory = Variable("directory", Directory)

    def unpack(self):
        self.preview.unpack()
        self.description.unpack()
        self.directory.unpack()

    def pack(self):
        self.preview.pack()
        # self.preview_size = self.preview.compressed_size + 4 + 4 + 4
        self.description.pack()
        # self.description_size = self.preview.compressed_size + 4 + 4 + 4 + 8
        self.directory.pack()
        #self.directory_size = self.directory.length + 4

    def dump_to_folder(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

        write_to_file(os.path.join(path, "preview"), self.preview.get_data())
        write_to_file(os.path.join(path, "description"), self.description.get_data())
        write_to_file(os.path.join(path, "u1"), _int_array_to_bytes(self.u1.get_data()))
        write_to_file(os.path.join(path, "u2"), _int_array_to_bytes(self.u2.get_data()))
        write_to_file(os.path.join(path, "u3"), _int_array_to_bytes(self.u3.get_data()))
        write_to_file(os.path.join(path, "u4"), _int_array_to_bytes(self.u4.get_data()))
        write_to_file(os.path.join(path, "ud"), _int_array_to_bytes(self.ud))
        self.directory.dump_to_folder(os.path.join(path, "sections"))

    def load_from_folder(self, path):
        self.preview = Preview()
        self.preview.uncompressed = read_file(os.path.join(path, "preview"))

        self.description = Description()
        self.description.uncompressed = read_file(os.path.join(path, "description"))

        self.u1 = bytes_to_int_array(read_file(os.path.join(path, "u1")))
        self.u2 = bytes_to_int_array(read_file(os.path.join(path, "u2")))
        self.u3 = bytes_to_int_array(read_file(os.path.join(path, "u3")))
        self.u4 = bytes_to_int_array(read_file(os.path.join(path, "u4")))
        self.ud = bytes_to_int_array(read_file(os.path.join(path, "ud")))

        self.directory = Directory.load_from_folder(os.path.join(path, "sections"))

    def from_file(self, fp: str):
        with open(fp, 'rb') as f:
            return self.from_buffer(Buffer(f.read()))

    def to_file(self, fp: str):
        b = Buffer()
        self.serialize_to_buffer(b)
        with open(fp, 'wb') as f:
            f.write(b.getvalue())
