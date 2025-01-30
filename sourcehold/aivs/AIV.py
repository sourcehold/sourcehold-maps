from sourcehold.aivs.AIVDirectory import AIVDirectory
from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.structure_tools.Field import Field
from sourcehold.structure_tools.Structure import Structure


import os


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