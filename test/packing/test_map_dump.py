import unittest

from sourcehold import structure_tools, maps


class TestDump(unittest.TestCase):

    def test_dump(self):
        with open("resources/MxM_unseen_1.map", 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.unpack()
        m.directory.unpack()

        import tempfile

        dir = tempfile.TemporaryDirectory()

        path = dir.name

        m.dump_to_folder(path)

        dir.cleanup()
