import unittest

from sourcehold import structure_tools, maps


class ChangeDescription(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:
        with open("resources/MxM_unseen_1_description.map", 'rb') as f:
            cls.raw1 = f.read()
            buf = structure_tools.Buffer(cls.raw1)

        m = maps.Map().from_buffer(buf)
        m.unpack()

        buf2 = structure_tools.Buffer()
        m.serialize_to_buffer(buf2)
        cls.m = m
        cls.buf2 = buf2

    def no_change_description(self):

        ChangeDescription.m.description.uncompressed = ChangeDescription.m.description.uncompressed

        ChangeDescription.m.pack()

        buf2 = structure_tools.Buffer()
        ChangeDescription.m.serialize_to_buffer(buf2)

        self.assertEqual(ChangeDescription.raw1, buf2.getvalue())

        with open("resources/MxM_unseen_1_description_no_change.map", 'wb') as f:
            f.write(buf2.getvalue())

    def change_description(self):
        ChangeDescription.m.description.uncompressed = ChangeDescription.m.description.uncompressed[:-3] + b' ??'

        ChangeDescription.m.pack()

        buf2 = structure_tools.Buffer()
        ChangeDescription.m.serialize_to_buffer(buf2)

        self.assertEqual(ChangeDescription.raw1, buf2.getvalue())

        with open("resources/MxM_unseen_1_description_change.map", 'wb') as f:
            f.write(buf2.getvalue())
