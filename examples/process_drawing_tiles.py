from sourcehold.debugtools.memory.common.access import AccessContext

process = AccessContext()
import struct


from sourcehold.world import TileLocationTranslator
SerializedTilePoint = TileLocationTranslator().SerializedTilePoint


def draw_diamond_systematically(start=SerializedTilePoint(100, 8),width=64*3, height=64*3, fmt="<H", x_value_offset=0, y_value_offset=0):
    fmt_size = struct.calcsize(fmt)

    indices = [v.index for v in
               start.to_serialized_tile_index().get_indices_for_diamond(width=width,
                                                                                             height=height)]
    for i, index in enumerate(indices):
        x = i % width
        y = i // width
        process.write_section("1001", offset=(int(index) * fmt_size), data=struct.pack(fmt, ((((y+y_value_offset) << 8) | (x + x_value_offset))) % (2**(8*fmt_size))))
        # pymem.memory.write_bytes(process.process_handle, address_list['section1001'] + (int(index) * fmt_size),
        #                          struct.pack(fmt, ((((y+y_value_offset) << 8) | (x + x_value_offset))) % (2**(8*fmt_size))), fmt_size)



def draw_system_of_diamonds(rows, cols, point = SerializedTilePoint(100, 8), diamond_width=8, diamond_height=8, x_offset=0, y_offset=0):
    i_point = point
    x_off = x_offset
    y_off = y_offset
    width = diamond_width
    height = diamond_height
    cols = cols
    rows = rows

    for i in range(rows):
        current = i_point

        for j in range(cols):
            draw_diamond_systematically(current, width=width, height=height, x_value_offset=x_off + (j * width),
                                        y_value_offset=y_off + (i * height))
            for _ in range(width):
                current = current.move_east()
            current = current.move_east()

        for _ in range(height):
            i_point = i_point.move_south()
        i_point = i_point.move_south()

    return i_point

draw_system_of_diamonds(rows=16, cols=16, x_offset=8*16*2)

draw_system_of_diamonds(rows=1, cols=40, y_offset=11*8, x_offset=1, point=SerializedTilePoint(200, 8))