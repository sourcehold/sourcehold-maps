import io



class Buffer(io.BytesIO):

    def __init__(self, initial_bytes=b''):
        super().__init__(initial_bytes)
        self.bytes_length = len(initial_bytes)

    def read(self, size=-1):
        d = super().read(size)
        if len(d) < size:
            raise Exception("Data underflow. Expected {} bytes, but got {}".format(size, len(d)))
        return d

    def write(self, b):
        diff = len(b) - (self.bytes_length - self.tell())
        if diff > 0:
            self.bytes_length += diff
        return super().write(b)

    def remaining(self):
        return self.bytes_length - self.tell()

    def peek(self, size=1):
        d = self.read(size)
        self.seek(self.tell() - len(d))
        return d

    def eof(self):
        return self.remaining() == 0

    def assert_eof(self):
        assert self.remaining() == 0


import struct


class BreakFunctions(object):

    @staticmethod
    def break_at_eof(buf):
        data = buf.read(1)
        buf.seek(buf.tell() - 1)
        if data == b'':
            return True
        return False


def bytes_to_int_array(data: bytes):
    if len(data) % 4 != 0:
        raise Exception()
    buf = Buffer(data)
    while buf.remaining() > 0:
        yield struct.unpack("I", buf.read(4))[0]


def ints_to_byte_array(ints: list):
    buf = Buffer()
    for i in ints:
        buf.write(struct.pack("I", i))
    return buf.getvalue()


class Variable(object):

    def __init__(self, name, type, array_size=0, break_array=BreakFunctions.break_at_eof):
        object.__init__(self)
        self.name = name
        self.type = type
        self.array_size = array_size
        self.break_array = break_array
        self.fget = None
        self.fset = None
        self.fdel = None

    def __call__(self, fget):
        self.fget = fget
        return self

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        if not self.fget is None:
            return self.fget(obj, self.name)
        if "_" + self.name not in obj.__dict__:
            raise AttributeError("object has no attribute {}".format(self.name))
        return obj.__dict__["_" + self.name]

    def __set__(self, obj, value):
        if not self.fset is None:
            return self.fset(obj, self.name, value)
        obj.__dict__["_" + self.name] = value

    def __delete__(self, obj):
        if not self.fdel is None:
            return self.fdel(obj, self.name)
        del obj.__dict__["_" + self.name]

    def getter(self, fget):
        self.fget = fget
        return self

    def setter(self, fset):
        self.fset = fset
        return self

    def deleter(self, fdel):
        self.fdel = fdel
        return self

    def serialize_to_buffer(self, obj, buf: Buffer):
        if self.type.__class__ == str:
            if self.array_size == 0:
                r = struct.pack(self.type, self.__get__(obj))
                buf.write(r)
            else:
                if self.array_size == "*":
                    for o in self.__get__(obj):
                        buf.write(struct.pack(self.type, o))
                elif self.array_size.__class__ == int:
                    for o in self.__get__(obj):
                        buf.write(struct.pack(self.type, o))
                elif self.array_size.__class__ == Variable:
                    self.array_size.__set__(obj, len(self.__get__(obj)))
                    for o in self.__get__(obj):
                        buf.write(struct.pack(self.type, o))
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))
        elif self.type.__class__ == type:
            if self.array_size == 0:
                o = self.__get__(obj)
                o.serialize_to_buffer(buf)
            else:
                if self.array_size == "*":
                    for o in self.__get__(obj):
                        o.serialize_to_buffer(buf)
                elif self.array_size.__class__ == int:
                    for o in self.__get__(obj):
                        o.serialize_to_buffer(buf)
                elif self.array_size.__class__ == Variable:
                    for o in self.__get__(obj):
                        o.serialize_to_buffer(buf)
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))
        else:
            raise Exception("Invalid type specification {}".format(self.type))

    def set_from_buffer(self, obj, buf: Buffer, **kwargs):
        if self.type.__class__ == str:
            if self.array_size == 0:
                s = struct.calcsize(self.type)
                r = struct.unpack(self.type, buf.read(s))[0]
                self.__set__(obj, r)
            else:
                if self.array_size == "*":
                    s = struct.calcsize(self.type)
                    r = []
                    while not self.break_array(buf):
                        r.append(struct.unpack(self.type, buf.read(s))[0])
                    self.__set__(obj, r)
                elif self.array_size.__class__ == int:
                    s = struct.calcsize(self.type)
                    r = [struct.unpack(self.type, buf.read(s))[0] for i in range(self.array_size)]
                    self.__set__(obj, r)
                elif self.array_size.__class__ == Variable:
                    si = self.array_size.__get__(obj)
                    s = struct.calcsize(self.type)
                    r = [struct.unpack(self.type, buf.read(s))[0] for i in range(si)]
                    self.__set__(obj, r)
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))
        elif self.type.__class__ == type:
            if self.array_size == 0:
                r = create_structure_from_buffer(self.type, buf, **kwargs)
                self.__set__(obj, r)
            else:
                if self.array_size == "*":
                    s = struct.calcsize(self.type)
                    r = []
                    while not self.break_array(buf):
                        r.append(create_structure_from_buffer(self.type, buf, **kwargs))
                    self.__set__(obj, r)
                elif self.array_size.__class__ == int:
                    r = [create_structure_from_buffer(self.type, buf, **kwargs) for i in range(self.array_size)]
                    self.__set__(obj, r)
                elif self.array_size.__class__ == Variable:
                    si = self.array_size.__get__(obj)
                    r = [create_structure_from_buffer(self.type, buf, **kwargs) for i in range(si)]
                    self.__set__(obj, r)
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))

        else:
            raise Exception("Invalid type specification {}".format(self.type))


