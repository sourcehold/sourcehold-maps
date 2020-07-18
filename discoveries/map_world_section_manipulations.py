
from sourcehold import *
from discoveries.tools import *
from sourcehold.maps.sections import TileStructure


mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]


sections = [1001, 1037, 1036, 1034, 1017, 1091, 1023, 1024, 1046, 1040, 1052, 1126]

tile_sections = [k for k in sections if isinstance(maps[0].directory[k], TileStructure)]

print(tile_sections)

# This does not do much

maps[0].directory.sections[0].unpack(True)

s1001 = maps[0].directory[1001]

s1001.set_data(b'\x01\x00' * (len(s1001.get_data())//2))

s1001.pack(True)

maps[0].pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr1001.map"))

# This also did not do much

maps[0].directory.sections[0].unpack(True)

s1001 = maps[0].directory[1001]

s1001.set_data(b'\x00\x00' * (len(s1001.get_data())//2))

s1001.pack(True)

maps[0].pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr1001.map"))

# Does not doo much

maps[0].directory.sections[0].unpack(True)

s1037 = maps[0].directory[1037]

s1037.set_data(b'\x00\x00' * (len(s1037.get_data())//2))

s1037.pack(True)

maps[0].pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr1037.map"))


# Does not doo much

maps[0].directory.sections[0].unpack(True)

s1036 = maps[0].directory[1036]

s1036.set_data(b'\x00\x00' * (len(s1036.get_data())//2))

s1036.pack(True)

maps[0].pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr1036.map"))



### Section by section


# When section numbers 0-9 are cleared, all terrain becomes sandlike


mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

all_sections = list(filter(lambda v: v != 0, maps[0].directory.section_indices)) # This did not work for some reason...
tile_sections = [k for k in all_sections if isinstance(maps[0].directory[k], TileStructure)]

all_sections = tile_sections


def clear_sections(m, ss):
    for s in ss:
        m.directory[s].set_data(b'\x00' * len(m.directory[s].get_data()))
        m.directory[s].pack()
    m.directory.pack()


for i in range(1, len(all_sections) + 1):
    clear_sections(maps[0], all_sections[:i])
    save_map(maps[0], expand_var_path("shcusermap~/xlcr_cleared_until_{}.map".format(i)))




print(all_sections[9]) # 1005

# we can add error to the height basically.

mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

maps[0].directory[1005].get_system().create_image().show()

import random

error = [random.choice([-1, 0, 1]) for i in range(80400)]

maps[0].directory[1005].set_data(bytes(bytearray([v + error[i] for i, v in enumerate(maps[0].directory[1005].get_data_as_bytearray())])))

maps[0].directory[1005].pack()
maps[0].directory.pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1005_noise.map"))


# this produces a plateau, so yes, section 1005 is height map.

from sourcehold.maps.sections.tools import DiamondSystem
dia = DiamondSystem()

s = maps[0].directory[1005].get_system()

for i in range(0, 400):
    for j in range(len(s[i])):
        s[i][j] = 8*8 if i < 24 else 8

maps[0].directory[1005].set_data(s.to_bytes())

maps[0].directory[1005].pack()
maps[0].directory.pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1005_plateau.map"))




# Excluding s1005, when section numbers 0-13 are cleared, all terrain becomes sandlike


mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

all_sections = list(filter(lambda v: v != 0, maps[0].directory.section_indices)) # This did not work for some reason...
tile_sections = [k for k in all_sections if isinstance(maps[0].directory[k], TileStructure)]
tile_sections.remove(1005)
all_sections = tile_sections


def clear_sections(m, ss):
    for s in ss:
        m.directory[s].set_data(b'\x00' * len(m.directory[s].get_data()))
        m.directory[s].pack()
    m.directory.pack()


for i in range(1, len(all_sections) + 1):
    clear_sections(maps[0], all_sections[:i])
    save_map(maps[0], expand_var_path("shcusermap~/xlcr_cleared_until_{}.map".format(i)))

print(all_sections[12])


# 1008 seems to be randomness, but maybe it is important for texture tile selection, setting it to the first value produces a certain texture.
# Image143.png is the value of the texture that is repeatedly displayed. You can draw with the height tool.

mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

s = maps[0].directory[1008].get_system()
for i in range(0, 400):
    for j in range(len(s[i])):
        s[i][j] = s[0][0]


maps[0].directory[1008].set_data(s.to_bytes())

maps[0].directory[1008].pack()
maps[0].directory.pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1008_first_value.map"))


# 1008 seems to be randomness, but maybe it is important for texture tile selection, setting it to the first value + 1 produces a certain tiny texture.

mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

s = maps[0].directory[1008].get_system()
for i in range(0, 400):
    for j in range(len(s[i])):
        s[i][j] = s[0][0] + 1


maps[0].directory[1008].set_data(s.to_bytes())

maps[0].directory[1008].pack()
maps[0].directory.pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1008_first_value_plus_1.map"))

# 1008 seems to be randomness, but maybe it is important for texture tile selection, setting it to the second value produces a certain texture.
# Same as first value, interesting.

mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

s = maps[0].directory[1008].get_system()
for i in range(0, 400):
    for j in range(len(s[i])):
        s[i][j] = s[0][1]


maps[0].directory[1008].set_data(s.to_bytes())

maps[0].directory[1008].pack()
maps[0].directory.pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1008_second_value.map"))

# third: produced Image141.png
mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

s = maps[0].directory[1008].get_system()
for i in range(0, 400):
    for j in range(len(s[i])):
        s[i][j] = s[1][0]


maps[0].directory[1008].set_data(s.to_bytes())

maps[0].directory[1008].pack()
maps[0].directory.pack()

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1008_third_value.map"))


# fourth: same as third, Image141.png
def clone_values(m, section, nth=(0,0)):
    s = m.directory[section].get_system()
    a, b = nth
    for i in range(0, 400):
        for j in range(len(s[i])):
            s[i][j] = s[a][b]

    m.directory[section].set_data(s.to_bytes())

    m.directory[section].pack()
    m.directory.pack()

mappaths = ["shcusermap~/xlcr.map"]# + ["shcusermap~/xlcr_oasis_grass.map"] + ["shcusermap~/xlcr_2_oasis_grass.map"]
maps = [load_map(expand_var_path(p)) for p in mappaths]

clone_values(maps[0], 1008, nth=(1, 1))

save_map(maps[0], expand_var_path("shcusermap~/xlcr_1008_fourth_value.map"))

