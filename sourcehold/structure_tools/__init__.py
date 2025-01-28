
from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.structure_tools.Table import Table


import struct


def bytes_to_int_array(data: bytes):
    if len(data) % 4 != 0:
        raise Exception()
    buf = Buffer(data)
    while buf.remaining() > 0:
        yield struct.unpack("I", buf.read(4))[0]


def ints_to_byte_array(ints: list):
    buf = Buffer()
    for i in ints:
        buf.write(struct.pack("I", i))
    return buf.getvalue()

def _resolve_cls_as_type(cls) -> str:
    if cls == int:
        return "I"
    if cls == str:
        raise NotImplementedError()
    if cls == float:
        return "f"
    if cls == bytes:
        return "B"
    return cls

def create_structure_from_buffer(structure: type, buf: Buffer, **kwargs):
    self = structure()

    self.from_buffer(buf, **kwargs)

    return self


def dict_join(d1, d2):
    d = d1.copy()
    d.update(d2)
    return d


TABLE_TEST = Table(["A", "B", "C"], ["D", "E", "F"])
for i in range(len(TABLE_TEST.rownames)):
    TABLE_TEST.set(i, i, i * i)


