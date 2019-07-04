
constants_1 = [
0x03030203,
0x05040404,
0x06050505,
0x07070606
    ]

constants_2 = [
0x0105020F,
0x01030008,
0x0104020A,
0x01030006,
0x0105020C,
0x01030007,
0x01040209,
0x01030006,
0x0105020D,
0x01030008,
0x0104020A,
0x01030006,
0x0105020B,
0x01030007,
0x01040209,
0x01030006,
0x0105020E,
0x01030008,
0x0104020A,
0x01030006,
0x0105020C,
0x01030007,
0x01040209,
0x01030006,
0x0105020D,
0x01030008,
0x0104020A,
0x01030006,
0x0105020B,
0x01030007,
0x01040209,
0x01030006,
0x0105020F,
0x01030008,
0x0104020A,
0x01030006,
0x0105020C,
0x01030007,
0x01040209,
0x01030006,
0x0105020D,
0x01030008,
0x0104020A,
0x01030006,
0x0105020B,
0x01030007,
0x01040209,
0x01030006,
0x0105020E,
0x01030008,
0x0104020A,
0x01030006,
0x0105020C,
0x01030007,
0x01040209,
0x01030006,
0x0105020D,
0x01030008,
0x0104020A,
0x01030006,
0x0105020B,
0x01030007,
0x01040209,
0x01030006
    ]

constants_3 = [
0x00000000,
0x00000000,
0x04030201,
0x08070605
    ]

constants_4 = [
0x00010000,
0x00030002,
0x00050004,
0x00070006,
0x000A0008,
0x0016000E,
0x00460026,
0x01060086
    ]

constants_5 = [
0x05040402,
0x06050505,
0x06060606,
0x06060606,
0x06060606,
0x07070606,
0x07070707,
0x07070707,
0x07070707,
0x07070707,
0x07070707,
0x07070707,
0x08080808,
0x08080808,
0x08080808,
0x08080808
    ]

constants_6 = [
0x0017063F,
0x000E0227,
0x0012042F,
0x000A011F,
0x00140537,
0x000C0223,
0x0010032B,
0x0008011B,
0x0015063B,
0x000D0225,
0x0011042D,
0x0009011D,
0x00130533,
0x000B0221,
0x000F0329,
0x00070119,
0x0016063D,
0x000E0226,
0x0012042E,
0x000A011E,
0x00140535,
0x000C0222,
0x0010032A,
0x0008011A,
0x00150639,
0x000D0224,
0x0011042C,
0x0009011C,
0x00130531,
0x000B0220,
0x000F0328,
0x00070118,
0x0017063E,
0x000E0227,
0x0012042F,
0x000A011F,
0x00140536,
0x000C0223,
0x0010032B,
0x0008011B,
0x0015063A,
0x000D0225,
0x0011042D,
0x0009011D,
0x00130532,
0x000B0221,
0x000F0329,
0x00070119,
0x0016063C,
0x000E0226,
0x0012042E,
0x000A011E,
0x00140534,
0x000C0222,
0x0010032A,
0x0008011A,
0x00150638,
0x000D0224,
0x0011042C,
0x0009011C,
0x00130530,
0x000B0220,
0x000F0328,
0x00070118

    ]


class PNGER(object):

    def __init__(self):
        self.array_a = 0x19C720
        self.mapfiledata = 0x19E942

    @property
    def word_h(self):
        return self._word_h

    @word_h.setter
    def word_h(self, value):
        self._word_h = value

    @property
    def word_i(self):
        return self._word_i

    @word_i.setter
    def word_i(self, value):
        self._word_i = value

    @property
    def word_e(self):
        return self._word_e

    @word_e.setter
    def word_e(self, value):
        self._word_e = value

    @property
    def word_d(self):
        return self._word_d

    @word_d.setter
    def word_d(self, value):
        self._word_d = value

    @property
    def word_g(self):
        return self._word_g

    @word_g.setter
    def word_g(self, value):
        self._word_g = value

    @property
    def word_f(self):
        return self._word_f

    @word_f.setter
    def word_f(self, value):
        self._word_f = value

    @property
    def word_j(self):
        return self._word_j

    @word_j.setter
    def word_j(self, value):
        self._word_j = value

    @property
    def word_a(self):
        return self._word_a

    @word_a.setter
    def word_a(self, value):
        self._word_a = value
		
    @property
    def dword_c(self):
        return self._dword_c

    @word_a.setter
    def dword_c(self, value):
        self._dword_c = value

pnger = PNGER()

import cpu_emulator as cpu

#cpu = CPU()

import struct
from io import BytesIO

path = "resources/MxM_unseen_1.map"

with open(path, 'rb') as f:
    data = f.read()

f = BytesIO(data)

magic, int1, const1, int2, int3 = struct.unpack("<IIIII", f.read(4*5))


pnger.array_a = 0x19C720
pnger.mapfiledata = 0x19E942

cpu._mem.set(pnger.mapfiledata, f.read(0x800))

assert cpu.get_byte(pnger.mapfiledata) == 0

#0x4078A1
#eax comes from earlier
cpu.eax = 0x800

