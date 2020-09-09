meta:
  id: section1107
  endian: le
  
seq:
  - id: player_data
    type: player_data_1107
    size: 28056
    repeat: expr
    repeat-expr: 9

types:
  player_data_1107:
    seq:
      - id: player_id
        type: u4
      - id: ai_id
        type: u4
        enum: ai_id_1107
      - id: unknown2
        type: u4
      - id: keep_orientation
        type: u4
        doc: |
          orientation of the top left corner of the keep; 
          0: north
          2: west
          4: south
          6: east
      - id: unknown4
        type: u4
      - id: unknown5
        type: u4
      - id: unknown6
        type: u4
      - id: unknown7
        type: u4
      - id: step_total
        type: u4
      - id: unknown9
        type: u4
      - id: unknown10
        type: u4
      - id: unknown11
        type: u4
      - id: unknown12
        type: u4
      - id: building_steps
        type: building_step
        # size: 1000 # why does size for automatic padding not work like for player_data?
        repeat: expr
        repeat-expr: step_total+1
        doc: | 
          step 0: nothing
          step 1: keep
          step 2+: steps as displayed in aiv editor
      - id: padding1                    
        size: 12000-12*(step_total+1)
      - id: region_tile_index
        type: u4
        repeat: expr
        repeat-expr: 4000
      - id: total_region_tiles
        type: u4

  building_step:
    seq:
      - id: build_status
        type: u1
        enum: built_status
      - id: flag2
        type: u1
      - id: building_type
        type: u2
        enum: building_id_1107
      - id: quantity
        type: u2
      - id: flag3
        type: u2
      - id: building_instruction
        type: u2
        doc: |
          buildings: absolute tile index
          wall, moat, pitch: builds region, defined as
          q = quantity
          bi = building_instruction
          rti = region_tile_index
          region = rti[bi:bi+q]
      - id: flag4
        type: u2
  
enums:
  built_status:
    1: unbuilt      # build never
    3: built        # built once
    5: unbuildable  # cannot be build
    
  building_id_1107:
    # walls
    25:  high_wall
    46:  low_wall
    26:  high_crenel
    35:  low_crenel
    181: stairs_1
    182: stairs_2
    183: stairs_3
    184: stairs_4
    185: stairs_5
    # 186: stairs_6 #?
    # castle
    110: tower_1
    111: tower_2
    112: tower_3
    113: tower_4
    114: tower_5
    180: oil_smelter
    312: dog_cage
    98:  killing_pit
    86:  mercenary_post
    144: small_gatehouse_ew
    145: small_gatehouse_ns
    146: large_gatehouse_ew
    147: large_gatehouse_ns
    105: drawbridge
    # weapons and troops
    82:  poleturner
    50:  fletcher
    83:  blacksmith
    85:  tanner
    84:  armourer
    87:  barracks
    81:  armoury
    88:  engineer_guild
    89:  tunnelor_guild
    65:  stables
    # industy
    52:  stockpile
    51:  woodcutter
    56:  quarry
    55:  ox_tether
    90:  iron_mine
    91:  pitch_rig
    77:  trading_post
    # moats and pitch
    106: moat
    99:  pitch
    # food
    80:  granary
    72:  apple_farm
    73:  dairy_farm
    70:  wheat_farm
    78:  hunter
    71:  hops_farm
    74:  windmill
    75:  bakery
    76:  brewery
    92:  inn
    # town
    54:  house
    95:  chapel
    96:  church
    97:  cathedral
    93:  healers
    330: well
    342: waterpot
    # good things
    175: maypole
    324: dancing_bear
    313: statue
    318: shrine
    169: town_garden
    166: comunal_garden
    325: small_pond
    327: large_pond
    # bad things
    176: gallows
    301: cess_pit
    177: stocks
    305: burning_stake
    307: dungeon
    308: rack
    306: gibbet
    310: chopping_block
    311: dunking_stool
    
  ai_id_1107:
    0:  no_ai   # human or empty
    2:  rat
    3:  snake
    4:  pig
    5:  wolf
    6:  saladin
    7:  caliph
    8:  sultan
    9:  richard
    10: frederick
    11: philipp
    12: wazir
    13: emir
    14: nizar
    15: marshal
    16: marshal
    17: abbot