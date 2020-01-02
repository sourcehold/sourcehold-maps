from sourcehold.structure_tools import Table

files = [
    'file_inspection/maps/160cb_unseen',
    'file_inspection/maps/160cr_unseen',
    'file_inspection/maps/400cb_unseen',
    'file_inspection/maps/400cr_unseen',
    'file_inspection/maps/Close Encounters'
]

key = 1001


def average_overlap(a, b):
    length = len(a) if len(a) < len(b) else len(b)
    count = 0
    for i in range(length):
        if a[i] == b[i]:
            count += 1
    return "{} / {}".format(count, length)


def create_matrix_from_files_for_key(files, key, evaluation):
    datas = [open(file + "/{}.dat".format(key), 'rb').read() for file in files]

    matrix = Table([file.split('/')[-1] for file in files], [file.split('/')[-1] for file in files])

    for x in range(len(datas)):
        for y in range(len(datas)):
            if x == y:
                continue
            if x > y:
                continue

            matrix.set(x, y, evaluation(datas[x], datas[y]))

    return matrix


def describe_keys_for_files(keys, files, compare=len):
    matrix = Table(keys, files)
    for file in files:
        for key in keys:
            data = open("file_inspection/maps/" + file + "/{}.dat".format(key), 'rb').read()
            matrix.set(key, file, compare(data))
    return matrix


# matrix = create_matrix_from_files_for_key(files, key, average_overlap)

import os
import csv


def write_key_comparison():
    keys = [file.split(".dat")[0] for file in os.listdir("file_inspection/maps/160cb_unseen") if file.endswith(".dat")]
    data = [create_matrix_from_files_for_key(files, key, average_overlap).as_dict_array() for key in keys]

    for i in range(len(keys)):
        for j in range(len(data[i])):
            data[i][j]['key'] = keys[i]

    with open('file_inspection/tryout1.csv', 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=["key", "a", "b", "value"])
        writer.writeheader()
        for i in range(len(data)):
            writer.writerows(data[i])


def write_key_description():
    keys = [file.split(".dat")[0] for file in os.listdir(files[-1]) if file.endswith(".dat")]
    m = describe_keys_for_files(keys, [file.split("/")[-1] for file in files])

    data = m.as_array("section")

    mw = MarkdownTableWriter()
    mw.table_name = "Comparison of lengths of sections"
    mw.headers = data[0]
    mw.value_matrix = data[1:]

    with open("file_inspection/section_length.md", 'w') as f:
        mw.dump(f)


from pytablewriter import MarkdownTableWriter


def get_dat_files(path):
    return [file for file in os.listdir(path) if file.endswith(".dat")]


def compare_files_on_percentage_byte_overlap(changed_keys, filesdict, skip_equal=True):
    header = ["section", "file1", "file2", "percentage overlap"]
    matrix = []

    for key in filesdict.keys():
        keys = [k for k in filesdict[key].keys()]
        for i in range(len(keys)):
            for j in range(len(keys)):
                if i >= j:
                    continue
                key1 = keys[i]
                key2 = keys[j]
                d1 = filesdict[key][key1]
                d2 = filesdict[key][key2]

                if skip_equal:
                    if d1 == d2:
                        continue

                changed_keys.add(key)

                v = average_overlap(d1, d2)
                matrix.append([key, key1, key2, v])

    writer = MarkdownTableWriter()
    # writer.table_name = title
    writer.value_matrix = matrix
    writer.headers = header

    return writer


from sourcehold import maps
from sourcehold.maps import library


