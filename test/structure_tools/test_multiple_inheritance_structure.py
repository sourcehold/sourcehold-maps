
import unittest


from sourcehold.structure_tools import Structure, Field, Buffer


class A(Structure):
    size = Field(name="size", typ="<I")
    data = Field(name="data", typ="B", array_size=size)

    def test(self):
        print("I am A")


class B(object):

    def test(self):
        print("I am B")


class C(A, B):

    def test(self):
        super().test()
        print("I am C")


class MultipleInheritance(unittest.TestCase):

    def test_multiple_inheritance_fields(self):
        buf = Buffer(b'\x05\x00\x00\x00\x01\x02\x03\x04\x05')
        c = C().from_buffer(buf)
        c.test()