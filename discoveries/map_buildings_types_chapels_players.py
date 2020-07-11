
from sourcehold import *
from sourcehold.maps.sections.objects import Building
from discoveries.tools import *
import pathlib

map = load_map(expand_var_path("shcusermap~/xlcr_8_chapels.map"), unpack=False)


data = map.directory[1013].get_data()

buf = Buffer(data)

buildings = [Building().deserialize_from(buf) for b in range(0, (8) + 1)]

write_csv(pathlib.Path().cwd() / "resources" / "chapels-players-1013.data", *[interpret_as(data[i*812:(i+1)*812], "H") for i in range(0, (8) + 1)])