meta:
  id: crusader_1_41
  file-extension: cfg
seq:
  - id: struct1
    type:
      switch-on: _io.size
      cases:
        '1328': struct1_16
  - id: gamespeed
    type: s4le
  - id: bubblehelp
    type: s4le
  - id: resolution_copy
    type: s4le
  - id: zoom
    type: s4le
  - id: scrollspeed
    type: s4le
  - id: soundactive
    type: s4le
  - id: streamvolume0
    type: s4le
  - id: streamvolume1
    type: s4le
  - id: streamvolume3
    type: s4le
  - id: progresscalltoarms
    type: s4le
  - id: progresssaladinsconquest
    type: s4le
  - id: progressthekingscrusade
    type: s4le
  - id: progresscrusaderstates
    type: s4le
  - id: unknown8
    type: s4le
  - id: unknown9
    type: s4le
  - id: autosaveminutes
    type: s4le
  - id: unknown10
    type: s4le
  - id: unknown11
    type: s4le
  - id: unknown12
    type: s4le
  - id: unknown13
    type: s4le
  - id: unknown14
    type: s4le
  - id: unknown15
    type: s4le
  - id: cursortype
    type: s4le
  - id: ip
    type:
      switch-on: _io.size
      cases:
        '1328': struct2_16
  - id: furthestmission
    type: s4le
  - id: lordicon
    type: s4le
  - id: skirmishtrailprogress
    type: s4le
  - id: selectedlordtype
    type: s4le
  - id: skirmishtrailyearreached
    type: s4le
  - id: skirmishtrailmonthstakenorchicken
    type: s4le
    repeat: expr
    repeat-expr: 50
  - id: genievoiceactive
    type: s4le
  - id: unknown19
    type: s4le
  - id: warchesttrailprogress
    type: s4le
  - id: warchesttrailyearreached
    type: s4le
  - id: warchesttrailmonthstakenorchicken
    type: s4le
    repeat: expr
    repeat-expr: 30
  - id: unknown22
    type: s4le
  - id: extremetrailprogress
    type: s4le
  - id: extremetrailyearreached
    type: s4le
  - id: extremetrailmonthstakenorchicken
    type: s4le
    repeat: expr
    repeat-expr: 30
  - id: unknown26
    type: s1
  - id: unknown27
    type: s1
  - id: resolution
    type: s4le
types:
  struct1_8:
    seq:
      - id: unknown0
        size: 15*1
        type: str
        encoding: UTF-8
      - id: unknown1
        size: 5*1
        type: str
        encoding: UTF-8
      - id: unknown2
        size: 15*1
        type: str
        encoding: UTF-8
      - id: playername
        size: 256*1
        type: str
        encoding: UTF-8
  struct1_16:
    seq:
      - id: unknown0
        size: 15*2
        type: str
        encoding: UTF-16LE
      - id: unknown1
        size: 5*2
        type: str
        encoding: UTF-16LE
      - id: unknown2
        size: 15*2
        type: str
        encoding: UTF-16LE
      - id: playername
        size: 256*2
        type: str
        encoding: UTF-16LE
  struct2_8:
    seq:
      - id: ip1
        type: str
        encoding: UTF-8
        size: 20
      - id: ip2
        type: str
        encoding: UTF-8
        size: 20
      - id: ip3
        type: str
        encoding: UTF-8
        size: 20
      - id: ip4
        type: str
        encoding: UTF-8
        size: 20
  struct2_16:
    seq:
      - id: ip1
        type: str
        encoding: UTF-16LE
        size: 20*2
      - id: ip2
        type: str
        encoding: UTF-16LE
        size: 20*2
      - id: ip3
        type: str
        encoding: UTF-16LE
        size: 20*2
      - id: ip4
        type: str
        encoding: UTF-16LE
        size: 20*2
  