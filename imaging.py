from maps import read_file
from maps.sections import *

d1 = read_file("file_inspection/maps/Scr/sections/1001")
# d2 = read_file("file_inspection/maps/S_onetree/sections/1001")
#
#
d1i = interpret(d1, "H", b'\x01\x00\x02\x00', b'\x02\x00\x01\x00')
# d2i = interpret(d2, "H", b'\x01\x00\x02\x00', b'\x02\x00\x01\x00')
#
#
#
# d1 = read_file("file_inspection/maps/Scr/sections/1003")
# d2 = read_file("file_inspection/maps/S_anothertree_left/sections/1003")
#
#
# d1i = interpret(d1, "I", b'\x10\x00\x00\x00\x20\x00\x00\x00', b'\x20\x00\x00\x00\x10\x00\x00\x00')
# d2i = interpret(d2, "I", b'\x10\x00\x00\x00\x20\x00\x00\x00', b'\x20\x00\x00\x00\x10\x00\x00\x00')


# d1 = read_file("file_inspection/maps/Scr/sections/1003")
# d2 = read_file("file_inspection/maps/S_walls_straightline/sections/1003")
#
#
# d1i = interpret(d1, "I", b'\x10\x00\x00\x00\x20\x00\x00\x00', b'\x20\x00\x00\x00\x10\x00\x00\x00')
# d2i = interpret(d2, "I", b'\x10\x00\x00\x00\x20\x00\x00\x00', b'\x20\x00\x00\x00\x10\x00\x00\x00')

# m1 = maps.Map().from_buffer(Buffer(open("../../Documents/Stronghold Crusader/Maps/S_sea_hello_world.map", 'rb').read()))
# m1.unpack()
# d2i = m1.directory.sections[0].interpret()
#
# d1i2 = cut(read_file("file_inspection/maps/Scr/sections/1002"), "H", 198)
# d2i2 = m1.directory.sections[2].interpret()
#
# d3 = read_file("file_inspection/maps/Scr/sections/1003")
# d1i3 = cut(d3, "I", 198)
# d2i3 = m1.directory.sections[3].interpret()


d1i = cut(read_file("file_inspection/maps/Scr/sections/1036"), "H", 198)
d2i = cut(read_file("file_inspection/maps/160cr_arab_archer_red/sections/1036"), "H", 198)

im = create_image(d1i, d2i)

im.show()
