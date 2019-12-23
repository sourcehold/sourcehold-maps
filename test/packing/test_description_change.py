import unittest

from sourcehold import structure_tools, maps


class ChangeDescription(unittest.TestCase):

    def change_description(self):
        with open("resources/MxM_unseen_1.map", 'rb') as f:
            buf = structure_tools.Buffer(f.read())

        m = maps.Map().from_buffer(buf)
        m.unpack()
        m.directory.unpack()

        m.description.uncompressed = b'hello world!'

        m.pack()
        m.directory.pack()

        buf2 = structure_tools.Buffer()
        m.serialize_to_buffer(buf2)

        with open("resources/MxM_unseen_1_hello_world.map", 'wb') as f:
            f.write(buf2.getvalue())
