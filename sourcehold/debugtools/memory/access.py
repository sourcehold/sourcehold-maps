try:
    import pymem
except ValueError:
    import sys
    print("memory debugging is only supported on windows currently", file=sys.stderr)

import pathlib
import xml.etree.ElementTree as ET

from sourcehold.debugtools.memory.common import section_lengths


def read_all_mem(p):
    return p.read_bytes(p.process_base.lpBaseOfDll, 34148352)


def load_cheat_table(path):
    return ET.parse(str(path))

from sourcehold.debugtools.memory.common import MemorySection
from sourcehold.debugtools.memory.common import section_lengths
import struct


def read_address_list_village(process):
    addr = 0x004709b8
    end = 0x00470a98
    size = 4+4+4+2+2
    data = process.read_bytes(addr, end-addr)
    for i in range(0, end-addr, size):
        sub = data[i:i+size]
        m = MemorySection(name=str(struct.unpack("<H", sub[14:16])[0]),
                          size=struct.unpack("<I", sub[8:12])[0],
                          address=struct.unpack("<I", sub[:4])[0])
        yield m

def read_address_list_shce(process):
    addr = 0x00b92be8
    end = 0x00b93398
    size = 4+4+4+2+2
    data = process.read_bytes(addr, end-addr)
    for i in range(0, end-addr, size):
        sub = data[i:i+size]
        m = MemorySection(name=str(struct.unpack("<H", sub[14:16])[0]),
                          size=struct.unpack("<I", sub[8:12])[0],
                          address=struct.unpack("<I", sub[:4])[0])
        yield m


def read_address_list_shc(process):
    addr = 0x00b92a58
    end = 0x00b93208
    size = 4+4+4+2+2
    data = process.read_bytes(addr, end-addr)
    for i in range(0, end-addr, size):
        sub = data[i:i+size]
        m = MemorySection(name=str(struct.unpack("<H", sub[14:16])[0]),
                          size=struct.unpack("<I", sub[8:12])[0],
                          address=struct.unpack("<I", sub[:4])[0])
        yield m


def read_address_list_sh(process):
    addr = 0x0081e518
    end = 0x0081eb48
    size = 4+4+4+2+2
    data = process.read_bytes(addr, end-addr)
    for i in range(0, end-addr, size):
        sub = data[i:i+size]
        m = MemorySection(name=str(struct.unpack("<H", sub[14:16])[0]),
                          size=struct.unpack("<I", sub[8:12])[0],
                          address=struct.unpack("<I", sub[:4])[0])
        yield m


def convert_address_list_to_memory_sections(address_list):
    return [MemorySection(key, addr, section_lengths[key]) for key, addr in address_list.items() if len(key) == 4 and key.isnumeric()]

import sys
import os


class AccessContext(object):

    def __init__(self, process_name):
        #self.cheat_table = cheat_table

        error = None
        try:
            #sys.stdout = open(os.devnull, "w")
            #sys.stderr = open(os.devnull, "w")
            self.process = pymem.Pymem(process_name)
            self.base = self.process.process_base.lpBaseOfDll
        except Exception as te:
            error = te
        finally:
            #sys.stdout.close()
            #sys.stderr.close()
            #sys.stdout = sys.__stdout__
            #sys.stderr = sys.__stderr__
            if isinstance(error, pymem.exception.ProcessNotFound): # type: ignore
                print("Process is not running")
                exit(1)
            if error is not None:
                raise error

        #self.address_list = load_address_list_from_cheat_table(self.cheat_table, offset=self.base)

        self.memory_cache = None
        self.memory_sections = None

    def read_all_memory(self):
        self.memory_cache = None

        return read_all_mem(self.process)

    def read_section(self, section, offset=0):

        if section not in self.memory_sections:
            raise Exception(f"Don't know how to read section: {section}. Available sections: {self.memory_sections.keys()}")

        return self.read_bytes(self.memory_sections[section].address + offset, self.memory_sections[section].size - offset)

    def write_section(self, section, data, offset=0, recycle=False):
        if section not in self.memory_sections:
            raise Exception(f"Don't know how to write to section: {section}")

        if recycle:
            while len(data) < self.memory_sections[section].size:
                data += data
            data = data[:self.memory_sections[section].size]

        if type(data) == bytearray:
            data = bytes(data)

        return self.write_bytes(self.memory_sections[section].address + offset, data)

    def read_bytes(self, addr, size):
        return pymem.memory.read_bytes(self.process.process_handle, addr, size)

    def write_bytes(self, addr, data):
        return pymem.memory.write_bytes(self.process.process_handle, addr, data, len(data))


class SH(AccessContext):

    def __init__(self):
        super().__init__(process_name="Stronghold")
        self.memory_sections = {m.name: m for m in read_address_list_sh(self.process)}


class SHC(AccessContext):
    futureMapOrientation = 0x01fe7aa8
    currentMapOrientation = 0x01fe7aa4

    def __init__(self):
        super().__init__(process_name="Stronghold Crusader")
        self.memory_sections = {m.name: m for m in read_address_list_shc(self.process)}

    def force_redraw(self):
        self.write_bytes(self.futureMapOrientation, self.read_bytes(self.currentMapOrientation, 1))


class SHCE(AccessContext):

    def __init__(self):
        super().__init__(process_name="Stronghold_Crusader_Extreme")
        self.memory_sections = {m.name: m for m in read_address_list_shce(self.process)}


class Village(AccessContext):
    
    def __init__(self):
        super().__init__(process_name="village")
        self.memory_sections = {m.name: m for m in read_address_list_village(self.process)}

    def show(self, section):
        import numpy
        import struct
        from matplotlib import pyplot

        select_all = numpy.ones((100, 100), dtype='bool')

        typ = ""
        data = self.read_section(section)
        if len(data) == 100 * 100:
            matrix = numpy.zeros((100, 100), dtype='uint8')
            typ = "B"
        elif len(data) == 100 * 100 * 2:
            matrix = numpy.zeros((100, 100), dtype='uint16')
            typ = "H"
        elif len(data) == 100 * 100 * 4:
            matrix = numpy.zeros((100, 100), dtype='uint32')
            typ = "I"
        else:
            raise Exception("cannot show")
        matrix[select_all] = struct.unpack(f"<{100*100}{typ}", data)

        pyplot.imshow(matrix)
        pyplot.show()
        