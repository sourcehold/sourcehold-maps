# TODO: section 1001 works, but produces a black map!

from sourcehold import *
from sourcehold.maps import MapSection

m = load_map(expand_var_path("shcusermap~/160cr.map"))

sections = []
for i in range(len(m.directory.sections)):
    if i not in []:
        continue
    section = m.directory.sections[i]
    d = section.get_data()
    s = MapSection().from_buffer(Buffer(d), length=len(d))
    m.directory.sections[i] = s

m.directory.sections[0].uncompressed = b'\x00' + m.directory.sections[0].uncompressed[1:]

save_map(m, expand_var_path("shcusermap~/160cr_unpacked.map"))

# This fails, expected.
# m2 = load_map(expand_var_path("shcusermap~/160cr_unpacked.map"))
