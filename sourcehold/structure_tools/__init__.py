import io


class UnderflowException(Exception):

    def __init__(self, msg):
        super().__init__(msg)


class Buffer(io.BytesIO):

    def __init__(self, initial_bytes=b''):
        super().__init__(initial_bytes)
        self.bytes_length = len(initial_bytes)

    def read(self, size=-1):
        d = super().read(size)
        if len(d) < size:
            raise UnderflowException("Data underflow. Expected {} bytes, but got {}".format(size, len(d)))
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


def _resolve_cls_as_type(cls):
    if cls == int:
        return "I"
    if cls == str:
        raise NotImplementedError()
    if cls == float:
        return "f"
    if cls == bytes:
        return "B"
    return cls


class Field(object):

    def __init__(self, name, typ, array_size=0, break_array=BreakFunctions.break_at_eof):
        object.__init__(self)
        self.name = name
        self.type = typ if type(typ) != type else _resolve_cls_as_type(typ)
        self.array_size = array_size
        self.break_array = break_array
        self.fget = self.__get__
        self.fset = self.__set__
        self.fdel = None

    def __call__(self, fget):
        self.fget = fget
        return self

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        # if not self.fget is None:
        #    return self.fget(obj, self.name)
        if "_" + self.name not in obj.__dict__:
            raise AttributeError("object {} has no attribute {}".format(obj, self.name))
        return obj.__dict__["_" + self.name]

    def __set__(self, obj, value):
        # if not self.fset is None:
        #    return self.fset(obj, self.name, value)
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
                elif self.array_size.__class__ == Field:
                    self.array_size.__set__(obj, len(self.__get__(obj)))
                    for o in self.__get__(obj):
                        buf.write(struct.pack(self.type, o))
                elif self.array_size.__class__.__name__ == 'function':
                    # self.array_size.__set__(obj, len(self.__get__(obj)))
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
                elif self.array_size.__class__ == Field:
                    # TODO: is there a setter missing here?
                    for o in self.__get__(obj):
                        o.serialize_to_buffer(buf)
                elif self.array_size.__class__.__name__ == 'function':
                    for o in self.__get__(obj):
                        o.serialize_to_buffer(buf)
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))
        else:
            raise Exception("Invalid type specification {}".format(self.type))

    def set_from_buffer(self, obj, buf: Buffer, **kwargs):
        try:
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
                    elif self.array_size.__class__ == Field:
                        si = self.array_size.__get__(obj)
                        s = struct.calcsize(self.type)
                        r = [struct.unpack(self.type, buf.read(s))[0] for i in range(si)]
                        self.__set__(obj, r)
                    elif self.array_size.__class__.__name__ == 'function':
                        si = self.array_size(obj)
                        s = struct.calcsize(self.type)
                        r = [struct.unpack(self.type, buf.read(s))[0] for i in range(si)]
                        self.__set__(obj, r)
                    else:
                        raise Exception("Invalid size specification {}".format(self.array_size))
                    if self.type == "B":
                        #  Treat special case where we want a bytearray instead of an array of integers.
                        self.__set__(obj, bytearray(r))
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
                    elif self.array_size.__class__ == Field:
                        si = self.array_size.__get__(obj)
                        r = [create_structure_from_buffer(self.type, buf, **kwargs) for i in range(si)]
                        self.__set__(obj, r)
                    elif self.array_size.__class__.__name__ == 'function':
                        si = self.array_size(obj)
                        s = struct.calcsize(self.type)
                        r = [struct.unpack(self.type, buf.read(s))[0] for i in range(si)]
                        self.__set__(obj, r)
                    else:
                        raise Exception("Invalid size specification {}".format(self.array_size))

            else:
                raise Exception("Invalid type specification {}".format(self.type))
        except UnderflowException as e:
            raise Exception("An exception occurred during the processing of {}:\n\n".format(obj, e))




import logging


def create_structure_from_buffer(structure: type, buf: Buffer, **kwargs):
    self = structure()

    self.from_buffer(buf, **kwargs)

    return self


def dict_join(d1, d2):
    d = d1.copy()
    d.update(d2)
    return d


