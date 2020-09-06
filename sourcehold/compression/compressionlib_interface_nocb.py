import ctypes
import platform
import sys
import pathlib


def generate_library_name():
    os = None
    ext = None
    if 'windows' in platform.platform().lower():
        os = 'windows-latest'
        ext = ".dll"
    if 'linux' in platform.platform().lower():
        os = 'ubuntu-latest'
        ext = '.so'
    if 'macos' in platform.platform().lower():
        os = 'macOS-latest'
        ext = '.so'

    arch = None
    if '64' in platform.architecture()[0]:
        arch = 'x64'
    if '32' in platform.architecture()[0]:
        arch = 'x86'

    return f"compressionlib-nocb-{os}-{arch}{ext}"


def load_library(lib_name):
    potential_locations = [pathlib.Path(lib_name), pathlib.Path(__file__).parent / lib_name,
                           pathlib.Path(__file__).parent.parent.parent / lib_name, pathlib.Path(sys.prefix) / "sourcehold" / lib_name]

    for location in potential_locations:
        if location.exists():
            return ctypes.CDLL(str(location.absolute()))


    raise Exception(f"Could not find library: {lib_name}")


dll = load_library(generate_library_name())

dll.explode_nocb.restype = ctypes.c_uint
dll.explode_nocb.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.POINTER(ctypes.c_int),
                             ctypes.POINTER(ctypes.c_ubyte), ctypes.c_int]

dll.explode_nocb.restype = ctypes.c_void_p
dll.explode_nocb.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.POINTER(ctypes.c_int),
                             ctypes.POINTER(ctypes.c_ubyte), ctypes.c_int]

import struct

OUTBUFFERSIZE = 1000 * 1000 * 32  # reserve 32mb


def decompress(data):
    indata = data
    indatalen = len(data)

    pbInBuff = ctypes.cast(indata, ctypes.POINTER(ctypes.c_ubyte))
    pbInBuffEnd = indatalen

    outdata = b'\x00' * OUTBUFFERSIZE
    outdatalen = len(outdata)

    pbOutBuff = ctypes.cast(outdata, ctypes.POINTER(ctypes.c_ubyte))
    # pbOutBuffEnd = ctypes.cast(outdatalen, ctypes.POINTER(ctypes.c_int))
    pbOutBuffEnd = ctypes.c_int(outdatalen)

    # ob = ctypes.cast(pbOutBuff, ctypes.c_void_p).value

    # print("explode data", file=sys.stderr)
    result = dll.explode_nocb(pbOutBuff, ctypes.byref(pbOutBuffEnd), pbInBuff, pbInBuffEnd)

    size = pbOutBuffEnd.value

    # print("getting data", file=sys.stderr)
    r = outdata[0:size]
    # print("returning data", file=sys.stderr)
    return b''.join(struct.pack("B", v) for v in r)


def compress(data, level=6):
    indata = data
    indatalen = len(data)

    pbInBuff = ctypes.cast(indata, ctypes.POINTER(ctypes.c_ubyte))
    pbInBuffEnd = indatalen

    # print("pbInBuff is at {}. pbInBuffEnd is at: {} {}".format(hex(addr), hex(newaddr), pvoid), file=sys.stderr)

    outdata = b'\x00' * OUTBUFFERSIZE
    outdatalen = len(outdata)

    pbOutBuff = ctypes.cast(outdata, ctypes.POINTER(ctypes.c_ubyte))
    pbOutBuffEnd = ctypes.c_int(outdatalen)

    # print("pbOutBuff is at {}. pbOutBuffEnd is at: {} {}".format(hex(addr), hex(newaddr), pvoid), file=sys.stderr)

    # dsize = ctypes.c_uint(0x1000)
    level = ctypes.c_uint(level - 3)
    type = ctypes.c_uint(0)

    # print("imploding data", file=sys.stderr)
    result = dll.implode_nocb(pbOutBuff, ctypes.byref(pbOutBuffEnd), pbInBuff, pbInBuffEnd, type, level)
    # print("data imploded", file=sys.stderr)

    # print(hex(ctypes.cast(info.pbOutBuff, ctypes.c_void_p).value), file=sys.stderr)
    # print(hex(ob), file=sys.stderr)

    size = pbOutBuffEnd.value

    r = outdata[0:size]
    # print(len(r))

    # print("returning data", file=sys.stderr)
    return b''.join(struct.pack("B", v) for v in r)


if __name__ == "__main__":

    if len(sys.argv) < 2:
        # print(sys.argv)
        # raise Exception("Not enough arguments")
        # data = open('resources/MxM_unseen_1.preview', 'rb').read()
        data = open('resources/MxM_unseen_1.map', 'rb').read()[20:]
        sys.argv.append("decompress")
        # sys.argv.append("compress")
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
