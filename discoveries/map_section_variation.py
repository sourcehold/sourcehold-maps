from sourcehold import load_map
import pathlib

# section_index: section_data dictionary
reference_data = {}
reference_data_source = {}

differences = {}

path_to_traverse = pathlib.Path("~/Desktop/SHCHD1.41/maps").expanduser()

def generate_different_sections_index():

    for path in path_to_traverse.iterdir():
        print(f"processing: {path.name}")

        map = load_map(path)
        for index in map.directory.section_indices:
            if index == 0:
                continue

            if index in differences.keys():
                continue  # If we already have two different maps, move on.

            if index not in reference_data:
                reference_data[index] = map.directory[index].get_data()
                reference_data_source[index] = path
            else:

                if reference_data[index] != map.directory[index].get_data():
                    if index not in differences:
                        differences[index] = []

                    differences[index].append((reference_data_source[index], path))

    import json

    (pathlib.Path() / "map_section_variation.map").write_text(json.dumps({index: [paths[0][0].name, paths[0][1].name] for index, paths in differences.items()}, indent=2))


from debugtools.memory.common import memory_findall
from sourcehold import expand_var_path, save_map
from debugtools.memory.common.access import AccessContext

process = AccessContext()

map1 = load_map(expand_var_path("shcmap~/A Friend Indeed.map"))
map2 = load_map(expand_var_path("shcmap~/A Mighty Oasis.map"))

memdump1 = process.read_all_memory()


def unlock_game_map(name):
    m = load_map(expand_var_path(f"shcmap~/{name}.map"))
    m.u3.map_locked = 0
    save_map(m, expand_var_path(f"shcusermap~/{name}.map"))


map1 = load_map(expand_var_path("shcmap~/A Friend Indeed.map"))
map2 = load_map(expand_var_path("shcmap~/Caesarea Swampland.map"))
map1.u3.map_locked = 0
map2.u3.map_locked = 0
save_map(map1, expand_var_path("shcusermap~/A Friend Indeed - unlocked.map"))
save_map(map2, expand_var_path("shcusermap~/Caesarea Swampland - unlocked.map"))


from debugtools.memory.common.comparisons import compare_bytes_bytewise
from hashlib import sha1
from binascii import b2a_hex

def generate_single_section_map_comparison(section=1106):
    datas = {path: load_map(path).directory[section].get_data() for path in path_to_traverse.iterdir()}

    items = list(datas.items())

    reference = items[0]

    values = {}

    if len(reference[1]) > 32:
        f = lambda v: b2a_hex(sha1(v).digest())
    else:
        f = lambda v: b2a_hex(v)

    for path, data in items:
        values[path] = f(data)

    (pathlib.Path() / f"map_variation_per_section_{section}.md").write_text("|index|values|\n|---|---|\n" + f"\n".join(f"|{path.name}|{value}|" for path, value in values.items()))

    return values



