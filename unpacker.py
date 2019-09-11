import binascii
import os
import struct
import subprocess


class ImportHelper(object):
    MAP_PATH = os.path.expanduser("~/Documents/Stronghold Crusader/Maps")

    def __init__(self):
        pass

    def _fix_mapname(self, mapname):
        if not mapname.endswith(".map"):
            return mapname + ".map"
        return mapname

    def _get_name_for_mapname(self, mapname):
        while mapname.endswith(".map"):
            mapname = mapname[:-4]
        return mapname

    def get_path_to(self, mapname):
        return os.path.join(ImportHelper.MAP_PATH, self._fix_mapname(mapname))

    def get_file_handle(self, mapname):
        return open(self.get_path_to(mapname), 'rb')

    def load(self, mapname):
        return MapStructure(0, self.get_file_handle(mapname).read())

    def get_library_path_to(self, mapname):
        return "file_inspection/maps/{}".format(self._get_name_for_mapname(mapname))

    def dump_to_library(self, mapname):
        return self.load(mapname).dump_to_folder(self.get_library_path_to(mapname))

    def exists_in_library(self, mapname):
        return os.path.exists(self.get_library_path_to(mapname))

BLAST_PATH = "resources/blast.exe"


def decompress(data: bytes):
    result = subprocess.run(BLAST_PATH, input=data, stdout=subprocess.PIPE)
    result.check_returncode()
    return result.stdout


from structure_tools import Buffer


#
# class Buffer(io.BytesIO):
#
#     def __init__(self, initial_bytes=b''):
#         super().__init__(initial_bytes)
#         self.bytes_length = len(initial_bytes)
#
#     def read(self, size=-1):
#         # if size == -1:
#         #     return super().read(size)
#         d = super().read(size)
#         if len(d) < size:
#             raise Exception("Data underflow. Expected {} bytes, but got {}".format(size, len(d)))
#         return d
#
#     def write(self, b):
#         raise NotImplementedError()
#
#     def remaining(self):
#         return self.bytes_length - self.tell()


class CompressedSection(object):

    def __init__(self):
        self.decompressed = None
        self.crc32 = None

    def decompress(self):
        if self.decompressed == None:
            self.decompressed = decompress(self.compressed_data)
        return self.decompressed

    def verify(self, signature=None):
        if signature != None:
            return binascii.crc32(self.decompress()) == signature
        if self.crc32 == None:
            raise Exception("No signature to compare with specified")
        return binascii.crc32(self.decompress()) == self.crc32


class PreviewSection(CompressedSection):

    def __init__(self, offset, raw):
        super().__init__()
        self.offset = (offset, offset + len(raw))
        self.raw = raw
        self.buf = Buffer(raw)
        self.uncompressed_size = struct.unpack("<I", self.buf.read(4))[0]
        self.compressed_size = struct.unpack("<I", self.buf.read(4))[0]
        self.crc32 = struct.unpack("<I", self.buf.read(4))[0]
        self.compressed_data = self.buf.read(self.compressed_size)

        assert self.buf.remaining() == 0


