A key step to understanding the map/sav file format is to understand its sections.
We understand some of them, but not all of them yet.

Generally speaking, there are two types of sections:
1. Info data regarding the map, like building availability, starting goods, etcetera, see [here](https://github.com/sourcehold/sourcehold-maps/blob/master/sourcehold/maps/sections/__init__.py)
2. Tile data. A map consists of 19800 tiles, and are layed out in a specific format, see [here](https://github.com/sourcehold/sourcehold-maps/blob/master/resources/tiles-illustration.pdf).

# Overview table
| Index | Size | Type | Interpretation |
| ------------- | ------------- | --- | --- |
| 1001 | 160800 | Tile data (short) | Contains many objects, but not units |
| 1002 | 160800 | Tile data (short) | Contains terrain height data |
| 1003 | 321600 | Tile data (int) | Contains information about buildings, non-buildable terrain types (water, rocks, hills) |
| 1004 | 160800 | Tile data (short) | Trees and rocks |
| 1036 | 160800 | Tile data (short) | Contains terrain roughness data, looks like patches (each patch tiles increment by 64), but the terrain type is mysterious |
| 1073 | 200 | Info data (short) | Building availability in booleans |
| 1085 | 14 | Info data (short) | Unit availability (non-arab units) |

# How to contribute
## Using external tools
1. Unpack a .map file to a folder
```console
python examples\map_file_packing.py --unpack --dest a mymap.map
```
2. Investigate the sections with a hex editor, or other external tool of choice
3. Repack a .map folder to a .map file (experimental)
```console
python examples\map_file_packing.py --pack --dest mymap.map a
```
4. Optional: make images of tile data sections
```console
python examples\map_section_imaging.py a a\images
```
## Using Python
```python
from sourcehold import *
mymap = load_map(SHC_MAPS_USER.get_from_map('mymap.map'))
mymap.directory #contains the map sections

# To inspect tile data sections:
mymap.directory[1036] #retrieve a (tile data) section by index
data = mymap.directory[1036].get_data()
from sourcehold.maps.sections.tools import cut, DiamondSystem
cutdata = cut(data, "H", 198) #The type ('H') is a struct type ('short'), and depends on the size of data.

# To inspect a diamond (of size 2) on the map (starting at (1,0)):
d = DiamondSystem(396)
indices = d.retrieve_diamond_indices((1, 0), 2)
values = [d[i][j] for i, j in indices]

# To save edited values
save_map(mymap, SHC_MAPS_USERS.get_from_maps('mymap.map'))
```