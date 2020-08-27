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
| [1001](Section-1001) | Tile data (short) | Contains many objects, but not units. Seems to be a cache for drawing the screen |
| [1002](Section-1002) | Tile data (short) | Contains terrain data: keeps, stockpile, boulders, iron  |
| [1003](Section-1003) | Tile data (int)   | Contains information about buildings, non-buildable terrain types (water, rocks, hills) |
| [1004](Section-1004) | Tile data (short) | Trees and rocks |
| [1005](Section-1005) | Tile data (byte)  | Contains height data, including stairs |
| [1006](Section-1006) | Tile data (byte)  | Whether a unit can move from a tile to another tile (stored as direction flags) |
| [1007](Section-1007) | Tile data (short) ||
| [1008](Section-1008) | Tile data (short) | Random numbers used for texture diversity. Changes when buildings built and destroyed in editor. |
| [1009](Section-1009) | Tile data (short) | Something with oil and walls, and the stronghold. Odd.|
| [1010](Section-1010) | Tile data (short) | Unit Unique ID
| [1012](Section-1012) | Tile data (short) | Building unique ID |
| [1013](Section-1013) | Info data array   | Building data in array format. Max 2000 buildings, every building is 812 bytes.|
| [1014](Section-1014) | Tile data (int)   ||
| [1015](Section-1015) | Info data array   | Unit data in array format. Max 2500 units and every unit is 1168 bytes.|
| [1016](Section-1016) |||
| [1017](Section-1017) |||
| [1018](Section-1018-1019) | Int               | `x_view`: specifies `x`-position of the map. |
| [1019](Section-1018-1019) | Int               | `y_view`: specifies `y`-position of the map. |
| [1020](Section-1020) | Tile data (byte)  ||
| [1021](Section-1021) | Tile data (short) ||
| [1022](Section-1022) | Info data (mixed) | Contains player data. |
| [1023](Section-1023) |||
| [1024](Section-1024) |||
| [1025](Section-1025) |||
| [1026](Section-1026) | Tile data (short) ||
| [1028](Section-1028) | Tile data (byte)  ||
| [1029](Section-1029) | Tile data (byte)  ||
| [1030](Section-1030) | Tile data (byte)  ||
| [1031](Section-1031) |||
| [1033](Section-1033) | Tile data (short) | Buildings, including destroyed ones. |
| [1034](Section-1034) |||
| [1035](Section-1035) |||
| [1036](Section-1036) | Tile data (short) | Contains terrain roughness data, looks like patches (each patch tiles increment by 64), but the terrain type is mysterious |
| [1037](Section-1037) | Tile data (byte)  | Contains earth/sand/grass texture data in SHC|
| [1038](Section-1038) |||
| [1040](Section-1040) | Random state      | Contains the internal state of the random number generator. |
| [1041](Section-1041) |||
| [1042](Section-1042) |||
| [1043](Section-1043) | Tile data (byte)  ||
| [1044](Section-1044) | Int               | Map orientation. |
| [1045](Section-1045) | Tile data (byte)  ||
| [1046](Section-1046) | Int               ||
| [1047](Section-1047) | Int               ||
| [1048](Section-1048) | Int               ||
| [1049](Section-1049) | Tile data (byte)  | Building type idenfiers |
| [1050](Section-1050) | Int               | Map size (160, 200, 300 or 400) |
| [1051](Section-1051) |||
| [1052](Section-1052) |||
| [1053](Section-1053) |||
| [1054](Section-1054) |||
| [1055](Section-1055) |||
| [1056](Section-1056) | Int               | Starting year (or current year?). |
| [1057](Section-1057) | Int               | Starting month (or current month?). |
| [1058](Section-1058) | Info data (int)   | Starting resources. |
| [1059](Section-1059) |||
| [1061](Section-1061) | Int               | Starting popularity. |
| [1062](Section-1062) |||
| [1063](Section-1063) | Event data        | Events. |
| [1064](Section-1064) |||
| [1065](Section-1065) | Info data (int)   | Trade availability (bool). |
| [1066](Section-1066) |||
| [1067](Section-1067) |||
| [1068](Section-1068) |||
| [1071](Section-1071) |||
| [1072](Section-1072) |||
| [1073](Section-1073) | Info data (short) | Building availability (bool). |
| [1074](Section-1074) |||
| [1076](Section-1076) |||
| [1077](Section-1077) |||
| [1078](Section-1078) |||
| [1079](Section-1079) |||
| [1080](Section-1080) |||
| [1081](Section-1081) |||
| [1082](Section-1082) |||
| [1083](Section-1083) |||
| [1084](Section-1084) |||
| [1085](Section-1085) | Info data (short) | Barrack unit availability (bool). |
| [1086](Section-1086) | Short             | Xbow producible (bool). |
| [1087](Section-1087) | Short             | Sword producible (bool). |
| [1088](Section-1088) | Short             | Pike producible (bool). |
| [1089](Section-1089) |||
| [1090](Section-1090) |||
| [1091](Section-1091) |||
| [1093](Section-1093) |||
| [1095](Section-1095) |||
| [1099](Section-1099) |||
| [1100](Section-1100) |||
| [1101](Section-1101) |||
| [1102](Section-1102) | Info data (short) | Mercenary unit availability (bool). |
| [1103](Section-1103) | Tile data (byte)  ||
| [1104](Section-1104) | Tile data (byte)  ||
| [1105](Section-1105) | Tile data ???     ||
| [1106](Section-1106) |||
| [1107](Section-1107) |||
| [1108](Section-1108) |||
| [1109](Section-1109) |||
| [1110](Section-1110) |||
| [1111](Section-1111) | Short             | Bow producible (bool). |
| [1112](Section-1112) | Short             | Mace producible (bool). |
| [1113](Section-1113) | Short             | Spear producible (bool). |
| [1114](Section-1114) |||
| [1115](Section-1115) |||
| [1116](Section-1116) |||
| [1117](Section-1117) |||
| [1118](Section-1118) | Tile data (byte)  ||
| [1119](Section-1119) |||
| [1120](Section-1120) |||
| [1121](Section-1121) |||
| [1122](Section-1122) |||
| [1123](Section-1123) |||
| [1124](Section-1124) |||
| [1125](Section-1125) |||
| [1126](Section-1126) |||
| [1127](Section-1127) |||
| [1129](Section-1129) |||
| [1130](Section-1130) |||
| [1131](Section-1131) |||
| [1132](Section-1132) |||
| [1133](Section-1133) |||
| [1134](Section-1134) |||
| [1135](Section-1135) |||
| [1136](Section-1136) |||