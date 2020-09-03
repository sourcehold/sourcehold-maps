import unittest
from sourcehold import structure_tools, maps
import pathlib


class TestMapSections(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:
        map_file = str(pathlib.Path("resources/map/crusader/MxM_unseen_1.map"))
        with open(map_file, 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.directory.unpack(False)

        cls.map = m

    def test_keyvalue_section(self):

        section = self.map.directory[1073]
        nonsense = section.manor_house + section.stone_keep

    def test_tile_section(self):

        section = self.map.directory[1001]
        nonsense = section.get_system()[0][0] + section.get_system()[1][1]