class Structure(object):

    def __init__(self):
        pass

    # def __getattr__(self, item):
    #     if item not in self.fields:
    #         return None
    #     return self.fields[item].fget(self)
    #
    # def __setattr__(self, key, value):
    #     self.fields[key].fset(self, value)

    @classmethod
    def get_fields(cls) -> dict:
        fields = {}

        tree = list(cls.__mro__)

        for c in tree:
            if not hasattr(c, "__dict__"):
                continue
            props = {key: value for key, value in c.__dict__.items() if c.__dict__[key].__class__ == Field}
            fields.update(props)

        return fields

    @classmethod
    def get_data_properties(cls):
        fields = {}

        tree = list(cls.__mro__)

        for c in tree:
            if not hasattr(c, "__dict__"):
                continue
            props = {key: value for key, value in c.__dict__.items() if c.__dict__[key].__class__ == DataProperty}
            fields.update(props)

        return fields

    def pack(self, force=False):
        pass

    def unpack(self, force=False):
        pass

    def get_data(self):
        return self.data

    def set_data(self, data):
        self.data = data

    def from_buffer(self, buf: Buffer, **kwargs):
        self._buf = buf
        props = self.__class__.get_fields()
        for name, prop in props.items():
            # print("setting {}. buf is at {}".format(prop, buf.tell()))
            bef = buf.tell()
            try:
                prop.set_from_buffer(self, buf, **kwargs)
            except Exception as e:
                print("An error occurred while loading {}, at property {}".format(type(self).__name__, name))
                raise e
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
#        self.pack()
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

    def yield_inequalities(self, other, with_pack=False, ignore_keys=None):

        if ignore_keys is None:
            ignore_keys = []
        elif type(ignore_keys) == str:
            ignore_keys = [ignore_keys]
        elif type(ignore_keys) == list:
            pass
        else:
            raise Exception("Invalid type for ignore_keys parameter: {}".format(type(ignore_keys)))

        if type(self) != type(other):
            yield "unequal types for self and other: {} {}".format(type(self), type(other))

        if with_pack:
            self.pack()
            other.pack()

        fields_1 = self.get_fields()
        fields_2 = other.get_fields()

        if fields_1 != fields_2:
            yield "unequal variables for self and other: {} {}".format(fields_1, fields_2)

        keys = fields_1.keys()
        if keys != fields_2.keys():
            yield "unequal keys in variables dict for self and other: {} {}".format(keys, fields_2.keys())

        for key in fields_1.keys():

            if key in ignore_keys:
                continue

            a = fields_1[key].fget(self)
            b = fields_2[key].fget(other)

            if a is None and b is None:
                continue

            if a is None and b is not None or b is None and a is not None:
                yield "unequal values for key: {} in\n\tself: \n{}\n\tand other: \n{}".format(key, a, b)

            if isinstance(a, Structure) and isinstance(b, Structure):
                for ineq in a.yield_inequalities(b, False, ignore_keys):
                    yield "inside {}:\n\t{}".format(key, ineq)

                if a.get_data() != b.get_data():
                    da = a.get_data()
                    db = b.get_data()
                    n = min(len(da), len(db))
                    diffs = [i for i in range(n) if da[i] != db[i]]
                    yield "unequal data ({}/{} = {}) for key: {} in\n\tself: \n{}\n\tand other: \n{}".format(len(diffs), n, round(len(diffs)/n, 2), key, '', '')
            elif a != b:
                yield "unequal values for key: {} in\n\tself: \n{}\n\tand other: \n{}".format(key, a, b)

    def test_equality(self, other, with_pack=True, ignore_keys=None):
        for ineq in self.yield_inequalities(other, with_pack, ignore_keys):
            return False
        return True

    def assert_equality(self, other, with_pack=True, ignore_keys=None):
        ineq = list(self.yield_inequalities(other, with_pack, ignore_keys))
        if len(ineq) > 0:
            message = "No equality. Reasons: \n"
            message += "\n".join("\t" + m for m in ineq)
            raise Exception(message)
        return True

    def __sub__(self, other):
        """Comparison function by substraction"""
        d0 = self.get_data()
        d1 = other.get_data()
        n0 = len(d0)
        n1 = len(d1)
        n = min(n0, n1)
        for i in range(n):
            yield d0[n] - d1[n]

    def compare_data(self, other):
        d0 = self.get_data()
        d1 = other.get_data()
        n0 = len(d0)
        n1 = len(d1)
        if n0 != n1:
            yield "unequal data sizes: {} {}".format(n0, n1)
        n = min(n0, n1)
        for i in range(n):
            if d0[n] != d1[n]:
                yield "unequal values at index: {}, value 0: {}, value 1: {}".format(n, d0[n], d1[n])


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


