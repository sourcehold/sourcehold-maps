
from pnger_constants import *

class A1(object):

    def __init__(self, mapfilehandle):
        self.datum = 0 #f10
        self.f2 = 0
        self.shift = 0 #f12
        self.file_data = mapfilehandle #mapfilehandle #f18
        self.read_into_buffer = cb2_read_chunk_of_size #read_chunk_from_mapfile #f22
        self.f26 = callback1_ #f26
        #mapfiledata is 0x2222 bytes away from A1 pointer. mapfildata starts 0x17 bytes into mapfile
        self.data = Memory()
        self.data30 = Memory() #f30
        self.buffer_pointer = 0 #f14
        self.size_of_buffer = None #f16
        self.f8 = None
        self.f6 = None
        self.f4 = None
        self.myst1 = Memory()
        self.heap1 = Memory()
        self.heap1_pointer = 0

from cpu_emulator import Memory, MemoryPointer

#Basically puts memory from a1 into a3.heap1, as specified by a2
def callback1_(a1 : Memory, a2 : int, a3 : A1):
    v1 = fun_402770(a3.myst1, a1, a2 & 0xffff)
    v2 = MemoryPointer(a3.heap1) #TODO what happens to heap1_pointer?
    v3 = MemoryPointer(a1)

    a3.myst1 = v1
    v4 = (a2 & 0xffff) >> 2

    while v4 != 0:
        v4 -= 1
        v2.dword = v3.dword
        v2 += 4
        v3 += 4

    v5 = a2 & 3
    while v5 != 0:
        v5 -= 1
        v2.byte = v3.byte
        v2 += 1
        v3 += 1

    a3.heap1_pointer = a3.heap1_pointer + (a2 & 0xffff)
    return a2


def callback1_(a1 : Memory, a2 : int, a3 : A1):
    ebp4 = a3
    esi5 = a1
    eax6 = ebp4.myst1
    ebx7 = a2 & 0xffff
    eax8 = fun_402770(eax6, esi5, ebx7)
    edi9 = MemoryPointer(ebp4.heap1) #is f8 an address?
    esi5 = MemoryPointer(esi5) #I added this
    edx10 = ebx7
    ebp4.myst1 = eax8
    ecx11 = ebx7 >> 2
    #_offset_edi9 = 0
    #_offset_esi5 = 0
    while ecx11 != 0:
        ecx11 -= 1
        edi9.dword = esi5.dword #this should work
  #      edi9.set(_offset_edi9, esi5.get(_offset_esi5, nbytes = 4))#*edi9 = *(void***)esi5; TODO
        edi9 = edi9 + 4
        esi5 = esi5 + 4
    ecx12 = edx10 & 3
    while ecx12 != 0:
        ecx12 = ecx12 - 1
        edi9.byte = esi5.byte
        edi9+=1
        esi5+=1
    ebp4.heap1_pointer = ebp4.heap1_pointer + ebx7
    return a2

def read_bytes(dst : A1, times, size, src):
    d = src.read(times*size)
    dst.data = d
    return len(d)

def cb2_read_chunk_of_size(dst, size, mapfilehandle):
    v4 = mapfilehandle
    eax5 = read_bytes(dst, 1, size & 0xFFFF, v4)
    return eax5 #bytes_read

def not_dword(v):
    return v ^ 0xFFFFFFFF



#0041D5D4  8D EF 02 2D 20 64 65 66 6C 61 74 65 20 31 2E 31  .ï.- deflate 1.1
#0041D5E4  2E 33 20 43 6F 70 79 72 69 67 68 74 20 31 39 39  .3 Copyright 199
#0041D5F4  35 2D 31 39 39 38 20 4A 65 61 6E 2D 6C 6F 75 70  5-1998 Jean-loup
#0041D604  20 47 61 69 6C 6C 79 20 00 00 00 00 00 00 00 00   Gailly ........


def fun_402770(a1 : int, a2 : Memory, a3 : int):
    a2 = MemoryPointer(a2, 0)
    if a2:
        esi5 = a3
        eax6 = not_dword(a1)
        if esi5 >= 8:
            edi7 = esi5 >> 3

            while True:
                ebx8 = ecx4.dword
                esi5 -= 8
                eax9 = data_0x41d1d8.get()
                #Unfinished

