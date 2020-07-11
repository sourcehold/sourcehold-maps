from sourcehold import *

m = load_map(expand_var_path("shcusermap~/xlcr.map"))

from random import randint

steps = list(range(30))
from itertools import accumulate

s = m.directory[1005].get_system()
times = len(s.rows)//len(steps)
t = []
a = [steps[i//(times+1)] for i in range(len(s.rows))]


for i in range(len(s.rows)):
    for j in range(len(s.rows[i].data)):
        s[i][j] = 8
        # if s[i][j] == 3:
        #     print(i, j)
        #     break

# s[1][0] = 3

m.directory[1005].set_data(s.to_bytes())


s = m.directory[1002].get_system()
for i in range(len(s.rows)):
    for j in range(len(s.rows[i].data)):
        s[i][j] = 0
        # if s[i][j] == 3:
        #     print(i, j)
        #     break

# s[1][0] = 3

m.directory[1002].set_data(s.to_bytes())

save_map(m, expand_var_path("shcusermap~/xlcr_height_manual.map"))