cpu.dx = cpu.get_byte(pnger.mapfiledata + 1)
cpu.di = cpu.get_byte(pnger.mapfiledata)
cpu.cx = cpu.get_byte(pnger.mapfiledata + 2)

cpu.set_word(pnger.array_a + 2, cpu.di)
cpu.set_word(pnger.array_a + 6, cpu.dx)
cpu.set_word(pnger.array_a + 0xA, cpu.cx)
cpu.set_word(pnger.array_a + 0xC, 0)
cpu.set_word(pnger.array_a + 0xE, 3)
cpu.set_word(pnger.array_a + 0x10, cpu.ax)

    
pnger.word_h = cpu.di
pnger.word_i = cpu.dx
pnger.word_e = cpu.cx
pnger.word_d = 0
pnger.word_g = 3
pnger.word_f = cpu.ax

mapfilepointers = 0x423C70

def _0x00407D40(ebx, array_a):
    #?(ebx, array_a)
    cpu.ebx = pnger.dword_c = cpu.ebx
    cpu.esi = array_a
    cpu.ebp = cpu.ebx
    cpu.ebp &= 0xFFFF
    cpu.ax = pnger.word_d
    cpu.edx = 0x004021E0
    cpu.edi = mapfilepointers
    cpu.ecx = cpu.eax
    cpu.ecx &= 0xFFFF
    if cpu.ebp > cpu.ecx:
        cpu.ax = pnger.word_g
        pnger.word_e = pnger.word_e >> cpu.cl
        cpu.set_word(array_a + 0xA, pnger.word_e)
        #while not at end of mapfiledata buffer?
        if cpu.ax != pnger.word_f:
            #0x407DBD
            cpu.ax = pnger.word_g
            cpu.ecx = cpu.eax
            cpu.edx = 0
            #cpu.edi = constants_destination_5
            cpu.ecx &= 0xFFFF
            cpu.dh = pnger.mapfiledata + cpu.ecx #3
            cpu.cl = cpu.bl
            pnger.word_e |= cpu.dx
            cpu.eax += 1
            #pnger.word_g = mapfiledata pointer?
            pnger.word_g = cpu.ax
            cpu.ax = pnger.word_d
            cpu.cl -= cpu.al
            cpu.eax -= cpu.ebx #ebx is that 1 that was pushed to the stack all the way back, this becomes a negative value now
            pnger.word_e = pnger.word_e >> cpu.cl #dejavu: pnger.word_e is shifted right by pnger.word_d (-al)
            cpu.eax += 8 #some kind of module bytes operation?
            assert cpu.eax == 7
            pnger.word_d = cpu.ax
            cpu.ax = 0

if cpu.dx >= 4:
    if cpu.dx <= 6:
        cpu.ecx = 0x10
        cpu.ecx -= cpu.edx
        cpu.edx = 0xFFFF
        cpu.edx = cpu.edx >> cpu.cl
        cpu.set_word(pnger.array_a + 0x08, cpu.dx)
        pnger.word_j = cpu.dx
        assert pnger.word_j == 0x3F

        if cpu.di <= 1:
            if cpu.di == 0:
                cpu.edi = pnger.array_a + 0x30E2
                
                #0x40793C
                i = 0
                for const in constants_1:
                    cpu.set_dword(cpu.edi + i, const)
                    i += 4
                
                #0x407941
                cpu.edi = pnger.array_a + 0x2B22
                i = 0
                for const in constants_2:
                    cpu.set_dword(cpu.edi + i, const)
                    i += 4

                #0x407963
                cpu.edi = pnger.array_a + 0x30F2
                i = 0
                for const in constants_3:
                    cpu.set_dword(cpu.edi + i, const)
                    i += 4

                #0x407976
                cpu.edi = pnger.array_a + 0x3102
                i = 0
                for const in constants_4:
                    cpu.set_dword(cpu.edi + i, const)
                    i += 4

                #0x407989
                cpu.edi = pnger.array_a + 0x30A2
                i = 0
                for const in constants_5:
                    cpu.set_dword(cpu.edi + i, const)
                    i += 4

                #0x7079A0
                cpu.edi = pnger.array_a + 0x2A22
                i = 0
                for const in constants_6:
                    cpu.set_dword(cpu.edi + i, const)
                    i += 4

                pnger.word_a = 0x1000
                cpu.set_word(pnger.array_a + 0x4, 0x1000)

                #0x407AD0
                #translate_byte_v1(pnger.array_a)
                cpu.esi = pnger.array_a
                cpu.ebx = 1
                cpu.al = cpu.get_byte(pnger.array_a + 0xA)
                pnger.word_e = cpu.get_byte(pnger.array_a + 0xA)
                assert cpu.al == pnger.word_e

                if (cpu.al & cpu.bl) == 0:
                    #0x407D40
                    _0x00407D40(cpu.ebx, pnger.array_a)

                if cpu.ax == 0:
                    #0x407BAB
                    if pnger.word_h == 0:
                        cpu.edx = 0
                        #push 8
                        #push pnger.array_a
                        cpu.dl = pnger.word_e
                        #fails: todo: assert cpu.dl == 0
                        cpu.edi = cpu.edx #0

                        _0x00407D40(8, pnger.array_a)
