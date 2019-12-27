import unittest

from sourcehold import structure_tools, maps


class ChangeDescription(unittest.TestCase):

    def no_change_description(self):
        with open("resources/MxM_unseen_1_description.map", 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.unpack()
        #m.directory.unpack()

        #m.description.uncompressed = m.description.uncompressed

        m.pack()
        #m.directory.pack()

        buf2 = structure_tools.Buffer()
        m.serialize_to_buffer(buf2)

        self.assertEqual(buf.getvalue(), buf2.getvalue())

        with open("resources/MxM_unseen_1_description_no_change.map", 'wb') as f:
            f.write(buf2.getvalue())

    def change_description(self):
        with open("resources/MxM_unseen_1_description.map", 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.unpack()
        m.directory.unpack()

        m.description.uncompressed = m.description.uncompressed[:-3] + b' ??'

        m.pack()
        m.directory.pack()

        buf2 = structure_tools.Buffer()
        m.serialize_to_buffer(buf2)

        with open("resources/MxM_unseen_1_description_change.map", 'wb') as f:
            f.write(buf2.getvalue())
