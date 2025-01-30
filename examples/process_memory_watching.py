

from sourcehold.debugtools.memory.access import AccessContext, convert_address_list_to_memory_sections
from sourcehold.debugtools.memory.common.watching import SectionsWatcher

process = AccessContext(process_name="Stronghold Crusader.exe")
memory_sections = convert_address_list_to_memory_sections(process.address_list)

ignore_list = ['1015', '1007', '1008', '1034', '1105', '1045', '1016']

relevant_memory_sections = [section for section in memory_sections if section.name not in ignore_list]

watcher = SectionsWatcher(process=process, memory_sections=relevant_memory_sections, interval=0.1)

change = next(watcher.watch_next_change(update_baseline=True, lazy=False))

sections_involved = set(el[0].name for el in change)