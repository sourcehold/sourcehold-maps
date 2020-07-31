


from sourcehold import *

src_map = load_map(expand_var_path("shcusermap~/Door01.map"))

dst_map = load_map(expand_var_path("shcusermap~/xlcs_invasion.map"))


def overwrite(srcmap, dstmap, srcsection, dstsection=None, truncate=True):
    if dstsection is None:
        dstsection = srcsection

    srcdata = srcmap.directory[srcsection].get_data()
    dstdata = dstmap.directory[dstsection].get_data()

    if len(srcdata) > len(dstdata) and truncate is False:
        raise Exception("the src section is larger than the dst section and truncate=False")

    srcdata = srcdata[:len(dstdata)]

    dstmap.directory[dstsection].set_data(srcdata)

    dstmap.directory[dstsection].pack(True)
    dstmap.directory.pack()

# Nothing
overwrite(src_map, dst_map, 1001, 1001, truncate=False)

# Nothing
overwrite(src_map, dst_map, 1002, 1002, truncate=False)

# Walls, towers, keeps, stockpile, iron, boulder, farmlands, water, oil, marsh, appear, flat rocks as well.
# Without height data though.
overwrite(src_map, dst_map, 1003, 1003, truncate=False)

# The rock surface have become proper rocks
overwrite(src_map, dst_map, 1004, 1004, truncate=False)

# Produces a height map for SH, but no walls where they should be, just mountains, funnily enough.
# Also creates sand on high plains. Towers are still glitchy.
overwrite(src_map, dst_map, 1005, 1005, truncate=False)


# Cannot see a difference
overwrite(src_map, dst_map, 1006, 1006, truncate=False)


# Nothing special happens
overwrite(src_map, dst_map, 1008, 1008, truncate=False)

# Nothing special happens
overwrite(src_map, dst_map, 1009, 1009, truncate=False)

# Nothing special happens
overwrite(src_map, dst_map, 1010, 1010, truncate=False)

# All buildings appear! Towers are complete now. Gatehouses also appear. Farms have the correct crops harvested. Everything is owned by player 1 though.
# Ownership banners are missing.
# Stockpiles have the right goods.
# nothing is clickable btw.
overwrite(src_map, dst_map, 1012, 1012, truncate=False)

# Nothing special
overwrite(src_map, dst_map, 1021, 1021, truncate=False)

overwrite(src_map, dst_map, 1030, 1030, truncate=False)

overwrite(src_map, dst_map, 1036, 1036, truncate=False)

# Oasis terrain is added. High plains become diverse.
overwrite(src_map, dst_map, 1037, 1037, truncate=False)

overwrite(src_map, dst_map, 1049, 1049, truncate=False)

# Nothing really special happens, interesting...
overwrite(src_map, dst_map, 1013, 1013, truncate=False)

# Nothing really special happens, interesting...
overwrite(src_map, dst_map, 1015, 1015, truncate=False)


overwrite(src_map, dst_map, 1007, 1007, truncate=False)

save_map(dst_map, expand_var_path("shcusermap~/xlcs_invasion_infused_Door01.map"))














