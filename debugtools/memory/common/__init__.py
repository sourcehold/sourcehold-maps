
def read_all_mem(p):
    return p.read_bytes(p.process_base.lpBaseOfDll, 34148352)


def memory_find(data, memdump):
    i = memdump.find(data)
    if i == -1:
        return []
    return [i]


def memory_findall(data, memdump):

    occurences = []
    i = 0

    i = memdump.find(data, i)

    while i != -1:
        occurences.append(i)
        i = memdump.find(data, i + 1)

    return occurences


section_lengths = {



}

#memory_complete = process.read_bytes(process.process_base.lpBaseOfDll, 34148352)

# test
import struct

import random
