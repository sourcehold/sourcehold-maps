Welcome to the sourcehold-maps wiki!

## The general layout of a .map file (and .sav file)
A map file is a zip file with a header and data sections.
The header consists of:
- a preview of the world image
- a custom description of the map
- whether the map is considered balanced for all player positions
- and much more (most of which is unknown)

The data sections are often compressed, and contain, for example:
- tile data (terrain, terrain height, buildings)
- unit data (unit locations, health)

However, there are roughly 30 sections (depends on map type), and it is currently unclear what some sections represent.

Click on one of the pages on the right to know more about the .map file format.

## How to read the specs
We use [kaitai](https://kaitai.io) to communicate the file format specification for two reasons:
1. The specs can be used to automagically generate deserialization code in many languages.
2. They have a nice [Web IDE](https://ide.kaitai.io) that is easy to use for inspection purposes.

To view a specification and its mapping to data, follow these steps:
1. open the Kaitai [Web IDE](https://ide.kaitai.io)
2. download the .ksy file for the section you want to learn about
3. drag and drop the .ksy file in the IDE
4. drag and drop a data file in the IDE
5. inspect the data file

Note: due to compressed sections, you should probably unzip a map file first. To "unzip" (and uncompress) a map file, you can use [this](https://sourcehold.github.io/sourcehold-maps) converter.