def fun_402770(a1 : int, a2 : Memory, a3 : int):

    ecx4 = a2 #array b destination?
    _offset_ecx4 = 0
    if ecx4:
        esi5 = a3
        eax6 = not_dword(a1)
        if esi5 >= 8:
            edi7 = esi5 >> 3

            while True:
                ebx8 = ecx4.get(_offset_ecx4, 4)
                esi5 = esi5 - 8
                eax9 = data_0x41d1d8.get((eax6 & 0xff ^ ebx8) * 4, 4) ^ eax6 >> 8

                ebx10 = ecx4.get(_offset_ecx4 + 1, 1)
                ecx11 = _offset_ecx4 + 1;
                edx12 = data_0x41d1d8.get((eax9 & 0xff ^ ebx10) * 4, 4) ^ eax9 >> 8

                ebx13 = ecx4.get(ecx11 + 1, 1)
                ecx14 = ecx11 + 1;
                eax15 = data_0x41d1d8.get((edx12 & 0xff ^ ebx13) * 4, 4) ^ edx12 >> 8

                ebx16 = ecx4.get(ecx14 + 1, 1)
                ecx17 = ecx14 + 1;
                edx18 = data_0x41d1d8.get((eax15 & 0xff ^ ebx16) * 4, 4) ^ eax15 >> 8

                ebx19 = ecx4.get(ecx17 + 1, 1)
                ecx20 = ecx17 + 1;
                eax21 = data_0x41d1d8.get((edx18 & 0xff ^ ebx19) * 4, 4) ^ edx18 >> 8

                ebx22 = ecx4.get(ecx20 + 1, 1)
                ecx23 = ecx20 + 1;
                edx24 = data_0x41d1d8.get((eax21 & 0xff ^ ebx22) * 4, 4) ^ eax21 >> 8

                ebx25 = ecx4.get(ecx23 + 1, 1)
                ecx26 = ecx23 + 1;
                eax27 = data_0x41d1d8.get((edx24 & 0xff ^ ebx25) * 4, 4) ^ edx24 >> 8

                ebx28 = ecx4.get(ecx26 + 1, 1)
                eax6 = eax27 >> 8 ^ data_0x41d1d8.get((eax27 & 0xff ^ ebx28) * 4, 4)
                _offset_ecx4 = ecx26 + 1 + 1
                edi7 -= 1
                if not edi7:
                    break
        if esi5:
            while True:
                ebx29 = ecx4.get(_offset_ecx4, 1)
                eax6 = eax6 >> 8 ^ data_0x41d1d8.get((eax6 & 0xff ^ ebx29)*4, 4) #this seems pointless, check TODO
                _offset_ecx4 += 1
                esi5 -= 1
                if not esi5:
                    break
        return not_dword(eax6)
    else:
        return 0

def set_h(src, v):
    v = v << 8
    src = src & 0xFFFF00FF
    src = src | v
    return src

def fun_407d40(a1 : A1, a2):

    if (a2 & 0xFFFF) > (a1.shift & 0xFFFF):
        a1.datum = a1.datum >> (a1.shift & 0xFFFF)
        if a1.buffer_pointer == a1.size_of_buffer:
            a1.buffer_pointer = 0x800
            a1.size_of_buffer = a1.read_into_buffer(a1, 0x800, a1.file_data)  # set a1.data
            if a1.size_of_buffer != 0:
                a1.buffer_pointer = 0
            else:
                return 1 #this should never happen
        #a1.datum = a1.datum | (a1.get_byte_at((a1.buffer_pointer & 0xffff) + 0x2222, 1) << 8)
        a1.datum = a1.datum | (a1.data.get(a1.buffer_pointer & 0xffff, 1) << 8)
        a1.buffer_pointer = a1.buffer_pointer + 1
        a1.datum = a1.datum >> (a2 - a1.shift)
        a1.shift = a1.shift - a2 + 8
        return 0
    else:
        a1.datum = a1.datum >> a2
        a1.shift = a1.shift - a2
        return 0

