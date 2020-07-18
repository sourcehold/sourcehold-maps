
from sourcehold import *
from discoveries.tools import *
from sourcehold.maps.sections import TileStructure


mappaths = ["shcusermap~/xlcr.map"] + ["shcusermap~/xlcr_{}_p1hovel.map".format(i) for i in range(1, 6)]
maps = [load_map(expand_var_path(p)) for p in mappaths]

diffs = list(diff for diff in maps[1].yield_inequalities(maps[2]))

for diff in diffs:
    print(diff)

sections = list(maps[1].directory.different_sections(maps[2].directory))
sections = [1001, 1033, 1002, 1003, 1036, 1007, 1030, 1012, 1021, 1049, 1034, 1013, 1017, 1091, 1022, 1023, 1024, 1035, 1046, 1040, 1052, 1126]

tile_sections = [k for k in sections if isinstance(maps[0].directory[k], TileStructure)]

tiles = maps[1].directory[1002].get_system().get_tiles()
for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] not in {0, 1, 5782}:
            print(i, j, tiles[i][j])

# I am looking for an index value. not a whole number, just like section 1010 for units.

tiles = maps[1].directory[1033].get_system().get_tiles()
for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] not in {0}:
            print(i, j, tiles[i][j])

# I am looking for an index value. not a whole number, just like section 1010 for units.

tiles = maps[1].directory[1003].get_system().get_tiles()
for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] not in {0, 16, 32, 32768}:
            print(i, j, tiles[i][j])

# Yes, maybe, but 33792 is a bit high, right! Exactly 1024 over 32768 btw. And same for all buildings. Weird.

tiles = maps[1].directory[1036].get_system().get_tiles()
for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] not in {0}:
            print(i, j, tiles[i][j])

# Wow this section is messy!

tiles = maps[1].directory[1007].get_system().get_tiles()
for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] not in {0, 16}:
            print(i, j, tiles[i][j])

# This is three values.

system = maps[4].directory[1012].get_system()
tiles = maps[4].directory[1012].get_system().get_tiles()
for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] not in {0}:
            print(i, j, tiles[i][j])

# Found it! This contains the index numbers.



#1034: 7/256000 = 32000 (if 8), 1013: 86/1624000=18883.721, 1091: 2/1062748 = 531374, 1022: 2/133524 = 66762, 1023: 26/262608 = 10100.30 (16413 if 16), 1040: 8/40016 (5002),

#5002 seems reasonable. Many more things are capped at 5000 I guess.

section = 1040
datas = [m.directory[section].get_data() for m in maps]

equal_lengths = list(progressive_apply(*datas, summary=len, func=find_equals))
unequal_lengths = list(progressive_apply(*datas, summary=len, func=find_unequals))

assert set(equal_lengths) == {40008}

# This is impossible if data is added.. move on

section = 1034
datas = [m.directory[section].get_data() for m in maps]

equal_lengths = list(progressive_apply(*datas, summary=len, func=find_equals))
unequal_lengths = list(progressive_apply(*datas, summary=len, func=find_unequals))

# This is impossible if data is added.. move on

section = 1013
datas = [m.directory[section].get_data() for m in maps]

equal_lengths = list(progressive_apply(*datas, summary=len, func=find_equals))
unequal_lengths = list(progressive_apply(*datas, summary=len, func=find_unequals))

# Yes, this seems reasonable!
# 82 bytes per building. or maybe 80. Would allow 20300 buildings. Seems fair.


nonzeroes1 = [eq for eq in find_equals(*datas) if 0 not in set(eq[1])]
nonzeroes2 = [eq for eq in find_equals(*datas[1:]) if 0 not in set(eq[1])]
nonzeroes3 = [eq for eq in find_equals(*datas[2:]) if 0 not in set(eq[1])]
nonzeroes4 = [eq for eq in find_equals(*datas[3:]) if 0 not in set(eq[1])]

lasts = [d[-1][0] for d in [nonzeroes1, nonzeroes2, nonzeroes3, nonzeroes4] if d]
# Size is probably 812. Would allow for 2000 houses. Bingo!

building_infos_data = maps[-1].directory[1013].get_data() # interpret_as(maps[-1].directory[1013].get_data(), "H")
building_infos = [building_infos_data[i*812:(i+1)*812] for i in range(0, 7)]

import pathlib
write_csv(pathlib.Path().cwd() / "resources" / "1013-5.data", *building_infos)

building_infos_data = interpret_as(maps[-1].directory[1013].get_data(), "H") # interpret_as(maps[-1].directory[1013].get_data(), "H")
building_infos = [building_infos_data[i*406:(i+1)*406] for i in range(0, 7)]

import pathlib
write_csv(pathlib.Path().cwd() / "resources" / "1013-5.data", *building_infos)

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] == 1:
            print(i, j)


building_infos_data = maps[-1].directory[1013].get_data()
buf = Buffer(building_infos_data)

from sourcehold.maps.sections.objects import BuildingDeprecated
buildings = [BuildingDeprecated() for b in range(0, 6)]
for building in buildings:
    building.deserialize_from(buf)

for i in range(1, 6):
    buildings[i].health_hypothesis1 = 40
    #buildings[i].health_hypothesis2 = 10

buf = Buffer()
for building in buildings:
    building.serialize_to(buf)

newdata = buf.getvalue() + building_infos_data[6*812:]
assert len(newdata) == len(building_infos_data)

maps[-1].directory[1013].set_data(newdata)
maps[-1].directory[1013].pack()
maps[-1].directory.pack()

save_map(maps[-1], expand_var_path("shcusermap~/xlcr_5_p1hovel_mod.map"), pack=False)


mmod_resave = load_map(expand_var_path("shcusermap~/xlcr_5_p1hovel_mod_s.map"), unpack=False)

moddata = mmod_resave.directory[1013].get_data()

buf = Buffer(moddata)

from sourcehold.maps.sections.objects import BuildingDeprecated
buildings = [BuildingDeprecated() for b in range(0, 6)]
for building in buildings:
    building.deserialize_from(buf)

assert buildings[1].building_id == 5

import pathlib
write_csv(pathlib.Path().cwd() / "resources" / "1013-5-s.data", *[interpret_as(moddata[i*812:(i+1)*812], "H") for i in range(0, 7)])

damaged = load_map(expand_var_path("shcusermap~/xlcr_5_p1hovel_damaged.map"), unpack=False)


moddata = damaged.directory[1013].get_data()

buf = Buffer(moddata)

from sourcehold.maps.sections.objects import BuildingDeprecated
buildings = [BuildingDeprecated() for b in range(0, 6)]
for building in buildings:
    building.deserialize_from(buf)

write_csv(pathlib.Path().cwd() / "resources" / "1013-5-damaged.data", *[interpret_as(moddata[i*812:(i+1)*812], "H") for i in range(0, 7)])