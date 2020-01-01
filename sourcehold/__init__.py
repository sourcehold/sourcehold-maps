
from .maps import Map
from .iotools import Buffer
from .iotools import read_file
from .iotools import write_to_file


def load_map(path):
    map = Map().from_buffer(Buffer(read_file(path)))
    map.unpack()
    return map


def save_map(map, path):
    buf = Buffer()
    map.pack()
    map.serialize_to_buffer(buf)
    write_to_file(path, buf.getvalue())