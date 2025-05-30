import json
import pathlib, sys

from sourcehold.tool.convert.aiv.exports import to_json
from sourcehold.tool.convert.aiv.imports import from_json


def convert_aiv(args):
  #' returns None in case of non applicable
  if args.service != "convert":
    return None
  
  if args.type != "aiv":
     return None
  
  inp = args.input
  if inp != '-' and not pathlib.Path(inp).exists():
      raise Exception(f"file does not exist: {inp}")
  inp_invert_y = args.from_invert_y
  inp_invert_x = args.from_invert_x
  inp_format = args.from_format
  if not inp_format:
    if inp.endswith(".aiv"):
      inp_format = 'aiv'
    elif inp.endswith(".json"):
      inp_format = "json"

  out_invert_y = args.to_invert_y
  out_invert_x = args.to_invert_x
  out_skip_keep = False
  out_format = args.to_format
  if not out_format:
    if inp_format == "aiv":
      out_format = "json"
    elif inp_format == "json":
      out_format = "aiv"
  else:
    out_format_tokens = out_format.split(",")
    if 'inverty' in out_format_tokens:
      out_invert_y = True
    if 'invertx' in out_format_tokens:
      out_invert_x = True
    if 'skipkeep' in out_format_tokens:
      out_skip_keep = True  
  if args.output == None:
    if out_format == "json":
      args.output = "-"
    elif out_format == "aiv":
      if inp == "-":
        args.output = "output.aiv"
      else:
        args.output = f"{pathlib.Path(inp).name}.aiv"
    #args.output = f"{pathlib.Path(inp).name}.json"
  
  if args.debug:
    print(f"converting '{inp_format}: inverty={inp_invert_y}' file '{inp}' to '{out_format}: inverty={out_invert_y}' file '{args.output}'")
  
  if inp_format.startswith('aiv') and out_format.startswith("json"):

    conv = to_json(path = inp, include_extra=args.extra, report=args.debug, invert_y=out_invert_y, invert_x=out_invert_x, skip_keep=out_skip_keep)
    if args.verify:
      target = json.dumps(json.loads(pathlib.Path(args.verify).read_text()), indent=2)
      target_lines = target.split("\n")
      conv_lines = conv.split("\n")
      nlines = min(len(target_lines), len(conv_lines))
      for li in range(nlines):
        if target_lines[li] != conv_lines[li]:
          print(f"Lines differ:\nSource:\n{conv_lines[li]}\nTarget:\n{target_lines[li]}", file=sys.stderr)
    if args.output == "-":
      sys.stdout.write(conv)
      sys.stdout.flush()
    else:
      pathlib.Path(args.output).write_text(conv)
  elif inp_format.startswith('json') and out_format.startswith("aiv"):
    if inp == "-":
      conv = from_json(f = sys.stdin, report=args.debug, invert_y=inp_invert_y, invert_x=inp_invert_x)
    else:
      conv = from_json(path = inp, report=args.debug, invert_y=inp_invert_y, invert_x=inp_invert_x)
    conv.to_file(args.output)
  else:
    raise NotImplementedError(f"combination of from-format '{inp_format}' and to-format '{out_format}' not implemented")

  return True