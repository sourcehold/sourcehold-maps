from construct import *

ConstructMap = Struct(
    Const(b'\xff\xff\xff\xff'),

# Preview
    "preview" / Struct(
        "size"          / Int32sl,
        "uncompr_size"  / Int32sl,
        "compr_size"    / Int32sl,
        "crc_32"        / Int32sl,
        "data"          / Bytes(this.compr_size),
    ),

# Description
    "description" / Struct(
        "size"                  / Int32sl,
        "use_string_table"      / Int32sl,
        "string_table_index"    / Int32sl,
        "uncompr_size"          / Int32sl,
        "compr_size"            / Int32sl,
        "crc_32"                / Int32sl,
        "data"                  / Bytes(this.compr_size),
    ),

# First Section contains SHC, SHCE multiplayer data (SH no files to check...)
    Const(b'\x08\x00\x00\x00'),
    "s1_unknown1"   / Int32sl,  # data types not clear, probably something smaller
    "s1_unknown2"   / Int32sl,

# Second Section contains map meta data, always 28 bytes long
    Const(b'\x1c\x00\x00\x00'),
    "type"          / Int32sl,  # TODO: document different types

    # following unknowns are always 0, except the listed SH multiplayer maps have a 1
    "s2_unknown1"   / Int32sl,  # mountain fortress, the four castles, wall to wall
    "s2_unknown2"   / Int32sl,  # mountain fortress, the four castles, wall to wall
    "s2_unknown3"   / Int32sl,  # mountain fortress, the four castles, wall to wall, 8 player - no walls, 8 player mayhem
    "s2_unknown4"   / Int32sl,  # wall to wall
    "s2_unknown5"   / Int32sl,  # wall to wall

    "player_cnt"    / Int32sl,  # TODO: not clear: some singleplayer maps also have a 0 up to 5...

# Third Section contains Firefly meta data
    "_s3"           / Int32sl,      # SH: 93; SHC: 93, 97, 1017; SHCE: 1017
    "s3_unknown0"   / Int32sl,
    "s3_unknown1"   / Int32sl,
    "official"      / Int32sl,      #locked
    "_s3_string"    / PaddedString(this._s3 - 12, "utf-8"),     # the idea of this string might have been to encode the name, but this is not used...

# Fourth Section contains more map meta data
    "_s4"           / Int32sl,  # SH: all maps 12, except 0: mission0; 4: mission1; 8: mission5, mission6, mission8, mission9, mission17, mission19; SHC, SHCE: all maps 80
    "s4_unknown0"   / If(this._s4 >=  4, Int32sl),  # always zero, except SH: king of the hill, the gauntlet
    If(this._s4 >=  8, Const(b'\x00\x00\x00\x00')),
    "s4_unknown2"   / If(this._s4 >= 12, Int32sl),  # SH: 0; SHC, SHCE: {0, 5, 10}

    # following entries only relevant for SHC and SHCE
    "unbalanced"    / If(this._s4 == 80, Int32sl),  # TODO: also invasion or economy scenario?

    # different numbers, seems to default to -1; unrolled array for individual naming
    "s4_unknown4"   / If(this._s4 == 80, Int32sl),
    "s4_unknown5"   / If(this._s4 == 80, Int32sl),
    "s4_unknown6"   / If(this._s4 == 80, Int32sl),
    "s4_unknown7"   / If(this._s4 == 80, Int32sl),
    "s4_unknown8"   / If(this._s4 == 80, Int32sl),
    "s4_unknown9"   / If(this._s4 == 80, Int32sl),
    "s4_unknown10"  / If(this._s4 == 80, Int32sl),
    "s4_unknown11"  / If(this._s4 == 80, Int32sl),
    "s4_unknown12"  / If(this._s4 == 80, Int32sl),
    "s4_unknown13"  / If(this._s4 == 80, Int32sl),
    "s4_unknown14"  / If(this._s4 == 80, Int32sl),
    "s4_unknown15"  / If(this._s4 == 80, Int32sl),
    "s4_unknown16"  / If(this._s4 == 80, Int32sl),
    "s4_unknown17"  / If(this._s4 == 80, Int32sl),
    "s4_unknown18"  / If(this._s4 == 80, Int32sl),
    "s4_unknown19"  / If(this._s4 == 80, Int32sl),

# Padding, does not exist for SH mission0, which is the only map with _s4 == 0
    If(this._s4 != 0, Const(b'\x00\x00\x00\x00')),

# Directory
    "dir" / Struct(
        "dir_size"      / Int32sl,
        "file_size_without_directory"/ Int32sl, # TODO: Check....
        "sec_cnt"       / Int32sl,
        "version"       / Int32sl,  # SH: {152, 154, 155, 158}; SH: {168, 161, 170, 172}; SHCE: 172

        Const(b'\x00\x00\x00\x00'*4),

        "uncompr_size"  / IfThenElse(this.version >= 161,  Array(150, Int32sl), Array(100, Int32sl)),
        "compr_size"    / IfThenElse(this.version >= 161,  Array(150, Int32sl), Array(100, Int32sl)),
        "id"            / IfThenElse(this.version >= 161,  Array(150, Int32sl), Array(100, Int32sl)),
        "is_compr"      / IfThenElse(this.version >= 161,  Array(150, Int32sl), Array(100, Int32sl)),
        "offset"        / IfThenElse(this.version >= 161,  Array(150, Int32sl), Array(100, Int32sl)),

        Const(b'\x00\x00\x00\x00'),
    ),

# Sections
    "sec" / Array(this.dir.sec_cnt,
        Struct(
            "index"         / Computed(lambda l: l._index),                               # index
            "uncompr_size"  / Computed(lambda l: l._.dir.uncompr_size[l._index]),         # uncompressed size
            "compr_size"    / Computed(lambda l: l._.dir.compr_size[l._index]),           # compressed size
            "id"            / Computed(lambda l: l._.dir.id[l._index]),                   # identifier
            "is_compr"      / Computed(lambda l: l._.dir.is_compr[l._index]),             # is section compressed?
            "offset"        / Computed(lambda l: l._.dir.offset[l._index]),               # offset

            "data" / Switch(this.id,
                {
                    1001: Struct(
                            Check(this._.uncompr_size == 160800),           # Checks can be removed later, but might help to find interesting stuff
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1002: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1003: Struct(
                            Check(this._.uncompr_size == 321600),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1004: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1005: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1006: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1007: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1008: Struct(
                            Check(this._.uncompr_size == 160800),
                            "data"          / Bytes(this._.uncompr_size)
                            ),

                    1009: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1010: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1012: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1013: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1014: Struct(
                            Check(this._.uncompr_size == 312000),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1015: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1016: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1017: Struct(
                            Check(this._.uncompr_size == 28),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1018: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1019: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1020: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1021: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1022: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1023: Struct(
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1024: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1025: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1026: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1027: Struct(
                            Check(this._.uncompr_size == 289332),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1028: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1029: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1030: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1031: Struct(
                            Check(this._.uncompr_size == 103200),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1033: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1034: Struct(
                            Check(this._.uncompr_size == 256000),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1035: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1036: Struct(
                            Check(this._.uncompr_size == 160800),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1037: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1038: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1040: Struct(
                            Check(this._.uncompr_size == 40016),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1041: Struct(
                            Check(this._.uncompr_size == 256000),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1042: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1043: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1044: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1045: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1046: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1047: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1048: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1049: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1050: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1051: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1052: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1053: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1054: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1055: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1056: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1057: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1058: Struct(
                            Check(this._.uncompr_size == 100),
                            "data" / Array(this._.uncompr_size//4, Int32sl)
                            ),

                    1059: Struct(
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1060: Struct(
                            "data" / Int32sl
                            ),

                    1061: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1062: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1063: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1064: Struct(
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1065: Struct(
                            Check(this._.uncompr_size == 100),
                            "data" / Array(this._.uncompr_size//4, Int32sl)
                            ),

                    1066: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1067: Struct(
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1068: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1071: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1072: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1073: Struct(
                            Check(this._.uncompr_size == 200),
                            "data" / Array(this._.uncompr_size//2, Int16sl)
                            ),

                    1074: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1075: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1076: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1077: Struct(
                            Check(this._.uncompr_size == 10000),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1078: Struct(
                            Check(this._.uncompr_size == 32),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1079: Struct(
                            Check(this._.uncompr_size == 32),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1080: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1081: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1082: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1083: Struct(
                            Check(this._.uncompr_size == 80000),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1084: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1085: Struct(
                            Check(this._.uncompr_size == 14),
                            "data" / Array(this._.uncompr_size//2, Int16sl)
                            ),

                    1086: Struct(
                            Check(this._.uncompr_size == 2),
                            "data" / Int16sl
                            ),

                    1087: Struct(
                            Check(this._.uncompr_size == 2),
                            "data" / Int16sl
                            ),

                    1088: Struct(
                            Check(this._.uncompr_size == 2),
                            "data" / Int16sl
                            ),

                    1089: Struct(
                            Check(this._.uncompr_size == 128),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1090: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1091: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1092: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1093: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1095: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1099: Struct(
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1100: Struct(
                            Check(this._.uncompr_size == 36),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1101: Struct(
                            Check(this._.uncompr_size == 36),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1102: Struct(
                            Check(this._.uncompr_size == 14),
                            "data" / Array(this._.uncompr_size//2, Int16sl)
                            ),

                    1103: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1104: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1105: Struct(
                            Check(this._.uncompr_size == 723600),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1106: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1107: Struct(
                            Check(this._.uncompr_size == 252504),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1108: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1109: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1110: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1111: Struct(
                            Check(this._.uncompr_size == 2),
                            "data" / Int16sl
                            ),

                    1112: Struct(
                            Check(this._.uncompr_size == 2),
                            "data" / Int16sl
                            ),

                    1113: Struct(
                            Check(this._.uncompr_size == 2),
                            "data" / Int16sl
                            ),

                    1114: Struct(
                            Check(this._.uncompr_size == 307200),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1115: Struct(
                            Check(this._.uncompr_size == 816),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1116: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1117: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1118: Struct(
                            Check(this._.uncompr_size == 80400),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1119: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1120: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1121: Struct(
                            Check(this._.uncompr_size == 36),
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1122: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1123: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1124: Struct(
                            "data" / Bytes(this._.uncompr_size)
                            ),

                    1125: Struct(
                            Check(this._.uncompr_size == 1912),
                            "uncompr_size"  / Int32sl,
                            "compr_size"    / Int32sl,
                            "crc_32"        / Int32sl,
                            "compr_data"    / Bytes(this._.compr_size - 12)
                            ),

                    1126: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1127: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1129: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1130: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1131: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1132: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1133: Struct(
                            Check(this._.uncompr_size == 4),
                            "data" / Int32sl
                            ),

                    1134: Struct(
                            Check(this._.uncompr_size == 2000),
                            "data" / Int32sl
                            ),

                    1135: Struct(
                            Check(this._.uncompr_size == 4000),
                            "data" / Int32sl
                            ),

                    1136: Struct(
                            Check(this._.uncompr_size == 1),
                            "data" / Int32sl
                            )
                },
                default = Struct(
                            Check(this._.uncompr_size == 0),
                            "data" / Bytes(this._.uncompr_size)
                            ),
            )
        )
    )
)