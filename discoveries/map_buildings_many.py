

from sourcehold import *
from sourcehold.maps.sections.objects import Building
from discoveries.tools import *
import pathlib

map = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings.map"), unpack=False)
basemap = load_map(expand_var_path("shcusermap~/xlcr.map"), unpack=False)

sections = list(map.directory.different_sections(basemap.directory))

data = map.directory[1013].get_data()

buf = Buffer(data)

buildings = [Building().deserialize_from(buf) for b in range(0, 100)]

img = map.directory[1012].get_system().create_image()
img.save("resources/many-buildings-1012.png")


write_csv(pathlib.Path().cwd() / "resources" / "many-buildings-1013.data", *[interpret_as(data[i*812:(i+1)*812], "H") for i in range(0, 100)])

buf = Buffer()
buildings[0].serialize_to(buf)
buildings[2].building_id = 1
buildings[2].serialize_to(buf)

buf.seek(0)

data_part1 = buf.getvalue()
data_part2 = b'\x00'*(len(data)-len(data_part1))

map.directory[1013].set_data(data_part1 + data_part2)

map.directory[1013].pack()
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/xlcr_almost_buildings_mod.map"), pack=False)

m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_mod.map"), unpack=False)
buf = Buffer(m.directory[1013].get_data())
buildings = [Building().deserialize_from(buf) for b in range(0, 100)]

# When the building is clicked, it now says training ground! and shows the top right corner training ground texture.
# Overlayed on the original barracks texture!
# All the other buildings are still there but they are ghosts.

section = 1033
m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_mod.map"), unpack=False)
system = m.directory[section].get_system()
for i, j, count, value in system.tiles():
    system[i][j] = 0

m.directory[section].set_data(system.to_bytes())
m.directory[section].pack()
m.directory.pack()

save_map(m, expand_var_path("shcusermap~/xlcr_almost_buildings_2.map"), pack=False)
# Nope, did not make textures disappear.

m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_2.map"), unpack=False)
m.directory[section].get_system().create_image().show()




section = 1007
m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_mod.map"), unpack=False)
system = m.directory[section].get_system()
for i, j, count, value in system.tiles():
    system[i][j] = 2048

m.directory[section].set_data(system.to_bytes())
m.directory[section].pack()
m.directory.pack()

save_map(m, expand_var_path("shcusermap~/xlcr_almost_buildings_2.map"), pack=False)
# Nope, did not make textures disappear.

m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_2.map"), unpack=False)
m.directory[section].get_system().create_image().show()

# Stuff reappeared!


section = 1049
m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_mod.map"), unpack=False)
system = m.directory[section].get_system()
system.create_image().show()
# This looks interesting! These are the building IDs!

appearence_order = []

for i, j, count, value in system.tiles():
    if value not in appearence_order:
        appearence_order.append(value)
    system[i][j] = 0

m.directory[section].set_data(system.to_bytes())
m.directory[section].pack()
m.directory.pack()

save_map(m, expand_var_path("shcusermap~/xlcr_almost_buildings_2.map"), pack=False)
# Nope, did not make textures disappear.
# Everything is now filled with ruins! Weird! 12 is the ruins of a Fletchers workshop.

m = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings_2.map"), unpack=False)
m.directory[section].get_system().create_image().show()

# Stuff is still there.




map = load_map(expand_var_path("shcusermap~/xlcr_almost_buildings.map"), unpack=False)
basemap = load_map(expand_var_path("shcusermap~/xlcr.map"), unpack=False)

sections = list(map.directory.different_sections(basemap.directory))

data = map.directory[1013].get_data()

buf = Buffer(data)

buildings = [Building().deserialize_from(buf) for b in range(0, 100)]

buf = Buffer()
buildings[0].serialize_to(buf)
buildings[2].building_id = 1
buildings[2].serialize_to(buf)


data_part1 = buf.getvalue()
data_part2 = b'\x00'*(len(data)-len(data_part1))

for section in map.directory.sections:
    section.set_data(b'\x00'*len(section.get_data()))

map.directory[1013].set_data(data_part1 + data_part2)

map.directory[1013].pack()
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/xlcr_almost_buildings0.map"), pack=False)