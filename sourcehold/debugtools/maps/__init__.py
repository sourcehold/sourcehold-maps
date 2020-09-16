

from sourcehold import *
import struct
import plotly.graph_objects as go

from sourcehold.world import TileLocationTranslator
tlt = TileLocationTranslator(square_width=400)

def populate_value_matrix(matrix, values):
    for index, value in enumerate(values):
        p = tlt.SerializedTileIndex(index).to_serialized_tile_point().to_adjusted_serialized_tile_point()
        matrix[p.i][int(p.j)] = value

    return matrix

def yield_values(section_object):
    buffer = Buffer(section_object.get_data())
    size = struct.calcsize(section_object._TYPE_)
    while buffer.remaining():
        yield struct.unpack(section_object._TYPE_, buffer.read(size))[0]


def init_matrix(shape=(400,400), value=None):
    return [[value for j in range(shape[1])] for i in range(shape[0])]


def dstack(matrices, shape=(400,400)):
    result = init_matrix(shape)
    for i in range(shape[0]):
        for j in range(shape[1]):
            result[i][j] = [matrix[i][j] for matrix in matrices]
    return result




def show_section(section_object, categorical_color_mode=False):
    dv = list(yield_values(section_object))
    # Square array of data where north-west is 0,0
    d_value = init_matrix()

    d_serialized_i = init_matrix()
    d_serialized_j = init_matrix()
    d_serialized_tile_index = init_matrix()
    d_adjusted_tile_number = init_matrix()

    if categorical_color_mode:
        d_value_categorical = init_matrix()
        unique_values = sorted(list(set(dv)))

    for index, value in enumerate(dv):
        p = tlt.SerializedTileIndex(index).to_serialized_tile_point().to_adjusted_serialized_tile_point()
        d_serialized_i[p.i][int(p.j)] = tlt.SerializedTileIndex(index).to_serialized_tile_point().i
        d_serialized_j[p.i][int(p.j)] = tlt.SerializedTileIndex(index).to_serialized_tile_point().j
        d_serialized_tile_index[p.i][int(p.j)] = index
        d_adjusted_tile_number[p.i][int(p.j)] = int((p.i * 400) + p.j)
        d_value[p.i][int(p.j)] = value
        if categorical_color_mode:
            d_value_categorical[p.i][int(p.j)] = unique_values.index(value)

    if not categorical_color_mode:
        fig = go.Figure(data=go.Heatmap(name="",
                                        colorscale="Rainbow",
                                        z=d_value,
                                        zmin=0,
                                        zmax=((2 ** (8 * struct.calcsize(
                                            section_object._TYPE_))) - 1),
                                        customdata=dstack((d_serialized_i, d_serialized_j, d_serialized_tile_index,
                                                           d_adjusted_tile_number)),
                                        hovertemplate="<br>".join(["i (serialized):%{customdata[0]:0f}",
                                                                   "j (serialized):%{customdata[1]:0f}",
                                                                   "j (game):%{x:0f}",
                                                                   "tile index (serialized):%{customdata[2]:0f}",
                                                                   "tile index (game):%{customdata[3]:0f}",
                                                                   "value:%{z:0f}", ])),
                        layout=go.Layout(yaxis=dict(autorange="reversed", scaleanchor="x", scaleratio=1)))
    else:

        fig = go.Figure(data=go.Heatmap(name="",
                                        colorscale="Rainbow",
                                        z=d_value_categorical,
                                        zmin=0,
                                        zmax=len(unique_values),
                                        customdata=dstack((d_serialized_i, d_serialized_j, d_serialized_tile_index,
                                                                 d_adjusted_tile_number, d_value)),
                                        hovertemplate="<br>".join(["i (serialized):%{customdata[0]:0f}",
                                                                   "j (serialized):%{customdata[1]:0f}",
                                                                   "j (game):%{x:0f}",
                                                                   "tile index (serialized):%{customdata[2]:0f}",
                                                                   "tile index (game):%{customdata[3]:0f}",
                                                                   "value:%{customdata[4]:0f}", ])),
                        layout=go.Layout(yaxis=dict(autorange="reversed", scaleanchor="x", scaleratio=1)))
    return fig
