import struct

from structure_tools import Buffer


def unpack(type: str, data: bytes, amount=0):
    if amount == 0:
        first, *rest = struct.unpack(type, data)
        assert len(rest) == 0
        return first
    else:
        type = str(amount) + type
        first, *rest = struct.unpack(type, data)
        return [first] + rest


def unpack_from(type: str, data: Buffer, amount=0):
    size = struct.calcsize(type)
    if amount == 0:
        return unpack(type, data.read(size), amount)
    else:
        return unpack(type, data.read(size * amount), amount)
