import pathlib
from sourcehold.debugtools.memory.access import SHC, SHCE

def get_process_handle(version):
  if version == "SHC1.41-latin":
    return SHC()
  # if version == "SHCE1.41-latin":
  #   return SHCE()
  raise NotImplementedError(f"process not implemented: {version}")


def validate_path(img_path):
  if not img_path:
    raise Exception(f"no input file specified")
  if img_path == "-":
    raise NotImplementedError(f"stdin input not yet implemented for this action. Specify a file path using --input")

  if not pathlib.Path(img_path).exists():
    raise Exception(f"file does not exist: {img_path}")