def fun_407d40(a1 : A1, a2):
    ebx3 = a2
    eax4 = a1.shift #f12
    edx5 = a1.read_into_buffer #f22
    edi6 = a1.file_data #f18
    ecx7 = eax4 & 0xFFFF
    if (ebx3 & 0xFFFF) > ecx7:
        ax8 = a1.buffer_pointer #f14
        a1.datum = a1.datum >> ecx7 #f10
        if ax8 == a1.size_of_buffer: #f16
            a1.buffer_pointer = 0x800
            eax9 = edx5(a1, 0x800, edi6) # set a1.data
            a1.size_of_buffer = eax9 #f16
            if eax9 != 0:
                a1.buffer_pointer = 0
            else:
                eax9 = 1
                return 1
        eax9 = a1.buffer_pointer
        #edx10 = a1.get_byte_at((eax9 & 0xffff) + 0x2222) #*(int8_t*)((int32_t)&edx10 + 1) = *(int8_t*)((eax9 & 0xffff) + (uint8_t)a1 + 0x2222);
        edx10 = a1.data.get(eax9 & 0xffff, 1)
        a1.datum = a1.datum | edx10
        eax11 = eax9 + 1
        a1.buffer_pointer = eax11
        eax11 = a1.shift
        a1.datum = a1.datum >> (ebx3 - eax11)
        eax12 = eax11 - ebx3 + 8
        a1.shift = eax12
        eax12 = 0
        return 0
    else:
        cx13 = ebx3
        eax14 = eax4-ebx3
        a1.datum = a1.datum >> cx13
        a1.shift = eax14
        eax14 = 0
        return 0

def translate_byte_v1(a1 : A1):
    a12 = a1.datum
    if a12 & 1 != 0:
        eax3 = fun_407d40(a1, 1)
        if eax3 == 0:
            #eax4 = a1.datum #but a byte, not the full word!
            eax4 = a1.datum & 0xFF
            #TODO undestand what is going on here... what data is this? is this in the constants area? constants_destination_2?
            #ecx5 = a1.get_byte_at(eax4 + 0x2b22) #*(int8_t*)((int32_t)eax4 + (uint8_t)a1 + 0x2b22);
            ecx5 = constants_2.get(eax4, 1)
            edi7 = ecx5
            ebp8 = ecx5 & 0xFFFF
            #edx6 = a1.get_byte_at(ebp8 + 0x30e2) #*(int8_t*)((uint8_t)a1 + (uint32_t)ebp8 + 0x30e2);
            edx6 = constants_1.get(ebp8, 1)
            eax9 = fun_407d40(a1, edx6)
            if eax9 == 0:
                #ecx10 = a1.get_byte_at(ebp8 + 0x30f2) #*(uint8_t*)((uint8_t)a1 + (uint32_t)ebp8 + 0x30f2);
                ecx10 = constants_3.get(ebp8, 1)
                if ecx10 == 0:
                    eax11 = a1.datum
                    ebx12 = ((1 << ecx10) - 1) & eax11
                    eax9 = fun_407d40(a1, ecx10)
                    if not eax9 or (ebx12 & 0xFFFF) + ebp8 == 0x10e:
                        #edil3 = a1.get_byte_at((ebp8*2) + 0x3102) #*(int16_t*)((uint32_t)(a1 + (uint32_t)ebp8 * 2) + 0x3102);
                        edi13 = constants_4.get(ebp8*2, 2)
                        edi7 = edil3 + ebx12
                    else:
                        eax9 = 0x306
                        return 0x306
                edi14 = edi7 + 0x100
                eax9 = edi14
                return eax9
            else:
                return 0x306
        else:
            return 0x306
    eax15 = fun_407d40(a1, 1)
    if eax15 != 0:
        return 0x306
    if a1.f2 != 0:
        edx30 = a1.datum
        edi20 = edx30
        eax28 = fun_407d40(a1, 8)
        if eax28 != 0:
            return 0x306
        return eax28
    eax16 = a1.datum
    if eax16 == 0:
        eax17 = fun_407d40(a1, 8)
        if eax17 == 0:
            ecx18 = a1.datum
            #edx19 = a1.get_byte_at(ecx18 + 0x2ea2) #*(int8_t*)((int32_t)ecx18 + (uint8_t)a1 + 0x2ea2);
            raise Exception("Unused memory location")
            edi20 = edx19
        else:
            return 0x306
    else:
        #edx21 = a1.get_byte_at((eax16 & 0xff) + 0x2c22) #*(uint8_t*)((eax16 & 0xff) + (uint8_t)a1 + 0x2c22);
        raise Exception("Unused memory location")
        edi20 = edx21
        if edi20 == 0xff:
            if eax16 & 63 == 0:
                eax22 = fun_407d40(a1, 6)
                if eax22 == 0:
                    edx21 = a1.datum
                    #eax23 = a1.get_byte_at((edx21  & 0x7f) + 0x2e22) #*(int8_t*)((edx21 & 0x7f) + (uint8_t)a1 + 0x2e22);
                    raise Exception("Unused memory location")
                    edi20 = eax23
                else:
                    return 0x306
            else:
                eax24 = fun_407d40(a1, 4)
                if eax24 == 0:
                    eax25 = a1.datum
                    #ecx26 = a1.get_byte_at(eax25 + 0x2d22) #*(int8_t*)((int32_t)eax25 + (uint8_t)a1 + 0x2d22);
                    raise Exception("Unused memory location")
                    edi20 = ecx26
                else:
                    return 0x306
    raise Exception("Unused memory location")
    #ecx27 = a1.get_byte_at((edi20 & 0xffff) + 0x2fa2) #*(int8_t*)((edi20 & 0xffff) + (uint8_t)a1 + 0x2fa2);
    eax28 = fun_407d40(a1, ecx27)
    zf29 = eax28 == 0
    eax28 = 0x306
    if zf29:
        eax28 = edi20
        return eax28
    else:
        return eax28

