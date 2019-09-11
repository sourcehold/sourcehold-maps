from structure_tools import Table

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


def compare_files_on_percentage_byte_overlap(title, files, keys=None):
    if keys == None:
        keys = [file.split(".")[0] for file in get_dat_files(files[0])]

    fnames = [file.split("/")[-1] for file in files]

    header = ["section", "file1", "file2", "percentage overlap"]
    matrix = []

    for key in keys:
        datas = [open(file + "/{}.dat".format(key), 'rb').read() for file in files]

        for i in range(len(datas)):
            for j in range(len(datas)):
                if i >= j:
                    continue
                d1 = datas[i]
                d2 = datas[j]
                v = average_overlap(d1, d2)
                # v = round(v, 3)
                matrix.append([key, fnames[i], fnames[j], v])

    writer = MarkdownTableWriter()
    writer.table_name = title
    writer.value_matrix = matrix
    writer.headers = header

    return writer


import unpacker

IMPORT_HELPER = unpacker.ImportHelper()


def compare_unit_movement():
    fs = [
        "file_inspection/maps/160cr_arab_archer_red",
        "file_inspection/maps/160cr_arab_archer_r_m1",
        "file_inspection/maps/160cr_arab_archer_r_m2",
        "file_inspection/maps/160cr_arab_archer_r_m3",
    ]

    ufs = [f for f in fs if not os.path.exists(f)]
    for uf in ufs:
        mapname = uf.split("/")[-1]
        IMPORT_HELPER.dump_to_library(mapname)

    w = compare_files_on_percentage_byte_overlap("Percentage of byte overlap in unit movement", fs)

    w.dump(open("file_inspection/findings/byte_overlap_in_unit_movement.md", "w"))


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

if __name__ == "__main__":
    compare_view_nav()
