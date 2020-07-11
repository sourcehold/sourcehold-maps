
from struct import unpack, calcsize, pack

try:
    from numpy import var
except ImportError:
    pass


def compare_index(index, *datas):
    return [data[index] for data in datas]


def generate_rows(*datas):
    n = min([len(data) for data in datas])
    for i in range(n):
        yield [data[i] for data in datas]


def find_equals(*datas):
    for i, row in enumerate(generate_rows(*datas)):
        if len(set(row)) == 1:
            yield i, row


def find_unequals(*datas):
    for i, row in enumerate(generate_rows(*datas)):
        if len(set(row)) != 1:
            yield i, row


def progressive_apply(*datas, summary=len, func=find_equals):
    n = len(datas)
    tests = [datas[0:i] for i in range(2, n+1)]
    for test in tests:
        yield summary(list(func(*test)))





def calculate_variance(x):
    return var(x)


def interpret_as(x, fmt):
    size = calcsize(fmt)
    n = len(x) // size
    return list(unpack("{}{}".format(n, fmt), x))


def uninterpret_as(x, fmt):
    n = len(x)
    return pack("{}{}".format(n, fmt), *x)


import csv


def write_csv(path, *datas, fieldnames=[]):
    if not fieldnames:
        fieldnames = ["d{}".format(i) for i in range(len(datas))]
    n = min(len(data) for data in datas)
    with path.open('w', newline='') as f:
        writer = csv.writer(f, delimiter='\t')
        writer.writerow(fieldnames)
        for i in range(n):
            row = [data[i] for data in datas]
            writer.writerow(row)


def adjust_ij(ij):
    i, j = ij
    return i, j + (abs(199 - i) if i < 200 else abs(200 - i))


