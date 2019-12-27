import unittest

from sourcehold import structure_tools, maps


with open("resources/MxM_unseen_1.map", 'rb') as f:
    raw1 = f.read()
    buf = structure_tools.Buffer(raw1)

m = maps.Map().from_buffer(buf)
m.unpack()
m.directory.unpack()

buf2 = structure_tools.Buffer()
m.serialize_to_buffer(buf2)

class TestEqual(unittest.TestCase):

    def test_equal(self):
        self.assertEqual(raw1, buf2.getvalue())

    def test_equal_description_change(self):
        dirbuf1 = structure_tools.Buffer()
        dirbuf2 = structure_tools.Buffer()

        m.directory.serialize_to_buffer(dirbuf1)
        m.description.uncompressed = b''

        m.pack()

        m.directory.serialize_to_buffer(dirbuf2)

        self.assertEqual(dirbuf1.getvalue(), dirbuf2.getvalue())
