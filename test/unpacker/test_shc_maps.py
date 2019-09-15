import os
import unittest

import unpacker


class TestMapStructure(unittest.TestCase):

    def test_structures(self):
        files = ["resources/" + f for f in os.listdir("resources/") if f.endswith(".map")]

        import compression
        compression.COMPRESSION = compression.BlastDecompression()

        for file in files:
            print("reading file: {}".format(file))
            with open(file, 'rb') as f:
                data = f.read()

            print("parsing file")
            m = unpacker.MapStructure(0, data)

            print("verifying file")
            verifications = m.verify()
            print(verifications)
            for i in range(len(verifications)):
                if not verifications[i]:
                    raise Exception("file {}. section number {} has an invalid crc32".format(file, i))

            print("checking no data is left")
            self.assertEqual(m.buf.remaining(), 0)
