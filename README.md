# sourcehold-maps
Reverse engineering the map file format of Stronghold

### Project goal
The goal is to understand the .map file format of Stronghold (& Stronghold Crusader).

# Current progress
You can run map preview extractor Python file to extract the map preview image.

```r
python preview_image_extractor.py input_file output_file
```

## Unpack a .map file
You can run unpacker.py to unpack a .map file into a directory
```r
python unpacker.py map_file output_directory
```

## .map file specification
See the Wiki and `map_structure.h` for details.

## Dependencies
* Python 3 (I have not tested 2.7)
* Python Pillow
* Compile blast.c to blast .exe, which can be found here https://github.com/madler/zlib/blob/master/contrib/blast/blast.c

See the Wiki for further detailed information
