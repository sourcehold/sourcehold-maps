
def read_all_mem(p):
    return p.read_bytes(p.process_base.lpBaseOfDll, 34148352)


def memory_find(data, memdump):

    try:
        return [memdump.index(data)]
    except:
        return []


def memory_findall(data, memdump):

    occurences = []
    i = 0
    while True:
        try:
            i = memdump.index(data, i)
            occurences.append(i)
            i += 1
        except:
            break

    return occurences


section_lengths = {



}

#memory_complete = process.read_bytes(process.process_base.lpBaseOfDll, 34148352)

# test
import struct

import random
