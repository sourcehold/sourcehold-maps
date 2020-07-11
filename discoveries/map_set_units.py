from sourcehold import *
from sourcehold.maps.sections import TileStructure
mbasic = load_map(expand_var_path("shcusermap~/xlcr.map"))

m = load_map(expand_var_path("shcusermap~/xlcr_1redarcher.map"), unpack=False)

#
# diffs = [diff for diff in mbasic.yield_inequalities(m)]
#
# for diff in diffs:
#     print(diff)

diff_sections = [1010, 1034, 1015, 1016, 1017, 1091, 1022, 1023, 1024, 1035, 1046, 1040, 1052, 1126]

tiled_sections = [m.directory[s] for s in diff_sections if isinstance(m.directory[s],TileStructure )]

from random import randint

steps = list(range(30))
from itertools import accumulate

section = 1010

def mod_routine_1(sect):
    s = m.directory[sect].get_system()
    for i in range(len(s.rows)):
        for j in range(len(s.rows[i].data)):
            s[i][j] = 0
            # if s[i][j] == 3:
            #     print(i, j)
            #     break
    m.directory[sect].set_data(s.to_bytes())
    m.directory[sect].pack()


def mod_routine_1_random(sect):
    s = m.directory[sect].get_system()
    for i in range(len(s.rows)):
        for j in range(len(s.rows[i].data)):
            s[i][j] = randint(0, 1)
            # if s[i][j] == 3:
            #     print(i, j)
            #     break
    m.directory[sect].set_data(s.to_bytes())
    m.directory[sect].pack()

def mod_routine_2(sect):
    s = m.directory[sect]
    s.set_data(b'\x00' * len(s.get_data()))
    m.directory[sect].pack()

# s[1][0] = 3

#mod_routine_1(1010)  # Archer is gone but reappears as soon as it walks.
mod_routine_1_random(1010)  # Archer is gone but reappears as soon as it walks. In the map preview, there are many red dots :)
#mod_routine_2(1015)  # Archer disappears
#mod_routine_2(1034)  # Nothing to see
#mod_routine_2(1016)  # Initial walk animation was cleared. Reset animation?
#mod_routine_2(1017)  # Nothing to see
#mod_routine_2(1091)  # Nothing to see
#mod_routine_2(1022)  # Nothing to see
#mod_routine_2(1023)  # Nothing to see
#mod_routine_2(1024)  # Nothing to see
#mod_routine_2(1035)  # Nothing to see
#mod_routine_2(1046)  # Nothing to see
#mod_routine_2(1040)  # Nothing to see
#mod_routine_2(1052)  # Nothing to see
#mod_routine_2(1126)  # Nothing to see

m.directory.pack()

save_map(m, expand_var_path("shcusermap~/xlcr_1redarcher_mod.map"), pack=False)