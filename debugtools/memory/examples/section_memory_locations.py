from debugtools.memory.common.access import AccessContext
from debugtools.memory.common import memory_find, memory_findall

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
