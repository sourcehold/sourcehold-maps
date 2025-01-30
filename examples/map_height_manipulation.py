import numpy, struct
from sourcehold.debugtools.memory.access import SHC
from sourcehold.world import create_binary_matrix as create_selection_matrix

process = SHC()

m = create_selection_matrix()

# (Little endian) unsigned bytes
def get_raw_height():
  return struct.unpack("<80400B", process.read_section('1045'))

def set_raw_height(data):
  bytes_data = struct.pack("<80400B", *data)
  # Logical terrain height layer
  process.write_section('1045', bytes_data)
  # Visual height layer, I think also includes walls and towers
  process.write_section('1005', bytes_data)

def show(matrix):
  import matplotlib.pyplot
  matplotlib.pyplot.imshow(matrix)
  matplotlib.pyplot.show()


raw_height = get_raw_height()

height_matrix = numpy.zeros((400, 400), dtype='uint8')
height_matrix[m] = raw_height

show(height_matrix)

def generate_random_heights():
  # python -m pip install perlin-noise
  from perlin_noise import PerlinNoise # type: ignore
  noise = PerlinNoise(octaves=10, seed=1)
  xpix, ypix = 400, 400
  pic = [[noise([i/xpix, j/ypix]) for j in range(xpix)] for i in range(ypix)]
  return numpy.asmatrix(pic)

heights_noise = generate_random_heights()

heights_noise -= heights_noise.min() # Make minimum be 0
heights_noise /= heights_noise.max() # Make the max be 1
heights_noise *= (127 - 8) # Make the max be 127 what the game expects as the max
# Now make sure there are enough flat plains to build on
heights_noise -= (128//2)
heights_noise[heights_noise < 0] = 0
heights_noise += 8 # Make minimum be 8 what the game expects

heights_noise = heights_noise.astype("uint8")

# Make sure to rotate the map to force a redraw
set_raw_height(heights_noise[m].flat)