class BreakFunctions(object):

    @staticmethod
    def break_at_eof(buf):
        data = buf.read(1)
        buf.seek(buf.tell() - 1)
        if data == b'':
            return True
        return False