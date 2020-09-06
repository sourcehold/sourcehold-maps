# sourcehold-maps/structure

This folder contains different files and subfolders describing the structure of the map file format in a machine-readable way. For a more human readable version see the [wiki](https://github.com/sourcehold/sourcehold-maps/wiki).  
Note: None of these structure definitions are used directly; synchronization between different files need to be done by hand.

## structure/kaitai
The [kaitai](https://kaitai.io/) structure defines cross-platform and cross-language parser definitions. It is used to reverse static binary files.  
The power of this tool is its [online IDE](https://ide.kaitai.io/), which can also generate parsers for many languages, and the superb [documentation](https://doc.kaitai.io/user_guide.html).

## structure/cheatengine
Cheat engine is the swiss knife of game hacking and reversing. Some structures are really hard/almost impossible to reverse statically with kaitai. However, checking out the memory, dynamic properties are really easy to observe. In such cases we use cheat engine structure definitions.

## structure/construct
The python-package [construct](https://construct.readthedocs.io/en/latest/) is basically a python-only version of kaitai. The main advantage of this package is that it can not only parse, but also write files.

## map_structure.h
C-like description of the map file format. Due to different map versions, which is hard specify concise in C, we refere to [structure/kaitai](#structure/kaitai).