def fun_407cb0(a1 : A1, a2 : int):
    eax3 = a1.datum
    #ebx4 = a1.get_byte_at(eax3 + 0x2a22)
    ebx4 = constants_6.get(eax3, 1)
    #edx5 = a1.get_byte_at((ebx4 & 0xffff) + 0x30a2)
    edx5 = constants_5.get(ebx4 & 0xffff)
    eax6 = fun_407d40(a1, edx5)
    if eax6 == 0:
        if a2 != 2:
            ecx7 = a1.f6
            edi8 = a1.f8
            v10 = ecx7
            edx9 = a1.datum
            edi11 = edi8 & edx9 | ebx4 << ecx7
        else:
            eax6 = a1.datum
            v10 = 2
            edi11 = eax6 & 3 | ebx4 * 4
        eax6 = fun_407d40(a1, v10)
        if eax6 == 0:
            return edi11 + 1
    eax6 = 0
    return eax6


#my interpretation

def dynamic_constant_loading(a1 : int, a2 : int, a3 : Memory, a4 : Memory):
    a1 -= 1
    if a1 < 0:
        return


    while True:
        d = MemoryPointer(a2, a1).byte
        d2 = MemoryPointer(a3, a1).byte

        edx13 = 1 << d
        while True:
            ecx14 = d2
            d2 += edx13
            MemoryPointer(a4, ecx14).byte = a1
            if d2 >= 0x100:
                break
        a1 -= 1
        d -= 1
        if a1 < 0:
            break

#0x10
#constants_destination_1
#constants_2
#constants_destination_2 #which is 16*16 bytes long. some sort of mapping?

def dynamic_constant_loading(a1 : int, a2 : Memory, a3 : Memory, a4 : Memory, *args):
    ebx8 = a1 & 0xffffffff
    if ebx8 >= 0:
        edi9 = a4
        esi10 = ebx8 + a2 #(uint8_t*)(*(int16_t*)&ebx8 + (uint8_t)a2); where did -1 go?
        esi10 = MemoryPointer(a2, ebx8).byte
        ebp11 = a3 - a2
        while True:
            eax12 = esi10 + ebp11
            edx13 = 1 << esi10 #*esi10
            while True:
                ecx14 = eax12
                eax12 = eax12 + edx13
                MemoryPointer(edi9, ecx14).byte = ebx8#edi9.set(ecx14 & 0xffff, ebx8)
                if eax12 >= 0x100:
                    break
            ebx8 -= 1
            esi10 -= 1
            if ebx8 < 0:
                break
    return None


def mem_cpy1(dst : Memory, src :  Memory, amount : int, *args):
    #actually a memcpy
    #a3 = amount
    #a2 = source
    #a1 = destination
    src_ = src
    dst_ = dst
    amount_ = amount
    esi7 = amount_ >> 2 #divided by 4.
    _offset = 0
    if esi7 != 0:
        n = esi7 * 4 #and then multiplied by 4?
        _offset = 0
        while True:
            #407F49
            #quite confusing, as it is a simple memcpy...
            #v1 = _offset.get()
            v1 = src_.get(_offset, nbytes = 4)

            #*dst_ = *_offset;
            dst_.set(_offset, v1)

            _offset = _offset + 4
            if _offset > n:
                break
    edx9 = amount_ - esi7 * 4 - 1
    if edx9 != 0:
        _offset = 0 # assumed
        edx10 = edx9 - 1
        if edx10 != 0:
            if edx10 - 1 != 0:
                return dst_ #return
            else:
                v1 = src_.get(_offset)
                dst_.set(_offset, v1)
                _offset += 1
        #*dst_ = *_offset;
        v1 = src_.get(_offset)
        dst_.set(_offset, v1)
        _offset += 1
    #*dst_ = *_offset
    dst_.set(_offset, src.get(_offset))
    return dst_ #return
