
### General

#### Map layout is tiled data in some sections
Many sections contain tile data in a staggered map format starting in the top right corner.

Visualizing these tiles by giving different colors to different numbers visualizes the map data.

#### Section 1001 seems to be about terrain.
```python
from sourcehold import *

m = load_map(expand_var_path("shcusermap~/160cr.map"))

m.directory.sections[0].create_image().show()
```

