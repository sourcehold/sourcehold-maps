from sourcehold import *
from sourcehold.maps.sections import MapSection

m = load_map(expand_var_path("shcusermap~/xlcr.map"), unpack=True, force=True)

s0 = m.directory.sections[0]
s1 = m.directory.sections[1]

k0 = m.directory.section_indices[0]
k1 = m.directory.section_indices[1]

m.directory.sections[1] = s0
m.directory.sections[0] = s1

m.directory.section_indices[1] = k0
m.directory.section_indices[0] = k1

m.directory.pack(True)

save_map(m, expand_var_path("shcusermap~/xlcr_shuffled.map"), pack=True, force=True)