from sourcehold.debugtools.memory.access import SHC

import struct


process = SHC()

yComponentMatrixAddress = 0x021d5d98
yComponentMatrix = process.read_bytes(yComponentMatrixAddress, 2 * 80400)

def getYComponent(tile):
  return struct.unpack("<h", process.read_bytes( yComponentMatrixAddress + (tile * 2), 2))[0]

assert getYComponent(6) == 2


start = 0x023372e8
end = start + (10+400) * 3 * 4

startMatrix = 0x02337300

data = process.read_bytes(start, end-start)

def findLineStartForY(y):
  offset = y * 4 * 3
  return struct.unpack("<i", data[20:][offset : (offset + 4)])

assert findLineStartForY(400)[0] == 80400

def do(a):
  return struct.unpack("<i", process.read_bytes(0x02337300 + (4 * a), 4))[0]

tile = 6
y = getYComponent(tile)
offset = tile - do(y * 3)
tile2 = do(y * 3 - 6) + offset
