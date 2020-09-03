from sourcehold.debugtools.memory.common.access import AccessContext
from sourcehold.debugtools.memory.common import memory_find, memory_findall

process = AccessContext()

process.write_section("section1001", 0, b'\x00' * 160800)