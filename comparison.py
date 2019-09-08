import unpacker

files = [
    '../../Documents/Stronghold Crusader/Maps/160cb_unseen.map',
    '../../Documents/Stronghold Crusader/Maps/160cr_unseen.map',
    '../../Documents/Stronghold Crusader/Maps/400cb_unseen.map',
    '../../Documents/Stronghold Crusader/Maps/400cr_unseen.map'
]

maps = [unpacker.MapStructure(0, open(file, 'rb').read()) for file in files]

import functools, operator

allfine = set(functools.reduce(operator.add, [map.verify() for map in maps]))
assert len(allfine) == 1 and True in allfine

sc = len(maps[0].meta_section.section_indices)

matrix = {}
for s in maps[0].sections_dict.keys():
    row = {}
    for x in range(len(maps)):
        for y in range(x + 1, len(maps)):
            if x == y:
                continue
            # key = "{} == {}".format(x, y)
            row[(x, y)] = maps[x].sections_dict[s].decompressed == maps[y].sections_dict[s].decompressed
    matrix[s] = row

for key in matrix.keys():
    print(key, ":")
    print("\t")
    row = matrix[key]
    print(row)
    # for key in row.keys():
    #     print(key[0], key[1], row[key])

key = 1001

matrix = {}
for s in [1001]:
    row = {}
    for x in range(len(maps)):
        for y in range(x + 1, len(maps)):
            if x == y:
                continue
            # key = "{} == {}".format(x, y)
            v = []
            for i in range(len(maps[x].sections_dict[s].decompressed)):
                va = maps[x].sections_dict[s].decompressed[i] == maps[y].sections_dict[s].decompressed[i]
                v.append(va)
            row[(x, y)] = v
    matrix[s] = row
