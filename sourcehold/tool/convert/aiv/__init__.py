import pathlib

from .conversion import to_json


def convert_aiv(args):
  #' returns None in case of non applicable
  if args.service != "convert":
    return None
  
  if args.type != "aiv":
     return None
  
  inp = args.input
  if not pathlib.Path(inp).exists():
      raise Exception(f"file does not exist: {inp}")
  
  inp_format = args.from_format
  if not inp_format:
      if inp.endswith(".aiv"):
        inp_format = 'aiv'
  out_format = args.to_format
  if inp_format == "aiv":
    out_format = "json"
  if args.output == None:
    args.output = f"{pathlib.Path(inp).name}.json"

  if args.debug:
    print(f"converting '{inp_format}' file '{inp}' to '{out_format}' file '{args.output}'")
  if inp_format == 'aiv' and out_format == "json":
    pathlib.Path(args.output).write_text(to_json(path = inp, include_extra=args.extra, report=args.debug))
  else:
    raise NotImplementedError(f"combination of in-format '{inp_format}' and out-format '{out_format}' not implemented")

  return True