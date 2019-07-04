
class Event(object):

    QUIT = 0x00 #?
    DROP = 0x233

    def __init__(self, type, path = None):
        self.type = type
        self.path = path

    def get_path(self):
        return self.path

_simulated_events = []

def next_event():
    if len(_simulated_events) > 0:
        return _simulated_events.pop(0)
    return Event(Event.QUIT)

#0x0040114C - 0x0040117E
def event_loop():
    while True:
        event = next_event()
        if event.type == event.QUIT:
            break

        process_event(event)


def path_split(path):
    result = path.split(".")
    if len(result) == 1:
        return None
    return result[1]

def is_valid_path(path):
    return path.endswith(".map")
    
#0x00401190 -         
def process_event(event):
    #stack = [process_event, esi, event.type]

    if event.type > 0xA3:
        t = event.type - 0xA4
        if t == 0:
            pass
        t = t - 0x6D
        if t == 0:
            pass
        t = t - 0x122
        if t == 0:
            #on drop
            mappath = event.get_path()
            if not mappath:
                return
            p = path_split(mappath)
            if not p:
                return
            v = is_valid_path(mappath)
            if not v:
                return

            pngpath = mappath[:mappath.index(".map")] + ".png"

            args = [0, pngpath, mappath]
            convert_file(*args)

from io import BytesIO

def convert_file(*args):
    import os
    u0, pngpath, mappath = args
    if os.path.exists(pngpath):
        return

    with open(file = mappath, mode = 'rb') as f:
        mapdata = f.read()

    mapfilepointers = BytesIO(mapdata)

    #0x0019F874
    u0 = mapfilepointers.read(4)

    if u0 > 0xFFFFFFFF:
        return

    try:
        pngfile_handle = open(file = pngpath, mode = 'wb')
    except:
        return

    args = [pngfile_handle, mapfilepointers]
    convert_and_write(*args)

    pngfile_handle.close()

global eax
eax = 0

from memory_emulator import Memory

mem = Memory()

#Amount of ints read?
mem.set(0x19E854, 1)

import struct

stack = []
    
def convert_and_write(*args):
    pngfile_handle, mapfilepointers = args

    global eax
    eax = 0x3154

    #0x00417A50
    def uf0():
        ecx = 4

        #address of mapfilepointers: 0x19F854
        ecx = 0x19F854

        if eax < 0x1000:
            return

        while True:

            ecx -= 0x1000
            eax -= 0x1000

            # test [ecx], eax
            
            if eax >= 0x1000:
                continue
            else:
                break

        ecx -= eax

        #then we do a stack jump to ecx
        #stack elements:
        #   garbage?
        #   mapfilepointers
        #   mapfilepointers.start + 1080
        #   mapfilepointers.start + a lot (1090168d), that says eefeeefe repeatedly
        return [0x0211CF20, 0x021130E0, 0x00423C70, 0xA12E9770]

    stack.append(uf0())

    stack.append(mapfilepointers)
    esi = mapfilepointers
    stack.append(esi)
    stack.append(1)
    stack.append(4)
    # read into:
    stack.append(0x19C714)
    read_bytes(stack)

    eax = struct.unpack("<I", mem.get(0x19C714, nbytes = 4))

    stack.pop()
    stack.pop()
    stack.pop()
    stack.pop()

    if eax < 1:
        return #not sure
    
    stack.append(0x9E40)

    def _0x417992():
        stack.append(0)
        stack.append(stack[-2])

        def _0x4179A4():
            if stack[-1] > 0xFFFFFFE0:
                return
            stack.append(stack[-1])

            def _0x4179D0():
                
                #stub
                mem.set(0x4257C4, 1)

                #1
                eax = struct.unpack("<I", mem.get(0x4257C4, 4))

                stack.append(esi) #mapfilepointers

                esi = stack[-2]

                if eax != 3:
                    if eax != 2:
                        if esi != 0:
                            esi += 0xF
                            esi &= 0xFFFFFFF0
                            stack.append(esi)
                            stack.append(0)
                            stack.append(0x4257C0) #pointer to newly created memory, of size esi?

                            #RtlAllocateHeap
                            #returned 0x2113CC0 presumable this happened:
                            mem.set(0x2113CC0, b"\x00"*esi, type = 'B')
                            stack.pop()
                            stack.pop()
                            stack.pop()

                            #mapfilepointers
                            esi = stack.pop()

                            return 0x2113CC0
                            
            eax = _0x4179D0()

            #0x9E40
            ecx = stack.pop()

            if eax != 0:
                return eax
            else:
                pass #stub
        eax = _0x4179A4()
        
        #0x9E40
        ecx = stack.pop()
        #0x00
        ecx = stack.pop()

        return eax

    eax = _0x417992()
        
    stack.pop()
    assert(stack[-1] == mapfilepointers)
    stack[-4] = eax #0x02113CC0 substitutes 0x021130E0
    
    if eax == 0:
        return #stub

    stack.append(mapfilepointers)
    stack.append(1)
    ecx = 0x19C714 #esp+24
    stack.append(4)
    stack.append(ecx)  #0x19C718

    stack[-9] = eax #0x0211CF20 is also substituted
    #put mapfilepointers on stack, already there
    #zero out that bullshit value from earlier
    stack[-10] = 0

    eax = read_bytes_into(ecx, 1, 4, mapfilepointers)

    stack.pop()
    stack.pop()
    stack.pop()
    stack.pop()

    if eax == 0:
        return #EOF
    
    eax = read_bytes_into(0x19C714+8, 1, 4, mapfilepointers)

    if eax == 0:
        return #EOF

    eax = 0x19C414-0x14 #new stack base, stack[-4]
    
    eax = read_bytes_into(0x19C414-0x14, 1, 4, mapfilepointers)
    #extra
    stack[-4] = mem.get(0x19C414-0x14, nbytes = 4)

    if eax == 0:
        return

    ecx = 0x19C414-0x14 + 0x04 #which points to mapfilepointers
    edx = 0x19C720

    #mapfilepointers.read(1)

    file_processor(mapfilepointers, edx, callback1, cb2_read_chunk)
    
    
