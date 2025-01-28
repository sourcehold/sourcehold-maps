from sourcehold.structure_tools import _resolve_cls_as_type, create_structure_from_buffer


import struct

from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.structure_tools.UnderflowException import UnderflowException


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