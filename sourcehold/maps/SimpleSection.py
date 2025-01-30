from sourcehold.structure_tools.Field import Field
from sourcehold.structure_tools.Structure import Structure


class SimpleSection(Structure):
    size = Field("size", "I")
    data = Field("data", "B", size)

    def pack(self, force=False):
        self.size = len(self.data)

    def unpack(self, force=False):
        assert len(self.data) == self.size

    def size_of(self):
        return self.size + 4