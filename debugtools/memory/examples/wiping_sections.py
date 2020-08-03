from debugtools.memory.common.access import AccessContext
from debugtools.memory.common import memory_find, memory_findall

process = AccessContext()

process.write_section("section1001", 0, b'\x00' * 160800)