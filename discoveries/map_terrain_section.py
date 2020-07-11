
from sourcehold import *
from discoveries.tools import *
from sourcehold.maps.sections import TileStructure


mappaths = ["shcusermap~/xlcr.map"] + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

for diff in maps[0].yield_inequalities(maps[1]):
    print(diff)

sections = [1001, 1037, 1036, 1034, 1017, 1091, 1023, 1024, 1046, 1040, 1052, 1126]

tile_sections = [k for k in sections if isinstance(maps[0].directory[k], TileStructure)]

system = maps[1].directory[1001].get_system()
#tiles = maps[1].directory[1001].get_system().get_tiles()
for i, j, count, value in system.tiles():
    if value not in {1, 2}:
        print(i, j, value)

# Unlikely, it is hard to see what is special.

system = maps[1].directory[1037].get_system()
#options = set(maps[1].directory[1037].get_data())
#print(options)
for i, j, count, value in system.tiles():
    if value not in {0}:
        print(i, j, value)

# Yes, this seems reasonable!

system = maps[1].directory[1036].get_system()
#options = set(maps[1].directory[1036].get_data())
#print(options)
for i, j, count, value in system.tiles():
    if value not in {0, 1, 2}:
        print(i, j, value)

# No, these are too many.

section = 1037
datas = [m.directory[section].get_data() for m in maps]

equal_lengths = list(progressive_apply(*datas, summary=len, func=find_equals))
unequal_lengths = list(progressive_apply(*datas, summary=len, func=find_unequals))

# 144 bytes? -> 12 x 12?, no: (1+3+5+7+9+11+13+15+17+15+13+11+9+7+5+3) (staggered square, top left is normal)



mappaths = ["shcusermap~/xlcr.map"] + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass_1_scr.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

system = maps[3].directory[1037].get_system()
#options = set(maps[1].directory[1037].get_data())
#print(options)
for i, j, count, value in system.tiles():
    if value not in {0}:
        print(i, j, value)

# Oasis grass = 16, Scrub = 1,

mappaths = ["shcusermap~/xlcr.map"] + ["shcusermap~/xlcr_terrains.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]
system = maps[1].directory[1037].get_system()
#options = set(maps[1].directory[1037].get_data())
#print(options)
for i, j, count, value in system.tiles():
    if value not in {0}:
        print(i, j, value)

# thick scrub, oasis grass, scrub, earth, boulders, rocks, driven sand, earth and stones
# 128,          16,          1,       0?,              64,      2,

mappaths = ["shcusermap~/xlcr_tr.map"] + ["shcusermap~/xlcr_tr_all_terrains.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]
system = maps[1].directory[1037].get_system()
#options = set(maps[1].directory[1037].get_data())
#print(options)
first = 999999999999
last = 0
highi = 0
highj = 0
mini = 99999999
minj = 99999999
occurence_order = []
for i, j, count, value in system.tiles():
    if value not in {0}:
        mini = min([mini, i])
        minj = min([minj, j])
        highi = max([highi, i])
        highj = max([highj, j])
        first = min([first, count])
        last = max([first, count])
        if value not in occurence_order:
            occurence_order.append(value)
        print(i, j, count, value)

tiles = system.get_tiles()
part = [j[minj:highj] for j in tiles[mini:highi+1]]

system.create_image().show()
#iron, earth and stones, driven sand, rocks, boulders,
#earth, scrub, oasis grass, thick scrub
#sea, beach, river, ford
#marsh, oil in marsh

#Only 2, 3, 7, 8, 9, 11 show: earth and stones, driven sand, scrub, oasis grass, thick scrub, beach,
#values: 2, 64, 1, 16, 128, 32

for i in range(len(system)):
    for j in range(len(system[i])):
        system[i][j] = 64

data = system.to_bytes()

buf2 = Buffer()
maps[0].serialize_to_buffer(buf2)
buf2.seek(0)
mod = Map().from_buffer(buf2)
mod.directory[1037].set_data(data)
mod.directory[1037].pack()
mod.directory.pack()

save_map(mod, expand_var_path("shcusermap~/mod_all_earthandstones.map"), pack=False)

# Works!


# Now for all the other terrains
sections = list(maps[0].directory.different_sections(maps[1].directory))
tile_sections = [k for k in sections if isinstance(maps[0].directory[k], TileStructure)]

maps[-1].directory[1030].get_system().create_image().show()
# Nice, but same colors for every terrain.

maps[-1].directory[1009].get_system().create_image().show()
# Water and oil animation?

maps[-1].directory[1007].get_system().create_image().show()
#Walkable or buildable?

maps[-1].directory[1006].get_system().create_image().show()
#Edges only

maps[-1].directory[1045].get_system().create_image().show()
# Two of same color.

maps[-1].directory[1005].get_system().create_image().show()
# Four of same color.

maps[-1].directory[1036].get_system().create_image().show()
# Lots of randomness, except for terrain edges

maps[-1].directory[1003].get_system().create_image().show()
# This seems helpful!
# We only see 1, 4, 5, 10, 11 (edges only), 12, 13, 14, 15

system = maps[1].directory[1003].get_system()
#options = set(maps[1].directory[1037].get_data())
#print(options)
first = 999999999999
last = 0
highi = 0
highj = 0
mini = 99999999
minj = 99999999
occurence_order = []
for i, j, count, value in system.tiles():
    if value not in {0, 32768, 16, 32}: # TODO: are these defaults? or earth?
        mini = min([mini, i])
        minj = min([minj, j])
        highi = max([highi, i])
        highj = max([highj, j])
        first = min([first, count])
        last = max([first, count])
        if value not in occurence_order:
            occurence_order.append(value)
        print(i, j, count, value)

for i in range(len(system)):
    for j in range(len(system[i])):
        system[i][j] = 0

data = system.to_bytes()

buf2 = Buffer()
maps[0].serialize_to_buffer(buf2)
buf2.seek(0)
mod = Map().from_buffer(buf2)
mod.directory[1003].set_data(data)
mod.directory[1003].pack()
mod.directory.pack()

save_map(mod, expand_var_path("shcusermap~/mod_all_earth.map"), pack=False)

#These are gone: earth and stones, driven sand, earth?, scrub, oasis grass, thick scrub, beach

#These seem to be the valeus: 557056, 32896, 163840, 1, 1048576, 2097152, 536870912, 536903680, 2684387328
# Types: iron, rocks, boulders, sea, beach + edge, river, ford + edge, marsh, oil in marsh

# iron: 557056
# rocks: 32896
# boulders: 163840
# sea: 1
# river: 1048576
# ford: 2097152
# marsh: 536870912
# also marsh: 536903680
# oil: 2684387328
# bobbled earth/sand stuff: 0, 16, 32, 32768
#