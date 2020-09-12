meta:
  id: map
  file-extension: map, sav, msv
  endian: le

seq:
  - id: magic
    contents: [0xff, 0xff, 0xff, 0xff]
  - id: preview
    type: preview
  - id: description
    type: description
  - id: u1
    type: simple_section
  - id: u2
    type: simple_section
  - id: u3
    type: simple_section
  - id: u4
    type: simple_section
  - id: ud
    contents: [0xff, 0xff, 0xff, 0xff]
    if: u4.size != 0
  - id: directory
    type: directory
  - id: sections
    repeat: expr
    repeat-expr: _root.directory.sections_count
    type:
      switch-on: _root.directory.section_compressed[_index]
      cases:
        0: defined_section(_index)  # <= pass `_index` into file_entry
        1: compressed_section

types:
  preview:
    seq:
      - id: size
        type: u4
      - id: section
        type: compressed_section

  description:
    seq:
      - id: size
        type: u4
      - id: use_string_table
        type: u4
      - id: string_table_index
        type: u4
      - id: section
        type: compressed_section

  directory:
    seq:
      - id: directory_size
        type: u4
      - id: size
        type: u4
      - id: sections_count
        type: u4
      - id: directory_u1
        type: u4
        repeat: expr
        repeat-expr: 5
      - id: uncompressed_lengths
        type: u4
        repeat: expr
        repeat-expr: 'directory_u1[0] >= 161 ? 150 : 100'
      - id: section_lengths
        type: u4
        repeat: expr
        repeat-expr: 'directory_u1[0] >= 161 ? 150 : 100'
      - id: section_indices
        type: u4
        repeat: expr
        repeat-expr: 'directory_u1[0] >= 161 ? 150 : 100'
      - id: section_compressed
        type: u4
        repeat: expr
        repeat-expr: 'directory_u1[0] >= 161 ? 150 : 100'
      - id: section_offsets
        type: u4
        repeat: expr
        repeat-expr: 'directory_u1[0] >= 161 ? 150 : 100'
      - id: u7
        type: u4

  compressed_section:
    seq:
      - id: uncompressed_size
        type: u4
      - id: compressed_size
        type: u4
      - id: hash
        type: u4
      - id: data
        size: compressed_size

  defined_section:
    params:
      - id: i  # => receive `_index` as `i` here
        type: u4
    seq:
      - id: data
        size: _root.directory.section_lengths[i]

  simple_section:
    seq:
      - id: size
        type: u4
      - id: data
        size: size

instances:
  max_sections_count:
    value: '_root.directory.directory_u1[0] >= 161 ? 150 : 100'
