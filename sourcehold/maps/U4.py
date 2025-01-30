from sourcehold.maps.SimpleSection import SimpleSection
from sourcehold.structure_tools.DataProperty import DataProperty


class U4(SimpleSection):

    int0 = DataProperty("I", start=0)
    int1 = DataProperty("I", start=4)
    int2 = DataProperty("I", start=8)
    unbalanced = DataProperty("I", start=12)
    rest = DataProperty("B", array_size=64, start=16)

    def get_unbalanced_flag(self):
        return self.unbalanced == 1

    def set_unbalanced_flag(self, value: bool):
        self.unbalanced = 1 if value else 0