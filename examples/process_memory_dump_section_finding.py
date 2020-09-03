
from sourcehold.debugtools.memory.common.access import AccessContext
import pathlib


def dump(name):
    process = AccessContext()
    pathlib.Path(name + ".dump").write_bytes(process.read_all_memory())


mapnames = ["a-resourceful-divide-rat",
        "craggy-cliffs-rat",
        "savegame-resav",
        "friedrichburg-resav",
        "sherif burg1-resav",
        "arab mit harnish-resav"] + [f"dump{i}-resav" for i in range(1, 26)]


def load_save(mapname):
    return load_map(expand_var_path("shcusersav~/" + mapname + ".sav"))


def load_dump(mapname):
    return pathlib.Path(mapname + ".dump").read_bytes()


import random
#mapnames = random.choices(mapnames, k=10)
mapnames = mapnames[-5:]

from sourcehold import load_map, expand_var_path
from debugtools.memory.common import memory_findall

saves = [load_save(mapname) for mapname in mapnames]
#dumps = [load_dump(mapname) for mapname in mapnames]

location_options = {}

from debugtools.memory.common.access import load_address_list_from_cheat_table

all_section_selection = [int(k[:4]) for k in load_address_list_from_cheat_table().keys() if '?' in k]
section_selection = [k for k in all_section_selection if len(set([map.directory[k].get_data() for map in saves])) > 2]  # We need > 2 here, else the results are not accurate in case of 0s in the data.

print(f"WARNING: {len(set(all_section_selection).difference(set(section_selection)))} sections had identical data, and were skipped.")
print(f"processing {len(section_selection)} sections for {len(saves)} maps")

datas = [{index: m.directory[index].get_data() for index in section_selection} for m in saves]

saves.clear()

for section in section_selection:#[i for i in map.directory.section_indices if i != 0]:

    print(f"processing section: {section}")

    ref_data = datas[0][section]
    ref_dump = load_dump(mapnames[0])

    misses = []
    location_options[section] = memory_findall(ref_data, ref_dump)

    print(f"in processing section: {section}, there were {len(location_options[section])} initial candidates")

    for i in range(1, len(mapnames)):
        other_dump = load_dump(mapnames[i])
        other_data = datas[i][section]
        new_candidates = [candidate for candidate in location_options[section] if other_dump[candidate:candidate+len(other_data)] == other_data]
        print(f"processing map {i} lost us {len(set(location_options[section]) - set(new_candidates))} candidates for section {section}")
        location_options[section] = new_candidates

    print(f"in processing section: {section}, we found the following locations {[hex(candidate) for candidate in location_options[section]]}")

    for i, data in enumerate(datas):
        del data[section]

    # for candidate in memory_findall(ref_data, ref_dump):
    #     miss = False
    #     for i in range(1, len(mapnames)):
    #         other_dump = load_dump(mapnames[i])
    #         other_data = datas[i][section]
    #         if other_dump[candidate:].startswith(other_data):
    #             continue
    #         else:
    #             miss = True
    #             break
    #     if not miss:  #another option here is using: else:  # If succesfully looped through the for loop without breaking. Basically: if not miss:
    #         print(f"in processing section: {section}, we found a location {hex(candidate)}")
    #         location_options[section].append(candidate)
    #
    # for i, data in enumerate(datas):
    #     del data[section]
