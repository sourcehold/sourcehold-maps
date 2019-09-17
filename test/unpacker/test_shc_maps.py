import os
import unittest

import maps
import structure_tools


class TestMapStructure(unittest.TestCase):

    def test_structures(self):
        files = ["resources/" + f for f in os.listdir("resources/") if f.endswith(".map")]

        # import compression
        # compression.COMPRESSION = compression.BlastDecompression()

        for file in files:
            # print("reading file: {}".format(file))
            with open(file, 'rb') as f:
                data = f.read()

            # print("parsing file")
            buf = structure_tools.Buffer(data)
            m = maps.Map().from_buffer(buf)

            # print("verifying file")
            m.unpack()
            m.directory.unpack()

            # print("checking no data is left")
            self.assertEqual(buf.remaining(), 0)
