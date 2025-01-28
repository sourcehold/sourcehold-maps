import unittest

from sourcehold.structure_tools import Buffer
from sourcehold.maps import Map

class TestEqual(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:
        with open("resources/map/crusader/MxM_unseen_1.map", 'rb') as f:
            cls.raw1 = f.read()
            buf = Buffer(cls.raw1)

        m = Map().from_buffer(buf)
        m.unpack()
        m.directory.unpack()

        buf2 = Buffer()
        m.serialize_to_buffer(buf2)
        cls.m = m
        cls.buf2 = buf2

    def test_equal(self):
        self.assertEqual(TestEqual.raw1, TestEqual.buf2.getvalue())

    def test_packing(self):
        m1 = Map().from_buffer(Buffer(TestEqual.raw1))
        m1.unpack()
        m2 = Map().from_buffer(Buffer(TestEqual.raw1))
        m2.unpack()

        m2.pack()
        gen = m1.yield_inequalities(m2)

        for ineq in gen:
            self.fail("not equal: {}".format(ineq))
