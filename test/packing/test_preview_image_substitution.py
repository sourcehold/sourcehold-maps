import PIL.Image as I
import unittest
import pathlib
from sourcehold.maps import Map, Buffer


class T(unittest.TestCase):

    def test_preview_image_replacement(self):
        m = Map().from_buffer(Buffer(pathlib.Path("resources/map/crusader/MxM_unseen_1.map").read_bytes()))
        img = I.new(mode='P', size=(200,200), color=0)
        m.preview.set_image(img)
