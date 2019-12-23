import unittest

from sourcehold import compression


class TestCompression(unittest.TestCase):

    def test_equality(self):
        with open("resources/MxM_unseen_1.map", 'rb') as f:
            data = f.read()[20:20 + 10217]

        self.assertEqual(data, compression.COMPRESSION.compress(compression.COMPRESSION.decompress(data)))
