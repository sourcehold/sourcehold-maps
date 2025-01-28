from sourcehold.structure_tools import _resolve_cls_as_type, create_structure_from_buffer


import struct
from typing import Callable, Generic, Iterable, cast

from sourcehold.structure_tools.BreakFunctions import BreakFunctions
from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.structure_tools.UnderflowException import UnderflowException

from typing import TypeVar

T = TypeVar("T")

class Field(Generic[T]):

    def __init__(self, name, typ, array_size: int | Callable | str=0, break_array=BreakFunctions.break_at_eof):
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

    def __get__(self, obj, objtype=None) -> T:
        if obj is None:
            raise Exception() # return self
        # if not self.fget is None:
        #    return self.fget(obj, self.name)
        if "_" + self.name not in obj.__dict__:
            raise AttributeError("object {} has no attribute {}".format(obj, self.name))
        return obj.__dict__["_" + self.name]

    def __set__(self, obj, value: T):
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
                    for o in self.__get__(cast(Iterable, obj)):
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