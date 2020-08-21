import os
import unittest

from sourcehold import structure_tools, maps


class TestMapStructure(unittest.TestCase):

    def test_structures(self):
        files = ["resources/" + f for f in os.listdir("resources/") if f.endswith(".map")]

        # import compression
        # compression.COMPRESSION = compression.BlastDecompression()

        for file in files:

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
