import sys


class Array(object):

    def __init__(self, array, offset=0):
        self._array = array
        self._offset = offset

    def offset(self):
        return self._offset

    # return *array
    @property
    def value(self):
        return self._array[self._offset]

    # *array = 0
    @value.setter
    def value(self, value):
        try:
            iterator = iter(value)
        except TypeError:
            self._array[self._offset] = value
        else:
            i = 0
            for v in value:
                self._array[self._offset + i] = v
                i += 1

    # array = array + b
    def __add__(self, other):
        return Array(self._array, self._offset + other)

    def __sub__(self, other):
        return Array(self._array, self._offset - other)

    # array[0]
    def __getitem__(self, item):
        if item + self._offset >= len(self._array):
            print("out of range {}".format(item + self._offset), file=sys.stderr)

            return self._array[self._offset + item]
        return self._array[self._offset + item]

    # array[0] = 2
    def __setitem__(self, key, value):
        self._array[self._offset + key] = value

    # for v in array
    def __iter__(self):
        for i in range(self._offset, len(self._array)):
            yield self._array[i]

    def __len__(self):
        return len(self._array)


CMP_BINARY = 0
CMP_ASCII = 1
CMP_NO_ERROR = 0
CMP_INVALID_DICTSIZE = 1
CMP_INVALID_MODE = 2
CMP_BAD_DATA = 3
CMP_ABORT = 4

CMP_IMPLODE_DICT_SIZE1 = 1024
CMP_IMPLODE_DICT_SIZE2 = 1024 * 2
CMP_IMPLODE_DICT_SIZE3 = 1024 * 4

MAX_REP_LENGTH = 0x204
DistBits = [
    0x02, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
]

DistCode = [
    0x03, 0x0D, 0x05, 0x19, 0x09, 0x11, 0x01, 0x3E, 0x1E, 0x2E, 0x0E, 0x36, 0x16, 0x26, 0x06, 0x3A,
    0x1A, 0x2A, 0x0A, 0x32, 0x12, 0x22, 0x42, 0x02, 0x7C, 0x3C, 0x5C, 0x1C, 0x6C, 0x2C, 0x4C, 0x0C,
    0x74, 0x34, 0x54, 0x14, 0x64, 0x24, 0x44, 0x04, 0x78, 0x38, 0x58, 0x18, 0x68, 0x28, 0x48, 0x08,
    0xF0, 0x70, 0xB0, 0x30, 0xD0, 0x50, 0x90, 0x10, 0xE0, 0x60, 0xA0, 0x20, 0xC0, 0x40, 0x80, 0x00
]

ExLenBits = [
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
]

LenBits = [
    0x03, 0x02, 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x07, 0x07
]

LenCode = [
    0x05, 0x03, 0x01, 0x06, 0x0A, 0x02, 0x0C, 0x14, 0x04, 0x18, 0x08, 0x30, 0x10, 0x20, 0x40, 0x00
]

ChBitsAsc = [
    0x0B, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x08, 0x07, 0x0C, 0x0C, 0x07, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0D, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x04, 0x0A, 0x08, 0x0C, 0x0A, 0x0C, 0x0A, 0x08, 0x07, 0x07, 0x08, 0x09, 0x07, 0x06, 0x07, 0x08,
    0x07, 0x06, 0x07, 0x07, 0x07, 0x07, 0x08, 0x07, 0x07, 0x08, 0x08, 0x0C, 0x0B, 0x07, 0x09, 0x0B,
    0x0C, 0x06, 0x07, 0x06, 0x06, 0x05, 0x07, 0x08, 0x08, 0x06, 0x0B, 0x09, 0x06, 0x07, 0x06, 0x06,
    0x07, 0x0B, 0x06, 0x06, 0x06, 0x07, 0x09, 0x08, 0x09, 0x09, 0x0B, 0x08, 0x0B, 0x09, 0x0C, 0x08,
    0x0C, 0x05, 0x06, 0x06, 0x06, 0x05, 0x06, 0x06, 0x06, 0x05, 0x0B, 0x07, 0x05, 0x06, 0x05, 0x05,
    0x06, 0x0A, 0x05, 0x05, 0x05, 0x05, 0x08, 0x07, 0x08, 0x08, 0x0A, 0x0B, 0x0B, 0x0C, 0x0C, 0x0C,
    0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D,
    0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D,
    0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0D, 0x0C, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D,
    0x0D, 0x0D, 0x0C, 0x0C, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D
]

