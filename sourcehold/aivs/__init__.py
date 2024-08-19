
import csv
import logging
import os
import pathlib
import struct
from sourcehold.aivs.sections import AIVSection, CompressedAIVSection, get_section_for_index
from sourcehold.iotools import read_file, write_to_file
from sourcehold.maps import CompressedSection
from sourcehold.structure_tools import Buffer, Field, Structure, bytes_to_int_array, ints_to_byte_array



class AIVDirectory1(Structure):
    pass

class AIVDirectory(Structure):
    # Stronghold crusader has values 161, 168, or 170, or 172 if custom Stronghold
    # The version differ in the amount of sections, 150 or 100.
    _MAX_SECTIONS_COUNT = lambda v: 100
    directory_size = Field("directory_size", "I")
    size = Field("size", "I")
    sections_count = Field("sections_count", "I")
    version_number = Field("version_number", "I")
    directory_u1 = Field("directory_u1", "I", 4)
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
        # zeroes = AIVDirectory._MAX_SECTIONS_COUNT(self) - len(self.sections)

        accum = 0

        self.sections_count = len(self.sections)
        for i in range(self.sections_count):
            s = self.sections[i]
            if isinstance(s, AIVSection):
                self.section_uncompressed_lengths[i] = s.size_of()
                self.section_lengths[i] = s.size_of()
                self.section_compressed[i] = 0
            elif isinstance(s, CompressedAIVSection):
                self.section_uncompressed_lengths[i] = s.uncompressed_size
                self.section_lengths[i] = s.size_of()
                self.section_compressed[i] = 1

            self.section_offsets[i] = accum
            accum += int(self.section_lengths[i])

        for i in range(self.sections_count, AIVDirectory._MAX_SECTIONS_COUNT(self)):
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

        write_to_file(os.path.join(path, 'directory_version_number'), struct.pack("I", self.version_number))
        write_to_file(os.path.join(path, "directory_u1"), ints_to_byte_array(self.directory_u1))
        write_to_file(os.path.join(path, "directory_u7"), struct.pack("I", self.directory_u7))

    def load_from_folder(self, path):
        self.version_number = list(bytes_to_int_array(read_file(os.path.join(path, "directory_version_number"))))[0]
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
        

class AIV(Structure):
    directory = Field("directory", AIVDirectory)
    
    def unpack(self, force = False):
        self.directory.unpack(force)

    def pack(self, force = False):
        self.directory.pack(force)

    def dump_to_folder(self, path):
        if not os.path.exists(path):
            os.makedirs(path)

        self.directory.dump_to_folder(os.path.join(path, "sections"))

    def load_from_folder(self, path):

        self.directory = AIVDirectory()
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
