from .iotools import Buffer
from .maps import Map
import pathlib
import unittest
import sys


def entry_point():
    import runpy
    runpy.run_module(__name__)


def test():
    test_suite = unittest.TestLoader().discover(str(pathlib.Path(sys.prefix) / "sourcehold" / "tests" / '.'))
    unittest.TextTestRunner(descriptions=True, verbosity=2).run(test_suite)


def load_map(path, strict=True, unpack=True, force=False):
    buf = Buffer(pathlib.Path(path).read_bytes())
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
    pathlib.Path(path).write_bytes(buf.getvalue())


import json
import os

CONFIG = {'shc': 'C:/Program Files (x86)/FireFly Studios/Stronghold Crusader',
          'sh': 'C:/Program Files (x86)/FireFly Studios/Stronghold',
          'shc_user': '~/Documents/Stronghold Crusader',
          'sh_user': '~/Documents/Stronghold'}


def load_config(path=pathlib.Path("~").expanduser() / ".sourcehold" / 'config.json'):
    global CONFIG

    if not path.exists():
        path.parent.mkdir(parents=True)
        path.write_text(json.dumps(CONFIG))

    CONFIG = json.loads(path.read_text())

    CONFIG = {key: str(pathlib.Path(value).expanduser()) for key, value in CONFIG.items()}


load_config()

from sourcehold.maps.library import expand_var_path