ChCodeAsc = [
    0x0490, 0x0FE0, 0x07E0, 0x0BE0, 0x03E0, 0x0DE0, 0x05E0, 0x09E0,
    0x01E0, 0x00B8, 0x0062, 0x0EE0, 0x06E0, 0x0022, 0x0AE0, 0x02E0,
    0x0CE0, 0x04E0, 0x08E0, 0x00E0, 0x0F60, 0x0760, 0x0B60, 0x0360,
    0x0D60, 0x0560, 0x1240, 0x0960, 0x0160, 0x0E60, 0x0660, 0x0A60,
    0x000F, 0x0250, 0x0038, 0x0260, 0x0050, 0x0C60, 0x0390, 0x00D8,
    0x0042, 0x0002, 0x0058, 0x01B0, 0x007C, 0x0029, 0x003C, 0x0098,
    0x005C, 0x0009, 0x001C, 0x006C, 0x002C, 0x004C, 0x0018, 0x000C,
    0x0074, 0x00E8, 0x0068, 0x0460, 0x0090, 0x0034, 0x00B0, 0x0710,
    0x0860, 0x0031, 0x0054, 0x0011, 0x0021, 0x0017, 0x0014, 0x00A8,
    0x0028, 0x0001, 0x0310, 0x0130, 0x003E, 0x0064, 0x001E, 0x002E,
    0x0024, 0x0510, 0x000E, 0x0036, 0x0016, 0x0044, 0x0030, 0x00C8,
    0x01D0, 0x00D0, 0x0110, 0x0048, 0x0610, 0x0150, 0x0060, 0x0088,
    0x0FA0, 0x0007, 0x0026, 0x0006, 0x003A, 0x001B, 0x001A, 0x002A,
    0x000A, 0x000B, 0x0210, 0x0004, 0x0013, 0x0032, 0x0003, 0x001D,
    0x0012, 0x0190, 0x000D, 0x0015, 0x0005, 0x0019, 0x0008, 0x0078,
    0x00F0, 0x0070, 0x0290, 0x0410, 0x0010, 0x07A0, 0x0BA0, 0x03A0,
    0x0240, 0x1C40, 0x0C40, 0x1440, 0x0440, 0x1840, 0x0840, 0x1040,
    0x0040, 0x1F80, 0x0F80, 0x1780, 0x0780, 0x1B80, 0x0B80, 0x1380,
    0x0380, 0x1D80, 0x0D80, 0x1580, 0x0580, 0x1980, 0x0980, 0x1180,
    0x0180, 0x1E80, 0x0E80, 0x1680, 0x0680, 0x1A80, 0x0A80, 0x1280,
    0x0280, 0x1C80, 0x0C80, 0x1480, 0x0480, 0x1880, 0x0880, 0x1080,
    0x0080, 0x1F00, 0x0F00, 0x1700, 0x0700, 0x1B00, 0x0B00, 0x1300,
    0x0DA0, 0x05A0, 0x09A0, 0x01A0, 0x0EA0, 0x06A0, 0x0AA0, 0x02A0,
    0x0CA0, 0x04A0, 0x08A0, 0x00A0, 0x0F20, 0x0720, 0x0B20, 0x0320,
    0x0D20, 0x0520, 0x0920, 0x0120, 0x0E20, 0x0620, 0x0A20, 0x0220,
    0x0C20, 0x0420, 0x0820, 0x0020, 0x0FC0, 0x07C0, 0x0BC0, 0x03C0,
    0x0DC0, 0x05C0, 0x09C0, 0x01C0, 0x0EC0, 0x06C0, 0x0AC0, 0x02C0,
    0x0CC0, 0x04C0, 0x08C0, 0x00C0, 0x0F40, 0x0740, 0x0B40, 0x0340,
    0x0300, 0x0D40, 0x1D00, 0x0D00, 0x1500, 0x0540, 0x0500, 0x1900,
    0x0900, 0x0940, 0x1100, 0x0100, 0x1E00, 0x0E00, 0x0140, 0x1600,
    0x0600, 0x1A00, 0x0E40, 0x0640, 0x0A40, 0x0A00, 0x1200, 0x0200,
    0x1C00, 0x0C00, 0x1400, 0x0400, 0x1800, 0x0800, 0x1000, 0x0000
]


def BYTE_PAIR_HASH(buffer: Array):
    return ((buffer[0] * 4) + (buffer[1] * 5))


