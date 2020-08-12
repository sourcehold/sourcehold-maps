
import time


class Watcher(object):

    def __init__(self, process, addr, byte_length, interval=1):
        self.process = process
        self.addr = addr
        self.byte_length = byte_length
        self.interval = interval

    def _read(self):
        self._data = self.process.read_bytes(self.addr, self.byte_length)
        return self._data

    def watch_once(self):
        data = self._read()
        while True:
            time.sleep(self.interval)

            data2 = self._read()

            if data == data2:
                data = data2
                continue

            for i in range(len(data)):
                if data[i] == data2[i]:
                    continue

                print(f"value at {i} changed from {data[i]} into {data2[i]}. binary form: {bin(data[i])[2:]} {bin(data2[i])[2:]}")

            break

    def watch_iterator(self):
        data = self._read()
        while True:
            time.sleep(self.interval)

            data2 = self._read()

            if data == data2:
                data = data2
                continue

            changes = {i: (data[i], data2[i]) for i in range(len(data)) if data[i] != data2[i]}

            yield changes





class SectionsWatcher(object):

    def __init__(self, process, memory_sections, interval=1):
        self.memory_sections = memory_sections
        self.process = process
        self.interval = interval
        self.snapshot = None

    def _compare_section(self, section, snapshot1, snapshot2):
        data1 = snapshot1[section.address:section.address+section.size]
        data2 = snapshot2[section.address:section.address+section.size]

        if data1 == data2:
            return

        for i in range(len(data1)):
            if data1[i] != data2[i]:
                yield i, data1[i], data2[i]

    def _compare_sections(self, sections, snapshot1, snapshot2):
        for section in sections:
            data1 = snapshot1[section.address:section.address + section.size]
            data2 = snapshot2[section.address:section.address + section.size]

            if data1 == data2:
                continue

            for i in range(len(data1)):
                if data1[i] != data2[i]:
                    yield section, i, data1[i], data2[i]

    def _compare_sections_lazy(self, sections, snapshot1, snapshot2):
        for section in sections:
            data1 = snapshot1[section.address:section.address + section.size]
            data2 = snapshot2[section.address:section.address + section.size]

            if data1 != data2:
                yield section

    def watch_next_change(self, update_baseline=False, interval=None, lazy=False):
        interval = interval if interval is not None else self.interval
        baseline = self.process.read_all_memory()
        while True:
            print(f"going to sleep for {interval} seconds..")
            time.sleep(interval)
            comparison = self.process.read_all_memory()
            if baseline != comparison:
                print(f"starting comparison of memory snapshots")
                if lazy:
                    differences = list(self._compare_sections_lazy(self.memory_sections, baseline, comparison))
                else:
                    differences = list(self._compare_sections(self.memory_sections, baseline, comparison))
                print(f"finished comparing")

                if len(differences) > 0:
                    yield differences

            if update_baseline:
                baseline = comparison



