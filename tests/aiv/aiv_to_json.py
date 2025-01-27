
import pathlib
import unittest

from sourcehold.aivs import AIV
from sourcehold.aivs.conversion import to_json

BASEPATH = pathlib.Path("C:/Program Files (x86)/Steam/steamapps/common/Stronghold Crusader Extreme/aiv")

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