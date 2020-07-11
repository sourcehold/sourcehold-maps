from sourcehold import *
from sourcehold.maps.sections import MapSection

m = load_map(expand_var_path("shcusermap~/xlcr.map"), unpack=True, force=True)

for i, section in enumerate(m.directory.sections):
    #buf = Buffer(section.get_data())
    #buf.seek(0)
    s = MapSection()
    s.set_data(section.get_data())
    m.directory.sections[i] = s
    m.directory.sections[i].pack(True)

m.directory.pack(True)

save_map(m, expand_var_path("shcusermap~/xlcr_unpacked.map"), pack=True, force=True)

mmod = load_map(expand_var_path("shcusermap~/xlcr_unpacked.map"), unpack=True, force=True)