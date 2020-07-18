
import sys
import os

import pathlib
sys.path.insert(1, str(pathlib.Path().cwd().parent))

from sourcehold import *
from sourcehold.maps.sections.objects import BuildingDeprecated, Building
from discoveries.tools import *
import pathlib

map = load_map(expand_var_path("shcusermap~/xlcr_8_chapels.map"), unpack=False)

from debugtools.maps.mapgui import display_tiles
from sourcehold.maps.sections.tools import TiledDiamondSystem
display_tiles(map.directory[1002].get_system(), TiledDiamondSystem(tilewidth=8, tileheight=4))

# 1012: building IDs in tile map structure.
data = map.directory[1013].get_data()

buf = Buffer(data)

buildings = [BuildingDeprecated().deserialize_from(buf) for b in range(0, (8) + 1)]

write_csv(pathlib.Path().cwd() / "resources" / "chapels-players-1013.data", *[interpret_as(data[i*812:(i+1)*812], "H") for i in range(0, (8) + 1)])