


from sourcehold.world.TileLocationTranslator import TileLocationTranslator


def create_matrix(dtype="uint32", size = 400):
    import numpy

    return numpy.zeros(shape=(size,size), dtype=dtype)


def create_binary_matrix(size = 400):
    import numpy

    matrix = numpy.zeros(shape=(size, size), dtype="bool")

    tlt = TileLocationTranslator(square_width=size)

    for i in range(size * ((size // 2) + 1)):
        stp = tlt.SerializedTileIndex(i).to_serialized_tile_point().to_adjusted_serialized_tile_point()
        matrix[int(stp.i), int(stp.j)] = True

    return matrix

create_selection_matrix = create_binary_matrix


def create_tile_index_matrix():
    import numpy

    matrix = numpy.zeros(shape=(400, 400), dtype="uint32")

    tlt = TileLocationTranslator()

    for i in range(80400):
        stp = tlt.SerializedTileIndex(i).to_serialized_tile_point().to_adjusted_serialized_tile_point()
        matrix[int(stp.i), int(stp.j)] = i

    return matrix


