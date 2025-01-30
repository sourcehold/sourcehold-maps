from sourcehold.structure_tools.Structure import Structure


import logging


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