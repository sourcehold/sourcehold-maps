
global v
v = 1

@property
def version():
    return v

@version.setter
def version(value):
    global v
    v = value


from types import ModuleType


import struct

class Memory(object):

    def __init__(self, strict = False):
        self.memory = {}
        self.strict = strict
        
    def get(self, key, nbytes = 1):
        result = b''
        
        for i in range(nbytes):
            k = key + i
            if not k in self.memory:
                if self.strict:
                    raise Exception("Tried to touch untouched memory: {}".format(hex(k)))
                result += b'\x00'
            else:
                b = struct.pack("B", self.memory[k])
                if not b:
                    raise Exception("struct returned None")
                result += b
                
        return result

    def set(self, key, value):

        if type(value).__name__ != "bytes":
            raise Exception("value is not of type bytes")
        
        for i in range(len(value)):
            self.memory[key + i] = value[i]




class CPU(ModuleType):

    def __init__(self):
        super().__init__("cpu_emulator")
        self._eax = 0
        self._ebx = 0
        self._ecx = 0
        self._edx = 0
        self._ebp = 0
        self._esp = 0
        self._esi = 0
        self._edi = 0
        self._mem = Memory()
        self._stack = []

    def get_dword(self, address):
        return struct.unpack("<I", self._mem.get(address, nbytes = 4))[0]

    def get_word(self, address):
        return struct.unpack("<H", self._mem.get(address, nbytes = 2))[0]

    def get_byte(self, address):
        return struct.unpack("B", self._mem.get(address, nbytes = 1))[0]

    def set_dword(self, address, value):
        self._mem.set(address, struct.pack("<I", value))

    def set_word(self, address, value):
        self._mem.set(address, struct.pack("<H", value))

    def set_byte(self, address, value):
        self._mem.set(address, struct.pack("B", value))

    def pop(self):
        return stack.pop()

    def push(self, value):
        return stack.append(value)

    @property
    def eax(self):
        return self._eax

    @eax.setter
    def eax(self, value):
        self._eax = value

    @property
    def ax(self):
        return self._eax & 0xFFFF

    @ax.setter
    def ax(self, value):
        self._eax = value & 0xFFFF

    @property
    def ebx(self):
        return self._ebx

    @ebx.setter
    def ebx(self, value):
        self._ebx = value

    @property
    def bx(self):
        return self._ebx & 0xFFFF

    @bx.setter
    def bx(self, value):
        self._ebx = value & 0xFFFF

    @property
    def ecx(self):
        return self._ecx

    @ecx.setter
    def ecx(self, value):
        self._ecx = value

    @property
    def cx(self):
        return self._ecx & 0xFFFF

    @cx.setter
    def cx(self, value):
        self._ecx = value & 0xFFFF

    @property
    def edx(self):
        return self._edx

    @edx.setter
    def edx(self, value):
        self._edx = value

    @property
    def dx(self):
        return self._edx & 0xFFFF

    @dx.setter
    def dx(self, value):
        self._edx = value & 0xFFFF

    @property
    def ebp(self):
        return self._ebp

    @ebp.setter
    def ebp(self, value):
        self._ebp = value

    @property
    def bp(self):
        return self._ebp & 0xFFFF

    @bp.setter
    def bp(self, value):
        self._ebp = value & 0xFFFF

    @property
    def esp(self):
        return self._esp

    @esp.setter
    def esp(self, value):
        self._esp = value

    @property
    def sp(self):
        return self._esp & 0xFFFF

    @sp.setter
    def sp(self, value):
        self._esp = value & 0xFFFF

    @property
    def esi(self):
        return self._esi

    @esi.setter
    def esi(self, value):
        self._esi = value

    @property
    def si(self):
        return self._esi & 0xFFFF

    @si.setter
    def si(self, value):
        self._esi = value & 0xFFFF

    @property
    def edi(self):
        return self._edi

    @edi.setter
    def edi(self, value):
        self._edi = value

    @property
    def di(self):
        return self._edi & 0xFFFF

    @di.setter
    def di(self, value):
        self._edi = value & 0xFFFF

    @property
    def dl(self):
        return self._edx & 0xFF

    @dl.setter
    def dl(self, value):
        self._edx &= 0xFFFFFF00
        self._edx |= (value & 0xFF)

    @property
    def cl(self):
        return self._ecx & 0xFF

    @cl.setter
    def cl(self, value):
        self._ecx &= 0xFFFFFF00
        self._ecx |= (value & 0xFF)

    @property
    def bl(self):
        return self._ebx & 0xFF

    @bl.setter
    def bl(self, value):
        self._ebx &= 0xFFFFFF00
        self._ebx |= (value & 0xFF)

    @property
    def al(self):
        return self._eax & 0xFF

    @al.setter
    def al(self, value):
        self._eax &= 0xFFFFFF00
        self._eax |= (value & 0xFF)

    @property
    def dh(self):
        return self._edx & 0xFF00

    @dh.setter
    def dh(self, value):
        self._edx &= 0xFFFF00FF
        self._edx |= (value & 0xFF) << 8

    @property
    def ch(self):
        return self._ecx & 0xFF00

    @ch.setter
    def ch(self, value):
        self._ecx &= 0xFFFF00FF
        self._ecx |= (value & 0xFF) << 8

    @property
    def bh(self):
        return self._ebx & 0xFF00

    @bh.setter
    def bh(self, value):
        self._ebx &= 0xFFFF00FF
        self._ebx |= (value & 0xFF) << 8

    @property
    def ah(self):
        return self._eax & 0xFF00

    @ah.setter
    def ah(self, value):
        self._eax &= 0xFFFF00FF
        self._eax |= (value & 0xFF) << 8

#test = CPU()

import sys
old_module = sys.modules["cpu_emulator"]
new_module = sys.modules["cpu_emulator"] = CPU()

##test.eax = 16
##test.eax = test.eax >> 1
##assert test.eax == 8
##
##test.set_byte(0, 0x01)
##assert 1 == test.get_byte(0)
