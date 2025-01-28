import struct

from sourcehold.structure_tools.Buffer import Buffer


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


def read_file(path):
    with open(path, 'rb') as f:
        return f.read()


def write_to_file(path, data):
    with open(path, 'wb') as f:
        f.write(data)


def _int_array_to_bytes(array):
    return b''.join(struct.pack("B", v) for v in array)
