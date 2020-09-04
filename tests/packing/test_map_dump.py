import unittest
import tempfile

from sourcehold import structure_tools, maps, load_map, save_map, Map, Buffer


class TestDumpAndLoadFromFolder(unittest.TestCase):

    def test_dump_to_folder(self):
        m = load_map("resources/map/crusader/MxM_unseen_1.map")
        m.unpack(True)

        tempdir = tempfile.TemporaryDirectory()

        path = tempdir.name

        m.dump_to_folder(path)
        tempdir.cleanup()

    def test_load_from_folder(self):
        map = load_map("resources/map/crusader/MxM_unseen_1.map")
        map.unpack(force=True)

        tempdir = tempfile.TemporaryDirectory()

        path = tempdir.name

        map.dump_to_folder(path)

        map2 = Map().load_from_folder(path)
        map2.pack(True)
        map2.serialize_to_buffer(Buffer())

        tempdir.cleanup()
