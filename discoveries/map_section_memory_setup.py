

from sourcehold import *
import binascii

map = load_map(expand_var_path("shcusermap~/Door01.map"))


def activity_level(d):
    avg = sum([v for v in d]) / len(d)
    var = sum([abs(avg - v) ** 2 for v in d]) / len(d)
    return var

def highest_activity_level(data):
    chunk_size = 50
    scores = {i: activity_level(data[i:i+50]) for i in range(0, len(data), chunk_size)}.items()

    return sorted(scores, key=lambda o: o[1], reverse=True)[0]


for i, section in enumerate(map.directory.sections):
    if len(section.get_data()) % 80400 == 0 and len(section.get_data()) != 0:

        print(map.directory.section_indices[i])
        print(binascii.b2a_hex(section.get_data()[:60]))

#         target = "section" + str(map.directory.section_indices[i])
#         target = target.encode('ascii')
#         #target = b''.join([target.encode('ascii')[i:i+1] + b'\x00' for i in range(len(target.encode('ascii')))])
#
#         data = section.get_data()
#         section.set_data(target + data[len(target):])
#
#         print(target)
#
#         section.pack(True)
#
# map.directory.pack()
#
# save_map(map, expand_var_path("shcusermap~/xlcr_mem_2.map"))
