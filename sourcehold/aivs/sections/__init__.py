
import logging
from sourcehold.maps import CompressedSection
from sourcehold.structure_tools.Structure import Structure
from typing import cast

class AIVSection(Structure):

    def __init__(self):
        super().__init__()

    def size_of(self):
        return self.length

    def from_buffer(self, buf, **kwargs):
        super().from_buffer(buf, **kwargs)
        if 'length' not in kwargs:
            raise KeyError()
        self.length = cast(int, kwargs.get('length'))
        self.data = buf.read(self.length)
        return self

    def pack(self, force = False):
        self.length = len(self.data)

    def serialize_to_buffer(self, buf):
        self.pack()

        # note: we do not serialize length!
        prop = "data"
        bef = buf.tell()
        buf.write(self.data)
        aft = buf.tell()
        l = aft - bef
        logging.debug("serialized {:16s}. length: {:10d} before: {:10d},  after: {:10d}".format(
            prop,
            l,
            bef,
            aft
        ))

class CompressedAIVSection(CompressedSection):
    pass

class AIVSection2004(CompressedAIVSection):
   
   def __init__(self):
      super().__init__()

   def show(self):
      import matplotlib
      from matplotlib import pyplot

      import struct

      import numpy as np

      matrix = np.zeros((100, 100), 'uint8')
      data = struct.unpack(f"<{100*100}B", self.get_data())
      matrix[np.ones((100,100), 'bool')] = data
      pyplot.imshow(matrix)

      pyplot.show()


# Constructions
class AIVSection2007(CompressedAIVSection):
   
   def __init__(self):
      super().__init__()

   def show(self):
      import matplotlib
      from matplotlib import pyplot

      import struct

      import numpy as np

      matrix = np.zeros((100, 100), 'uint16')
      data = struct.unpack(f"<{100*100}H", self.get_data())
      matrix[np.ones((100,100), 'bool')] = data
      pyplot.imshow(matrix)

      pyplot.show()

# Build steps
class AIVSection2008(CompressedAIVSection):
   
   def __init__(self):
      super().__init__()

   def show(self):
      import matplotlib
      from matplotlib import pyplot

      import struct

      import numpy as np

      matrix = np.zeros((100, 100), 'uint32')
      data = struct.unpack(f"<{100*100}I", self.get_data())
      matrix[np.ones((100,100), 'bool')] = data
      pyplot.imshow(matrix)

      pyplot.show()

class AIVSection2005(AIVSection2004):
   pass

# Ignoreable
class AIVSection2006(AIVSection):
   pass

class AIVSection2013(AIVSection2004):
   pass

def get_section_for_index(index, compressed):
  if index == 2004 or index == "2004":
     return AIVSection2004
  if index == 2005 or index == "2005":
     return AIVSection2005
  # if index == 2006 or index == "2006":
  #    return AIVSection2006
  if index == 2007 or index == "2007":
     return AIVSection2007
  if index == 2008 or index == "2008":
     return AIVSection2008
  if index == 2013 or index == "2013":
     return AIVSection2013
  if compressed:
    return CompressedAIVSection
  else:
    return AIVSection