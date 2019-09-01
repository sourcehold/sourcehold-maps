
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
        self.array_a = 0x19C720 #basically at the start of the words data
        self.array_b = 0x19C73E #basically right after the words.
        self.mapfiledata = 0x19E942

        self.word_h = 0
        self.word_i = 0
        self.word_e_mfd_datum = 0
        self.word_d_bitshift = 0
        self.word_g_mfd_pointer = 0
        self.word_f = 0
        self.word_j = 0
        self.word_a = 0
        self.dword_c = 0



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
pnger.word_e_mfd_datum = cpu.cx
pnger.word_d_bitshift = 0
pnger.word_g_mfd_pointer = 3
pnger.word_f = cpu.ax

mapfilepointers = 0x423C70

def _0x00407D40(ebx, array_a):
    #?(ebx, array_a)
    cpu.ebx = pnger.dword_c = ebx #cpu.ebx
    cpu.esi = array_a
    cpu.ebp = cpu.ebx
    cpu.ebp &= 0xFFFF
    cpu.ax = pnger.word_d_bitshift
    cpu.edx = 0x004021E0
    edi = cpu.edi
    cpu.ecx = cpu.eax
    cpu.ecx &= 0xFFFF
    bitshift = pnger.word_d_bitshift & 0xFFFF
    if cpu.ebp > cpu.ecx:
        cpu.ax = pnger.word_g_mfd_pointer
        pnger.word_e_mfd_datum = pnger.word_e_mfd_datum >> (bitshift & 0xFF)
        #cpu.set_word(array_a + 0xA, pnger.word_e)
        #while not at end of mapfiledata buffer?
        if cpu.ax != pnger.word_f: #word_g == word_f
            #0x407DBD
            cpu.ax = pnger.word_g_mfd_pointer
            cpu.ecx = cpu.eax
            cpu.edx = 0
            #cpu.edi = constants_destination_5
            cpu.ecx &= 0xFFFF
            mfd_pointer = pnger.word_g_mfd_pointer & 0xFFFF
            cpu.dh = cpu.get_byte(pnger.mapfiledata + mfd_pointer) #3 #array_a + ecx + 0x2222
            cpu.cl = cpu.bl #comes from ebx, which was an argument to this function
            boffset = ebx & 0xFF
            pnger.word_e_mfd_datum |= cpu.dx
            cpu.eax += 1
            pnger.word_g_mfd_pointer = cpu.ax #pnger.word_g = mapfiledata pointer?
            cpu.ax = pnger.word_d_bitshift
            cpu.cl -= cpu.al
            cpu.eax -= cpu.ebx #ebx is the first arg of this function, that 1 that was pushed to the stack all the way back, this becomes a negative value now
            pnger.word_e_mfd_datum = pnger.word_e_mfd_datum >> ((ebx & 0xFF) - (pnger.word_d_bitshift & 0xFF)) #dejavu: pnger.word_e is shifted right by pnger.word_d (-al)
            cpu.eax += 8 #some kind of modulo bytes operation?
            #assert cpu.eax == 7
            #pnger.word_d_bitshift = cpu.ax
            pnger.word_d_bitshift = pnger.word_d_bitshift - ebx + 8
            cpu.ax = 0
            cpu.edi = edi
            return cpu.eax

    else:
        cpu.cx = cpu.bx
        cpu.eax -= cpu.ebx
        pnger.word_e_mfd_datum = pnger.word_e_mfd_datum >> cpu.cl
        pnger.word_d_bitshift = cpu.ax
        cpu.eax = 0
        return cpu.eax

    raise NotImplementedError()

def translate_byte_v1(array_a):
    # 0x407AD0
    cpu.esi = pnger.array_a
    cpu.ebx = 1
    cpu.al = cpu.get_byte(pnger.array_a + 0xA)
    pnger.word_e_mfd_datum = cpu.get_byte(pnger.array_a + 0xA)
   # assert cpu.al == pnger.word_e_mfd_datum

    if (cpu.al & cpu.bl) == 0:
        #0x407D40
        _0x00407D40(cpu.ebx, pnger.array_a)

        if cpu.ax == 0:
            #0x407BAB
            if pnger.word_h == 0:
                cpu.edx = 0
                #push 8
                #push pnger.array_a
                cpu.dl = pnger.word_e_mfd_datum
                #fails: todo: assert cpu.dl == 0
                cpu.edi = cpu.edx #0

                result = _0x00407D40(8, pnger.array_a)
                if cpu.ax == 0:
                    cpu.ax = cpu.di
                    return result
                    #return cpu.ax

    raise NotImplementedError()

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
                #cpu.set_word(pnger.array_a + 0x4, 0x1000)

                result = translate_byte_v1(pnger.array_a)

                cpu.bx = cpu.ax #result
                cpu.ebx &= 0xFFFF
                while cpu.bx < 0x305:
                    if cpu.bx < 0x100:
                        cpu.eax = 0
                        cpu.ebp = pnger.array_b
                        cpu.ax = pnger.word_a #0x1000
                        #assert cpu.ax == 0x1000
                        cpu.ecx = cpu.eax + 1
                        pnger.word_a = cpu.cx
                        cpu.set_byte(pnger.array_b + cpu.eax, result & 0xFF)
                        print("z")
                        if pnger.word_a < 0x2000:
                            print("a")
                            result = cpu.bx = translate_byte_v1(pnger.array_a) #TODO
                            cpu.ebx &= 0xFFFF
                            if cpu.eax == 0x1002:
                                print("b")
                                assert result == 0x8E
                            if cpu.bx < 0x305:
                                continue
                            else:
                                break
            else:
                raise NotImplementedError()
        else:
            raise NotImplementedError()






