import unittest

from sourcehold import structure_tools, maps


class ChangeDescription(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:

        def prepare(path, prefix):
            with open(path, 'rb') as f:
                setattr(cls, prefix + "_raw", f.read())
                setattr(cls, prefix + "_buf", structure_tools.Buffer(getattr(cls, prefix + "_raw")))

            setattr(cls, prefix + "_map", maps.Map().from_buffer(getattr(cls, prefix + "_buf")))
            getattr(cls, prefix + "_buf").seek(0)
            getattr(cls, prefix + "_map").unpack()

        prepare("resources/MxM_unseen_1_description.map", "original")
        prepare("resources/MxM_unseen_1_desc_1.map", "desc_1")
        prepare("resources/MxM_unseen_1_desc_2.map", "desc_2")
        prepare("resources/MxM_unseen_1_desc_3.map", "desc_3")

    def no_change_description(self):

        map2 = maps.Map().from_buffer(ChangeDescription.original_buf)
        ChangeDescription.original_buf.seek(0)
        map2.unpack()

        map2.description.set_description(ChangeDescription.original_map.description.get_description())

        map2.pack()
        #
        # buf2 = structure_tools.Buffer()
        # map2.serialize_to_buffer(buf2)

        gen = ChangeDescription.original_map.yield_inequalities(map2)

        for ineq in gen:
            self.fail("not equal: {}".format(ineq))


    def change_description(self):

        map2 = maps.Map().from_buffer(ChangeDescription.desc_1_buf)
        ChangeDescription.desc_1_buf.seek(0)
        map2.unpack()

        map2.unknown1 = ChangeDescription.desc_2_map.unknown1
        map2.description.set_description(ChangeDescription.desc_2_map.description.get_description())

        map2.pack()

        gen = map2.yield_inequalities(ChangeDescription.desc_2_map)

        from sourcehold import save_map
        save_map(map2, "temp_files/desc_12_test.map")

