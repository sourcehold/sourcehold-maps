
from sourcehold.debugtools.memory.access import AccessContext


class LiveByteArray(object):

    def __init__(self, access: AccessContext, section: str):
        self._access = access
        self._section = section
        self._cache = None
        self._paused = False

    def get_data(self):
        return self

    def __enter__(self):
        self._paused = True
        self._cache = bytearray(self._access.read_section(self._section))

        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self._access.write_section(self._section, data=self._cache)
        self._paused = False
        self._cache = None

    def __getitem__(self, item):
        if self._cache is None:
            with self:
                return self.__getitem__(item)
        if self._cache:
            return self._cache[item]
        raise NotImplementedError()

    def __setitem__(self, key, value):
        if self._cache is None:
            with self:
                return self.__setitem__(key, value)
        if self._cache:
            return self._cache.__setitem__(key, value)
        raise NotImplementedError()

    def __len__(self):
        return len(self._cache)


from xml.etree import ElementTree as ET
from sourcehold.structure_tools import DataProperty


def create_data_properties_from_csx(xml_path):
    doc = ET.parse(xml_path)
    elements = doc.findall(".//Element")

    for element in elements:
        offset = int(element.attrib['Offset'])
        bytesize = int(element.attrib['Bytesize'])
        name = element.attrib.get("Description", None)
        if bytesize == 4:
            fmt = "I"
        elif bytesize == 2:
            fmt = "H"
        elif bytesize == 1:
            fmt = "B"
        else:
            raise Exception(f"no format for bytesize: {bytesize}")

        yield name, DataProperty(fmt, start=offset)


class CheatEngineStructure(type):

    def __new__(mcs, class_name, parents, attrs):
        if not "FILE" in attrs:
            raise Exception("Need to specify the CSX File in FILE")

        f = attrs["FILE"]
        del attrs["FILE"]

        for name, prop in create_data_properties_from_csx(f):
            if name is None:
                continue
            attrs[name] = prop

        return super().__new__(mcs, class_name, parents, attrs)


from sourcehold.maps.sections.objects import Unit, Building, PlayerData


class CheatEngineUnit(Unit, metaclass=CheatEngineStructure):
    FILE = "structure/cheatengine/Unit.CSX"


class CheatEngineBuilding(Building, metaclass=CheatEngineStructure):
    FILE = "structure/cheatengine/Building.CSX"


class CheatEnginePlayerData(PlayerData, metaclass=CheatEngineStructure):
    FILE = "structure/cheatengine/PlayerData.CSX"


from sourcehold.maps.sections import Section1015, Section1013, Section1022


class LiveSection(object):

    def __init__(self, process, section):
        self._process = process
        self._section = section
        self._data = LiveByteArray(self._process, self._section)

    def cache(self):
        return self._data

    def get_data(self):
        return self._data


class LiveSection1015(LiveSection, Section1015):

    _TYPE_ = CheatEngineUnit

    def __init__(self, process):
        super().__init__(process, '1015')


class LiveSection1013(LiveSection, Section1013):

    _TYPE_ = CheatEngineBuilding

    def __init__(self, process):
        super().__init__(process, '1013')


class LiveSection1022(LiveSection, Section1022):

    _TYPE_ = CheatEnginePlayerData

    def __init__(self, process):
        super().__init__(process, '1022')

