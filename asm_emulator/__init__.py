
from types import ModuleType


import struct


ENDIANNESS = 'little'



class Register(object):

    def __init__(self, value=None, memory=None, size = None, offset = 0):
        self.value : int = value if not value is None else 0
        self.memory = memory if memory else Memory()
        self.offset = 0 #get(0) -> get(0x2222)
        self.size = 0  #0x2222 + 0x300, get(0x301) throws an error

    def _check_valid(self, pointer):
        if self.size != None and pointer >= self.size:
            return False
        if pointer < 0:
            return False
        return True

    def _shift(self, pointer):
        return pointer if self.offset == None else self.offset + pointer

    def __add__(self, other):
        return Register(self.value + other, self.memory)

    def __sub__(self, other):
        return Register(self.value - other, self.memory)

    def __mul__(self, other):
        return Register(self.value * other, self.memory)

    def __floordiv__(self, other):
        return Register(self.value // other, self.memory)

    def __lshift__(self, other):
        return Register(self.value << other, self.memory)

    def __rshift__(self, other):
        return Register(self.value >> other, self.memory)

    @property
    def l(self):
        return Register(self.value & 0xFF, self.memory)

    @l.setter
    def l(self, value):
        return Register((self.value & 0xFFFFFF00) | (value & 0xFF), self.memory)

    @property
    def h(self):
        return Register((self.value >> 8) & 0xFF, self.memory)

    @h.property
    def h(self, value):
        return Register((self.value & 0xFFFF00FF) | ((value & 0xFF) << 8), self.memory)

    @property
    def x(self):
        return Register(self.value & 0xFFFF, self.memory)

    @x.property
    def x(self, value):
        return Register((self.value & 0xFFFF0000) | (value & 0xFFFF), self.memory)

    @property
    def ex(self):
        return Register(self.value & 0xFFFFFFFF, self.memory)

    @ex.property
    def ex(self, value):
        return Register(value, self.memory)

    @property
    def dword(self):
        return int.from_bytes(self.memory.get(self.value, nbytes = 4), byteorder=ENDIANNESS, signed=False)

    @dword.setter
    def dword(self, value):
        self.memory.set(self.value, value.to_bytes(4, byteorder=ENDIANNESS))

    @property
    def word(self):
        return int.from_bytes(self.memory.get(self.value, nbytes = 2), byteorder = ENDIANNESS, signed = False)

    @word.setter
    def word(self, value):
        self.memory.set(self.value, value.to_bytes(2, byteorder = ENDIANNESS))

    @property
    def byte(self):
        return self.memory.get(self.value, nbytes = 1)

    @byte.setter
    def byte(self, value):
        self.memory.set(self.value, value)

    def put(self, data):
        self.memory.set(self.value, data)

    def get(self, nbytes):
        return self.memory.get(self.value, nbytes=nbytes)

class Memory(object):

    def __init__(self, offset = 0, strict = True):
        self.memory = {}
        self.strict = strict
        self.offset = offset

    def _transform_key(self, key):
        return key - self.offset

    def get(self, key, nbytes = 1):
        result = b''

        key = self._transform_key(key)

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

        key = self._transform_key(key)

        if type(value).__name__ != "bytes":
            raise Exception("value is not of type bytes")

        for i in range(len(value)):
            self.memory[key + i] = value[i]




class Emulator(ModuleType):

    def __init__(self):
        super().__init__("cpu_emulator")
        self._mem = Memory()
        self._eax = Register(0, _mem)
        self._ebx = Register(0, _mem)
        self._ecx = Register(0, _mem)
        self._edx = Register(0, _mem)
        self._ebp = Register(0, _mem)
        self._esp = Register(0, _mem)
        self._esi = Register(0, _mem)
        self._edi = Register(0, _mem)
        self._stack = []
        self._zf = 0
        self._sf = 0

    def test(self, a, b):
        self._zf = 0 if (a & b) == 0 else 1 #TODO


    def cmp(self, a, b):
        self._sf = 1 if a < b else 0

    def be(self):
        return self._sf == 1 or self._zf == 1

    def l(self):
        return self._sf == 0 and self._zf == 0

    def as_pointer(self, value):
        return Register(value, self._mem)

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
        return self._stack.pop()

    def push(self, value):
        return self._stack.append(value)

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



cpu = Emulator()
mem = cpu._mem


## Example ##

cpu.eax = cpu.as_pointer(cpu.esp+4).dword# mov eax,dword ptr ss:[esp+4]
cpu.push(cpu.ebx)# push ebx
cpu.ebx = (cpu.eax - 1).pointer# lea ebx,dword ptr ds:[eax-1]
cpu.test(cpu.bx, cpu.bx)# test bx,bx
if not cpu.l(): # jl stronghold map pnger.407E4E
    cpu.eax = cpu.as_pointer(cpu.esp + 0xC).dword# mov eax,dword ptr ss:[esp+C]
    cpu.ebp = cpu.as_pointer(cpu.esp + 0x14).dword# mov ebp,dword ptr ss:[esp+14]
    cpu.push(cpu.esi) # push esi
    cpu.esi = cpu.bx# movsx esi,bx
    cpu.push(cpu.edi)# push edi
    cpu.edi = cpu.as_pointer(cpu.esp + 20).dword# mov edi,dword ptr ss:[esp+20]
    cpu.esi += cpu.eax# add esi,eax
    cpu.ebp -= cpu.eax# sub ebp,eax
    while True:
        cpu.cl = cpu.as_pointer(cpu.esi).byte# mov cl,byte ptr ds:[esi]
        cpu.eax = 0# xor eax,eax
        cpu.al = cpu.as_pointer(cpu.esi + cpu.ebp).byte# mov al,byte ptr ds:[esi+ebp]
        cpu.edx = 1# mov edx,1
        cpu.edx = cpu.edx << cpu.cl# shl edx,cl
        while True:
            cpu.ecx = cpu.eax# mov ecx,eax
            cpu.eax += cpu.edx# add eax,edx
            cpu.ecx &= 0xFFFF# and ecx,FFFF
            cpu.cmp(cpu.ax, 0x100) # cmp ax,100
            cpu.as_pointer(cpu.ecx + cpu.edi).byte = cpu.bl # mov byte ptr ds:[ecx+edi],bl
            if cpu.b():# jb stronghold map pnger.407E31
                continue
            break
        cpu.ebx -= 1# dec ebx
        cpu.esi -= 1# dec esi
        cpu.test(cpu.bx, cpu.bx) # test bx,bx
        if cpu.ge(): # jge stronghold map pnger.407E23
            continue
        break
    cpu.edi = cpu.pop() # pop edi
    cpu.esi = cpu.pop() # pop esi
    cpu.ebp = cpu.pop() # pop ebp
cpu.ebx = cpu.pop() # pop ebx
# ret


def routine(a, b, c):


    def routine_sub1():
        pass

    def routine_sub2():
        pass

    cpu.eax = 1

    if cpu.ebx == 0:
        routine_sub1()
    routine_sub2()
