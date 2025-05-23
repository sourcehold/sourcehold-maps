import pathlib, sys

from sourcehold.tool.convert.aiv.exports import to_json
from sourcehold.tool.convert.aiv.imports import from_json
from sourcehold.tool.memory.map.height import get_height, set_height
from sourcehold.tool.memory.map.terrain import get_terrain, set_terrain


def memory_map(args):
  #' returns None in case of non applicable
  if args.service != "memory":
    return None
  
  if args.type != "map":
     return None
  
  if set_height(args):
    return True
  

  if get_height(args):
    return True

  if set_terrain(args):
    return True
  
  if get_terrain(args):
    return True

  return True