class TCmpStruct(object):

    def __init__(self):
        self.distance = 0
        self.out_bytes = 0
        self.out_bits = 0
        self.dsize_bits = 0
        self.dsize_mask = 0
        self.ctype = 0
        self.dsize_bytes = 0
        self.dist_bits = Array([0] * 0x40)
        self.dist_codes = Array([0] * 0x40)
        self.nChBits = Array([0] * 0x306)
        self.nChCodes = Array([0] * 0x306)
        self.offs09AE = 0
        self.param = None
        self.read_buf = None
        self.write_buf = None
        self.offs09BC = Array([0] * 0x204)
        self.offs0DC4 = 0
        self.phash_to_index = Array([0] * 0x900)
        self.phash_to_index_end = 0
        self.out_buff = Array([0] * 0x802)
        self.work_buff = Array([0] * 0x2204)
        self.phash_offs = Array([0] * 0x2204)


def SortBuffer(pWork: TCmpStruct, buffer_begin: Array, buffer_end: Array):
    phash_to_index = 0  # short
    buffer_ptr = 0  # unsigned char *
    total_sum = 0
    byte_pair_hash = 0
    byte_pair_offs = 0

    for i in range(len(pWork.phash_to_index)):
        pWork.phash_to_index[i] = 0

    for i in range(buffer_end.offset() - buffer_begin.offset()):
        pWork.phash_to_index[BYTE_PAIR_HASH((buffer_begin[i], buffer_begin[i + 1]))] += 1

    for i in range(len(pWork.phash_to_index)):
        total_sum += pWork.phash_to_index[i]
        pWork.phash_to_index[i] = total_sum

    for i in range(buffer_end.offset() - buffer_begin.offset() - 1, -1, -1):
        byte_pair_hash = BYTE_PAIR_HASH(buffer_begin + i)
        byte_pair_offs = i  # - pWork.work_buff #i relative to start of work_buff
        pWork.phash_to_index[byte_pair_hash] -= 1
        pWork.phash_offs[pWork.phash_to_index[byte_pair_hash]] = byte_pair_offs


def FlushBuf(pWork: TCmpStruct):
    size = 0x800
    pWork.write_buf(pWork.out_buff, size, pWork.param)

    save_ch1 = pWork.out_buff[0x800]
    save_ch2 = pWork.out_buff[pWork.out_bytes]
    pWork.out_bytes -= 0x800

    for i in range(0, len(pWork.out_buff)):
        pWork.out_buff[i] = 0

    if pWork.out_bytes != 0:
        pWork.out_buff[0] = save_ch1
    if pWork.out_bits != 0:
        pWork.out_buff[pWork.out_bytes] = save_ch2


def OutputBits(pWork: TCmpStruct, nbits, bit_buff):
    if nbits > 8:
        OutputBits(pWork, 8, bit_buff)
        bit_buff >>= 8
        nbits -= 8

    out_bits = pWork.out_bits
    pWork.out_buff[pWork.out_bytes] |= bit_buff << out_bits
    pWork.out_bits += nbits

    if pWork.out_bits > 8:
        pWork.out_bytes += 1
        bit_buff >>= (8 - out_bits)

        pWork.out_buff[pWork.out_bytes] = bit_buff
        pWork.out_bits &= 7

    else:
        pWork.out_bits &= 7
        if pWork.out_bits == 0:
            pWork.out_bytes += 1

    if pWork.out_bytes >= 0x800:
        FlushBuf(pWork)


