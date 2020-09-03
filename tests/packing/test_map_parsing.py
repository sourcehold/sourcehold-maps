import unittest
import pathlib

from sourcehold import structure_tools, maps


def _test_parse_map(path):
    error = None
    ret = -1

    try:

        with open(path, 'rb') as f:
            data = f.read()

        buf = structure_tools.Buffer(data)
        m = maps.Map().from_buffer(buf)

        m.unpack()
        m.directory.unpack()

        ret = buf.remaining()

    except Exception as e:
        error = e
        ret = -1

    return ret, error


def _test_maps(files):
    parses = {file: _test_parse_map(file) for file in files}
    failed = {file: v for file, v in parses.items() if v[0] != 0}

    failed_remaining = {file: v[0] for file, v in failed.items() if v[0] > 0}
    failed_error = {file: v[1] for file, v in failed.items() if v[1] is not None}

    msg = ""

    if len(failed_remaining) > 0:
        msg += "Parsing of the following maps failed because there was data remaining: "
        msg += "\n".join(
            ["file: " + str(file) + " remaining bytes: " + str(rem) for file, rem in failed_remaining.items()])

    if len(failed_error) > 0:
        msg += "Parsing of the following maps failed because there was an error: "
        msg += "\n".join(
            ["file: " + str(file) + " remaining bytes: " + str(error) for file, error in failed_error.items()])

    return msg


class TestMapStructure(unittest.TestCase):

    def test_shc_maps(self):
        msg = _test_maps(files=list(pathlib.Path("resources/map/crusader").rglob("*.map")))
        if msg:
            self.fail(msg)

    def test_shce_msvs(self):
        msg = _test_maps(files=list(pathlib.Path("resources/msv/extreme").rglob("*.msv")))
        if msg:
            self.fail(msg)

    def test_shc_savs(self):
        msg = _test_maps(files=list(pathlib.Path("resources/sav/crusader").rglob("*.sav")))
        if msg:
            self.fail(msg)


