
#### Changing a compressed section to uncompressed
It is not possible to change section 1001 from a CompressedSection into a MapSection,
and to set the compression to 0 in the directory.
```python
from sourcehold import *
from sourcehold.maps import MapSection

m = load_map(expand_var_path("shcusermap~/160cr.map"))

sections = []
for i in range(len(m.directory.sections)):
    if i not in [0]: # Only test section 0 (key 1001).
        continue
    section = m.directory.sections[i]
    d = section.get_data()
    s = MapSection().from_buffer(Buffer(d), length = len(d))
    m.directory.sections[i] = s

save_map(m, expand_var_path("shcusermap~/160cr_unpacked.map"))
```

#### Changing the order of sections
TODO: verify
```python
from sourcehold import *

m = load_map(expand_var_path("shcusermap~/160cr.map"))

s0 = m.directory.sections[0]
s1 = m.directory.sections[1]
#k0 = m.directory.section_indices[0]
#k1 = m.directory.section_indices[1]
m.directory.sections[0] = s1
m.directory.sections[1] = s0

save_map(m, expand_var_path("shcusermap~/160cr_section_change.map"))
```