def FindRep(pWork: TCmpStruct, input_data: Array):
    rep_length = 1

    phash_to_index = pWork.phash_to_index + BYTE_PAIR_HASH(input_data)
    min_phash_offs = ((input_data.offset() - pWork.work_buff.offset()) - pWork.dsize_bytes + 1)
    phash_offs_index = phash_to_index[0]

    phash_offs = pWork.phash_offs + phash_offs_index
    if phash_offs.value < min_phash_offs:
        while phash_offs.value < min_phash_offs:
            phash_offs_index += 1
            phash_offs += 1
        phash_to_index.value = phash_offs_index

    phash_offs = pWork.phash_offs + phash_offs_index
    prev_repetition = pWork.work_buff + phash_offs[0]
    repetition_limit = input_data - 1

    if prev_repetition.offset() >= repetition_limit.offset():
        return 0

    input_data_ptr = input_data
    while True:
        if input_data_ptr.value == prev_repetition.value and input_data_ptr[rep_length - 1] == prev_repetition[
            rep_length - 1]:
            prev_repetition += 1
            input_data_ptr += 1
            equal_byte_count = 2

            while equal_byte_count < MAX_REP_LENGTH:
                prev_repetition += 1
                input_data_ptr += 1

                if prev_repetition.value != input_data_ptr.value:
                    break

                equal_byte_count += 1

            input_data_ptr = input_data
            if equal_byte_count >= rep_length:
                pWork.distance = (input_data - prev_repetition.offset() + equal_byte_count - 1)

                rep_length = equal_byte_count
                if rep_length > 10:
                    break

        phash_offs_index += 1
        phash_offs += 1
        prev_repetition = pWork.work_buff + phash_offs.offset()  # [0]

        if prev_repetition.offset() >= repetition_limit.offset():
            return rep_length if (rep_length >= 2) else 0

    if equal_byte_count == MAX_REP_LENGTH:
        pWork.distance -= 1
        return equal_byte_count

    phash_offs = pWork.phash_offs + phash_offs_index
    if pWork.work_buff + phash_offs[1] >= repetition_limit:
        return rep_length

    pWork.offs09BC[0] = 0xFFFF
    pWork.offs09BC[1] = 0x0000
    di_val = 0

    for offs_in_rep in range(1, rep_length):
        if input_data[offs_in_rep] != input_data[di_val]:
            di_val = pWork.offs09BC[di_val]
            if di_val != 0xFFFF:
                continue

        offs_in_rep += 1
        di_val += 1
        pWork.offs09BC[offs_in_rep] = di_val

    prev_repetition = pWork.work_buff + phash_offs[0]
    prev_rep_end = prev_repetition + rep_length
    rep_length2 = rep_length

    while True:
        rep_length2 = pWork.offs09BC[rep_length2]
        if rep_length2 == 0xFFFF:
            rep_length2 = 0

        phash_offs = pWork.phash_offs + phash_offs_index

        while True:
            phash_offs += 1
            phash_offs_index += 1
            prev_repetition = pWork.work_buff + phash_offs.value
            if prev_repetition >= repetition_limit:
                return rep_length

            if prev_repetition + rep_length2 < prev_rep_end:
                continue
            else:
                break

        pre_last_byte = input_data[rep_length - 2]
        if pre_last_byte == prev_repetition[rep_length2 - 2]:
            if prev_repetition + rep_length2 != prev_rep_end:
                prev_rep_end = prev_repetition
                rep_length2 = 0
        else:
            phash_offs = pWork.phash_offs + phash_offs_index
            while True:
                phash_offs += 1
                phash_offs_index += 1
                prev_repetition = pWork.work_buff + phash_offs.value
                if prev_repetition >= repetition_limit:
                    return rep_length

                if prev_repetition[rep_length - 2] != pre_last_byte or prev_repetition[0] != input_data[0]:
                    continue
                else:
                    break

            prev_rep_end = prev_repetition + 2
            rep_length2 = 2

        while prev_rep_end.value == input_data[rep_length2]:
            rep_length2 += 1
            if rep_length2 >= 0x204:
                break
            prev_rep_end += 1

        if rep_length2 >= rep_length:
            pWork.distance = input_data - prev_repetition - 1
            rep_length = rep_length2
            if rep_length == 0x204:
                return rep_length

            while offs_in_rep < rep_length2:
                if input_data[offs_in_rep] != input_data[di_val]:
                    di_val = pWork.offs09BC[di_val]
                    if di_val != 0xFFFF:
                        continue
                offs_in_rep += 1
                di_val += 1
                pWork.offs09BC[offs_in_rep] = di_val


