from .section1001 import Section1001
from .section1002 import Section1002
from .section1003 import Section1003
from .section1004 import Section1004
from .section1005 import Section1005
from .section1006 import Section1006
from .section1007 import Section1007
from .section1008 import Section1008
from .section1009 import Section1009
from .section1010 import Section1010
from .section1012 import Section1012
from .section1013 import Section1013
from .section1015 import Section1015
from .section1016 import Section1016
from .section1017 import Section1017
from .section1020 import Section1020
from .section1021 import Section1021
from .section1022 import Section1022
from .section1023 import Section1023
from .section1025 import Section1025
from .section1026 import Section1026
from .section1028 import Section1028
from .section1029 import Section1029
from .section1030 import Section1030
from .section1033 import Section1033
from .section1036 import Section1036
from .section1037 import Section1037
from .section1043 import Section1043
from .section1045 import Section1045
from .section1049 import Section1049
from .section1056 import Section1056
from .section1057 import Section1057
from .section1058 import Section1058
from .section1061 import Section1061
from .section1065 import Section1065
from .section1073 import Section1073
from .section1085 import Section1085
from .section1086 import Section1086
from .section1087 import Section1087
from .section1088 import Section1088
from .section1089 import Section1089
from .section1102 import Section1102
from .section1103 import Section1103
from .section1104 import Section1104
from .section1105 import Section1105
from .section1111 import Section1111
from .section1112 import Section1112
from .section1113 import Section1113
from .section1118 import Section1118


import re
pattern = re.compile("Section[0-9]{4}")

REGISTERED = {key: value for key, value in globals().items() if pattern.match(key) is not None}


def find_section_for_index(index):
    key = "Section" + str(index)
    if key in REGISTERED:
        return REGISTERED[key]
    return None
