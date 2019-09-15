from __future__ import print_function

import ctypes
import io


class TDataInfo(ctypes.Structure):
    # _pack_ = 1
    _fields_ = [('pbInBuff', ctypes.POINTER(ctypes.c_ubyte)),
                ('pbInBuffEnd', ctypes.POINTER(ctypes.c_ubyte)),
                ('pbOutBuff', ctypes.POINTER(ctypes.c_ubyte)),
                ('pbOutBuffEnd', ctypes.POINTER(ctypes.c_ubyte))]


class TDcmpStruct(ctypes.Structure):
    # _pack_ = 1
    _fields_ = [('offs0000', ctypes.c_ulong),
                ('ctype', ctypes.c_ulong),
                ('outputPos', ctypes.c_ulong),
                ('dsize_bits', ctypes.c_ulong),
                ('dsize_mask', ctypes.c_ulong),
                ('bit_buff', ctypes.c_ulong),
                ('extra_bits', ctypes.c_ulong),
                ('in_pos', ctypes.c_int),
                ('in_bytes', ctypes.c_ulong),
                ('param', ctypes.c_void_p),
                ('read_buf', ctypes.c_void_p),
                ('write_buf', ctypes.c_void_p),
                ('out_buff', ctypes.c_ubyte * 0x2204),
                ('in_buff', ctypes.c_ubyte * 0x800),
                ('DistPosCode', ctypes.c_ubyte * 0x100),
                ('LengthCodes', ctypes.c_ubyte * 0x100),
                ('offs2C34', ctypes.c_ubyte * 0x100),
                ('offs2D34', ctypes.c_ubyte * 0x100),
                ('offs2E34', ctypes.c_ubyte * 0x80),
                ('offs2EB4', ctypes.c_ubyte * 0x100),
                ('ChBitsAsc', ctypes.c_ubyte * 0x100),
                ('DistBits', ctypes.c_ubyte * 0x40),
                ('LenBits', ctypes.c_ubyte * 0x10),
                ('ExLenBits', ctypes.c_ubyte * 0x10),
                ('LenBase', ctypes.c_ushort * 0x10)
                ]


# print(ctypes.sizeof(TDcmpStruct), file = sys.stderr)


import struct

TESTSIZE = 100000

o = io.BytesIO(b'')


@ctypes.CFUNCTYPE(None, ctypes.POINTER(ctypes.c_ubyte), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(TDataInfo))
def write(buf, size, param):
    info = param.contents
    nMaxWrite = ctypes.cast(info.pbOutBuffEnd, ctypes.c_void_p).value - ctypes.cast(info.pbOutBuff,
                                                                                    ctypes.c_void_p).value
    nToWrite = size.contents.value

    print("asked to write {} number of bytes".format(nToWrite), file=sys.stderr)

    if nToWrite > nMaxWrite:
        nToWrite = nMaxWrite

    for i in range(nToWrite):
        info.pbOutBuff[i] = buf[i]

    print("writing {} number of bytes".format(nToWrite), file=sys.stderr)

    # my:
    # o.write(b''.join(struct.pack("B", v) for v in buf[:nToWrite]))

    ctypes.cast(ctypes.pointer(info.pbOutBuff), ctypes.POINTER(ctypes.c_void_p)).contents.value += nToWrite

    # print(ctypes.cast(info.pbOutBuffEnd, ctypes.c_void_p).value - ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value)
    return None


@ctypes.CFUNCTYPE(ctypes.c_int, ctypes.POINTER(ctypes.c_ubyte), ctypes.POINTER(ctypes.c_uint),
                  ctypes.POINTER(TDataInfo))
