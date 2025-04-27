import pathlib, sys

from sourcehold.maps.Map import Map

def modify_map(args):
  if args.service != "modify" or args.type != "map":
    return False
  inp = args.input
  if inp != '-' and not pathlib.Path(inp).exists():
    raise Exception(f"file does not exist: {inp}")
  m = Map().from_file(inp)
  print(args)
  if args.unlock:
    if m.u3.map_locked:
      print(f"map file was locked, is now unlocked", file=sys.stderr)
      m.u3.map_locked = 0
    else:
      print(f"map file was already locked", file=sys.stderr)
  if args.lock:
    if m.u3.map_locked:
      print(f"map file was already locked", file=sys.stderr)
    else:
      print(f"map file was unlocked, is now locked", file=sys.stderr)
      m.u3.map_locked = 1
  outp = args.output
  if not outp:
    outp = inp
  m.to_file(outp)
  return True