def WriteCmpData(pWork: TCmpStruct):
    input_data = pWork.work_buff + pWork.dsize_bytes + 0x204
    input_data_ended = 0
    save_distance = 0
    phase = 0

    pWork.out_buff[0] = pWork.ctype
    pWork.out_buff[1] = pWork.dsize_bits
    pWork.out_bytes = 2

    for i in range(2, len(pWork.out_buff) - 2):
        pWork.out_buff[i] = 0
    pWork.out_bits = 0

    while input_data_ended == 0:
        bytes_to_load = 0x1000
        total_loaded = 0
        bytes_loaded = 0

        while bytes_to_load != 0:
            bytes_loaded = pWork.read_buf(pWork.work_buff + pWork.dsize_bytes + 0x204 + total_loaded, bytes_to_load,
                                          pWork.param)

            if bytes_loaded == 0:
                if total_loaded == 0 and phase == 0:
                    raise Exception("Exit")
                input_data_ended = 1
                break

            else:
                bytes_to_load -= bytes_loaded
                total_loaded += bytes_loaded

        input_data_end = pWork.work_buff + pWork.dsize_bytes + total_loaded
        if input_data_ended:
            input_data_end += 0x204

        if phase == 0:
            SortBuffer(pWork, input_data, input_data_end + 1)
            phase += 1
            if pWork.dsize_bytes != 0x1000:
                phase += 1
        elif phase == 1:
            SortBuffer(pWork, input_data - pWork.dsize_bytes + 0x204, input_data_end + 1)
            phase += 1
        else:
            SortBuffer(pWork, input_data - pWork.dsize_bytes, input_data_end + 1)

        while input_data.offset() < input_data_end.offset():
            rep_length = FindRep(pWork, input_data)
            while rep_length != 0:
                if rep_length == 2 and pWork.distance.value >= 0x100:
                    break

                if input_data_ended and input_data + rep_length > input_data_end:
                    rep_length = input_data_end - input_data
                    if rep_length < 2:
                        break

                    if rep_length == 2 and pWork.distance >= 0x100:
                        break

                    # raise Exception("__FlushRepetition")
                    OutputBits(pWork, pWork.nChBits[rep_length + 0xFE], pWork.nChCodes[rep_length + 0xFE])
                    if rep_length == 2:
                        OutputBits(pWork, pWork.dist_bits[pWork.distance >> 2],
                                   pWork.dist_codes[pWork.distance >> 2])
                        OutputBits(pWork, 2, pWork.distance & 3)
                    else:
                        OutputBits(pWork, pWork.dist_bits[pWork.distance >> pWork.dsize_bits],
                                   pWork.dist_codes[pWork.distance >> pWork.dsize_bits])
                        OutputBits(pWork, pWork.dsize_bits, pWork.dsize_mask & pWork.distance)

                    input_data += rep_length

                    if input_data_ended == 0:
                        input_data -= 0x1000
                        for i in range(pWork.dsize_bytes + 0x204):
                            pWork.work_buff[i] = (pWork.work_buff + 0x1000)[i]

                    OutputBits(pWork, pWork.nChBits[0x305], pWork.nChCodes[0x305])
                    if pWork.out_bits != 0:
                        pWork.out_bytes += 1
                    pWork.write_buf(pWork.out_buff, pWork.out_bytes, pWork.param)

                    return

                if rep_length >= 8 or input_data.offset() + 1 >= input_data_end.offset():
                    # raise Exception("__FlushRepetition")
                    OutputBits(pWork, pWork.nChBits[rep_length + 0xFE], pWork.nChCodes[rep_length + 0xFE])
                    if rep_length == 2:
                        OutputBits(pWork, pWork.dist_bits[pWork.distance >> 2],
                                   pWork.dist_codes[pWork.distance >> 2])
                        OutputBits(pWork, 2, pWork.distance & 3)
                    else:
                        OutputBits(pWork, pWork.dist_bits[pWork.distance >> pWork.dsize_bits],
                                   pWork.dist_codes[pWork.distance >> pWork.dsize_bits])
                        OutputBits(pWork, pWork.dsize_bits, pWork.dsize_mask & pWork.distance)

                    input_data += rep_length

                    if input_data_ended == 0:
                        input_data -= 0x1000
                        for i in range(pWork.dsize_bytes + 0x204):
                            pWork.work_buff[i] = (pWork.work_buff + 0x1000)[i]

                    OutputBits(pWork, pWork.nChBits[0x305], pWork.nChCodes[0x305])
                    if pWork.out_bits != 0:
                        pWork.out_bytes += 1
                    pWork.write_buf(pWork.out_buff, pWork.out_bytes, pWork.param)

                    return

                save_rep_length = rep_length
                save_distance = pWork.distance
                rep_length = FindRep(pWork, input_data + 1)

                if rep_length > save_rep_length:
                    if rep_length > save_rep_length + 1 or save_distance > 0x80:
                        OutputBits(pWork, pWork.nChBits[input_data.value], pWork.nChCodes[input_data.value])
                        input_data += 1
                        continue

                rep_length = save_rep_length
                pWork.distance = save_distance

                # def __FlushRepetition():
                OutputBits(pWork, pWork.nChBits[rep_length + 0xFE], pWork.nChCodes[rep_length + 0xFE])
                if rep_length == 2:
                    OutputBits(pWork, pWork.dist_bits[pWork.distance >> 2],
                               pWork.dist_codes[pWork.distance >> 2])
                    OutputBits(pWork, 2, pWork.distance & 3)
                else:
                    OutputBits(pWork, pWork.dist_bits[pWork.distance >> pWork.dsize_bits],
                               pWork.dist_codes[pWork.distance >> pWork.dsize_bits])
                    OutputBits(pWork, pWork.dsize_bits, pWork.dsize_mask & pWork.distance)

                input_data += rep_length
                # raise Exception("402252")
                if input_data_ended == 0:
                    input_data -= 0x1000
                    for i in range(pWork.dsize_bytes + 0x204):
                        pWork.work_buff[i] = (pWork.work_buff + 0x1000)[i]

                OutputBits(pWork, pWork.nChBits[0x305], pWork.nChCodes[0x305])
                if pWork.out_bits != 0:
                    pWork.out_bytes += 1
                pWork.write_buf(pWork.out_buff, pWork.out_bytes, pWork.param)

                return

            OutputBits(pWork, pWork.nChBits[input_data.value], pWork.nChCodes[input_data.value])
            input_data += 1

        # def _00402252():
        if input_data_ended == 0:
            input_data -= 0x1000
            for i in range(pWork.dsize_bytes + 0x204):
                pWork.work_buff[i] = (pWork.work_buff + 0x1000)[i]

    # def __Exit():
    OutputBits(pWork, pWork.nChBits[0x305], pWork.nChCodes[0x305])
    if pWork.out_bits != 0:
        pWork.out_bytes += 1
    pWork.write_buf(pWork.out_buff, pWork.out_bytes, pWork.param)

    return


