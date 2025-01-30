
import os, sys

from sourcehold.debugtools.memory.access import AccessContext

#sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), os.path.pardir)))

PACKAGE_PARENT = '..'
SCRIPT_DIR = os.path.dirname(os.path.realpath(os.path.join(os.getcwd(), os.path.expanduser(__file__))))
sys.path.append(os.path.normpath(os.path.join(SCRIPT_DIR, PACKAGE_PARENT)))


import matplotlib.pyplot as plt

from sourcehold.debugtools.maps import yield_values, populate_value_matrix, init_matrix
from sourcehold.maps.sections import find_section_for_index
import struct
from sourcehold.world.TileLocationTranslator import TileLocationTranslator



if __name__ == "__main__" and __file__ != "<input>":
    import argparse
    parser = argparse.ArgumentParser()

    parser.add_argument("--section", required=True, type=int)
    parser.add_argument("--categorical-colors", dest="cat", const=True, action="store_const", default=False)
    parser.add_argument("--interval", type=float, default=1.0)

    args = parser.parse_args()
    section = args.section
    categorical_color_mode = args.cat
    interval = args.interval
else:
    section = 1003
    categorical_color_mode = True
    interval = 1.0

tlt = TileLocationTranslator()

def format_coord(x, y):
    x = int(round(x))
    y = int(round(y))
    if x >= 0 and x < 400 and y >= 0 and y < 400:
        p = tlt.AdjustedSerializedTilePoint(y, x).to_serialized_tile_point()
        i = p.i
        j = int(p.j)
        index = p.to_serialized_tile_index().index
        game_index = (y*400) + x
        value = matrix[y][x]

        return f"x={x}, y={y}, i={i}, j={j}, tile index (serialized)={index}\nvalue={value}"
    return ""


process = AccessContext(process_name="Stronghold Crusader.exe")
dump = process.read_section(str(section))
cls = find_section_for_index(int(section))

if cls is None:
    raise Exception(f"Section {section} has not been implemented yet.")

s = cls()
s.uncompressed = dump
s.data = dump

if categorical_color_mode:
    vmax = (2**(struct.calcsize(s._TYPE_)*8))
    unique_values = sorted(list(set(yield_values(s))))
else:
    vmax = (2**(struct.calcsize(s._TYPE_)*8))

matrix = init_matrix((400,400), value=float('nan'))

matrix = populate_value_matrix(matrix, yield_values(s))

# You probably won't need this if you're embedding things in a tkinter plot...
# plt.ion()

fig = plt.figure()
ax = fig.add_subplot(111)
ax.format_coord = format_coord
if not categorical_color_mode:
    v_matrix = matrix
else:
    v_matrix = init_matrix((400,400), value=float('nan'))
    for i in range(400):
        for j in range(400):
            v = matrix[i][j]
            if v == v:
                v_matrix[i][j] = unique_values.index(v)

f = ax.imshow(v_matrix, cmap="rainbow")
f.format_cursor_data = lambda data: ""


prev_state = dump

while True:
    plt.pause(interval=interval)

    if not plt.get_fignums():
        break

    new_state = process.read_section(str(section))
    if prev_state == new_state:
        prev_state = new_state
        continue
    prev_state = new_state

    s.uncompressed = new_state
    if categorical_color_mode:
        unique_values = sorted(list(set(yield_values(s))))

    matrix = populate_value_matrix(matrix, yield_values(s))

    if categorical_color_mode:
        for i in range(400):
            for j in range(400):
                v = matrix[i][j]
                if v == v:
                    v_matrix[i][j] = unique_values.index(v)
    else:
        vmatrix = matrix

    f.set_data(v_matrix)
    fig.canvas.draw()
    fig.canvas.flush_events()