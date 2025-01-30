from sourcehold.iotools import read_file, write_to_file
from sourcehold.maps.Description import Description
from sourcehold.maps.Directory import Directory
from sourcehold.maps.Preview import Preview
from sourcehold.maps.U1 import U1
from sourcehold.maps.U2 import U2
from sourcehold.maps.U3 import U3
from sourcehold.maps.U4 import U4
from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.structure_tools.Field import Field
from sourcehold.structure_tools.Structure import Structure


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
        write_to_file(os.path.join(path, "u1"), self.u1.get_data())
        write_to_file(os.path.join(path, "u2"), self.u2.get_data())
        write_to_file(os.path.join(path, "u3"), self.u3.get_data())
        write_to_file(os.path.join(path, "u4"), self.u4.get_data())
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