def implode(read_buf, write_buf, pWork: TCmpStruct, param, type, dsize):
    pWork.read_buf = read_buf
    pWork.write_buf = write_buf
    pWork.dsize_bytes = dsize
    pWork.ctype = type
    pWork.param = param
    pWork.dsize_bits = 4
    pWork.dsize_mask = 0x0F

    if dsize == 0x1000:
        pWork.dsize_bits += 1
        pWork.dsize_mask |= 0x20
    elif dsize == 0x800:
        pWork.dsize_bits += 1
        pWork.dsize_mask |= 0x10
    elif dsize == 0x400:
        pass
    else:
        return CMP_INVALID_DICTSIZE

    if type == CMP_BINARY:
        nChCode = 0
        for nCount in range(0, 0x100):
            pWork.nChBits[nCount] = 9
            pWork.nChCodes[nCount] = nChCode
            nChCode = (nChCode & 0x0000FFFF) + 2

    elif type == CMP_ASCII:
        for nCount in range(0, 0x100):
            pWork.nChBits[nCount] = (ChBitsAsc[nCount] + 1)
            pWork.nChCodes[nCount] = (ChCodeAsc[nCount] * 2)

    else:
        return CMP_INVALID_MODE

    for i in range(0, 0x10):
        if 1 << ExLenBits[i] != 0:
            for nCount2 in range(0, 1 << ExLenBits[i]):
                pWork.nChBits[nCount] = ExLenBits[i] + LenBits[i] + 1
                pWork.nChCodes[nCount] = (nCount2 << (LenBits[i] + 1)) | ((LenCode[i] & 0xFFFF00FF) * 2) | 1
                nCount += 1

    for i in range(len(DistCode)):
        pWork.dist_codes[i] = DistCode[i]

    for i in range(len(DistBits)):
        pWork.dist_bits[i] = DistBits[i]

    WriteCmpData(pWork)

    return CMP_NO_ERROR


import io, struct

if __name__ == "__main__":
    data = open("resources/MxM_unseen_1.preview", 'rb').read()

    dbuf = io.BytesIO(data)

    obuf = io.BytesIO()


    def r(buf: Array, size: int, param):
        d = dbuf.read(size)
        if len(d) < size:
            raise Exception("data underflow")

        for i in range(len(d)):
            buf[i] = d[i]

        # buf._offset += len(d)

        return len(d)


    def w(buf: Array, size: int, param):
        for i in range(size):
            obuf.write(struct.pack("B", buf[i]))

        # buf._offset += size


    p = TCmpStruct()

    implode(r, w, p, None, CMP_BINARY, CMP_IMPLODE_DICT_SIZE3)
