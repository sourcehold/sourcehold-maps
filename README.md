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
python -m sourcehold --in "mymap.map" "mymap2.map" --unpack
```
### (Re)packing
Repack map/sav folder to a file:
```console
python -m sourcehold --in "mymap/" "mymap2/" --pack
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

## Installation
Find the right wheel file for your OS and (python) architecture [here](https://github.com/sourcehold/sourcehold-maps/actions?query=workflow%3A%22Python+package%22) (download the artifacts of the latest succesful build).
Then install using pip:
```console
python -m pip install sourcehold.whl
```

