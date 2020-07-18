import unittest

from sourcehold import *
from sourcehold import structure_tools
from sourcehold.maps.sections.objects import Building
import os


class TestBuildings(unittest.TestCase):

    def test_persistence(self):
        map_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "..", "resources", "MxM_unseen_1.map")
        with open(map_file, 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.directory[1013].unpack(True)

        m.directory[1013][0] = Building().from_buffer(Buffer(b'\x00' * Building.size_of()))
        m.directory[1013][0].building_id = 9000
        m.directory[1013].pack(True)

        m.directory.pack()

        buf2 = structure_tools.Buffer()
        m.serialize_to_buffer(buf2)

        buf2.seek(0)

        m2 = maps.Map().from_buffer(buf2)
        m2.directory[1013].unpack(True)
        self.assertEqual(m2.directory[1013][0].building_id, m.directory[1013][0].building_id)