#
# # alternative version
# def byte_processing_loop1(a1):
#     esi2 = a1
#     esi2.f4 = 0x1000
#     eax3 = translate_byte_v1(esi2)
#     ebx4 = eax3
#     ebx5 = ebx4 & 0xffff
#     if ebx5 >= 0x305:
#         eax3 = esi2.f4 - 0x1000
#         v6 = esi2.f18
#         esi2.f26(esi2 + 0x101e, eax3, v6)
#         return ebx5
#     else:
#         while True:
#             if ebx5 >= 0x100:
#                 ebx5 = ebx5 - 0xfe
#                 eax7 = fun_407cb0(esi2, ebx5)
#                 eax3 = eax7 & 0xffff
#                 if eax3 == 0: #!eax3
#                     break
#                 ecx8 = esi2.f4
#                 ebp9 = esi2.f1 #esi2 + 1
#                 edi10 = ecx8 + ebp9
#                 ecx11 = ecx8 + ebx5
#                 esi2.f4 = ecx11
#                 ecx12 = edi10 - eax3
#                 while True:
#                     ebx5 -= 1
#                     #*edi10 = *ecx12
#                     edi10 += 1
#                     ecx12 += 1
#                     if ebx5 == 0:
#                         break
#             else:
#                 ebp9 = esi2 + 1 #esi2 + 1, or this is meant to be esi2.f1?
#                 eax13 = esi2.f4
#                 ecx14 = eax13 + 1
#                 esi2.f4 = ecx14
#                 esi2.set_byte_at(eax13 + ebp9, ebx5)#*(int8_t*)(eax13 + ebp9) = *(int8_t*)&ebx5;
#             if esi2.f4 >= 0x2000:
#                 edi15 = esi2 + 0x101e
#                 v16 = esi2.f18
#                 esi2.f26(edi15, 0x1000, v16)
#                 ecx17 = esi2.f4
#                 load_constants(ebp9, edi15, ecx17 - 0x1000, edi15, 0x1000, v16)
#                 esi2.f4 = esi2.f4 - 0x1000
#             eax3 = translate_byte_v1(esi2)
#
#             ebx5 = eax3 # *(uint16_t *) & ebx5 = *(uint16_t *) & eax3;
#             ebx5 = ebx5 & 0xffff
#             if not ebx5 < 0x305:
#                 break
#         eax3 = esi2.f4 - 0x1000
#         v6 = esi2.f18
#         esi2.f26(esi2 + 0x101e, eax3, v6)
#         return ebx5

# full compilation version
def byte_processing_loop1(a1 : A1, a2, a3, a4, a5):
    v6 = None #missing
    v7 = None#ebx8
    v9 = None#ebp10
    v11 = None#esi12
    v14 = None#edi15
    esi13 = a1
    esi13.f4 = 0x1000
    eax16 = translate_byte_v1(esi13)
    ebx17 = eax16
    ebx18 = ebx17 & 0xffff
    if ebx18 >= 0x305:
        eax16 = esi13.f4 - 0x1000
        v19 = esi13.file_data
        esi13.f26(esi13 + 0x101e, eax16, v19) #TODO: this does not make any sense
        eax16 = ebx18
        return eax16
    else:
        while True:
            if ebx18 >= 0x100:
                ebx18 = ebx18 - 0xfe
                v20 = ebx18
                eax21 = fun_407cb0(esi13, v20)  #eax21 = fun_407cb0(esi13, *(int16_t*)&v20);
                eax16 = eax21 & 0xffff
                if eax16 == 0:
                    break
                ebp23 = esi13.data30
                ecx22 = esi13.f4
                #edi24 = ecx22 + ebp23 #TODO
                _offset_edi24 = 0 + esi13.f4
                #ecx25 = ecx22 + ebx18 #TODO
                _offset_ecx25 = ebx18 + esi13.f4 #what is ebx18?
                esi13.f4 = _offset_ecx25
                ecx26 = _offset_edi24 - eax16
                _offset = 0
                while True:
                    #This loop puts 01 02 03 0 40 5s
                    ebx18 = ebx18 - 1
                    esi13.data30.set(_offset_edi24, esi13.data30.get(_offset_ecx25))
                    _offset_edi24 += 1
                    _offset_ecx25 += 1
                    if not ebx18:
                        break
            else:
                ebp23 = esi13.data30
                eax27 = esi13.f4
                ecx28 = eax27 + 1
                esi13.f4 = ecx28
                esi13.data30.set(eax27, ebx18)
            if esi13.f4 >= 0x2000:
                edi29 = esi13 + 0x101e
                v30 = esi13.file_data
                esi13.f26(edi29, 0x1000, v30)
                ecx31 = esi13.f4
                mem_cpy1(ebp23, edi29, ecx31 - 0x1000, edi29, 0x1000, v30, v14, v11, v9, v7, v6, a1, a2, a3, a4, a5)
                esi13.f4 = esi13.f4 + 0xf000
            eax16 = translate_byte_v1(esi13)
            ebx18 = eax16
            ebx18 = ebx18 & 0xffff
            if ebx18 >= 0x305:
                break
        eax16 = esi13.f4 - 0x1000
        v19 = esi13.file_data
        esi13.f26(esi13 + 0x101e, eax16, v19)
        eax16 = ebx18
        return eax16

    ebx18 = 0x306
    eax16 = esi13.f4 - 0x1000
    v19 = esi13.file_data
    esi13.f26(esi13 + 0x101e, eax16, v19) #TODO
    eax16 = ebx18
    return eax16

