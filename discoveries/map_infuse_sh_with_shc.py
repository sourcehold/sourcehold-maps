


from sourcehold import *

sh_map = load_map(expand_var_path("shusermap~/xlmp.map"))

shc_map = load_map(expand_var_path("shcusermap~/Door01.map"))


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


overwrite(shc_map, sh_map, 1001, 1001, truncate=False)


save_map(sh_map, expand_var_path("shcusermap~/xlcr_infused_Door01.map"))

overwrite(shc_map, sh_map, 1002, 1002, truncate=False)


# Walls, stockpile, iron, boulder, farmlands, water, oil, marsh, appear.
# Some textures are wrong though.
overwrite(shc_map, sh_map, 1003, 1003, truncate=False)

# rocks?
overwrite(shc_map, sh_map, 1004, 1004, truncate=False)


# Produces a height map for SH, but no walls, funny enough.
overwrite(shc_map, sh_map, 1005, 1005, truncate=False)


overwrite(shc_map, sh_map, 1006, 1006, truncate=False)

# Nothing special happens
overwrite(shc_map, sh_map, 1009, 1009, truncate=False)




save_map(sh_map, expand_var_path("shusermap~/Door01_shc_to_sh.map"))