class MetaSection(object):
    AMOUNT_OF_SECTIONS = 122

    def __init__(self, offset, raw):
        self.offset = (offset, offset + len(raw))
        self.raw = raw
        self.buf = Buffer(raw)
        self.data_size = struct.unpack("<I", self.buf.read(4))[0]
        self.sections_count = struct.unpack("<I", self.buf.read(4))[0]
        self.unknown_data = [struct.unpack("<I", self.buf.read(4))[0] for i in range(5)]
        self.uncompressed_lengths = [struct.unpack("<I", self.buf.read(4))[0] for i in
                                     range(MetaSection.AMOUNT_OF_SECTIONS)]
        self.unknown_data_2 = [struct.unpack("<I", self.buf.read(4))[0] for i in range(28)]
        self.compressed_section_lengths = [struct.unpack("<I", self.buf.read(4))[0] for i in
                                           range(MetaSection.AMOUNT_OF_SECTIONS)]
        self.unknown_data_3 = [struct.unpack("<I", self.buf.read(4))[0] for i in range(28)]
        self.section_indices = [struct.unpack("<I", self.buf.read(4))[0] for i in range(MetaSection.AMOUNT_OF_SECTIONS)]
        self.unknown_data_4 = [struct.unpack("<I", self.buf.read(4))[0] for i in range(28)]
        self.section_compressed = [struct.unpack("<I", self.buf.read(4))[0] for i in
                                   range(MetaSection.AMOUNT_OF_SECTIONS)]
        self.unknown_data_5 = [struct.unpack("<I", self.buf.read(4))[0] for i in range(28)]
        self.section_offsets = [struct.unpack("<I", self.buf.read(4))[0] for i in range(MetaSection.AMOUNT_OF_SECTIONS)]
        self.unknown_data_6 = [struct.unpack("<I", self.buf.read(4))[0] for i in range(28)]
        self.unknown_7 = self.buf.read(4)

        self.finish = self.buf.tell() + offset

        if self.buf.remaining() > 0:
            print("warning: {} has bytes remaining: {}\n{}".format(self.__class__.__name__, self.buf.remaining(),
                                                                   self.buf.read()))


class DescriptionSection(CompressedSection):

    def __init__(self, offset, raw):
        super().__init__()
        self.offset = (offset, offset + len(raw))
        self.raw = raw
        self.buf = Buffer(raw)
        self.unknown_1 = self.buf.read(4)
        self.unknown_2 = self.buf.read(4)
        self.decompressed_size = struct.unpack("<I", self.buf.read(4))[0]
        self.compressed_size = struct.unpack("<I", self.buf.read(4))[0]
        self.crc32 = struct.unpack("<I", self.buf.read(4))[0]
        self.compressed_data = self.buf.read(self.compressed_size)

        if self.buf.remaining() > 0:
            print("warning: {} has bytes remaining: {}".format(self.__class__.__name__, self.buf.remaining()))

class CompressedDataSection(CompressedSection):

    def __init__(self, raw):
        super().__init__()
        self.raw = raw
        self.buf = Buffer(raw)
        self.decompressed_size = struct.unpack("<I", self.buf.read(4))[0]
        self.compressed_size = struct.unpack("<I", self.buf.read(4))[0]
        self.crc32 = struct.unpack("<I", self.buf.read(4))[0]
        self.compressed_data = self.buf.read(self.compressed_size)

        if self.buf.remaining() > 0:
            print("warning: {} has bytes remaining: {}".format(self.__class__.__name__, self.buf.remaining()))


class UncompressedDataSection(object):

    def __init__(self, raw):
        self.raw = raw
        self.decompressed = raw

    def verify(self):
        return True


