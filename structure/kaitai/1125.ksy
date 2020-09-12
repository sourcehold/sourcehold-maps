meta:
  id: "s1125"
  endian: le
  
seq:
  - id: player_names
    type: strz
    size: 90
    encoding: utf-8
    repeat: expr
    repeat-expr: 9
  - id: player_active
    type: u1
    repeat: expr
    repeat-expr: 9
  - id: padding0
    contents: [0x00]
  - id: gold
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: max_population
    type: s2
    repeat: expr
    repeat-expr: 9
  - id: max_good_things
    type: s1
    repeat: expr
    repeat-expr: 9
  - id: padding1
    contents: [0x00]
  - id: time_alive
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something1
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something2
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something3
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something4
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something5
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something6
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something7
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something8
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something9
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: buildings_burned
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: food_produced
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: iron_produced
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: stone_produced
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: wood_produced
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: pitch_produced #?
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: max_bad_things
    type: s1
    repeat: expr
    repeat-expr: 9
  - id: stars #?
    type: s1
    repeat: expr
    repeat-expr: 9
  - id: padding3
    contents: [0x00, 0x00]
  - id: weapons_produced
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: buildings_destroyed
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: troops_killed_weighted
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: buildings_destroyed_weighted
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: troops_produced
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: goods_recieved
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: goods_sent
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something12
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: something13 # seems to encode death somehow
    type: s4
    repeat: expr
    repeat-expr: 9
  - id: year_start
    type: s4
  - id: month_start
    type: s4
  - id: year_end
    type: s4
  - id: month_end
    type: s4
  - id: padding_final # filesize always 1912 bytes
    contents: [0x00]
    repeat: expr
    repeat-expr: 92
