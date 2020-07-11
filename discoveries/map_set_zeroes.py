from sourcehold import *

m = load_map(expand_var_path("shcusermap~/xlcr.map"))
from sourcehold.maps.sections import TileStructure

for i, section in enumerate(m.directory.sections):
    # if i in [100]: #100 is the weird 9B section
    #     #continue
    #     section.set_data(b'\x00' * len(section.get_data()))
    # if isinstance(section, TileStructure):
    #     s = section.get_system()
    #     for i in range(len(s.rows)):
    #         for j in range(len(s.rows[i].data)):
    #             s[i][j] = 0
    #     section.set_data(s.to_bytes())

    section.set_data(b'\x00'*len(section.get_data()))


save_map(m, expand_var_path("shcusermap~/xlcr_super0d.map"))

# On resave, this differs: 1001, 1034, 1036, 1017, 1023, 1024, 1126,




m = load_map(expand_var_path("shusermap~/xlmp.map"))
from sourcehold.maps.sections import TileStructure

for i, section in enumerate(m.directory.sections):
    # if i in [100]: #100 is the weird 9B section
    #     #continue
    #     section.set_data(b'\x00' * len(section.get_data()))
    # if isinstance(section, TileStructure):
    #     s = section.get_system()
    #     for i in range(len(s.rows)):
    #         for j in range(len(s.rows[i].data)):
    #             s[i][j] = 0
    #     section.set_data(s.to_bytes())

    section.set_data(b'\x00'*len(section.get_data()))


save_map(m, expand_var_path("shusermap~/xlmp_super0d.map"))

# On resave, this differs: 1001, 1034, 1036, 1017, 1023, 1024, 1126,