Welcome to the sourcehold-maps wiki!

# Current progress

## World
 - [x] Understand the [coordinate system](https://github.com/sourcehold/sourcehold-maps/wiki/Map-coordinates)

## Units
 - [x] Manipulate unit type
   - [x] Figure out [unit type IDs](https://github.com/J-T-de/CrusaderData/blob/master/data/crusader_data.CT)
 - [X] Manipulate unit location
 - [X] Manipulate unit path
 - [ ] Manipulate unit health
 - [ ] Manipulate unit owner
 - [ ] Manipulate unit task
 - [ ] Manipulate unit destination
 - [ ] Manipulate unit grouping
 - [ ] Manipulate items carried by worker
 - [ ] Manipulate unit health
  
## Buildings
 - [x] Manipulate building type
   - [ ] Figure out [building type IDs](https://github.com/J-T-de/CrusaderData/blob/master/data/crusader_data.CT)
   - [ ] Correct building tile drawing
 - [ ] Manipulate worker associated with building
 - [ ] Manipulate building sleep state
 - [ ] Manipulate building health/damage
 - [ ] Manipulate building on fire
 
## Terrain
 - [ ] Manipulate terrain height
 - [ ] Manipulate terrain type
 - [ ] Manipulate terrain type pattern

## General map info
 - [ ] Manipulate balanced/unbalanced
 - [ ] Manipulate type (deathmatch, ...)
 
## General game experience
 - [ ] Manipulate view box
 - [ ] Manipulate game speed
 - [ ] Manipulate zoom level
 - [ ] Manipulate rotation

# Getting started with debugging

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

## Unpacking a map file
Due to compression, you should probably unzip a map file first. To "unzip" (and uncompress) a map file, you can use [this](https://sourcehold.github.io/sourcehold-maps) converter.

## How to use the specs
We use [kaitai](https://kaitai.io) to communicate the file format specification for two reasons:
1. The specs can be used to automagically generate deserialization code in many languages.
2. They have a nice [Web IDE](https://ide.kaitai.io) that is easy to use for inspection purposes.

Additionally, specs are sometimes communicated via a C struct like pseudo format.

To view a kaitai specification and its mapping to data, follow these steps:
1. open the Kaitai [Web IDE](https://ide.kaitai.io)
2. download the .ksy file for the section you want to learn about
3. drag and drop the .ksy file in the IDE
4. drag and drop a data file in the IDE
5. inspect the data file

## Contributing
You are very much invited to file an issue or a pull request to the sourcehold-maps repository explaining what you found.

### Debugging tips
* Zero out (wipe) sections to see what disappears. Re-save the map file and see what data is reintroduced.
* If loading your own modified map file crashed the game, the cause is probably a deserialization issue.
In other words, all sections can be wiped to 0's and the game will still happily load the map (but it might be unusable).  