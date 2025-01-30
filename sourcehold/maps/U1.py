from sourcehold.maps.SimpleSection import SimpleSection
from sourcehold.structure_tools.DataProperty import DataProperty


class U1(SimpleSection):

    int0 = DataProperty("I", start=0)
    int1 = DataProperty("I", start=4)