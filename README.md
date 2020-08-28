# sourcehold-maps
Reverse engineering the map file format of Stronghold & Stronghold Crusader.

### Project goal
The goal is to understand the .map file format of Stronghold & Stronghold Crusader and to be able to manipulate it.

# Current progress
## Online map unpacking and exploring
Visit the [github page](https://sourcehold.github.io/sourcehold-maps/) for this repository to unpack .map and .sav files.

We understand the layout of a map file (e.g., see this C-style header [file](https://github.com/sourcehold/sourcehold-maps/blob/master/structure/map_structure.h)).
Further details and explanation can be found in the wiki of this repository.

## Contribute
If you want to contribute, unpack a map [online](https://sourcehold.github.io/sourcehold-maps/) and have a look [here](https://github.com/sourcehold/sourcehold-maps/wiki/Map-sections), and in the wiki, to help us understand all the sections! 


## Current functionalities of the Python library
### Unpacking
Unpack map/sav files to a folder:
```console
python examples/map_file_packing.py --dest out/ "Close Encounters.map"
```

### Generate images of map sections
```console
python examples/map_section_imaging.py "Close Encounters.map" "CloseEncountersImages"
```

### Map preview image
Extract an image like so:
```console
python examples/map_preview_image.py extract "Close Encounters.map" close_encounters.png
```
Substitute an image like so:
```console
python examples/map_preview_image.py replace "Close Encounters.map" --replacement close_encounters.png "Close Encounters mod.map"
```
### Modify map properties
#### Disable buildings
```python
from sourcehold import load_map, expand_var_path, save_map
# You can configure your installation folder (where shcmap points to) in /config.json
map = load_map(expand_var_path('shcmap~/Close Encounters.map'))
map.directory["building_availability"].granary = False
save_map(map, expand_var_path('shcusermap~/Close Encounters mod.map'))
```
#### Set starting popularity and goods
```python
from sourcehold import load_map, expand_var_path, save_map
# You can configure your installation folder (where shcmap points to) in /config.json
map = load_map(expand_var_path('shcmap~/Close Encounters.map'))
map.directory['STARTING_GOODS'].wood = 0
save_map(map, expand_var_path('shcusermap~/Close Encounters mod.map'))
```

## Dependencies
* Python 3.8
* Python Pillow
* Compile blast.c to blast .exe, which can be found here https://github.com/madler/zlib/blob/master/contrib/blast/blast.c

See the Wiki for further detailed information