import logging


def create_structure_from_buffer(structure: type, buf: Buffer, **kwargs):
    self = structure()

    self.from_buffer(buf, **kwargs)

    return self


class Structure(object):

    def __init__(self):
        pass

    def __getattr__(self, item):
        if not item in self.fields:
            return None
        return self.fields[item]

    @classmethod
    def get_fields(cls):
        fields = {}
        tree = []
        while cls is not None:
            tree.insert(0, cls)
            # Note: system does not support multiple inheritance
            cls = cls.__base__

        for cls in tree:
            if not hasattr(cls, "__dict__"):
                continue
            props = {key: value for key, value in cls.__dict__.items() if cls.__dict__[key].__class__ == Variable}
            fields.update(props)

        return fields

    @classmethod
    def get_fields_2(cls):
        # TODO: I need a substitute for properties, because they do not work in a dict... I guess?
        fields = {}
        tree = []
        while cls is not None:
            tree.insert(0, cls)
            # Note: system does not support multiple inheritance
            cls = cls.__base__

        for cls in tree:
            if not hasattr(cls, "__dict__"):
                continue
            fields.update(cls.__dict__["fields"])

        return fields

    def pack(self):
        pass

    def unpack(self):
        pass

    def get_data(self):
        return self.data

    def from_buffer(self, buf: Buffer, **kwargs):
        self._buf = buf
        props = self.__class__.get_fields()
        for name, prop in props.items():
            # print("setting {}. buf is at {}".format(prop, buf.tell()))
            bef = buf.tell()
            prop.set_from_buffer(self, buf, **kwargs)
            aft = buf.tell()
            l = aft - bef
            logging.debug("deserialized {:14s}. length: {:10d} before: {:10d},  after: {:10d}".format(
                name,
                l,
                bef,
                aft
            ))

        return self

    def serialize_to_buffer(self, buf: Buffer):
        self.pack()
        props = self.__class__.get_fields()
        for name, prop in props.items():
            # print("serializing {}. buf is at {}".format(prop, buf.tell()))
            bef = buf.tell()
            prop.serialize_to_buffer(self, buf)
            aft = buf.tell()
            l = aft - bef
            logging.debug("serialized {:16s}. length: {:10d} before: {:10d},  after: {:10d}".format(
                name,
                l,
                bef,
                aft
            ))

class Table(object):

    def __init__(self, rownames, colnames):
        self.rownames = rownames
        self.colnames = colnames
        self.matrix = []
        for row in self.rownames:
            self.matrix.append([None] * len(self.colnames))

    def set(self, row, col, value):
        if row.__class__ == str:
            row = self.rownames.index(row)
        if col.__class__ == str:
            col = self.colnames.index(col)
        self.matrix[row][col] = value

    def get(self, row, col):
        if row.__class__ == str:
            row = self.rownames.index(row)
        if col.__class__ == str:
            col = self.colnames.index(col)
        return self.matrix[row][col]

    def __repr__(self):
        length_r = max([len(v) for v in self.rownames])
        length_c = max([len(v) for v in self.colnames])
        length = length_r if length_r > length_c else length_c
        length += 4
        # print(length)
        field = "{{:{}s}}".format(length)
        # print(field)
        string = field.format(" ") + (field * len(self.colnames)).format(*[str(v) for v in self.colnames]) + "\n"
        for row in range(len(self.matrix)):
            string += field.format(self.rownames[row])
            string += (field * len(self.matrix[row])).format(*[str(v) if v != None else "" for v in self.matrix[row]])
            string += "\n"
        return string

    def as_array(self, rowname="rowname"):
        header = [rowname] + self.colnames
        values = [[self.rownames[i]] + self.matrix[i] for i in range(len(self.matrix))]
        return [header] + values

    def as_dict(self):
        d = {}
        for r in self.rownames:
            for c in self.colnames:
                if not r in d:
                    d[r] = {}
                v = self.get(r, c)
                if v != None:
                    d[r][c] = v
        return d

    def as_dict_array(self):
        a = []
        for r in self.rownames:
            for c in self.colnames:
                v = self.get(r, c)
                if v == None:
                    continue
                a.append({"a": r, "b": c, "value": v})
        return a


TABLE_TEST = Table(["A", "B", "C"], ["D", "E", "F"])
for i in range(len(TABLE_TEST.rownames)):
    TABLE_TEST.set(i, i, i * i)
