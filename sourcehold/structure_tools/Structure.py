from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.structure_tools.DataProperty import DataProperty


import logging

from sourcehold.structure_tools.Field import Field


class Structure(object):

    def __init__(self):
        self.length: int = -1

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