import maps
import structure_tools
import unittest


class TestDump(unittest.TestCase):

    def test_dump(self):
        with open("resources/MxM_unseen_1.map", 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map(buf)
        m.unpack()
        m.directory.unpack()

        import tempfile

        dir = tempfile.TemporaryDirectory()

        path = dir.name

        m.dump_to_folder(path)

        dir.cleanup()
