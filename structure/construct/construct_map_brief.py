from construct import *

construct_map = Struct(
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

# U1
    "U1"        / Struct(
        "size"  / Int32ul,
        "data"  / Bytes(this.size)
    ),

# U2
    "U2"        / Struct(
        "size"  / Int32ul,
        "data"  / Bytes(this.size)
    ),

# U3
    "U3"        / Struct(
        "size"  / Int32ul,
        "data"  / Bytes(this.size)
    ),

# U4
    "U4"        / Struct(
        "size"  / Int32ul,
        "data"  / Bytes(this.size)
    ),

    If(this._s4 != 0, Const(b'\x00\x00\x00\x00')),


# Directory
    "dir" / Struct(
        "dir_size"      / Int32sl,
        "file_size_without_directory"/ Int32sl, # TODO: Check....
        "sec_cnt"       / Int32sl,
        "version"       / Int32sl,

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
            "index"        / Computed(lambda l: l._index),                               # index
            "uncompr_size" / Computed(lambda l: l._.dir.uncompr_size[l._index]),         # uncompressed size
            "compr_size"   / Computed(lambda l: l._.dir.compr_size[l._index]),           # compressed size
            "id"           / Computed(lambda l: l._.dir.id[l._index]),                   # identifier
            "is_compr"     / Computed(lambda l: l._.dir.is_compr[l._index]),             # is section compressed?
            "offset"       / Computed(lambda l: l._.dir.offset[l._index]),               # offset
        
            "data" / Switch(this.is_compr,
                {
                    # Uncompressed section
                    0:  Struct(
                    # 0:  LazyStruct(
                            "data" / Bytes(this._.uncompr_size)
                        ),
    
                    # Compressed section
                    1:  Struct(
                    # 1:  LazyStruct(
                            "uncompr_size"  / Int32ul,
                            "compr_size"    / Int32ul,
                            "crc_32"        / Int32ul,
                            "data"          / Bytes(this._.compr_size-12)
                        )
                }
            )
        )
    )
)