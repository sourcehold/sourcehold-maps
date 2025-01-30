from sourcehold import *
from sourcehold.maps.library import SHC_FILES, SHC_FILES_USER

map = load_map(SHC_FILES.get_path_from_maps('Close Encounters'))
map.directory['STARTING_GOODS'].wood = 0
save_map(map, SHC_FILES_USER.get_path_from_maps('Close Encounters mod'))
