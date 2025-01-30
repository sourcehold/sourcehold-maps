from sourcehold import load_map, expand_var_path
from sourcehold.maps.library import SHC_FILES

map = load_map(SHC_FILES.get_all_map_paths()[0])

map2 = load_map(expand_var_path("shcmap~/Close Encounters.map"))
map2 = load_map(expand_var_path("shcusermap~/Close Encounters.map"))
