
from sourcehold import *
from sourcehold.maps.sections.objects import Building
from discoveries.tools import *
import pathlib

map = load_map(expand_var_path("shcusermap~/xlcr_8_engineers.map"), unpack=False)


data = map.directory[1015].get_data()

buf = Buffer(data)

buildings = [Building().deserialize_from(buf) for b in range(0, (8) + 1)]

write_csv(pathlib.Path().cwd() / "resources" / "engineers-players-1013.data", *[interpret_as(data[i*1168:(i+1)*1168], "H") for i in range(0, (8) + 1)])