

from sourcehold import *

map = load_map(expand_var_path("shcusermap~/scb_large_keep.map"))


from debugtools.maps.mapgui import display_tiles, TiledDiamondSystem

#display_tiles(map.directory[1049], TiledDiamondSystem(tilewidth=8, tileheight=4))

s = map.directory[1049].get_system()

for i in range(len(s)):
    for j in range(len(s[i])):
        if s[i][j] == 42:
            s[i][j] = 41


map.directory[1049].set_data(s.to_bytes())

map.directory[1049].pack(True)
map.directory.pack()

# save_map(map, expand_var_path("shcusermap~/scb_large_keep_1049.map"))
# Nothing happened

from discoveries.tools import write_csv, interpret_as
import pathlib

data = map.directory[1013].get_data()

write_csv(pathlib.Path().cwd() / "resources" / "scb_large_keep.data", *[interpret_as(data[i*812:(i+1)*812], "B") for i in range(0, (9) + 1)])

map.directory[1013][1].building_type_2 = 41
map.directory[1013].pack(True)
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/scb_large_keep_1049_1013.map"))
# Oof, ugly, but seems to work, Crusader keep, the doors are still wrong though...

map.directory[1013][1].building_type_2 = 43
map.directory[1013].pack(True)
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/scb_large_keep_1049_1013.map"))
# Oof, glitchy, but what the hell is it?
s = map.directory[1049].get_system()
for i in range(len(s)):
    for j in range(len(s[i])):
        if s[i][j] == 41:
            s[i][j] = 45
map.directory[1049].set_data(s.to_bytes())

map.directory[1049].pack(True)
map.directory.pack()

map.directory[1013][1].building_type_2 = 45
map.directory[1013].pack(True)
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/scb_large_keep_1049_1013.map"))
# Now it changed into a gatehouse... but the gatehouse cannot be climbed, but can be closed.