def read(buf, size, param):
    info = param.contents
    nMaxAvail = ctypes.cast(info.pbInBuffEnd, ctypes.c_void_p).value - ctypes.cast(info.pbInBuff,
                                                                                   ctypes.c_void_p).value
    nToRead = size.contents.value

    print("asked to read {} number of bytes".format(nToRead), file=sys.stderr)

    if nToRead > nMaxAvail:
        nToRead = nMaxAvail

    print("reading {} number of bytes".format(nToRead), file=sys.stderr)

    for i in range(nToRead):
        buf[i] = info.pbInBuff[i]

    ctypes.cast(ctypes.pointer(info.pbInBuff), ctypes.POINTER(ctypes.c_void_p)).contents.value += nToRead

    # print(ctypes.cast(info.pbInBuffEnd, ctypes.c_void_p).value - ctypes.cast(info.pbInBuff, ctypes.c_void_p).value)

    return nToRead


def decompress(data):
    indata = data

    # work_buf = TDcmpStruct()
    work_buf = (ctypes.c_ubyte * (12596 + 100))()
    work_buf = ctypes.cast(work_buf, ctypes.POINTER(ctypes.c_ubyte))

    info = TDataInfo()

    info.pbInBuff = ctypes.cast(indata, ctypes.POINTER(ctypes.c_ubyte))
    info.pbInBuffEnd = ctypes.cast(
        ctypes.cast(ctypes.cast(info.pbInBuff, ctypes.c_void_p).value + len(indata), ctypes.c_void_p),
        ctypes.POINTER(ctypes.c_ubyte))

    outdata = b'\x00' * TESTSIZE

    info.pbOutBuff = ctypes.cast(outdata, ctypes.POINTER(ctypes.c_ubyte))
    info.pbOutBuffEnd = ctypes.cast(
        ctypes.cast(ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value + TESTSIZE, ctypes.c_void_p),
        ctypes.POINTER(ctypes.c_ubyte))

    ob = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value

    print("explode data", file=sys.stderr)
    result = dll.explode(read, write, work_buf, info)

    if result != 0:
        raise Exception("conversion returned {}".format(result))
    print("explode done", file=sys.stderr)

    print(ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value, file=sys.stderr)
    print(ob, file=sys.stderr)

    decompressed_size = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value - ob

    print("data decompressed into {} bytes".format(decompressed_size), file=sys.stderr)

    print("getting data", file=sys.stderr)
    r = outdata[0:decompressed_size]
    print("returning data", file=sys.stderr)
    return r


def compress(data):
    indata = data  # + b'\x00\x00\x00\x00'

    # work_buf = TDcmpStruct()
    work_buf = (ctypes.c_ubyte * (36312 + 100))()
    work_buf = ctypes.cast(work_buf, ctypes.POINTER(ctypes.c_ubyte))

    info = TDataInfo()

    info.pbInBuff = ctypes.cast(indata, ctypes.POINTER(ctypes.c_ubyte))
    addr = ctypes.cast(info.pbInBuff, ctypes.c_void_p).value
    newaddr = ctypes.cast(info.pbInBuff, ctypes.c_void_p).value + len(indata)
    pvoid = ctypes.cast(newaddr, ctypes.c_void_p)
    info.pbInBuffEnd = ctypes.cast(pvoid, ctypes.POINTER(ctypes.c_ubyte))

    print("pbInBuff is at {}. pbInBuffEnd is at: {} {}".format(hex(addr), hex(newaddr), pvoid), file=sys.stderr)

    outdata = b'\x00' * TESTSIZE

    info.pbOutBuff = ctypes.cast(outdata, ctypes.POINTER(ctypes.c_ubyte))
    addr = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value
    newaddr = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value + TESTSIZE
    pvoid = ctypes.cast(newaddr, ctypes.c_void_p)
    info.pbOutBuffEnd = ctypes.cast(pvoid, ctypes.POINTER(ctypes.c_ubyte))

    print("pbOutBuff is at {}. pbOutBuffEnd is at: {} {}".format(hex(addr), hex(newaddr), pvoid), file=sys.stderr)

    ob = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value
    oa = ctypes.addressof(info.pbOutBuff)
    print(oa, file=sys.stderr)
    print(ob, file=sys.stderr)

    dsize = ctypes.c_uint(0x1000)
    type = ctypes.c_uint(0)

    print("imploding data", file=sys.stderr)
    result = dll.implode(read, write, work_buf, info, type, dsize)
    print("data imploded", file=sys.stderr)

    print(hex(ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value), file=sys.stderr)
    print(hex(ob), file=sys.stderr)

    compressed_size = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value - ob

    print("data compressed into {} bytes".format(compressed_size), file=sys.stderr)

    if result != 0:
        raise Exception("conversion returned {}".format(result))
    # print("explode done")

    #    r = convert_file(data, o)
    # print("opening destination file")

    f2 = sys.stdout.buffer
    #    with open(file + ".dat", 'wb') as f2:

    print("getting data", file=sys.stderr)
    od = (ctypes.c_ubyte * compressed_size).from_address(ob)
    # print(od[0], file=sys.stderr)
    # o.seek(0)
    r = od[0:compressed_size]
    # print(len(r))

    print("returning data", file=sys.stderr)
    return r


