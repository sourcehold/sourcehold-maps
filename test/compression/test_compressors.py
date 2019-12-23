import unittest

from sourcehold import compression

datac = b'\x00\x04\x82$%\x8f\x80\x7f'
datac2 = b'\x00\x06\x82$%\x0f\x02\xfe\x01'
datad = b'AIAIAIAIAIAIA'

c1 = compression.DirectCompression()
c2 = compression.BlastDecompression()
c3 = compression.SubprocessCompression()


class TestCompressors(unittest.TestCase):

    def test_direct_decompress(self):
        self.assertEqual(c1.decompress(datac), datad)

    def test_blast_decompress(self):
        self.assertEqual(c2.decompress(datac), datad)

    def test_subprocess_decompress(self):
        self.assertEqual(c3.decompress(datac), datad)

    def test_direct_compress(self):
        self.assertEqual(c1.compress(datad), datac2)

    # def test_blast_compress(self):
    #     self.assertEqual(c2.compress(datad), datac2)

    def test_subprocess_compress(self):
        self.assertEqual(c3.compress(datad), datac2)
