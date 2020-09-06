# sourcehold-maps/structure/kaitai

Here are the [kaitai](https://kaitai.io/) definitions of the map file format.

## Usage
Generate a parser:
- upload `kaitai_map.ksy` to the [web IDE](https://ide.kaitai.io/) (via drag-n-drop or upload on the bottom left)
- right-click on `kaitai_map.ksy` in the file browser, "Generate parser" and choose a language

Reverse a section:
- extract example data using for example the [online unpacker](https://sourcehold.github.io/sourcehold-maps/)
- upload this data to the [web IDE](https://ide.kaitai.io/) and double-click on the uploaded file
- create a new kaitai structure definition by right-clicking at the file browser and choose "Create .ksy file"
- define a new definition using the [documentation](https://doc.kaitai.io/user_guide.html)

## Files

|       name       | description                                    |
| :--------------: | :--------------------------------------------- |
| `kaitai_map.ksy` | kaitai definition of the map file format       |
| `mapping_u2.ksy` | TODO                                           |
|  `tiles_u2.ksy`  | TODO                                           |
|    `1XYZ.ksy`    | structure definition of the associated section |