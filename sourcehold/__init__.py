from .iotools import Buffer
from .iotools import read_file
from .iotools import write_to_file
from .maps import Map


def load_map(path, strict=True, unpack=True, force=False):
    buf = Buffer(read_file(path))
    map = Map().from_buffer(buf)
    if strict:
        if buf.remaining() != 0:
            raise Exception("Error, bytes remaining at end of buffer")
    if unpack:
        map.unpack(force)
    return map


def save_map(map, path, pack=True, force=False):
    buf = Buffer()
    if pack:
        map.pack(force)
    map.serialize_to_buffer(buf)
    write_to_file(path, buf.getvalue())


import json
import os

CONFIG = {'shc': 'C:/Program Files (x86)/FireFly Studios/Stronghold Crusader',
          'sh': 'C:/Program Files (x86)/FireFly Studios/Stronghold',
          'shc_user': '~/Documents/Stronghold Crusader',
          'sh_user': '~/Documents/Stronghold'}


def load_config(path='config.json'):
    global CONFIG

    if not os.path.exists(path):
        with open(path, 'w') as f:
            json.dump(CONFIG, f)

    with open(path, 'r') as f:
        CONFIG = json.load(f)

    CONFIG = {key: os.path.expanduser(value) for key, value in CONFIG.items()}


load_config()

from sourcehold.maps.library import SHC_FILES, SHC_FILES_USER, SH_FILES, SH_FILES_USER, expand_var_path
