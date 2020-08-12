

from debugtools.memory.common.access import AccessContext, load_address_list_from_cheat_table, convert_address_list_to_memory_sections
from debugtools.memory.common.watching import SectionsWatcher

process = AccessContext()
memory_sections = convert_address_list_to_memory_sections(process.address_list)

ignore_list = ['1015', '1007', '1008', '1034', '1105', '1045', '1016']

relevant_memory_sections = [section for section in memory_sections if section.name not in ignore_list]

watcher = SectionsWatcher(process=process, memory_sections=relevant_memory_sections, interval=0.1)

change = next(watcher.watch_next_change(update_baseline=True, lazy=False))

sections_involved = set(el[0].name for el in change)