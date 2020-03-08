from sourcehold import *
from sourcehold.maps.sections import TileStructure

m1 = load_map(expand_var_path("shcmapuser~/scr.map"))
m2 = load_map(expand_var_path("shcmapuser~/scr_1oasis.map"))

t1 = m1.directory[1001].get_system()
t2 = m2.directory[1001].get_system()

tdiff = t2 - t1
img = tdiff.create_image()
img.show()

imgs = []

for i, s in enumerate(m1.directory.sections):
    if isinstance(m1.directory.sections[i], TileStructure):
        imgs.append((m2.directory.sections[i].get_system() - m1.directory.sections[i].get_system()).create_image())
