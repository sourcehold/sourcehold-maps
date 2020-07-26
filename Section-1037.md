Terrain data in tile map format: oasis (all types), earth, earth and stones, sand?

|value|type|
|---|---|
|0x00|earth|
|0x01|scrub|
|0x02|earth & stones|
|0x04|earth or sand? (changes to earth on update)|
|0x08|earth or sand? (changes to earth on update)|
|0x10|oasis grass|
|0x20|beach|
|0x40|driven sand|
|0x80|thick scrub|

It is a bit flag, because:
|value|type|
|0x03|earth & stones|
|0x04| earth or sand? (changes to earth on update)|
|0x08| earth or sand? (changes to earth on update)|
|0x30|oasis grass|
|0x50|oasis grass|
|0x60|driven sand|
|0x70|oasis grass|
