# sourcehold-maps [![Discord](https://img.shields.io/discord/1259903348077756527.svg?color=7389D8&label=%20&logo=discord&logoColor=ffffff)](https://discord.gg/SKJGEGgPTv) <!-- omit in toc -->
Reverse engineering the map file format of the 2D Stronghold Games.

### Project Goal <!-- omit in toc -->
The goal is to understand the [map file format](#map-file-format) of Stronghold, Stronghold Crusader and Stronghold Crusader Extreme and to be able to [manipulate](#tools) it.

# Table of Contents <!-- omit in toc -->

- [Map File Format](#map-file-format)
- [Tools](#tools)
  - [Online Map Unpacking, Repacking and Exploring](#online-map-unpacking-repacking-and-exploring)
  - [Python Library](#python-library)
    - [Unpacking (CL)](#unpacking-cl)
    - [(Re-) Packing (CL)](#re--packing-cl)
    - [Generate Images of Map Sections (CL)](#generate-images-of-map-sections-cl)
    - [Map Preview Image (CL)](#map-preview-image-cl)
    - [Modify Map Properties](#modify-map-properties)
    - [Installation](#installation)
 
- [Contribute](#contribute)

# Map File Format
The current knowledge of the map file format (`*.map`, `*.sav` and `*.msv`) is documented in a human-readable form in the [wiki](https://github.com/sourcehold/sourcehold-maps/wiki) and in a machine-readable form in [here](/structure).

# Tools

## Online Map Unpacking, Repacking and Exploring
If you don't want to install the python library and jump directly into action, there is an [online tool](https://sourcehold.github.io/sourcehold-maps/) to unpack, repack and visualize map sections.

## Python Library
The python library contains multiple useful tools to interact with map files. The most important tools are directly accessible using the command line (CL), but most of the stuff is access

### Unpacking (CL)
Unpack map files to a folder:
```console
python -m sourcehold --in "mymap.map" "mymap2.map" "mysav.sav" --unpack
```
Unpack single sections:
```console
python -m sourcehold --in "mymap.map" "mysave.sav" --unpack --what 1107
```

### (Re-) Packing (CL)
Repack map folder to a file:
```console
python -m sourcehold --in "mymap/" "mymap2/" "mysav/" --pack
```

### Generate Images of Map Sections (CL)
```console
python examples/map_section_imaging.py "mymap.map" "mymap_images"
```

### Map Preview Image (CL)
Extract an image:
```console
python examples/map_preview_image.py extract "mymap.map" "mymap.png"
```

Substitute an image:
```console
python examples/map_preview_image.py replace "mymap.map" --replacement "mymap.png" "mymap_modified.map"
```

### Modify Map Properties
Disable buildings:
```python
from sourcehold import load_map, expand_var_path, save_map
# You can configure your installation folder (where shcmap points to) in /config.json
map = load_map(expand_var_path('shcmap~/mymap.map'))
map.directory["building_availability"].granary = False
save_map(map, expand_var_path('shcusermap~/mymap_modified.map'))
```

Set starting popularity and goods:
```python
from sourcehold import load_map, expand_var_path, save_map
map = load_map(expand_var_path('shcmap~/mymap.map'))
map.directory['STARTING_GOODS'].wood = 0
save_map(map, expand_var_path('shcusermap~/mymap_modified.map'))
```

### Installation
Find the right wheel file for your OS and (python) architecture [here](https://github.com/sourcehold/sourcehold-maps/actions?query=workflow%3A%22Python+package%22) (download the artifacts of the latest successful build).
Then install using pip:
```console
python -m pip install sourcehold.whl
```


# Contribute
There are multiple ways to contribute to this project, see [Contributing.md](/CONTRIBUTING.md) for more information.
