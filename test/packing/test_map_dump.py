import unittest
import tempfile

from sourcehold import structure_tools, maps


class TestDump(unittest.TestCase):

    def test_dump(self):
        with open("resources/map/crusader/MxM_unseen_1.map", 'rb') as f:
            raw1 = f.read()
            buf = structure_tools.Buffer(raw1)

        m = maps.Map().from_buffer(buf)
        m.unpack(force=True)

        tempdir = tempfile.TemporaryDirectory()

        path = tempdir.name

        m.dump_to_folder(path)
        tempdir.cleanup()
