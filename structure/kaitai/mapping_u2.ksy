meta:
  id: mapping_u2
  endian: le

params:
  - id: size
    type: u4
    
seq:
  - id: fields
    type: u2
    repeat: expr
    repeat-expr: size
    
