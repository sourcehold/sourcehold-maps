
from sourcehold import *
from discoveries.tools import *
import pathlib

map = load_map(expand_var_path("shcusermap~/xlcr_8_engineers.map"), unpack=False)


data = map.directory[1015].get_data()

map.directory[1015].unpack()
map.directory[1015][1].unit_type = 31

map.directory[1015].pack(True)
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/xlcr_8_engineers_31.map"))

# Consequence: changes an engineer into a ladderman.

write_csv(pathlib.Path().cwd() / "resources" / "engineers-players-1013.data", *[interpret_as(data[i*1168:(i+1)*1168], "B") for i in range(0, (8) + 1)])