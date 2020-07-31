
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