def convert_file(data, o):
    indata = data

    work_buf = TDcmpStruct()

    info = TDataInfo()

    info.pbInBuff = ctypes.cast(indata, ctypes.POINTER(ctypes.c_ubyte))
    newaddr = ctypes.cast(info.pbInBuff, ctypes.c_void_p).value + len(indata)
    pvoid = ctypes.cast(newaddr, ctypes.c_void_p)
    info.pbInBuffEnd = ctypes.cast(pvoid, ctypes.POINTER(ctypes.c_ubyte))

    outdata = (ctypes.c_ubyte * TESTSIZE)()
    outdata = b'\x00' * TESTSIZE

    info.pbOutBuff = ctypes.cast(outdata, ctypes.POINTER(ctypes.c_ubyte))
    newaddr = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value + TESTSIZE
    pvoid = ctypes.cast(newaddr, ctypes.c_void_p)
    info.pbOutBuffEnd = ctypes.cast(pvoid, ctypes.POINTER(ctypes.c_ubyte))

    # decodeddata = io.BytesIO(b'')

    # print("explode data")
    result = dll.explode(read, write, work_buf, info)
    # print(result)

    if result != 0:
        raise Exception("conversion returned {}".format(result))
    # print("explode done")


import sys

if __name__ == "__main__":

    if len(sys.argv) < 2:
        # print(sys.argv)
        # raise Exception("Not enough arguments")
        data = open('resources/MxM_unseen_1.preview', 'rb').read()
        # data = open('resources/MxM_unseen_1.map', 'rb').read()[20:]
        # sys.argv.append("decompress")
        sys.argv.append("compress")
    else:
        # file = sys.argv[2]

        # f = open(file, 'rb')
        f = sys.stdin.buffer

        data = f.read()
        # data = data[20:]

    dll = ctypes.CDLL("bin/compressionlib-vs.dll")
    # dll = ctypes.CDLL("../IMPBORL.DLL")

    dll.implode.restype = ctypes.c_uint
    dll.implode.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.POINTER(ctypes.c_ubyte),
                            ctypes.POINTER(TDataInfo),
                            ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint)]

    dll.explode.restype = ctypes.c_int
    dll.explode.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.POINTER(ctypes.c_ubyte),
                            ctypes.POINTER(TDataInfo)]

    print("Length of received data: {}".format(len(data)), file=sys.stderr)
    print("Last four values of received data: {}".format(data[-4:]), file=sys.stderr)

    o = io.BytesIO()

    if sys.argv[1] == "compress":
        compressed = compress(data)
        sys.stdout.buffer.write(b''.join(struct.pack("B", v) for v in compressed))

    elif sys.argv[1] == "decompress":
        decompressed = decompress(data)
        sys.stdout.buffer.write(b''.join(struct.pack("B", v) for v in decompressed))
