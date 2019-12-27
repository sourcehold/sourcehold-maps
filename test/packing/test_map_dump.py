import unittest

from sourcehold import structure_tools, maps

with open("resources/MxM_unseen_1.map", 'rb') as f:
    raw1 = f.read()
    buf = structure_tools.Buffer(raw1)

m = maps.Map().from_buffer(buf)
m.unpack()
m.directory.unpack()

import tempfile

dir = tempfile.TemporaryDirectory()

path = dir.name



class TestDump(unittest.TestCase):

    def test_dump(self):
        m.dump_to_folder(path)
        dir.cleanup()

