## Basic section information
Every section has a four digit key identifier in the 1000-1136 range. Not every number in this range is used.
Numbers >= 1100 seem applicable to Crusader only.

Every section is fixed in size, even for different map sizes. Keep in mind, most data in this wiki currently only reflects Stronghold Crusader maps, there could be differences (for example, in Crusader Extreme, Section 1015 should be larger). This is not fully true and needs to be updated: there are different sizes, and for .sav files, some sections seem to grow.

So far, there are three general structures for sections:
- Tile data.
When sections contain tile data, they are a multiple of 80400 in size (there are 80400 usable tiles in a world map).
- Array data. Other data such as unit data is stored in fixed-size array form where each element is of a fixed-size.
- Other data. There are also sections with data such as the in-game date, popularity, stock levels, etcetera, building availability.

A section can be in a compressed state. Most tile data sections are stored in a compressed state (exception: section 1008).

# Overview table
| Index | Type              | Interpretation |
| :--: | :---------------- | :------------- |
| [1001](wiki/Section-1001) | Tile data (short) | Contains many objects, but not units. Seems to be a cache for drawing the screen |
| [1002](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1002) | Tile data (short) | Contains terrain data: keeps, stockpile, boulders, iron  |
| [1003](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1003) | Tile data (int)   | Contains information about buildings, non-buildable terrain types (water, rocks, hills) |
| [1004](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1004) | Tile data (short) | Trees and rocks |
| [1005](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1005) | Tile data (byte)  | Contains height data, including stairs |
| [1006](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1006) | Tile data (byte)  | Whether a unit can move from a tile to another tile (stored as direction flags) |
| [1007](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1007) | Tile data (short) ||
| [1008](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1008) | Tile data (short) | Random numbers used for texture diversity. Changes when buildings built and destroyed in editor. |
| [1009](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1009) | Tile data (short) | Something with oil and walls, and the stronghold. Odd.|
| [1010](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1010) | Tile data (short) | Unit Unique ID
| [1012](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1012) | Tile data (short) | Building unique ID |
| [1013](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1013) | Info data array   | Building data in array format. Max 2000 buildings, every building is 812 bytes.|
| [1014](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1014) | Tile data (int)   ||
| [1015](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1015) | Info data array   | Unit data in array format. Max 2500 units and every unit is 1168 bytes.|
| [1016](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1016) |||
| [1017](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1017) |||
| [1018](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1018-1019) | Int               | `x_view`: specifies `x`-position of the map. |
| [1019](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1018-1019) | Int               | `y_view`: specifies `y`-position of the map. |
| [1020](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1020) | Tile data (byte)  ||
| [1021](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1021) | Tile data (short) ||
| [1022](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1022) | Info data (mixed) | Contains player data. |
| [1023](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1023) |||
| [1024](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1024) |||
| [1025](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1025) |||
| [1026](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1026) | Tile data (short) ||
| [1028](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1028) | Tile data (byte)  ||
| [1029](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1029) | Tile data (byte)  ||
| [1030](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1030) | Tile data (byte)  ||
| [1031](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1031) |||
| [1033](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1033) | Tile data (short) | Buildings, including destroyed ones. |
| [1034](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1034) |||
| [1035](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1035) |||
| [1036](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1036) | Tile data (short) | Contains terrain roughness data, looks like patches (each patch tiles increment by 64), but the terrain type is mysterious |
| [1037](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1037) | Tile data (byte)  | Contains earth/sand/grass texture data in SHC|
| [1038](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1038) |||
| [1040](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1040) | Random state      | Contains the internal state of the random number generator. |
| [1041](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1041) |||
| [1042](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1042) |||
| [1043](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1043) | Tile data (byte)  ||
| [1044](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1044) | Int               | Map orientation. |
| [1045](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1045) | Tile data (byte)  ||
| [1046](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1046) | Int               ||
| [1047](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1047) | Int               ||
| [1048](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1048) | Int               ||
| [1049](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1049) | Tile data (byte)  | Building type idenfiers |
| [1050](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1050) | Int               | Map size (160, 200, 300 or 400) |
| [1051](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1051) |||
| [1052](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1052) |||
| [1053](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1053) |||
| [1054](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1054) |||
| [1055](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1055) |||
| [1056](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1056) | Int               | Starting year (or current year?). |
| [1057](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1057) | Int               | Starting month (or current month?). |
| [1058](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1058) | Info data (int)   | Starting resources. |
| [1059](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1059) |||
| [1061](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1061) | Int               | Starting popularity. |
| [1062](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1062) |||
| [1063](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1063) | Event data        | Events. |
| [1064](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1064) |||
| [1065](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1065) | Info data (int)   | Trade availability (bool). |
| [1066](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1066) |||
| [1067](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1067) |||
| [1068](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1068) |||
| [1071](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1071) |||
| [1072](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1072) |||
| [1073](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1073) | Info data (short) | Building availability (bool). |
| [1074](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1074) |||
| [1076](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1076) |||
| [1077](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1077) |||
| [1078](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1078) |||
| [1079](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1079) |||
| [1080](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1080) |||
| [1081](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1081) |||
| [1082](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1082) |||
| [1083](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1083) |||
| [1084](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1084) |||
| [1085](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1085) | Info data (short) | Barrack unit availability (bool). |
| [1086](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1086) | Short             | Xbow producible (bool). |
| [1087](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1087) | Short             | Sword producible (bool). |
| [1088](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1088) | Short             | Pike producible (bool). |
| [1089](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1089) |||
| [1090](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1090) |||
| [1091](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1091) |||
| [1093](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1093) |||
| [1095](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1095) |||
| [1099](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1099) |||
| [1100](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1100) |||
| [1101](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1101) |||
| [1102](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1102) | Info data (short) | Mercenary unit availability (bool). |
| [1103](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1103) | Tile data (byte)  ||
| [1104](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1104) | Tile data (byte)  ||
| [1105](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1105) | Tile data ???     ||
| [1106](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1106) |||
| [1107](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1107) |||
| [1108](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1108) |||
| [1109](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1109) |||
| [1110](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1110) |||
| [1111](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1111) | Short             | Bow producible (bool). |
| [1112](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1112) | Short             | Mace producible (bool). |
| [1113](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1113) | Short             | Spear producible (bool). |
| [1114](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1114) |||
| [1115](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1115) |||
| [1116](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1116) |||
| [1117](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1117) |||
| [1118](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1118) | Tile data (byte)  ||
| [1119](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1119) |||
| [1120](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1120) |||
| [1121](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1121) |||
| [1122](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1122) |||
| [1123](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1123) |||
| [1124](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1124) |||
| [1125](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1125) |||
| [1126](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1126) |||
| [1127](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1127) |||
| [1129](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1129) |||
| [1130](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1130) |||
| [1131](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1131) |||
| [1132](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1132) |||
| [1133](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1133) |||
| [1134](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1134) |||
| [1135](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1135) |||
| [1136](https://github.com/sourcehold/sourcehold-maps/wiki/Section-1136) |||