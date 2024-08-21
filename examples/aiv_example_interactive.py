


import numpy, struct
from sourcehold.debugtools.memory.access import Village


process = Village()

# No idea, 127, unused
struct.unpack("<1I", process.read_section('2001'))

# No idea, 0, unused
struct.unpack("<1I", process.read_section('2002'))

# 2003 is rng, unused

# type info?, unused
process.show('2004')

# edges of walls and heigh points?, unused
process.show('2005')

# noise, unused
process.show('2006')

# construction type
process.show('2007')

# Which tile has which step
process.show('2008')

# Total steps or something? No idea, unused
struct.unpack("<1I", process.read_section('2009'))

# Total Steps
struct.unpack("<1I", process.read_section('2010'))

# Which steps have pauses, pauses are useful for waiting for money to flow in
struct.unpack("<20h", process.read_section('2011'))

# Each unit type has 10 slots. Braziers also count as units
unit_locations = numpy.zeros((24, 10), dtype='uint32')
unit_locations[numpy.ones((24, 10), dtype='bool')] = struct.unpack(f"<{960//4}I", process.read_section('2012'))
unit_locations_x = unit_locations % 100
unit_locations_y = unit_locations // 100


# No idea, unused
process.show('2013')

# Pause delay to apply (to all pauses), pauses are useful for waiting for money to flow in
struct.unpack("<1I", process.read_section('2014'))
