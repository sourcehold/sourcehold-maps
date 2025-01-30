import pathlib

from sourcehold import expand_var_path, load_map
from sourcehold.debugtools.memory.access import AccessContext

process = AccessContext(process_name="Stronghold Crusader.exe")

# Number of maps: 7 * 2
map_files = [load_map(expand_var_path(f"shcusermap~/m{i}.map")) for i in range(1, 16)]
dumps = [b''.join(section.get_data() for section in p.directory.sections) for p in map_files]
#dumps.append(process.read_all_memory())

# section 1023, and section 1085 are the primary two candidates, focus the dumps on that:
dumps = [p.directory[1023].get_data() for p in map_files]

equality_matrix = [
# unit type:     1   2   3   4   5   6   7
                [1,  1,  1,  1,  1,  1,  1], # map 1
                [1,  0,  1,  1,  1,  1,  1], # map 2
                [1,  1,  0,  1,  1,  1,  1], # map 3
                [1,  1,  1,  0,  1,  1,  1], # map 4
                [1,  1,  1,  1,  0,  1,  1], # map 5
                [1,  1,  1,  1,  1,  0,  1], # map 6
                [1,  1,  1,  1,  1,  1,  0], # map 7
                [1,  0,  0,  1,  1,  1,  1], # map 8
                [1,  1,  1,  0,  0,  1,  1], # map 9
                [1,  1,  1,  1,  1,  0,  0], # map 10
                [1,  0,  1,  0,  1,  1,  1], # map 11
                [1,  1,  0,  1,  0,  1,  1], # map 12
                [1,  1,  1,  0,  1,  0,  1], # map 13
                [1,  0,  1,  0,  0,  1,  0], # map 14
                [0,  0,  0,  0,  0,  0,  0], # map 15
]

size = len(dumps[0])

db = {i: list() for i in range(7)}

for unit_type in range(0, 7):
    unit_type_equality = [v[unit_type] for v in equality_matrix]
    equals = [i for i, v in enumerate(unit_type_equality) if v == 1]
    unequals = [i for i, v in enumerate(unit_type_equality) if v == 0]
    for i in range(size):
        values = [dump[i] for dump in dumps]
        selected_equals = [values[eq] for eq in equals]
        all_equal = all([v == selected_equals[0] for v in selected_equals])
        if all_equal:

            selected_unequals = [values[uneq] for uneq in unequals]
            all_equal = all([v != selected_equals[0] for v in selected_unequals])
            if all_equal:
                db[unit_type].append(i)

for unit_type, indices in db.items():
    print(f"{unit_type}: {indices}")

section_markers = {i: section.get_data() for i, section in enumerate(map_files[0].directory.sections)}

def find_section_for_offset(offset):
    cumsum = 0
    for i in range(len(section_markers)):
        cumsum += len(section_markers[i])
        if cumsum > offset:
            return i


for unit_type, indices in db.items():
    print(f"{unit_type}: {[find_section_for_offset(index) for index in indices]}")

# 36, 84
# Section1023, Section1085
#
# 0: [3504, 3508]
# 1: [3460, 3488]
# 2: [3468, 3496]
# 3: [3456, 3484]
# 4: [3464, 3492]
# 5: [3472]
# 6: [3476, 3512]

#3452 = archer
#3456 = crossbow
#3460 = spearman
#3464 = pikeman
#3468 = maceman
#3472 = swordsman
#3476 = knight

#3480 = bow weapon disappear
#3484 = crossbow weapon disappear
#3488 = spear
#3492 = pike
#3496 = mace
#3500 = swords
#3504 = leather
#3508 = armor
#3512 = horses disappear

#3520 = 1, if to 0, then player 1 is considered dead
#3548 = 8, if to 0, then player 8 is considered dead

#3564 = a short/int running time?

# trading:
#0117D1A4 = wheat
#0117D19C = ale
#0117D198 = apples
#0117D194 = meat
#0117D190 = cheese
#0117D18C = bread
#0117D188 = wheat
#0117D170 = hops

#0117D174 = stone
#0117D17C = iron
#0117D184 = oil

#0117D1DC game logic ticks?

