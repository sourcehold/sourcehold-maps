from sourcehold.debugtools.memory.access import SHC as AccessContext
from sourcehold.debugtools.memory.common import memory_find, memory_findall

process = AccessContext()


def dump_section_locations(filepath, dump_suffix=""):

    name = filepath.name
    #name = name[:-4] if name.endswith(".map") or name.endswith(".sav") else name

    from sourcehold import load_map

    with open(f"sections_dump.{name}{dump_suffix}.txt", 'w') as f:
        memdump = process.read_all_memory()

        m = load_map(filepath)
        datas = {i: m.directory[i].get_data() for i in m.directory.section_indices if i != 0}

        f.write(f"section\toffsets\tactual offsets\n")

        for si, data in datas.items():
            offs = memory_find(data, memdump)
            hexoffs = [hex(v) for v in offs]
            hexactualoffs = [hex(v + process.base) for v in offs]

            f.write(f"{si}\t{hexoffs}\t{hexactualoffs}\n")
            f.flush()

from sourcehold import expand_var_path

#dump_section_locations(expand_var_path("shcusermap~/Door01.map"), ".editor")
#dump_section_locations(expand_var_path("shcusermap~/Door01.map"), ".editor.live")
#dump_section_locations(expand_var_path("shcusermap~/Door01.map"), ".play.welcome")
dump_section_locations(expand_var_path("shcusermap~/Door01.map"), ".play.live")

import pathlib, json


def import_dump(filepath):
    lines = pathlib.Path(filepath).read_text().splitlines()
    header = lines[0]
    result = {}
    for line in lines[1:]:
        section_index, address, real_address = line.split("\t")
        result[section_index] = json.loads(address.replace("'", '"'))

    return result


from functools import reduce


def compare_dumps(filepaths):
    contents = {filepath: import_dump(filepath) for filepath in filepaths}
    all_keys = set()
    for content in contents.values():
        for key in content.keys():
            all_keys.add(key)
    all_keys = sorted(all_keys)

    data = {}
    non_equals = set()
    reference_file = filepaths[0]
    for file, content in contents.items():
        if file == reference_file:
            continue
        for key in content.keys():
            if key not in contents[reference_file]:
                raise Exception(f"{key} not found in {file}")

            d1 = contents[reference_file][key]
            d2 = content[key]
            if d1 != d2 and len(d1) != 0 and len(d2) != 0:
                non_equals.add(key)
                print(f"values ({d1}  {d2}) are different for key {key}")
            else:
                if d1:
                    data[key] = d1
                if d2:
                    data[key] = d2

    for key in non_equals:
        data.pop(key)

    equals = "\n".join(sorted(set(all_keys) - non_equals))
    result = "\n".join(f"{section}: {addr}" for section, addr in sorted(data.items(), key=lambda v: v[0]))
    print(f"the following sections have consistent values: \n{result}")

    return sorted(data.items(), key=lambda v: v[0])


import xml.etree.ElementTree as ET

def create_cheat_engine_list(s_addresses):
    ET.fromstringlist("<>")


filepaths = ["sections_dump.Door01.map.editor.live.txt", "sections_dump.Door01.map.play.live.txt", "sections_dump.Door01.map.play.welcome.txt", "sections_dump.Door01.map.editor.txt"]

vs = compare_dumps(filepaths)


def findallsectionsindump(map, memdump):
    results = {}
    for i, index in enumerate(map.directory.section_indices):
        data = map.directory[index].get_data()
        all = memory_findall(memdump=memdump, data=data)
        results[index] = all
    return results


def memory_sieve(array_of_section_index_possibilities_dicts):
    result = {}
    for section in array_of_section_index_possibilities_dicts[0].keys():
        all_pos = [array_of_section_index_possibilities_dicts[i][section] for i in range(len(array_of_section_index_possibilities_dicts))]
        r = all_pos[0]
        for pos in all_pos:
            for v in pos:
                if v in r:
                    pass
                else:
                    r.remove(v)
        result[section] = r
    return result








