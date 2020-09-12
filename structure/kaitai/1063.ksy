meta:
  id: "s1063"
  endian: le

seq:
  - id: scenario
    type: scenario_item
    repeat: expr
    repeat-expr: 200

types:
  scenario_item:
    seq:
      - id: month
        type: u4
      - id: year
        type: u4
      - id: item_type
        type: u4
      - id: magic
        contents: [0x00, 0x00, 0x00, 0x00]
      - id: intensity
        type: u4
      - id: invasion_content
        type: invasion
        if: item_type == 1
      - id: event_content
        type: event
        if: item_type == 3
      - id: empty
        type: u4
        repeat: expr
        repeat-expr: 52
        if: item_type != 1 and item_type != 3
        
      

  event:
    seq:
      - id: event_type
        type: u4
      - id: all_or_any_condition
        type: u1
      - id: magic
        contents: [0]
      - id: repeat
        type: u1
      - id: repeat_months
        type: u1
      - id: conditions
        type: condition
        repeat: expr
        repeat-expr: 39
      - id: win_timer
        type: u4
      - id: unknowns
        type: unknown
        repeat: expr
        repeat-expr: 10
  
  invasion:
    seq: 
      - id: units
        type: u4
        repeat: expr
        repeat-expr: 24
      - id: magic
        contents: [0x00, 0x00, 0x00, 0x00]
      - id: msg_month
        type: u4
      - id: msg_yr
        type: u4
      - id: repeat_months
        type: u4
      - id: crusader_arabian
        type: u4
      - id: unknowns
        type: unknown
        repeat: expr
        repeat-expr: 23
  
  condition:
    seq:
      - id: value
        type: u2
      - id: subtype
        type: u1
      - id: enabled
        type: u1
  
  unknown:
    seq:
      - id: magic
        contents: [0x00, 0x00, 0x00, 0x00]