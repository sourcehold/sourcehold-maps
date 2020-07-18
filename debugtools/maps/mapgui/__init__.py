

import tkinter as tk
import tkinter.ttk as ttk


class CanvasTooltip:
    '''
    It creates a tooltip for a given canvas tag or id as the mouse is
    above it.

    This class has been derived from the original Tooltip class I updated
    and posted back to StackOverflow at the following link:

    https://stackoverflow.com/questions/3221956/
           what-is-the-simplest-way-to-make-tooltips-in-tkinter/
           41079350#41079350

    Alberto Vassena on 2016.12.10.
    '''

    def __init__(self, canvas, tag_or_id,
                 *,
                 bg='#FFFFEA',
                 pad=(5, 3, 5, 3),
                 text='canvas info',
                 waittime=400,
                 wraplength=250):
        self.waittime = waittime  # in miliseconds, originally 500
        self.wraplength = wraplength  # in pixels, originally 180
        self.canvas = canvas
        self.text = text
        self.canvas.tag_bind(tag_or_id, "<Enter>", self.onEnter)
        self.canvas.tag_bind(tag_or_id, "<Leave>", self.onLeave)
        self.canvas.tag_bind(tag_or_id, "<ButtonPress>", self.onLeave)
        self.bg = bg
        self.pad = pad
        self.id = None
        self.tw = None

    def onEnter(self, event=None):
        self.schedule()

    def onLeave(self, event=None):
        self.unschedule()
        self.hide()

    def schedule(self):
        self.unschedule()
        self.id = self.canvas.after(self.waittime, self.show)

    def unschedule(self):
        id_ = self.id
        self.id = None
        if id_:
            self.canvas.after_cancel(id_)

    def show(self, event=None):
        def tip_pos_calculator(canvas, label,
                               *,
                               tip_delta=(10, 5), pad=(5, 3, 5, 3)):

            c = canvas

            s_width, s_height = c.winfo_screenwidth(), c.winfo_screenheight()

            width, height = (pad[0] + label.winfo_reqwidth() + pad[2],
                             pad[1] + label.winfo_reqheight() + pad[3])

            mouse_x, mouse_y = c.winfo_pointerxy()

            x1, y1 = mouse_x + tip_delta[0], mouse_y + tip_delta[1]
            x2, y2 = x1 + width, y1 + height

            x_delta = x2 - s_width
            if x_delta < 0:
                x_delta = 0
            y_delta = y2 - s_height
            if y_delta < 0:
                y_delta = 0

            offscreen = (x_delta, y_delta) != (0, 0)

            if offscreen:

                if x_delta:
                    x1 = mouse_x - tip_delta[0] - width

                if y_delta:
                    y1 = mouse_y - tip_delta[1] - height

            offscreen_again = y1 < 0  # out on the top

            if offscreen_again:
                # No further checks will be done.

                # TIP:
                # A further mod might automagically augment the
                # wraplength when the tooltip is too high to be
                # kept inside the screen.
                y1 = 0

            return x1, y1

        bg = self.bg
        pad = self.pad
        canvas = self.canvas

        # creates a toplevel window
        self.tw = tk.Toplevel(canvas.master)

        # Leaves only the label and removes the app window
        self.tw.wm_overrideredirect(True)

        win = tk.Frame(self.tw,
                       background=bg,
                       borderwidth=0)
        label = ttk.Label(win,
                          text=self.text,
                          justify=tk.LEFT,
                          background=bg,
                          relief=tk.SOLID,
                          borderwidth=0,
                          wraplength=self.wraplength)

        label.grid(padx=(pad[0], pad[2]),
                   pady=(pad[1], pad[3]),
                   sticky=tk.NSEW)
        win.grid()

        x, y = tip_pos_calculator(canvas, label)

        self.tw.wm_geometry("+%d+%d" % (x, y))

    def hide(self):
        if self.tw:
            self.tw.destroy()
        self.tw = None

from sourcehold.maps.sections.tools import TiledDiamondSystem, build_palette


