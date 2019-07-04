

import struct


class Memory(object):

    def __init__(self, endianness = "<", strict = False):
        self.endianness = endianness
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
                result += struct.pack("B", self.memory[k])
                
        return result

    def set(self, key, value):
        f = "B"
        if type(value).__name__ == "int":
            f = self.endianness + "I"
            value = struct.pack(f, value)

        if type(value).__name__ != "bytes":
            raise Exception("value is not of type bytes")
        
        for i in range(len(value)):
            self.memory[key + i] = value[i]


