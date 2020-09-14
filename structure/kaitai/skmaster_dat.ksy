meta:
  id: skmaster2_dat
  file-extension: dat
  endian: le
  # Automatically sorted by score!
  # missing: kills and killed units
  imports:
    - s1125

seq:
  - id: header
    type: header
    size: 1012
  - id: entries
    type: entry
    size: 3056
    repeat: expr
    repeat-expr: header.num_entries - 1
  - id: final_entry
    type: final_entry
    
types:
  header:
    seq:
    - id: magic
      contents: [0x00, 0x00, 0x40, 0x40]
    - id: num_entries
      type: s4
    - id: version
      type: s4
      
  entry:
    seq:
      - id: preview_data
        type: preview_data
      - id: results
        type: s1125         # imported struct
      - id: description
        type: description
        
  final_entry:
    seq:
      - id: preview_data
        type: preview_data
      - id: results
        type: s1125         # imported struct
      # the last entry is always missing the description...
        
  preview_data:
    seq:
      - id: score
        type: s4
      - id: num_players
        type: s4
      - id: team
        type: s4
        repeat: expr
        repeat-expr: 9
      - id: ai_id
        type: s4
        enum: ai_id_skmaster_dat
        repeat: expr
        repeat-expr: 9
      - id: survived
        type: s4
        repeat: expr
        repeat-expr: 9
      - id: player_lord_type
        type: s4
      - id: day
        type: s4
      - id: month
        type: s4
      - id: year
        type: s4
      - id: play_time_min     # minutes
        type: s4
      - id: play_time_ingame  # ticks or something
        type: s4
        
  description:
    seq:
      - id: map_description_index  # encodes map name, 0 for user generated maps
        type: u4
      - id: map_name        # used if map_description_index == 0
        type: strz
        size: 90            # size unclear, standard 90 byte string?
        encoding: utf-8
        
enums:
  ai_id_skmaster_dat:
    0:  no_ai               # human or empty
    1:  rat
    2:  snake
    3:  pig
    4:  wolf
    5:  saladin
    6:  caliph
    7:  sultan
    8:  richard
    9:  frederick
    10: philipp
    11: wazir
    12: emir
    13: nizar
    14: sheriff
    15: marshal
    16: abbot