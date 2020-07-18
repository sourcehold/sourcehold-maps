
import unittest, os

from sourcehold.maps.sections.tools import TileIndexTranslator
from sourcehold.maps.sections import TileSystem
from sourcehold import load_map, expand_var_path
import random


class TestCoordinates(unittest.TestCase):

    def test_tile_index_translator(self):
        m = load_map(expand_var_path("shcusermap~/xlcr.map"))

        ts = m.directory.sections[0].get_system()

        tit = TileIndexTranslator(square_size=400)
        self.assertEqual(tit.translate_file_index_to_game_tile_index(0, 0), 199)
        self.assertEqual(tit.translate_game_tile_index_to_file_index(199), (0, 0))

        r = random.randint(0, (400*400)-1)
        r = 54464
        titi, titj = tit.translate_game_tile_index_to_file_index(r)
        ts.get_tile_number_for_index((titi, titj))


        self.assertEqual((0, 199), ts.get_index_for_tile_number(0, True))
        ts.get_tile_number_for_index((0, 0))

        self.assertEqual(m.directory.sections[0].get_system().get_tile_number_for_index((2, 199), True), 8)
        self.assertEqual(12, m.directory.sections[0].get_system().get_tile_number_for_index((3, 0), False))
        self.assertEqual(12, m.directory.sections[0].get_system().get_tile_number_for_index((3, 196), True))
        self.assertEqual(12, m.directory.sections[0].get_system().get_tile_number_for_index((3, 196), True))