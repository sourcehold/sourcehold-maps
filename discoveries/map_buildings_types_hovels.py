
from sourcehold import *
from sourcehold.maps.sections.objects import BuildingDeprecated
from discoveries.tools import *
import pathlib

map = load_map(expand_var_path("shcusermap~/xlcr_hovels_3x7.map"), unpack=False)


data = map.directory[1013].get_data()

buf = Buffer(data)

buildings = [BuildingDeprecated().deserialize_from(buf) for b in range(0, (3 * 7) + 1)]

write_csv(pathlib.Path().cwd() / "resources" / "hovels-1013.data", *[interpret_as(data[i*812:(i+1)*812], "H") for i in range(0, (3*7) + 1)])