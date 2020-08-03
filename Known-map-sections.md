## Basic section information
Every section has a four digit key identifier in the 1000-1136 range. Not every number in this range is used.
Numbers >= 1100 seem applicable to Crusader only.

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
| 1002 | 160800 | Tile data (short) | Contains terrain data: keeps, stockpile, boulders, iron  |
| 1003 | 321600 | Tile data (int) | Contains information about buildings, non-buildable terrain types (water, rocks, hills) |
| 1004 | 160800 | Tile data (short) | Trees and rocks |
| 1005 | 80400  | Tile data (byte) | Contains height data, including stairs |
| 1006 | 80400 | Tile data (byte) | Whether a unit can move from a tile to another tile (stored as direction flags) |
|1007|160800|Tile data||
| 1008 |160800 |Tile data| Random numbers used for texture diversity. Changes when buildings built and destroyed in editor. |
| 1009 | 160800 | Tile data (short) | Something with oil and walls, and the stronghold. Odd.|
| 1010 | 160800| Tile data| Unit Unique ID
| 1012| 160800| Tile data | Building unique ID |
|1013|1624000| Info data array | Building data in array format. Max 2000 buildings, every building is 812 bytes.|
|1014|312000|Tile data||
|1015| 2920000 | Info data array |Unit data in array format. Max 2500 units and every unit is 1168 bytes.|
|1016|1025000|||
|1017|28|||
|1018|4|||
|1019|4|||
|1020|80400|Tile data||
| 1021 |160800|Tile data||
|1022|133524|||
|1023|262608|||
|1024|4|||
|1025|696000|||
|1026|160800|Tile data||
|1028|80400|Tile data||
|1029|80400|Tile data||
| 1030 | 80400|Tile data||
|1031|103200|||
| 1033 |160800|Tile data| Buildings, including destroyed ones. |
|1034|256000|||
|1035|4|||
| 1036 | 160800 | Tile data (short) | Contains terrain roughness data, looks like patches (each patch tiles increment by 64), but the terrain type is mysterious |
| 1037 |80400   | Tile data (byte) | Contains earth/sand/grass texture data in SHC|
|1038|128000|||
|1040|40016|||
|1041|256000|||
|1042|4|||
|1043|80400|Tile data||
|1044|4|||
|1045|80400|Tile data||
|1046|4|||
|1047|4|||
|1048|4|||
| 1049 | 80400 | Tile data (byte) | Building type idenfiers |
|1050|4|||
|1051|4|||
|1052|4|||
|1053|4|||
|1054|4|||
|1055|4|||
|1056|4|||
|1057|4|||
|1058|100|||
|1059|80|||
|1061|4|||
|1062|4|||
|1063|45600|Event data| Events |
|1064|32000|||
|1065|100|||
|1066|4|||
|1067|28|||
|1068|4|||
|1071|4|||
|1072|4|||
| 1073 | 200    | Info data (short) | Building availability in booleans |
|1074|4|||
|1076|4|||
|1077|10000|||
|1078|32|||
|1079|32|||
|1080|4|||
|1081|4|||
|1082|4|||
|1083|80000|||
|1084|4|||
| 1085 | 14 | Info data (short) | Unit availability (non-arab units) |
|1086|2|||
|1087|2|||
|1088|2|||
|1089|128|||
|1090|4|||
|1091|1062748|||
|1093|4|||
|1095|4|||
|1099|200000|||
|1100|36|||
|1101|36|||
|1102|14|||
|1103|80400|Tile data||
|1104|80400|Tile data||
|1105|723600|Tile data||
|1106|4|||
|1107|252504|||
|1108|4|||
|1109|4|||
|1110|4|||
|1111|2|||
|1112|2|||
|1113|2|||
|1114|307200|||
|1115|816|||
|1116|4|||
|1117|4|||
|1118|80400|Tile data||
|1119|4|||
|1120|4|||
|1121|36|||
|1122|4|||
|1123|4|||
|1124|264|||
|1125|1912|||
|1126|4|||
|1127|4|||
|1129|4|||
|1130|4|||
|1131|4|||
|1132|4|||
|1133|4|||
|1134|2000|||
|1135|4000|||
|1136|1|||