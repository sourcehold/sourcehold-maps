A map file consists of several parts.
* A header that includes a preview, some unknown data, and the description of the map.
* Then follows a specification of the map file. The file can be split into sections that are either compressed or uncompressed (specified).

Unpacking a .map file in our implementation yields a directory with files one can access and manipulate.

Sections have an index. Section files are named after that index. I am not sure what it means, but at least it is consistent.