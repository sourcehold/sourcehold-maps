import binascii
import io
import logging
import struct

from PIL import Image

from sourcehold import compression, palette
from sourcehold.iotools import read_file, write_to_file, _int_array_to_bytes
from sourcehold.structure_tools import Structure, Variable


class SimpleSection(Structure):
    size = Variable("size", "I")
    data = Variable("data", "B", size)

    def pack(self):
        self.size = len(self.data)

    def unpack(self):
        assert len(self.data) == self.size

    def size_of(self):
        return self.size + 4


class U2(SimpleSection):

    def get_players_count(self):
        return self.data[24]

    def set_players_count(self, count):
        self.data = self.data[:24] + [count] + self.data[25:]


class U4(SimpleSection):

    def get_unbalanced_flag(self):
        return self.data[12]

    def set_unbalanced_flag(self, value : bool):
        if value:
            self.data = self.data[:12] + [1] + self.data[13:]
        else:
            self.data = self.data[:12] + [0] + self.data[13:]


class CompressedSection(Structure):
    uncompressed_size = Variable("uncompressed_size", "I")
    compressed_size = Variable("compressed_size", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = [i for i in compression.COMPRESSION.compress(self.uncompressed)]
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

    def set_data(self, data):
        self.uncompressed = data

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

    def set_image(self, image : Image):
        palette_size = 512

        width, height = 200, 200

        if image.mode != 'P':
            image = image.convert('P')
        if image.size != (width, height):
            image = image.resize((width, height))

        if (len(image.getpalette()) / 3) * 2 != 512:
            #raise Exception("Used too many colors, please stick to 256 colors")
            image = image.quantize(256) #TODO: mode P conversion may be redundant

        pal = palette.pack_palette_to_stream(image.getpalette())
        if len(pal) != 512:
            raise Exception("Invalid length: {}".format(len(pal)))

        self.uncompressed = pal + image.tobytes()


class Description(Structure):
    size = Variable("size", "I") #This structure in size, + compressed size
    use_string_table = Variable("use_string_table", "I")
    string_table_index = Variable("string_table_index", "I")
    uncompressed_size = Variable("uncompressed_size", "I")
    compressed_size = Variable("compressed_size", "I")
    hash = Variable("hash", "I")
    data = Variable("data", "B", compressed_size)

    def pack(self):
        self.data = [i for i in compression.COMPRESSION.compress(self.uncompressed)]
        self.hash = binascii.crc32(self.uncompressed)
        self.uncompressed_size = len(self.uncompressed)
        self.compressed_size = len(self.data)
        self.size = self.compressed_size + (5*4)

    def set_description(self, string : str):
        bstring = string.encode('ascii')
        if len(bstring) >= 1000:
            raise Exception("description text too long: {}".format(len(bstring)))

        padded = bstring + b'\x00' * (1000-len(bstring))
        self.uncompressed = padded
        self.uncompressed = self.uncompressed[:212] + b'\x04\x00?\x00????8?8? ??' + self.uncompressed[227:]
        #self.description_size = len(bstring)

    def get_description(self):
        j = len(self.uncompressed)

        while j > 0:
            j -= 1
            v = self.uncompressed[j]
            if v != 0:
                break

        return self.uncompressed[:j].decode('ascii')

    def unpack(self):
        self.uncompressed = compression.COMPRESSION.decompress(self.data)
        assert len(self.data) == self.compressed_size
        assert len(self.uncompressed) == self.uncompressed_size
        assert binascii.crc32(self.uncompressed) == self.hash
        assert self.compressed_size + (5*4) == self.size

    def get_data(self):
        if not hasattr(self, "uncompressed"):
            self.unpack()
        return self.uncompressed

    def size_of(self):
        return self.compressed_size + (6*4)


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


class CompressedMapSection(CompressedSection):
    pass


from sourcehold.maps.sections import find_section_for_index

import csv
from sourcehold.structure_tools import ints_to_byte_array, bytes_to_int_array, create_structure_from_buffer, Buffer


def get_section_for_index(index, compressed):
    cls = find_section_for_index(index)
    if cls:
        return cls

    if compressed == True:
        return CompressedMapSection
    else:
        return MapSection


class Directory(Structure):
    #Stronghold crusader has values 161, 168, or 170, or 172 if custom Stronghold
    #The version differ in the amount of sections, 150 or 100.
    _MAX_SECTIONS_COUNT = lambda obj: 150 if obj.directory_u1[0] >= 161 else 100
    directory_size = Variable("directory_size", "I")
    size = Variable("size", "I")
    sections_count = Variable("sections_count", "I")
    directory_u1 = Variable("directory_u1", "I", 5)
    uncompressed_lengths = Variable("uncompressed_lengths", "I", _MAX_SECTIONS_COUNT)
    section_lengths = Variable("section_lengths", "I", _MAX_SECTIONS_COUNT)
    section_indices = Variable("section_indices", "I", _MAX_SECTIONS_COUNT)
    section_compressed = Variable("section_compressed", "I", _MAX_SECTIONS_COUNT)
    section_offsets = Variable("section_offsets", "I", _MAX_SECTIONS_COUNT)
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
        #TODO: stub
        return self.section_indices

    def pack(self):
        for section in self.sections:
            section.pack()

        # Lets keep things simple for now and not assume change in compressed and indices
        zeroes = Directory._MAX_SECTIONS_COUNT(self) - len(self.sections)

        accum = 0

        self.sections_count = len(self.sections)
        for i in range(self.sections_count):
            s = self.sections[i]
            if s.__class__ == MapSection:
                self.uncompressed_lengths[i] = s.size_of()
                self.section_lengths[i] = s.size_of()
                self.section_compressed[i] = 0
            if s.__class__ == CompressedMapSection:
                self.uncompressed_lengths[i] = s.uncompressed_size
                self.section_lengths[i] = s.size_of()
                self.section_compressed[i] = 1

            self.section_offsets[i] = accum
            accum += self.section_lengths[i]

        for i in range(self.sections_count, Directory._MAX_SECTIONS_COUNT(self)):
            self.section_lengths[i] = 0
            self.uncompressed_lengths[i] = 0
            self.section_compressed[i] = 0
            self.section_indices[i] = 0
            self.section_offsets[i] = 0  # TODO check this

    def serialize_to_buffer(self, buf):
        self.pack()

        super().serialize_to_buffer(buf)

        for i in range(len(self.sections)): #TODO: should this not be section count?
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
        self.directory_u7 = bytes_to_int_array(read_file(os.path.join(path, "directory_u7")))[0]


    def yield_inequalities(self, other, with_pack = False, ignore_keys = None):
        for ineq in super().yield_inequalities(other, with_pack, ignore_keys):
            yield ineq

        if self.section_indices == other.section_indices:
            for i in range(self.sections_count):
                if self.sections[i].get_data() != other.sections[i].get_data():
                    yield "unequal values for section: {} in\n\tself: \n{}\n\tand other: \n{}".format(self.section_indices[i], '', '')


import os


class Map(Structure):
    magic = Variable("magic", "I")
    preview_size = Variable("preview_size", "I") #Not sure whether to move this in Preview, or leave it here. makes sense in preview from a manipulation perspective.
    preview = Variable("preview", Preview)
    description = Variable("description", Description)
    u1 = Variable("u1", SimpleSection)
    u2 = Variable("u2", U2)
    u3 = Variable("u3", SimpleSection)
    u4 = Variable("u4", U4)
    ud = Variable("ud", "B", 4)

    directory = Variable("directory", Directory)

    def unpack(self):
        self.preview.unpack()
        self.description.unpack()
        self.directory.unpack()

    def pack(self):
        self.preview.pack()
        self.preview_size = self.preview.size_of()
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