def byte_processing_loop1(a1 : A1, a2, a3, a4, a5):
    v6 = None #missing
    v7 = None#ebx8
    v9 = None#ebp10
    v11 = None#esi12
    v14 = None#edi15
    esi13 = a1
    esi13.f4 = 0x1000
    eax16 = translate_byte_v1(esi13)
    ebx17 = eax16
    ebx18 = ebx17 & 0xffff
    if ebx18 >= 0x305:
        eax16 = esi13.f4 - 0x1000
        v19 = esi13.file_data
        esi13.f26(esi13 + 0x101e, eax16, v19)
        eax16 = ebx18
        return eax16
    else:
        while True:
            if ebx18 >= 0x100:
                ebx18 = ebx18 - 0xfe
                v20 = ebx18
                eax21 = fun_407cb0(esi13, v20)  #eax21 = fun_407cb0(esi13, *(int16_t*)&v20);
                eax16 = eax21 & 0xffff
                if eax16 == 0:
                    break
                ebp23 = esi13.data30
                ecx22 = esi13.f4
                #edi24 = ecx22 + ebp23 #TODO
                _offset_edi24 = 0 + esi13.f4
                #ecx25 = ecx22 + ebx18 #TODO
                _offset_ecx25 = ebx18 + esi13.f4 #what is ebx18?
                esi13.f4 = _offset_ecx25
                ecx26 = _offset_edi24 - eax16
                _offset = 0
                while True:
                    #This loop puts 01 02 03 0 40 5s
                    ebx18 = ebx18 - 1
                    esi13.data30.set(_offset_edi24, esi13.data30.get(_offset_ecx25, 1)) #is this really data30? or array_b_dest?
                    _offset_edi24 += 1
                    _offset_ecx25 += 1
                    if not ebx18:
                        break
            else:
                ebp23 = esi13.data30
                eax27 = esi13.f4
                ecx28 = eax27 + 1
                esi13.f4 = ecx28
                esi13.data30.set(eax27, ebx18)
            if esi13.f4 >= 0x2000:
                edi29 = esi13 + 0x101e
                v30 = esi13.file_data
                esi13.f26(edi29, 0x1000, v30)
                ecx31 = esi13.f4
                mem_cpy1(ebp23, edi29, ecx31 - 0x1000, edi29, 0x1000, v30, v14, v11, v9, v7, v6, a1, a2, a3, a4, a5)
                esi13.f4 = esi13.f4 + 0xf000
            eax16 = translate_byte_v1(esi13)
            ebx18 = eax16
            ebx18 = ebx18 & 0xffff
            if ebx18 >= 0x305:
                break
        eax16 = esi13.f4 - 0x1000
        v19 = esi13.file_data
        esi13.f26(esi13 + 0x101e, eax16, v19)
        eax16 = ebx18
        return eax16

    ebx18 = 0x306
    eax16 = esi13.f4 - 0x1000
    v19 = esi13.file_data
    esi13.f26(esi13 + 0x101e, eax16, v19) #TODO
    eax16 = ebx18
    return eax16