
from sourcehold import *
from discoveries.tools import *

mapset = ["shcusermap~/xlcr_90_1archer_loc_{}.map".format(i) for i in range(1, 6)]

maps = [load_map(expand_var_path(p)) for p in mapset]






sections = [m.directory[1010] for m in maps]


datas = [s.get_data() for s in sections]


variances = [calculate_variance(row) for row in generate_rows(*datas)]

nonzeroes = [i for i, value in enumerate(variances) if value != 0]

assert len(nonzeroes) == 5



sections = [m.directory[1015] for m in maps]


datas = [s.get_data() for s in sections]


variances = [calculate_variance(row) for row in generate_rows(*datas)]

nonzeroes = [(i, value) for i, value in enumerate(variances) if value != 0]

# index 20 and 22 might be location information!
# And pretty sure these are short values


datas = [interpret_as(s.get_data(), "H") for s in sections]


variances = [calculate_variance(row) for row in generate_rows(*datas)]

nonzeroes = [(i, value) for i, value in enumerate(variances) if value != 0]

# index 10 and 11 might be location information!
# Nope, theory busted

x = datas[0][10]
y = datas[0][11]

for data in datas:
    data[10] = x
    data[11] = y


mapset2 = ["shcusermap~/xlcr_90_1archer_loc_{}_samed.map".format(i) for i in range(1, 6)]
for i, map in enumerate(maps):
    #map.directory[1010].set_data(b'\x00' * len(map.directory[1010].get_data()))
    #map.directory[1010].pack()
    map.directory[1015].set_data(uninterpret_as(datas[0], "H"))
    map.directory[1015].pack()
    map.directory.pack()
    save_map(map, expand_var_path(mapset2[i]), pack=False)

# Interestingly, also when there is a mismatch between 1010 and 1015, there is no unit appearing.

# Last short that is different is 1131.
# 1168 shorts per unit gives us 1250 units to store. Seems about right.

merged_data = datas[0][:1168] + datas[1][1168:1168*2] + datas[0][1168*2:]

map = maps[0]
map.directory[1015].set_data(uninterpret_as(merged_data, "H"))
map.directory[1015].pack()
map.directory.pack()

save_map(map, expand_var_path("shcusermap~/xlcr_90_1archer_loc_1and2.map"), pack=False)

# Nope, no result


# If two archers, then max nonzero short is 1715.


# Find repeating values indexes: 540, 1124
mapset = ["shcusermap~/xlcr_90_1archer_loc_1.map", "shcusermap~/xlcr_90_2archer_loc_1_6.map"] + ["shcusermap~/xlcr_90_{}archer.map".format(i) for i in range(3, 6)]

maps = [load_map(expand_var_path(p)) for p in mapset]


sections = [m.directory[1015] for m in maps]

datas = [s.get_data() for s in sections]


nonzeroes1 = [eq for eq in find_equals(*datas) if 0 not in set(eq[1])]
nonzeroes2 = [eq for eq in find_equals(*datas[1:]) if 0 not in set(eq[1])]
nonzeroes3 = [eq for eq in find_equals(*datas[2:]) if 0 not in set(eq[1])]
nonzeroes4 = [eq for eq in find_equals(*datas[3:]) if 0 not in set(eq[1])]

assert [a[-1][0] for a in [nonzeroes1, nonzeroes2, nonzeroes3, nonzeroes4]] == list(range(2262, 5766+1, 1168))

# Every unit uses up 1168 bytes. or 584 shorts

modmap = maps[0]
modmap.directory[1015].set_data(maps[-1].directory[1015].get_data())

modmap.directory[1015].pack()
modmap.directory.pack()

save_map(modmap, expand_var_path("shcusermap~/xlcr_1_to_5_archers_mod.map"))

# Works!

unit_infos_data = interpret_as(maps[-1].directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]

import pathlib

datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)

system = maps[-1].directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


mv = load_map(expand_var_path("shcmapuser~/xlcr_1_to_5_archers_mv.map"))
system = mv.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(mv.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)

import pathlib

mv2 = load_map(expand_var_path("shcmapuser~/xlcr_1_to_5_archers_m2.map"))
system = mv2.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(mv2.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv-2.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)


assert system.get_tile_number_for_index((2,3)) == 9
assert system.get_index_for_tile_number(9) == (2,3)

system.get_index_for_tile_number(40197)

# There are tile numbers and they seem to match only the i, the j is oddly off.. Do not know why.



mv3 = load_map(expand_var_path("shcmapuser~/xlcr_1_to_5_archers_m3.map"))
system = mv3.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(mv3.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv-3.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)





mva = load_map(expand_var_path("shcmapuser~/xlcr_1_to_5_archers_ma.map"))
system = mva.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(mva.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv-a.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)

i, j = system.get_index_for_tile_number(3245)
i, j = i, j + (abs(199-i) if i < 200 else abs(200-i))





import pathlib


grp1 = load_map(expand_var_path("shcmapuser~/xlcr_5archers_grp.map"))
system = grp1.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(grp1.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv-grp-1.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)





import pathlib


grp2 = load_map(expand_var_path("shcmapuser~/xlcr_5archers_grp_1dwn.map"))
system = grp2.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(grp2.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 7)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv-grp-2.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)



adjust_ij(system.get_index_for_tile_number(43020))



grp3 = load_map(expand_var_path("shcmapuser~/xlcr_5archers_grp_1diag.map"))
system = grp3.directory[1010].get_system()
tiles = system.get_tiles()

for i in range(len(tiles)):
    for j in range(len(tiles[i])):
        if tiles[i][j] != 0:
            print(i, j)


unit_infos_data = interpret_as(grp3.directory[1015].get_data(), "H")
unit_infos = [unit_infos_data[i*584:(i+1)*584] for i in range(0, 6)]


datas = unit_infos
path = pathlib.Path().cwd() / "resources" / "1015-mv-grp-3.data"

fieldnames= []
if not fieldnames:
    fieldnames = ["d{}".format(i) for i in range(len(datas))]
n = min(len(data) for data in datas)
with path.open('w', newline='') as f:
    writer = csv.writer(f, delimiter='\t')
    writer.writerow(fieldnames)
    for i in range(n):
        row = [data[i] for data in datas]
        writer.writerow(row)

# 366, 367, those seem to be indexes of locations

system.get_index_for_tile_number(3363, game_adjusted=True)
assert system.get_tile_number_for_index((57, 57), game_adjusted=False) == 3363
assert system.get_tile_number_for_index((57, 199), game_adjusted=True) == 3363

unit_infos_data[366+584] = unit_infos_data[366]
unit_infos_data[367+584] = unit_infos_data[367]


unit_infos_data[366+584+584] = unit_infos_data[366]
unit_infos_data[367+584+584] = unit_infos_data[367]


unit_infos_data[366+584+584+584] = unit_infos_data[366]
unit_infos_data[367+584+584+584] = unit_infos_data[367]


unit_infos_data[366+584+584+584+584] = unit_infos_data[366]
unit_infos_data[367+584+584+584+584] = unit_infos_data[367]

grp3.directory[1015].set_data(uninterpret_as(unit_infos_data, "H"))

grp3.directory[1015].pack()
grp3.directory.pack()

save_map(grp3, expand_var_path("shcusermap~/grp3_mod.map"))