class MapStructure(object):

    def __init__(self, offset, raw):
        self.offset = offset
        self.raw = raw
        self.buf = Buffer(raw)
        self.magic_value = struct.unpack("<I", self.buf.read(4))[0]
        print("Processing preview")
        self.preview_section = PreviewSection(self.buf.tell() + 4,
                                              self.buf.read(struct.unpack("<I", self.buf.read(4))[0]))
        print("Processing description")
        self.description_section = DescriptionSection(self.buf.tell() + 4,
                                                      self.buf.read(struct.unpack("<I", self.buf.read(4))[0]))
        self.section_unknown_1 = self.buf.read(struct.unpack("<I", self.buf.read(4))[0])
        self.section_unknown_2 = self.buf.read(struct.unpack("<I", self.buf.read(4))[0])
        self.section_unknown_3 = self.buf.read(struct.unpack("<I", self.buf.read(4))[0])
        self.section_unknown_4 = self.buf.read(struct.unpack("<I", self.buf.read(4))[0])
        self.data_unknown_1 = self.buf.read(4)
        print("Processing meta section")
        self.meta_section_size = struct.unpack("<I", self.buf.read(4))[0] - 4
        self.meta_section = MetaSection(self.buf.tell(), self.buf.read(self.meta_section_size))

        # self.buf.seek(self.buf.tell()-4) # I am not sure why this is needed

        self.sections = []

        for i in range(self.meta_section.sections_count):
            length = self.meta_section.compressed_section_lengths[i]
            compressed = self.meta_section.section_compressed[i]
            print("Adding section: {}, length: {}, compressed: {}".format(i, length, compressed))
            if compressed == 1:
                self.sections.append(CompressedDataSection(self.buf.read(length)))
            elif compressed == 0:
                self.sections.append(UncompressedDataSection(self.buf.read(length)))

        self.sections_dict = {}
        for i in range(self.meta_section.sections_count):
            index = self.meta_section.section_indices[i]
            self.sections_dict[index] = self.sections[i]

    def verify(self):
        return [self.magic_value == 0xFFFFFFFF, self.preview_section.verify(), self.description_section.verify()] + [
            section.verify() for section in self.sections]

    def reordered(self):
        rindex = [self.meta_section.section_indices.index(v) for v in sorted(self.meta_section.section_indices)]
        return [self.sections[index] for index in rindex]

    def dump_to_folder(self, path):
        self.verify()
        import os
        if not os.path.exists(path):
            os.makedirs(path)
        with open(path + "/preview.png", 'wb') as f:
            from PIL import Image
            import palette
            b = Buffer(self.preview_section.decompressed)
            p = palette.build_serial_palette(b)
            width = height = int(b.remaining() ** 0.5)
            image = Image.new("P", (width, height))
            image.putpalette(p)
            image.putdata(b.read())
            image.save(f)
        with open(path + "/section_unknown_1.dat", 'wb') as f:
            f.write(self.section_unknown_1)
        with open(path + "/section_unknown_2.dat", 'wb') as f:
            f.write(self.section_unknown_2)
        with open(path + "/section_unknown_3.dat", 'wb') as f:
            f.write(self.section_unknown_3)
        with open(path + "/section_unknown_4.dat", 'wb') as f:
            f.write(self.section_unknown_4)
        with open(path + "/data_unknown_1.dat", 'wb') as f:
            f.write(self.data_unknown_1)
        with open(path + "/description.txt", 'wb') as f:
            f.write(self.description_section.decompressed)
        with open(path + "/description_unknown_1.dat", 'wb') as f:
            f.write(self.description_section.unknown_1)
        with open(path + "/description_unknown_2.dat", 'wb') as f:
            f.write(self.description_section.unknown_2)
        for i in range(self.meta_section.sections_count):
            index = self.meta_section.section_indices[i]

            with open(path + "/" + str(index) + ".dat", 'wb') as f:
                f.write(self.sections[i].decompressed)


def unpack_map(path, into):
    print("reading file")
    with open(path, 'rb') as f:
        data = f.read()

    # with open("resources/SxS_unseen_2_resave2.map", 'rb') as f:
    #     data = f.read()

    print("parsing file")
    m = MapStructure(0, data)

    print("verifying file")
    verifications = m.verify()
    for i in range(len(verifications)):
        if not verifications[i]:
            print("section number {} has an invalid crc32".format(i))

    print("checking no data is left")
    assert m.buf.remaining() == 0

    print("dumping to folder")
    m.dump_to_folder(into)

    print("done")
    return m


import sys, os

if __name__ == "__main__":

    srcpath = None
    dstpath = None

    if len(sys.argv) == 1:
        raise Exception("Not enough arguments")

    elif len(sys.argv) == 2:
        srcpath = sys.argv[1]
        dstpath = "unpacked/" + os.path.split(srcpath)[1].split(".")[0]

    elif len(sys.argv) == 3:
        srcpath = sys.argv[1]
        dstpath = sys.argv[2]

    print("unpacking map from: {} to {}".format(srcpath, dstpath))

    unpack_map(srcpath, dstpath)
