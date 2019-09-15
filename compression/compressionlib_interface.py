from __future__ import print_function

import ctypes
import sys


class TDataInfo(ctypes.Structure):
    _fields_ = [('pbInBuff', ctypes.POINTER(ctypes.c_ubyte)),
                ('pbInBuffEnd', ctypes.POINTER(ctypes.c_ubyte)),
                ('pbOutBuff', ctypes.POINTER(ctypes.c_ubyte)),
                ('pbOutBuffEnd', ctypes.POINTER(ctypes.c_ubyte))]


dll = ctypes.CDLL("bin/compressionlib-vs.dll")

dll.implode.restype = ctypes.c_uint
dll.implode.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.POINTER(ctypes.c_ubyte),
                        ctypes.POINTER(TDataInfo),
                        ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(ctypes.c_uint)]

dll.explode.restype = ctypes.c_int
dll.explode.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.POINTER(ctypes.c_ubyte),
                        ctypes.POINTER(TDataInfo)]

import struct

TESTSIZE = 1000 * 1000 * 32  # reserve 32mb


@ctypes.CFUNCTYPE(None, ctypes.POINTER(ctypes.c_ubyte), ctypes.POINTER(ctypes.c_uint), ctypes.POINTER(TDataInfo))
def write(buf, size, param):
    info = param.contents
    nMaxWrite = ctypes.cast(info.pbOutBuffEnd, ctypes.c_void_p).value - ctypes.cast(info.pbOutBuff,
                                                                                    ctypes.c_void_p).value
    nToWrite = size.contents.value

    # print("asked to write {} number of bytes".format(nToWrite), file=sys.stderr)

    if nToWrite > nMaxWrite:
        nToWrite = nMaxWrite

    for i in range(nToWrite):
        info.pbOutBuff[i] = buf[i]

    # print("writing {} number of bytes".format(nToWrite), file=sys.stderr)

    ctypes.cast(ctypes.pointer(info.pbOutBuff), ctypes.POINTER(ctypes.c_void_p)).contents.value += nToWrite

    return None


@ctypes.CFUNCTYPE(ctypes.c_int, ctypes.POINTER(ctypes.c_ubyte), ctypes.POINTER(ctypes.c_uint),
                  ctypes.POINTER(TDataInfo))
def read(buf, size, param):
    info = param.contents
    nMaxAvail = ctypes.cast(info.pbInBuffEnd, ctypes.c_void_p).value - ctypes.cast(info.pbInBuff,
                                                                                   ctypes.c_void_p).value
    nToRead = size.contents.value

    # print("asked to read {} number of bytes".format(nToRead), file=sys.stderr)

    if nToRead > nMaxAvail:
        nToRead = nMaxAvail

    # print("reading {} number of bytes".format(nToRead), file=sys.stderr)

    for i in range(nToRead):
        buf[i] = info.pbInBuff[i]

    ctypes.cast(ctypes.pointer(info.pbInBuff), ctypes.POINTER(ctypes.c_void_p)).contents.value += nToRead

    return nToRead


def decompress(data):
    indata = data

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

    # print("explode data", file=sys.stderr)
    result = dll.explode(read, write, work_buf, info)

    if result != 0:
        raise Exception("conversion returned {}".format(result))
    # print("explode done", file=sys.stderr)

    # print(ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value, file=sys.stderr)
    # print(ob, file=sys.stderr)

    decompressed_size = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value - ob

    # print("data decompressed into {} bytes".format(decompressed_size), file=sys.stderr)

    # print("getting data", file=sys.stderr)
    r = outdata[0:decompressed_size]
    # print("returning data", file=sys.stderr)
    return b''.join(struct.pack("B", v) for v in r)


def compress(data):
    indata = data

    work_buf = (ctypes.c_ubyte * (36312 + 100))()
    work_buf = ctypes.cast(work_buf, ctypes.POINTER(ctypes.c_ubyte))

    info = TDataInfo()

    info.pbInBuff = ctypes.cast(indata, ctypes.POINTER(ctypes.c_ubyte))
    addr = ctypes.cast(info.pbInBuff, ctypes.c_void_p).value
    newaddr = ctypes.cast(info.pbInBuff, ctypes.c_void_p).value + len(indata)
    pvoid = ctypes.cast(newaddr, ctypes.c_void_p)
    info.pbInBuffEnd = ctypes.cast(pvoid, ctypes.POINTER(ctypes.c_ubyte))

    # print("pbInBuff is at {}. pbInBuffEnd is at: {} {}".format(hex(addr), hex(newaddr), pvoid), file=sys.stderr)

    outdata = b'\x00' * TESTSIZE

    info.pbOutBuff = ctypes.cast(outdata, ctypes.POINTER(ctypes.c_ubyte))
    addr = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value
    newaddr = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value + TESTSIZE
    pvoid = ctypes.cast(newaddr, ctypes.c_void_p)
    info.pbOutBuffEnd = ctypes.cast(pvoid, ctypes.POINTER(ctypes.c_ubyte))

    # print("pbOutBuff is at {}. pbOutBuffEnd is at: {} {}".format(hex(addr), hex(newaddr), pvoid), file=sys.stderr)

    ob = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value
    oa = ctypes.addressof(info.pbOutBuff)
    # print(oa, file=sys.stderr)
    # print(ob, file=sys.stderr)

    dsize = ctypes.c_uint(0x1000)
    type = ctypes.c_uint(0)

    # print("imploding data", file=sys.stderr)
    result = dll.implode(read, write, work_buf, info, type, dsize)
    # print("data imploded", file=sys.stderr)

    # print(hex(ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value), file=sys.stderr)
    # print(hex(ob), file=sys.stderr)

    compressed_size = ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value - ob

    # print("data compressed into {} bytes".format(compressed_size), file=sys.stderr)

    if result != 0:
        raise Exception("conversion returned {}".format(result))
    # print("explode done")

    # print("opening destination file")

    # print("getting data", file=sys.stderr)
    od = (ctypes.c_ubyte * compressed_size).from_address(ob)
    # print(od[0], file=sys.stderr)
    # o.seek(0)
    r = od[0:compressed_size]
    # print(len(r))

    # print("returning data", file=sys.stderr)
    return b''.join(struct.pack("B", v) for v in r)


if __name__ == "__main__":

    if len(sys.argv) < 2:
        # print(sys.argv)
        # raise Exception("Not enough arguments")
        data = open('resources/MxM_unseen_1.preview', 'rb').read()
        # data = open('resources/MxM_unseen_1.map', 'rb').read()[20:]
        # sys.argv.append("decompress")
        sys.argv.append("compress")
    else:

        f = sys.stdin.buffer

        data = f.read()

    # print("Length of received data: {}".format(len(data)), file=sys.stderr)
    # print("Last four values of received data: {}".format(data[-4:]), file=sys.stderr)

    if sys.argv[1] == "compress":
        compressed = compress(data)
        sys.stdout.buffer.write(compressed)

    elif sys.argv[1] == "decompress":
        decompressed = decompress(data)
        sys.stdout.buffer.write(decompressed)
