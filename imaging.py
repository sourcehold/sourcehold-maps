import palette
from maps import read_file
from maps.sections import *

d1i = cut(read_file("file_inspection/maps/xlcr/sections/1001"), "H", 198)
d2i = cut(read_file("file_inspection/maps/xlcr_sea_rocks_ford/sections/1001"), "H", 198)


def produce_image(data):
    uniq = set(x for y in data for x in y)

    mapping = sorted(list(uniq))
    pal = palette.create_palette(len(mapping))

    def lookup(v):
        return pal[mapping.index(v)]

    im = create_image(data, lookup)
    return im


im = produce_image(cut(read_file("temp_files/Close Encounters/sections/1001"), "H", 198))
im.save("Close Encounters-1001.png")

im = produce_image(cut(read_file("temp_files/Close Encounters/sections/1002"), "H", 198))
im.save("Close Encounters-1002.png")

im = produce_image(cut(read_file("temp_files/Close Encounters/sections/1003"), "I", 198))
im.save("Close Encounters-1003.png")

# im = create_comparison_image(d1i, d2i)

# im.show()
