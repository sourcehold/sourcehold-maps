A map file consists of several parts.
* A header that includes a preview, some unknown data, and the description of the map.
* Then follows a specification of the map file data sections. These sections are either compressed or uncompressed (specified).

Unpacking a .map file in our implementation yields a directory with files one can access and manipulate.

Sections have an index. Section files are named after that index. I am not sure what it means, but at least it is consistent.

See [map structure](https://github.com/sourcehold/sourcehold-maps/blob/master/sourcehold/maps/map_structure.h) for a C++-like description of a map file.