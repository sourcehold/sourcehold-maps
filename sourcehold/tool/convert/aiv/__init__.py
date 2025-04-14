import pathlib

from sourcehold.tool.convert.aiv.exports import to_json
from sourcehold.tool.convert.aiv.imports import from_json


def convert_aiv(args):
  #' returns None in case of non applicable
  if args.service != "convert":
    return None
  
  if args.type != "aiv":
     return None
  
  inp = args.input
  if not pathlib.Path(inp).exists():
      raise Exception(f"file does not exist: {inp}")
  inp_invert_y = False
  inp_format = args.from_format
  if not inp_format:
    if inp.endswith(".aiv"):
      inp_format = 'aiv'
    elif inp.endswith(".json"):
      inp_format = "json"
      inp_invert_y = True
  else:
    inp_format_tokens = inp_format.split(",")
    if 'inverty' in inp_format_tokens:
      inp_invert_y = True
  
  out_invert_y = False
  out_skip_keep = False
  out_format = args.to_format
  if not out_format:
    if inp_format == "aiv":
      out_format = "json"
      out_invert_y = True
    elif inp_format == "json":
      out_format = "aiv"
  else:
    out_format_tokens = out_format.split(",")
    if 'inverty' in out_format_tokens:
      out_invert_y = True
    if 'skipkeep' in out_format_tokens:
      out_skip_keep = True  
  if args.output == None:
    if out_format == "json":
      args.output = "-"
    elif out_format == "aiv":
      args.output = f"{pathlib.Path(inp).name}.aiv"
    #args.output = f"{pathlib.Path(inp).name}.json"
  
  if args.debug:
    print(f"converting '{inp_format}: inverty={inp_invert_y}' file '{inp}' to '{out_format}: inverty={out_invert_y}' file '{args.output}'")
  
  if inp_format.startswith('aiv') and out_format.startswith("json"):

    conv = to_json(path = inp, include_extra=args.extra, report=args.debug, invert_y=out_invert_y, skip_keep=out_skip_keep)
    if args.output == "-":
      print(conv)
    else:
      pathlib.Path(args.output).write_text(conv)
  elif inp_format.startswith('json') and out_format.startswith("aiv"):
    conv = from_json(path = inp, report=args.debug, invert_y=inp_invert_y)
    conv.to_file(args.output)
  else:
    raise NotImplementedError(f"combination of in-format '{inp_format}' and out-format '{out_format}' not implemented")

  return True