from sourcehold import *

m = load_map(expand_var_path("shcusermap~/scr.map"))

s = m.directory[1001].get_system()
# for i in range(len(s.rows)):
#     for j in range(len(s.rows[i].data)):
#         if s[i][j] == 3:
#             print(i, j)
#             break

s[1][0] = 3

m.directory[1001].set_data(s.to_bytes())

save_map(m, expand_var_path("shcusermap~/scr_texture_manual.map"))