def create_byte_comparison(files, title, outputfile):
    fs = files

    ufs = [f for f in fs if not os.path.exists(f)]
    for uf in ufs:
        mapname = os.path.basename(uf)
        with open(library.LIBRARY.get_from_maps(mapname) + ".map", 'rb') as f:
            buf = maps.Buffer(f.read())
        map = maps.Map().from_buffer(buf)
        map.dump_to_folder("file_inspection/maps/" + mapname)

    names = [os.path.basename(f) for f in fs]
    files = ["/" + f for f in os.listdir("file_inspection/maps/" + names[0])] + ["/sections/" + f for f in os.listdir(
        "file_inspection/maps/" + names[0] + "/sections")]
    files.remove("/sections")

    fsdict = {f: {os.path.basename(fname): open(fname + f, 'rb').read() for fname in fs} for f in files}

    changed_keys = set()
    w = compare_files_on_percentage_byte_overlap(changed_keys, fsdict)
    changed_keys = sorted(list(changed_keys))

    with open(outputfile, "w") as f:
        f.write("#{}\r\n".format(title))
        f.write("The following sections were unequal:\r\n\r\n" + "\r\n".join(changed_keys) + "\r\n")
        w.dump(f)


def compare_unit_movement():
    fs = [
        "file_inspection/maps/160cr_arab_archer_red",
        "file_inspection/maps/160cr_arab_archer_r_m1",
        "file_inspection/maps/160cr_arab_archer_r_m2",
        "file_inspection/maps/160cr_arab_archer_r_m3",
    ]

    ufs = [f for f in fs if not os.path.exists(f)]
    for uf in ufs:
        mapname = os.path.basename(uf)
        with open(library.LIBRARY.get_from_maps(mapname) + ".map", 'rb') as f:
            buf = maps.Buffer(f.read())
        map = maps.Map().from_buffer(buf)
        map.dump_to_folder("file_inspection/maps/" + mapname)

    names = [os.path.basename(f) for f in fs]
    files = ["/" + f for f in os.listdir("file_inspection/maps/" + names[0])] + ["/sections/" + f for f in os.listdir(
        "file_inspection/maps/" + names[0] + "/sections")]
    files.remove("/sections")

    fsdict = {f: {os.path.basename(fname): open(fname + f, 'rb').read() for fname in fs} for f in files}

    changed_keys = set()
    w = compare_files_on_percentage_byte_overlap(changed_keys, fsdict)
    changed_keys = sorted(list(changed_keys))

    with open("file_inspection/findings/byte_overlap_in_unit_movement.md", "w") as f:
        f.write("#Percentage of byte overlap in unit movement\r\n")
        f.write("The following sections were unequal:\r\n\r\n" + "\r\n".join(changed_keys) + "\r\n")
        w.dump(f)


def compare_view_nav():
    fs = [
        "160crnav_upleft",
        "160crnav_upright",
        "160crnav_lowleft",
        "160crnav_lowright",
    ]

    ufs = [f for f in fs if not IMPORT_HELPER.exists_in_library(f)]
    for uf in ufs:
        IMPORT_HELPER.dump_to_library(uf)

    paths = [IMPORT_HELPER.get_library_path_to(f) for f in fs]
    w = compare_files_on_percentage_byte_overlap("Percentage of byte overlap in view navigation", paths)

    w.dump(open("file_inspection/findings/byte_overlap_in_view_navigation.md", "w"))


def a():
    create_byte_comparison([
        "file_inspection/maps/S_noveg",
        "file_inspection/maps/S_onetree",
        "file_inspection/maps/S_removetree",
        "file_inspection/maps/S_anothertree_left",
    ], "Byte comparison of vegetation (a tree)", "file_inspection/findings/byte_overlap_in_vegetation.md")


def b():
    create_byte_comparison([
        "file_inspection/maps/S_onewall_tl",
        "file_inspection/maps/S_onewall_tltr",
        "file_inspection/maps/S_onewall_tltrdr",
        "file_inspection/maps/S_onewall_tltrdrdl",
    ], "Byte comparison of wall placements", "file_inspection/findings/byte_overlap_in_wall_placements.md")


def c():
    create_byte_comparison([
        "file_inspection/maps/XL_1knight_100p",
        "file_inspection/maps/XL_1knight_60p"
    ], "Byte comparison of unit health", "file_inspection/findings/byte_overlap_in_unit_health.md")


if __name__ == "__main__":
    create_byte_comparison([
        "file_inspection/maps/Scr",
        "file_inspection/maps/160cr_arab_archer_red"
    ], "Byte comparison of unit creation", "file_inspection/findings/byte_overlap_in_unit_creation.md")
