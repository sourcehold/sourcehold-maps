# sourcehold-maps/structure/construct

Here are the [construct](https://construct.readthedocs.io/en/latest/) definitions of the map file format.

TODO: (De-) Compression is not yet supported in the repository! Need to adopt some stuff similar to [here](https://github.com/J-T-de/Villagepp).

TODO: Compression still encounters this [bug](https://github.com/construct/construct/issues/876)!

## Usage

When parsed, a map behaves like a python object, where one can manipulate its attributes.

```python
from construct_map import ConstructMap

map_data = ConstructMap.parse_file("PATH")  # PATH to map
print(map_data.type)
print(map_data.sec[1].data.uncompr_size)    # 1 is the index, not the identifier (1001-1136)

```

## Files

|           name           | description |
| :----------------------: | :---------- |
|    `construct_map.py`    | most developed version of the construct definition for the map file format, basically an unrolled version of `construct_map_brief.py` |
| `construct_map_brief.py` | almost 1:1 translation of `kaitai_map.ksy` |