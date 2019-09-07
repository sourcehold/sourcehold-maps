import os

import unpacker


def run(folder):
    files = os.listdir(folder)
    for file in files:
        print("reading file: {}".format(file))
        with open(folder + "/" + file, 'rb') as f:
            data = f.read()

        print("parsing file")
        m = unpacker.MapStructure(0, data)

        print("verifying file")
        verifications = m.verify()
        for i in range(len(verifications)):
            if not verifications[i]:
                raise Exception("section number {} has an invalid crc32".format(i))

        print("checking no data is left")
        assert m.buf.remaining() == 0


if __name__ == "__main__":
    import sys

    unpacker.BLAST_PATH = "../../" + unpacker.BLAST_PATH

    if len(sys.argv) < 2:
        raise Exception("no folder specified")

    run(sys.argv[1])
