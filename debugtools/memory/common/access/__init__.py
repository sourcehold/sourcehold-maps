import pymem, pathlib
import xml.etree.ElementTree as ET


from debugtools.memory.common import section_lengths


def read_all_mem(p):
    return p.read_bytes(p.process_base.lpBaseOfDll, 34148352)


def load_cheat_table(path=(pathlib.Path() / "cheatengine" / "shc_data.CT")):
    return ET.parse(str(path))


def load_address_list_from_cheat_table(path=(pathlib.Path() / "cheatengine" / "shc_data.CT"), offset=0):
    #data = path.read_bytes()

    address_list = {}

    root = ET.parse(str(path))

    imported = [entry for entry in root.findall(".//CheatEntry") if "imported" in entry.find(".//Description").text][0]

    entries = imported.findall(".//CheatEntry")
    for entry in entries:
        description = entry.find('./Description').text.replace('"', '')
        address = entry.find('./Address').text

        if not description[:4].isalnum():
            continue

        if "Stronghold Crusader.exe" in address:
            addr = address.split('"Stronghold Crusader.exe"+')[1]
            address = int(addr, 16) + offset

        address_list[description.replace('"', "")] = address

    return address_list


class AccessContext(object):

    def __init__(self, cheat_table=(pathlib.Path() / "cheatengine" / "shc_data.CT"), process_name="Stronghold Crusader"):
        self.cheat_table = cheat_table
        self.process = pymem.Pymem(process_name)
        self.base = self.process.process_base.lpBaseOfDll
        self.address_list = load_address_list_from_cheat_table(self.cheat_table, offset=self.base)
        self.memory_cache = None

    def read_all_memory(self):
        self.memory_cache = None

        return read_all_mem(self.process)

    def read_section(self, section, size=None):
        if size is None:
            if section in section_lengths:
                size = section_lengths[section]
            else:
                raise Exception(f"Don't know how many bytes to read for section: {section}")

        if section not in self.address_list:
            raise Exception(f"Don't know where to start reading for section: {section}")

        return self.read_bytes(self.address_list[section], size)

    def write_section(self, section, offset, data):
        if section not in self.address_list:
            raise Exception(f"Don't know where to start writing for section: {section}")

        return self.write_bytes(self.address_list[section] + offset, data)

    def read_bytes(self, addr, size):
        return pymem.memory.read_bytes(self.process.process_handle, addr, size)

    def write_bytes(self, addr, data):
        return pymem.memory.write_bytes(self.process.process_handle, addr, data, len(data))