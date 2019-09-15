import os
import unittest

import unpacker


class TestMapStructure(unittest.TestCase):

    def test_structures(self):
        files = ["resources/" + f for f in os.listdir("resources/") if f.endswith(".map")]

        # import compression
        # compression.COMPRESSION = compression.BlastDecompression()

        for file in files:
            print("reading file: {}".format(file))
            with open(file, 'rb') as f:
                data = f.read()

            print("parsing file")
            m = unpacker.MapStructure(0, data)

            print("verifying file")
            self.assertEqual(m.verify(), True)

            print("checking no data is left")
            self.assertEqual(m.buf.remaining(), 0)
