from sourcehold import *

m = load_map(expand_var_path("shcusermap~/xlcr.map"))

tiles = m.directory.sections[0].get_tiles()

from sourcehold.maps.sections.tools import DiamondSystem

d = DiamondSystem()


def find(tiles, size, step=1):
    margin = (size // 2) + (size % 2)
    for i in range(len(tiles) - margin):
        for j in range(len(tiles[i]) - margin):
            indices = [(ii + 1, jj) for ii, jj in
                       d.retrieve_diamond_indices((i, j), size)]  # system has empty row, thats why
            values = [tiles[i][j] for i, j in indices]
            svalues = sorted(values)
            if list(range(min(svalues), max(svalues) + 1, step)) == svalues:
                # values are consecutive
                yield indices, size, values


def replace(section, size, times=20, step=1):
    system = m.directory[section].get_system()
    default = None
    system2 = m.directory[section].get_system()
    for f in find(system.get_tiles(), size, step):
        times -= 1
        if times <= 0:
            break
        if default is None:
            default = f
            continue
        indices, s, values = f
        z = 0
        for i, j in indices:
            print(i, " ", j)
            system2[i][j] = default[2][z]
            z += 1

    return system2.to_bytes()


m.directory[1001].set_data(replace(1001, 2, times=20, step=1))
# m.directory[1036].set_data(replace(1036, 2, times=20, step=64))

save_map(m, expand_var_path("shcusermap~/xlcr_textsame.map"))

# Sections that are different: 1001, 1036, 1017, 1091, 1023, 1024, 1046, 1040, 1052, 1126
