meta:
  id: 'tiles_u2'
  endian: le
seq:
  - id: header
    type: u2
    repeat: expr
    repeat-expr: 2
  - id: chunks1
    repeat: expr
    repeat-expr: 199
    type: chunk(_index)
  - id: chunks2
    repeat: expr
    repeat-expr: 199
    type: chunk(198-_index)
  - id: footer
    type: u2
    repeat: expr
    repeat-expr: 2    
types:
  chunk:
    params:
      - id: i  # => receive `_index` as `i` here
        type: u4
    seq:
      - id: header
        type: u2
        repeat: expr
        repeat-expr: 2
      - id: data
        type: u2
        repeat: expr
        repeat-expr: i*2
      - id: footer
        type: u2
        repeat: expr
        repeat-expr: 2
