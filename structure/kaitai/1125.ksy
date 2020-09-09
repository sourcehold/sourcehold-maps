meta:
  id: "s1125"
  file-extension: "s1125"
  endian: le
  
seq:
  - id: player_names
    type: strz
    size: 90
    encoding: "utf-8"
    repeat: expr
    repeat-expr: 9
  - id: player_active # if player is participating or not
    type: u1
    repeat: expr
    repeat-expr: 9
  - id: padding0
    contents: [0x00]
  - id: something0
    type: u4
    repeat: expr
    repeat-expr: 9
  - id: something1
    type: u2
    repeat: expr
    repeat-expr: 9
  - id: something2
    type: u1
    repeat: expr
    repeat-expr: 9
  - id: padding1
    contents: [0x00]
  - id: something3
    type: u4
    repeat: expr
    repeat-expr: 9
  - id: something4
    type: u4
    repeat: expr
    repeat-expr: 248