def file_processor(mapfilepointers, edx, callback1, cb2_read_chunk):
    ecx = callback1
    esi = mapfilepointers
    stack.append(esi)

    esi = mapfilepointers
    eax = cb2_read_chunk

    #edi = pngpath
    #stack.append(edi)

    eax = cb2_read_chunk(mapfilepointers, 2048, 0x19E942)

    if eax == 4:
        return

    ax = eax & 0xFFFF

    esi = 0x19C720

    assert(0x19E942+1 == esi+0x2223)
    dx = mem.get(0x19E942+1) #6
    di = mem.get(0x19E942) #0
    cx = mem.get(0x19E942+2)

    
    mem.set(esi+2, struct.pack("<H", di))
    mem.set(esi+6, struct.pack("<H", dx))
    mem.set(esi+0xA, struct.pack("<H", cx))
    mem.set(esi+0xC, struct.pack("<H", 0))
    mem.set(esi+0xE, struct.pack("<H", 3))
    mem.set(esi+0x10, struct.pack("<H", ax))

    if dx < 4:
        return #stub
    if dx > 6:
        return #stub

    ecx = 0x10
    ecx -= edx
    edx = 0xFFFF

    assert(ecx == 0xA)

    edx = edx >> (ecx & 0xFF)

    mem.set(esi + 0x08, edx & 0xFFFF)

    if (edi & 0xFFFF) > 1:
        return

    if (edi & 0xFFFF) == 0:
        edi = 0x19F802

        #defaults
        mem.set(0x41D740, b'\x03\x02\x03\x03\x04\x04\x04\x05\x05\x05\x05\x06\x06\x06\x07\x07')

        def _0x407F30(n, src, dest):
            n = n >> 2

            while True:
                ebx = mem.get(src, nbytes = 4)
                mem.set(dest, ebx)
                src += 4
                dest += 4
                if dest > (src + (4*n)):
                    break
                
            
    
        _0x407F30(0x10, 0x41D740, 0x19F802)
    

def callback1():
    pass

def cb2_read_chunk(src, size, into):
    return read_bytes_into(into, size, 1, mapfilepointers)

def read_bytes_into(into, n, nbytes, src):
    _v = src.read(n*nbytes)
##    if len(_v) == 0:
##        _v = b'\x00' #see 0x004025BB
    mem.set(into, _v)

    return len(_v)
    
def read_bytes(stack):
    into = stack.pop()
    n = stack.pop()
    nbytes = stack.pop()
    mapfilepointers = stack.pop()

    _v = mapfilepointers.read(n*nbytes)
##    if len(_v) == 0:
##        _v = b'\x00' #see 0x004025BB
    mem.set(into, _v)
    
    stack.append(0x1000)
    stack.append(n)
    stack.append(nbytes)
    stack.append(0)

    return len(_v)
    

if __name__ == "__main__":
    print("Starting")
    _simulated_events.append(Event(Event.DROP, path = "resources/MxM_unseen_1.map"))
    event_loop()
    print("Quitting")

