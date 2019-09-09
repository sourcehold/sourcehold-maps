from structure_tools import Table

files = [
    'file_inspection/maps/160cb_unseen',
    'file_inspection/maps/160cr_unseen',
    'file_inspection/maps/400cb_unseen',
    'file_inspection/maps/400cr_unseen'
]

key = 1001


def average_overlap(a, b):
    length = len(a) if len(a) < len(b) else len(b)
    count = 0
    for i in range(length):
        if a[i] == b[i]:
            count += 1
    return "{:.3f}".format(count / length)


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


# matrix = create_matrix_from_files_for_key(files, key, average_overlap)

import os

keys = [file.split(".dat")[0] for file in os.listdir("file_inspection/maps/160cb_unseen") if file.endswith(".dat")]
data = [create_matrix_from_files_for_key(files, key, average_overlap).as_dict_array() for key in keys]

for i in range(len(keys)):
    for j in range(len(data[i])):
        data[i][j]['key'] = keys[i]

import csv

with open('file_inspection/tryout1.csv', 'w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=["key", "a", "b", "value"])
    writer.writeheader()
    for i in range(len(data)):
        writer.writerows(data[i])
