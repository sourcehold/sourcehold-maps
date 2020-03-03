# sourcehold-maps
Reverse engineering the map file format of Stronghold & Stronghold Crusader.

### Project goal
The goal is to understand the .map file format of Stronghold (& Stronghold Crusader).
And to be able to manipulate it.

# Current progress
We understand the layout of a .map file (the [file format](https://github.com/sourcehold/sourcehold-maps/blob/master/sourcehold/maps/map_structure.h)).

Basically, a .map file is divided into sections, and each section contains a kind of map data. We understand some of the sections, but not all.

## Contribute
If you want to contribute, have a look [here](https://github.com/sourcehold/sourcehold-maps/wiki/Map-sections) and help us understand all the sections! 

## Current functionalities
### Unpacking
Unpack map/sav files to a folder:
```console
python examples/map_file_packing.py --dest out/ "Close Encounters.map"
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
from sourcehold import *
map = load_map(SHC_FILES.get_path_from_maps('Close Encounters'))
map.directory["building_availability"].granary = False
save_map(map, SHC_FILES_USER.get_path_from_maps('Close Encounters mod'))
```
#### Set starting popularity and goods
```python
from sourcehold import *
map = load_map(SHC_FILES.get_path_from_maps('Close Encounters'))
map.directory['STARTING_GOODS'].wood = 0
save_map(map, SHC_FILES_USER.get_path_from_maps('Close Encounters mod'))
```

## Dependencies
* Python 3.8
* Python Pillow
* Compile blast.c to blast .exe, which can be found here https://github.com/madler/zlib/blob/master/contrib/blast/blast.c

See the Wiki for further detailed information
