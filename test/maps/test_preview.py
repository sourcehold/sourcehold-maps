import os
import unittest

from PIL import Image

from sourcehold import structure_tools, maps


class TestPreview(unittest.TestCase):

    def test_create_image(self):
        map_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "resources", "MxM_unseen_1.map")
        with open(map_file, 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.unpack()

        test_image = m.preview.create_image()

        expected_image_file = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                                           "..", "..", "resources", "MxM_unseen_1.png")
        expected_image = Image.open(expected_image_file)

        self.assertIsNotNone(test_image)
        self.assertEqual(list(expected_image.getdata()), list(test_image.getdata()))


if __name__ == "__main___":
    unittest.main()