class MyCanvas(tk.Canvas):

    def __init__(self, dt, system, **kwargs):
        super().__init__(**kwargs)
        self.dt = dt
        self.system = system

    def clear(self):
        self.delete('rectangle')

    def draw(self):
        system = self.system
        dt = self.dt.get_tiles()

        width = int(system.rows * system.tilewidth * 0.5)
        height = int(system.rows * system.tileheight * 0.5)
        # im = Image.new('RGBA', (width, height))
        # draw = ImageDraw.Draw(im)
        mapping, pal = build_palette(dt)

        self.tooltips = []

        game_index = 0

        for i, row in enumerate(dt):
            for j, value in enumerate(dt[i]):
                coords = system.system_tile_coordinates((i, j))
                coords = [(width - coord[0], coord[1]) for coord in coords]
                #draw.polygon(coords, outline=None, fill=pal[mapping.index(value)])

                color = pal[mapping.index(value)]
                color = '#{:02X}{:02X}{:02X}'.format(*color)
                #text = mask.format(color.capitalize(), tag[1:]) + further_text()


                square_size = 400
                if i < (square_size / 2):
                    index = ((square_size / 2) - 1 - i) + (i * square_size) + j
                else:
                    index = (-(square_size / 2) + 0 + i) + (i * square_size) + j

                text = "game_index: {}, i: {}, j:{}, value:{}".format(game_index, i, j, value)
                game_index += 1

                tag = 'R{}{}'.format(i, j)

                tk_coords = {["x{}", "y{}"][j].format(i): val for i, coord in enumerate(coords) for j, val in enumerate(coord)}
                tk_coords = coords

                try:
                    id_ = self.create_polygon(*tk_coords,
                                              fill=color,
                                              activefill='yellow',
                                              tags=('rectangle', tag)
                                              )
                except Exception as e:
                    print(tk_coords)
                    print(width)
                    print(height)
                    print(self['width'])
                    print(self['height'])
                    raise e
                tooltip = CanvasTooltip(self, id_, text=text)

                self.tooltips.append(tooltip)

    # def draw(self):
    #     width, height = int(self['width']), int(self['height'])
    #
    #     colors = ('blue', 'green', 'red',
    #               'brown', 'cyan', 'magenta',
    #               'violet', 'black', 'white')
    #
    #     self.tooltips = []
    #
    #     mask = '{} rectangle #{}.\n'
    #     for i in range(20):
    #         x, y = random.randint(0, width - 1), random.randint(0, height - 1)
    #         w, h = random.randint(5, 100), random.randint(5, 100)
    #         tag = 'R{}'.format(i)
    #         color = random.choice(colors)
    #         text = mask.format(color.capitalize(), tag[1:]) + further_text()
    #
    #         id_ = self.create_rectangle(x, y, x + w, y + h,
    #                                     fill=color,
    #                                     activefill='yellow',
    #                                     tags=('rectangle', tag))
    #
    #         tooltip = CanvasTooltip(self, id_, text=text)
    #
    #         self.tooltips.append(tooltip)

    def redraw(self, event):
        self.clear()
        self.draw()

    def onClick(self, event):
        coords = self.canvasx(event.x, 1), self.canvasy(event.y, 1)
        found = self.find_closest(*coords)[0]

        if found:
            self.target = found
            self.drag_x, self.drag_y = coords
            self.tag_raise(found)

        else:
            self.target, self.drag_x, self.drag_y = None, None, None

    def onDrag(self, event):
        if self.target is None:
            return

        coords = self.canvasx(event.x, 1), self.canvasy(event.y, 1)

        self.move(self.target,
                  coords[0] - self.drag_x,
                  coords[1] - self.drag_y)

        self.drag_x, self.drag_y = coords

    def onRelease(self, event):
        self.target, self.drag_x, self.drag_y = None, None, None


def display_tiles(tilesystem, system = TiledDiamondSystem()):
    root = tk.Tk()
    frame = ttk.Frame(root)

    dt = tilesystem
    system = system

    width = int(system.rows * system.tilewidth * 0.5) + 100
    height = int(system.rows * system.tileheight * 0.5) + 100

    c = frame.canvas = MyCanvas(dt, system, master=frame.master, width=width, height=height, scrollregion=(0, 0, width, height))
    c.draw()
    c.bind('<Double-Button-1>', c.redraw)
    c.tag_bind('rectangle', '<Button-1>', c.onClick)
    c.tag_bind('rectangle', '<B1-Motion>', c.onDrag)
    c.tag_bind('rectangle', '<ButtonRelease-1>', c.onRelease)
    c.grid(column=0, row=0, padx=(0, 0), pady=(0, 0))

    # Create a vertical scrollbar linked to the canvas.
    vsbar = tk.Scrollbar(frame, orient=tk.VERTICAL, command=c.yview)
    vsbar.grid(row=0, column=1, sticky=tk.NS)
    c.configure(yscrollcommand=vsbar.set)

    # Create a horizontal scrollbar linked to the canvas.
    hsbar = tk.Scrollbar(frame, orient=tk.HORIZONTAL, command=c.xview)
    hsbar.grid(row=1, column=0, sticky=tk.EW)
    c.configure(xscrollcommand=hsbar.set)

    frame.grid()
    root.mainloop()