class DataProperty(object):

    def __init__(self, cls, start=0, array_size=0):
        object.__init__(self)
        self.type = cls if type(cls) != type else _resolve_cls_as_type(cls)
        self.start = start
        self.array_size = array_size

    def _whats_my_name(self, obj):
        for field_name, field in type(obj).__dict__.items():
            if field is self:
                return field_name
        raise Exception("DataProperty ({}) not found in object: {}".format(self, obj))

    def __call__(self, fget):
        self.fget = fget
        return self

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        #name = self._whats_my_name(obj)
        start = self.start
        if hasattr(obj, "_offset"):
            start += getattr(obj, "_offset")
        data = obj.get_data()[start:]
        deserialized_value = self.deserialize(data)
        return deserialized_value

    def __set__(self, obj, value):
        #name = self._whats_my_name(obj)
        start = self.start
        if hasattr(obj, "_offset"):
            start += getattr(obj, "_offset")
        serialized_value = self.serialize(value)
        obj.get_data()[start:start + len(serialized_value)] = serialized_value

    def __delete__(self, obj):
        name = self._whats_my_name(obj)
        del obj.__dict__["_" + name]

    def serialize(self, value):
        buf = Buffer()
        self.serialize_to_buffer(buf, value)
        return buf.getvalue()

    def deserialize(self, data):
        buf = Buffer(data)
        buf.seek(0)
        return self.deserialize_from_buffer(buf)

    def serialize_to_buffer(self, buf: Buffer, value):
        if self.type.__class__ == str:
            if self.array_size == 0:
                r = struct.pack(self.type, value)
                buf.write(r)
            else:
                if self.array_size == "*":
                    for o in value:
                        buf.write(struct.pack(self.type, o))
                elif self.array_size.__class__ == int:
                    for o in value:
                        buf.write(struct.pack(self.type, o))
                elif self.array_size.__class__.__name__ == 'function':
                    # self.array_size.__set__(obj, len(self.__get__(obj)))
                    for o in value:
                        buf.write(struct.pack(self.type, o))
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))
        elif self.type.__class__ == type:
            if self.array_size == 0:
                o = value
                o.serialize_to_buffer(buf)
            else:
                if self.array_size == "*":
                    for o in value:
                        o.serialize_to_buffer(buf)
                elif self.array_size.__class__ == int:
                    for o in value:
                        o.serialize_to_buffer(buf)
                elif self.array_size.__class__.__name__ == 'function':
                    for o in value:
                        o.serialize_to_buffer(buf)
                else:
                    raise Exception("Invalid size specification {}".format(self.array_size))
        else:
            raise Exception("Invalid type specification {}".format(self.type))

    def deserialize_from_buffer(self, buf: Buffer, **kwargs):
        try:
            if self.type.__class__ == str:
                if self.array_size == 0:
                    s = struct.calcsize(self.type)
                    r = struct.unpack(self.type, buf.read(s))[0]
                    return r
                else:
                    r = None
                    if self.array_size == "*":
                        s = struct.calcsize(self.type)
                        r = []
                        while not self.break_array(buf):
                            r.append(struct.unpack(self.type, buf.read(s))[0])
                        #return r
                    elif self.array_size.__class__ == int:
                        s = struct.calcsize(self.type)
                        r = [struct.unpack(self.type, buf.read(s))[0] for i in range(self.array_size)]
                        #return r
                    elif self.array_size.__class__.__name__ == 'function':
                        raise NotImplementedError()
                        # si = self.array_size(obj)
                        # s = struct.calcsize(self.type)
                        # r = [struct.unpack(self.type, buf.read(s))[0] for i in range(si)]
                        # return r
                    else:
                        raise Exception("Invalid size specification {}".format(self.array_size))
                    if self.type == "B":
                        #  Handle special case where we want a bytearray
                        r = bytearray(r)
                    return r
            elif self.type.__class__ == type:
                if self.array_size == 0:
                    r = create_structure_from_buffer(self.type, buf, **kwargs)
                    return r
                else:
                    if self.array_size == "*":
                        s = struct.calcsize(self.type)
                        r = []
                        while not self.break_array(buf):
                            r.append(create_structure_from_buffer(self.type, buf, **kwargs))
                        return r
                    elif self.array_size.__class__ == int:
                        r = [create_structure_from_buffer(self.type, buf, **kwargs) for i in range(self.array_size)]
                        return r
                    elif self.array_size.__class__.__name__ == 'function':
                        raise NotImplementedError()
                        # si = self.array_size(obj)
                        # s = struct.calcsize(self.type)
                        # r = [struct.unpack(self.type, buf.read(s))[0] for i in range(si)]
                        # return r
                    else:
                        raise Exception("Invalid size specification {}".format(self.array_size))

            else:
                raise Exception("Invalid type specification {}".format(self.type))
        except UnderflowException as e:
            raise Exception("An exception occurred during the processing of {}:\n\n".format(e))
