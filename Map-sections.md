A key step to understanding the map/sav file format is to understand its sections.
We understand some of them, but not all of them yet.

Generally speaking, there are two types of sections:
1. Info data regarding the map, like building availability, starting goods, etcetera, see [here](https://github.com/sourcehold/sourcehold-maps/blob/master/sourcehold/maps/sections/__init__.py)
2. Tile data. A map consists of 80400 tiles (you can imagine it is as four triangles with each 20100 tiles stitched together at their right angle to form a diamond), and are layed out in a specific format, see [here](https://github.com/sourcehold/sourcehold-maps/blob/master/resources/tiles-illustration.pdf).
3. 



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
mymap = load_map(expand_var_path('shcusermap~/mymap.map'))
sections_directory = mymap.directory #contains the map sections

# To view an image of tile data sections:
mymap.directory[1001].create_image().show()

# To inspect tile data sections:
s1036 = mymap.directory[1036] #retrieve a (tile data) section by index
data = mymap.directory[1036].get_data()
tiles = mymap.directory[1036].get_tiles() #Tile system representation starting at the top right, to the bottom left.

tiles[1][1] = 1000

# To save edited values
mymap.directory[1036].pack(True)
mymap.directory.pack()
save_map(mymap, expand_var_path('shcusermap~/mymap.map'))

# To compare map sections
m1 = load_map(expand_var_path('shcusermap~/basic0.map'))
m2 = load_map(expand_var_path('shcusermap~/basic0_change.map'))
for ineq in m1.yield_inequalities(m2):
    print(ineq)
```