
import pathlib
import unittest

from sourcehold.aivs.AIV import AIV
from sourcehold.tool.convert.aiv.exports import to_json

BASEPATH = pathlib.Path("C:/Program Files (x86)/Steam/steamapps/common/Stronghold Crusader Extreme/aiv")

OUTPUT_DIR = pathlib.Path("output")
if not OUTPUT_DIR.exists():
  OUTPUT_DIR.mkdir()

class T(unittest.TestCase):
  
  @classmethod
  def setUpClass(cls) -> None:
    cls.override = not BASEPATH.exists()

  def test_rat(self):
    if self.override:
      return True
    
    count = 0
    for path in BASEPATH.glob("rat*.aiv"):
      count += 1
      aiv = AIV().from_file(str(path))
      j = to_json(aiv, include_extra=True)
    if count != 8:
      raise Exception(count)
    
  def test_abbot(self):
    if self.override:
      return True
    
    count = 0
    for path in BASEPATH.glob("Abbot*.aiv"):
      count += 1
      aiv = AIV().from_file(str(path))
      j = to_json(aiv, include_extra=True)
    if count != 8:
      raise Exception(count)
    
  def test_all(self):
    if self.override:
      return True
    
    count = 0
    for path in BASEPATH.glob("*.aiv"):
      count += 1
      aiv = AIV().from_file(str(path))
      j = to_json(aiv, include_extra=True)
      (pathlib.Path("output") / f"{path.name}json").write_text(j)