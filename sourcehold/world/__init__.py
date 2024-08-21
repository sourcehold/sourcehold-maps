


def create_matrix(dtype="uint32"):
    import numpy

    return numpy.zeros(shape=(400,400), dtype=dtype)


def create_binary_matrix():
    import numpy

    matrix = numpy.zeros(shape=(400, 400), dtype="bool")

    tlt = TileLocationTranslator()

    for i in range(80400):
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


class TileLocationTranslator(object):

    def __init__(self, square_width=400):
        import math

        self.size = square_width

        size = square_width
        n_serialized_tiles = (2*((size/2)*((size/2)+1)))

        class Point(object):

            def __init__(self, **kwargs):
                for key, value in kwargs.items():
                    setattr(self, key, value)

            def __repr__(self):
                return "{}<{}>".format(self.__class__.__name__, ",".join("{}={}".format(key, value) for key, value in self.__dict__.items()))

        class SerializedTilePoint(Point):

            def __init__(self, i, j):
                super().__init__(i=i, j=j)

            def to_serialized_tile_index(self):
                if self.i < size//2:
                    return SerializedTileIndex((self.i*(self.i+1)) + self.j)
                else:
                    return SerializedTileIndex((n_serialized_tiles - ((size - self.i)*(size-self.i+1))) + self.j)

            def to_game_tile_index(self):
                if self.i < size/2:
                    return GameTileIndex(((size/2)-1-self.i) + (self.i*size) + self.j)
                else:
                    return GameTileIndex((-(size/2)+0+self.i) + (self.i*size) + self.j)

            def to_screen_tile_point(self):
                if self.i < size/2:
                    x = (self.i*2) + 1 - self.j
                else:
                    x = size - self.j

                if self.i < size/2:
                    y = self.j
                else:
                    y = (self.i - (size/2)) * 2 + 1 + self.j

                return ScreenTilePoint(x, y)

            def to_adjusted_serialized_tile_point(self):
                return AdjustedSerializedTilePoint(i=self.i, j=self.j + (abs(((size//2)-1 if self.i < size//2 else size//2)-self.i)))


            # TODO: test these
            def move_north(self):
                if self.i < size//2:

                    return SerializedTilePoint(self.i - 1, self.j - 1)
                elif self.i == size//2:
                    return SerializedTilePoint(self.i-1, self.j)
                else:
                    return SerializedTilePoint(self.i-1, self.j + 1)

            def move_east(self):
                return SerializedTilePoint(self.i, self.j + 1)

            def move_south(self):
                if self.i >= size//2:
                    return SerializedTilePoint(self.i+1, self.j-1)
                elif self.i == (size//2) - 1:
                    return SerializedTilePoint(self.i+1, self.j)
                else:
                    return SerializedTilePoint(self.i + 1, self.j + 1)

            def move_west(self):
                return SerializedTilePoint(self.i, self.j - 1)

            def get_points_for_diamond(self, width, height):
                points = []

                left_most = self
                for j in range(height):
                    moving = left_most
                    for i in range(width):
                        points.append(moving)
                        moving = moving.move_east()
                    left_most = left_most.move_south()

                return points


        class SerializedTileIndex(Point):

            def __init__(self, index):
                super().__init__(index=index)

            def to_serialized_tile_point(self):
                if self.index < n_serialized_tiles/2:
                    i = math.floor(0.5 * ((math.sqrt((4 * self.index) + 1)) - 1))
                else:
                    i = math.floor(size - (0.5 * ((math.sqrt((4 * ((2 * ((size / 2) * ((size / 2) + 1))) - self.index)) + 1)) - 1)))

                index = SerializedTilePoint(i, 0).to_serialized_tile_index().index
                j = self.index - index

                return SerializedTilePoint(i, j)

            def get_indices_for_diamond(self, width, height):
                return [v.to_serialized_tile_index() for v in self.to_serialized_tile_point().get_points_for_diamond(width, height)]


        class AdjustedSerializedTilePoint(Point):

            def __init__(self, i ,j):
                super().__init__(i=i, j=j)

            def to_serialized_tile_point(self):
                return SerializedTilePoint(i=self.i, j = self.j - (abs((199 if self.i < 200 else 200)-self.i)))

            def get_adjusted_points_for_diamond(self, width, height):
                return [v.to_adjusted_serialized_tile_point() for v in self.to_serialized_tile_point().get_points_for_diamond(width, height)]


        class GameTileIndex(Point):

            def __init__(self, index):
                super().__init__(index=index)

            def to_serialized_tile_point(self):
                i = math.floor(self.index / size)
                if i < size/2:
                    j = (self.index % size)-((size/2)-i-1)
                else:
                    j = (self.index % size) - (-(size/2)+0+i)
                return SerializedTilePoint(i, j)

            def to_game_tile_point(self):
                i = math.floor(self.index / size)
                j = math.floor(self.index % size)
                return GameTilePoint(i, j)

        class GameTilePoint(Point):

            def __init__(self, i, j):
                super().__init__(i=i, j=j)

            def to_game_tile_index(self):
                return GameTileIndex(index=(size*self.i) + self.j)

            def move_north(self):
                return SerializedTilePoint(self.i - 1, self.j)

            def move_east(self):
                return SerializedTilePoint(self.i, self.j + 1)

            def move_south(self):
                return SerializedTilePoint(self.i + 1, self.j)

            def move_west(self):
                return SerializedTilePoint(self.i, self.j - 1)

        class ScreenTilePoint(Point):

            def __init__(self, x, y):
                super().__init__(x=x, y=y)

            def get_diamond(self, tile_width=8, tile_height=4, x_origin_offset=0, y_origin_offset=0):
                x = self.x * (tile_width/2)
                y = self.y * (tile_height/2)

                x += x_origin_offset
                y += y_origin_offset

                return [(x, y),
                        (x + (tile_width/2), y + (tile_height/2)),
                        (x, y + tile_height),
                        (x - (tile_width/2), y + (tile_height/2))]

        self.GameTileIndex = GameTileIndex
        self.GameTilePoint = GameTilePoint
        self.SerializedTileIndex = SerializedTileIndex
        self.SerializedTilePoint = SerializedTilePoint
        self.ScreenTilePoint = ScreenTilePoint
        self.AdjustedSerializedTilePoint = AdjustedSerializedTilePoint
