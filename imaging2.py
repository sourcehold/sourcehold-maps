from PIL import Image

from sourcehold.iotools import read_file
from sourcehold.maps.sections import cut
from sourcehold.maps.sections.tools import translate_diamond_to_checkerboard

SAND_RAISED_LAND = (1, 512)
MOAT = (1234, 1345)
RIVER = (1562, 1577)
RIVER_ROCKS_OUTLINE = (1593, 1609)
RIVER_WATER_SOMETHING1 = (1669, 1671)
RIVER_WATER_STONES = (1687, 1733)


def make_image_of_values(dt, values=None, from_value=None, until_value=None):
    im = Image.new('RGBA', (len(dt), len(dt[0])))
    da = im.load()

    global count
    count = 0

    if values != None:
        for i in range(len(dt)):
            for j in range(len(dt[i])):
                if dt[i][j] == None:
                    da[i, j] = (255, 255, 255)  # tkinter does not support transparency...
                elif not dt[i][j] in values:
                    da[i, j] = (255, 255, 255)  # tkinter does not support transparency...
                else:
                    count += 1
                    da[i, j] = (0, 0, 0)
    else:
        for i in range(len(dt)):
            for j in range(len(dt[i])):
                if dt[i][j] == None:
                    da[i, j] = (255, 255, 255)  # tkinter does not support transparency...
                elif dt[i][j] < from_value or dt[i][j] >= until_value:  # simulate range()
                    da[i, j] = (255, 255, 255)  # tkinter does not support transparency...
                else:
                    count += 1
                    da[i, j] = (0, 0, 0)
    return im


def count_visible(dt, values):
    count = 0
    for i in range(len(dt)):
        for j in range(len(dt[i])):
            if not dt[i][j] in values:
                pass
            else:
                count += 1
    return count


CURFILE = "file_inspection/maps/xlcr_noruins_noarab/sections/1001"
data = read_file(CURFILE)
mapped = cut(data, "H", 198)

mappedt = translate_diamond_to_checkerboard(mapped)

import tkinter as tk
from PIL import ImageTk

root = tk.Tk()
# root.geometry("397x397")
controller = tk.Frame(root)
controller.pack()
spinner1 = tk.Spinbox(controller, from_=0, to=0xFFFF)
spinner1.pack(side=tk.LEFT)
spinner2 = tk.Spinbox(controller, from_=0, to=0xFFFF)
spinner2.pack(side=tk.LEFT)
label = tk.Label(controller)
label.pack(side=tk.LEFT)


def regenerate_image():
    low = int(spinner1.get())
    high = int(spinner2.get())
    generate_image(low, high)


def generate_image(low, high):
    global im, tim, cim, count
    oldcount = count
    im = make_image_of_values(mappedt, from_value=low, until_value=high)
    label.config(text="before: {} pixels, after: {} pixels".format(oldcount, count))
    im = im.resize((len(mappedt) * 2, len(mappedt) * 2), Image.NEAREST)
    tim = ImageTk.PhotoImage(im)
    canvas.delete(cim)
    cim = canvas.create_image(0, 0, anchor=tk.NW, image=tim)


button_refresh = tk.Button(controller, text="Refresh", command=regenerate_image)
button_refresh.pack(side=tk.LEFT)
canvas = tk.Canvas(root, height=397 * 2, width=397 * 2)
canvas.pack()
# label.pack()

count = 0

oldcount = count
im = make_image_of_values(mappedt, from_value=1, until_value=512)
label.config(text="before: {} pixels, after: {} pixels".format(oldcount, count))
im = im.resize((len(mappedt) * 2, len(mappedt) * 2), Image.NEAREST)
tim = ImageTk.PhotoImage(im)
cim = canvas.create_image(0, 0, anchor=tk.NW, image=tim)
# label.pack(side = tk.TOP, expand=True, fill=tk.BOTH)
root.mainloop()
