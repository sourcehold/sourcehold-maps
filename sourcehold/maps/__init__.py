

from sourcehold.maps.CompressedMapSection import CompressedMapSection
from sourcehold.maps.MapSection import MapSection


from sourcehold.maps.sections import find_section_for_index



def get_section_for_index(index, compressed):
    cls = find_section_for_index(index)
    if cls:
        if issubclass(cls, CompressedMapSection) and not compressed:
            return MapSection
        return cls

    if compressed is True:
        return CompressedMapSection
    else:
        return MapSection


def determine_version(obj):
    return 150 if obj.directory_u1[0] >= 161 else 100


import re

SECTION_PATH_re = re.compile("^[0-9]+$")




