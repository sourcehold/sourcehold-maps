import maps
import structure_tools
import unittest


class TestEqual(unittest.TestCase):

    def test_equal(self):
        with open("resources/MxM_unseen_1.map", 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map(buf)
        m.unpack()
        m.directory.unpack()

        buf2 = structure_tools.Buffer()
        m.serialize_to_buffer(buf2)

        self.assertEqual(buf.getvalue(), buf2.getvalue())
