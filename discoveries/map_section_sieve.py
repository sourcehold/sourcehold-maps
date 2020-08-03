

from sourcehold import load_map, expand_var_path
import struct

maps = ["shusersav~/eco_free_pop80.sav",
        "shusersav~/eco_free_pop79.sav",
        "shusersav~/eco_free_pop78.sav"]

maps = [load_map(expand_var_path(m)) for m in maps]

# No results
targets = [80, 79, 78]
targets = [struct.pack("B", v) for v in targets]
# What about floats?
targets = [80, 79, 78]
targets = [struct.pack("f", v) for v in targets]
# What about doubles?
targets = [80, 79, 78]
targets = [struct.pack("d", v) for v in targets]
# What about half floats?
targets = [80, 79, 78]
targets = [struct.pack("e", v) for v in targets]


maps = ["shusersav~/eco_free_pop80.sav",
        "shusersav~/eco_free_pop79.sav",
        "shusersav~/eco_free_pop78.sav",
        "shusersav~/eco_free_pop77_gold_21.sav",
        "shusersav~/eco_free_pop75_gold_23.sav",
        "shusersav~/eco_free_pop73_gold_27.sav"]

maps = [load_map(expand_var_path(m)) for m in maps]

# Hooray! This shows section 1022, index 7268 is the integer for gold amount.
targets = [20, 20, 20, 21, 23, 27]
targets = [struct.pack("B", v) for v in targets]
# # What about floats?
# targets = [20, 20, 20, 21]
# targets = [struct.pack("f", v) for v in targets]
# # What about doubles?
# targets = [20, 20, 20, 21]
# targets = [struct.pack("d", v) for v in targets]
# # What about half floats?
# targets = [20, 20, 20, 21]
# targets = [struct.pack("e", v) for v in targets]


def find_all(needle, haystack):
    start = 0

    finds = []

    index = haystack.find(needle, start)

    if index == -1:
        return finds

    while index != -1:
        finds.append(index)
        index = haystack.find(needle, index + 1)

    return finds


def sieve(maps, targets):
    assert len(maps) == len(targets)

    finds = {}

    for section in filter(lambda v: v != 0, maps[0].directory.section_indices):
        datas = [map.directory[section].get_data() for map in maps]

        f = sieve_data(datas, targets)

        if len(f) > 0:
            finds[section] = f

    return finds

def sieve_old(maps, targets):
    finds = None

    for i in range(len(maps)):
        map = maps[i]
        target = targets[i]

        if finds is None:
            finds = {section: find_all(target, map.directory[section].get_data()) for section in filter(lambda v: v != 0, map.directory.section_indices)}
            print(f"potential locations: {sum(len(v) for v in finds.values())}")
        else:
            misses = []

            finds = {section: [index for index in indices if map.directory[section].get_data()[index] == target] for section, indices in finds.items()}

            misses = [section for section, indices in finds.items() if len(indices) == 0]

            for miss in misses:
                finds.pop(miss)
                print(f"sieved out section {miss}")

    return finds


def sieve_data(datas, targets):
    assert len(datas) == len(targets)

    finds = None

    for i in range(len(datas)):
        data = datas[i]
        target = targets[i]

        if finds is None:
            finds = find_all(target, data)
            print(f"potential locations: {len(finds)}")
        else:
            misses = []

            finds = [index for index in find_all(target, data) if index in finds]

    return finds


sieve_data(datas=[b'\x01\x02\x03\x04', b'\x02\x02\x04\x05', b'\x01\x02\x05\x06'], targets=[b'\x01', b'\x02', b'\x01'])


finds = sieve(maps, targets)