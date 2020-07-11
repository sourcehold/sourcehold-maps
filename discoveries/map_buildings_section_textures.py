
from sourcehold import *
from discoveries.tools import *
from sourcehold.maps.sections import TileStructure


mappaths = ["shcusermap~/xlcr.map"] + ["shcusermap~/xlcr_{}_p1hovel.map".format(i) for i in range(1, 6)]
maps = [load_map(expand_var_path(p), unpack=False) for p in mappaths]

sections = list(maps[1].directory.different_sections(maps[2].directory))
tile_sections = [k for k in sections if isinstance(maps[0].directory[k], TileStructure)]


section = 1001
datas = [m.directory[section].get_data() for m in maps]

unequal_lengths = list(progressive_apply(*datas, summary=len, func=find_unequals))


section = 1033
datas = [m.directory[section].get_data() for m in maps]
maps[-1].directory[section].create_image().show()

# Maybe 1033 is texture display? Nope.

unequal_lengths = list(progressive_apply(*datas, summary=len, func=find_unequals))