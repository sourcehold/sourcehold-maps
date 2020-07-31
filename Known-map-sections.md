## Basic section information
Every section has a four digit key identifier in the 1000-1126 range. Not every number in this range is used.

Every section is fixed in size, even for different map sizes.

So far, there are three general structures for sections:
- Tile data.
When sections contain tile data, they are a multiple of 80400 in size (there are 80400 usable tiles in a world map).
- Array data. Other data such as unit data is stored in fixed-size array form where each element is of a fixed-size.
- Other data. There are also sections with data such as the in-game date, popularity, stock levels, etcetera, building availability.

A section can be in a compressed state. Most tile data sections are stored in a compressed state (exception: section 1008).

# Overview table
| Index | Size | Type | Interpretation |
| ------------- | ------------- | --- | --- |
| 1001 | 160800 | Tile data (short) | Contains many objects, but not units. Seems to be a cache for drawing the screen |
| 1002 | 160800 | Tile data (short) | Contains terrain height data (as well as section 1005) |
| 1003 | 321600 | Tile data (int) | Contains information about buildings, non-buildable terrain types (water, rocks, hills) |
| 1004 | 160800 | Tile data (short) | Trees and rocks |
| 1005 | 80400  | Tile data (byte) | Contains height data, including stairs |
| 1008 ||Tile data| Random numbers used for texture diversity. Changes when buildings built and destroyed in editor. |
| 1009 | 160800 | Tile data (short) | Something with oil and walls, and the stronghold. Odd.|
| 1010 | | Tile data| Unit Unique ID
| 1012| | Tile data | Building unique ID |
|1013|1624000| Info data array | Building data in array format. Max 2000 buildings, every building is 812 bytes.|
|1015| 2920000 | Info data array |Unit data in array format. Max 2500 units and every unit is 1168 bytes.|
| 1021 ||||
| 1030 | |||
| 1036 | 160800 | Tile data (short) | Contains terrain roughness data, looks like patches (each patch tiles increment by 64), but the terrain type is mysterious |
| 1037 |80400   | Tile data (byte) | Contains earth/sand/grass texture data in SHC|
| 1049 | 80400 | Tile data (byte) | Building type idenfiers |
| 1073 | 200    | Info data (short) | Building availability in booleans |

| 1085 | 14 | Info data (short) | Unit availability (non-arab units) |