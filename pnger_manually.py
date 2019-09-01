
INIT_BREAKPOINT = ("0x430AF8", "init_debugger")

class Breakpoints(object):
    LANDING_POINT_DRAG_DROP_START = ("0x40136E", "landing_point_drag_drop_start")
    CONVERT_FILE_START = ("0x4026C0", "convert_file_start")
    CONVERT_AND_WRITE_START = ("0x402590", "convert_and_write_start")
    CALL_FILE_PROCESSOR = ("0x402651", "call_file_processor")
    FILE_PROCESSOR_START = ("0x407860", "file_processor_start")
    ARRAY_TRANSLATION_INIT = ("0x4078A1", "array_translation_init")
    ARRAY_TRANSLATION_INIT_END = ("0x4078FB", "array_translation_init_end")

    @staticmethod
    def set(debugger):
        bps = [Breakpoints.__dict__[key] for key in Breakpoints.__dict__ if key.isupper()]
        debugger.set_breakpoints(bps)

def setup_path(path = "C:\\Users\\Frank\\PycharmProjects\\x64dbgpy_networked"):
    import sys
    if not path in sys.path:
        sys.path.insert(1, "C:\\Users\\Frank\\PycharmProjects\\x64dbgpy_networked")

setup_path()
import debugger

debugger = debugger.NetworkedDebugger("C:\\Users\\Frank\\Downloads\\smpnger11\\Stronghold Map PNGer.exe")

from debugger import Testable, Variable, assert_equal

first800 = b'\x00\x06\x00\x00p$\xc6\x99\x18\x05R\xa4\xa9\x81$\x06\xda\xbd\x0c\x00`\xe0\xc8B\xb7\xe9=@\xf0=\xb3\x83 \x7f\xf3\xb2\xfe\x03l\x86\xca\x81\x82?\x00\x04\x00\x02\x10\x8a\x8f\x00,O\x04\xca\x07\xc6U\x06\x00\t\xbe\xb8\xbc\x13\xf7\x82\x05\xbe\x8c\xfe\x80Q~\x90\xbdWB\xe5\x05\xb0{\x19\xc9\x0e\xeb\xc1\xf4o\xdc\rEw\xf3\x91\xdf\xa7\x19\x01\x02\xf6!\xd2\xa4\xb6\xa5_i\x04\x90\xfdG\xc2\xfc\xfb\xa4V\xfb\xb4\xa0\xa37r]s\x80\xe1\xef\xd0\xf1Bt\xb7\x95\xb4~\x9cW\x1c\x7fr\xabf\x85\xcf\xcb\xe4\x03\x9bV\x8c\xee \x03\xa6\x85n^\xf0\xfc\r\xd1\x1f \xfc\x15\xc1\x1f&\r15\xcd\x8f\x1a\xd5\xb0\xfam~\xf3\x1fz\xa3\xe4\x97{\xf9\x14\xf5\x07\xd8\x00\x8c\n Z>p\x08\xd8\x17\xf4\x97\x9c_\xc8\x7f\xa07y\x99t\xfc\x01\xac3#\x04@~\x86L\xf9\xc9\xff\xa2\xd8\x90\x06@\xb4\xe4{\xde\xb1\xfc\x11\x16\x81\xfa=\x07\xf3+\xf9\x0f\xfe\xa9\xd7?A\xa5\xb7\xf9$/\xcc\x12\x80\xe9\tA\xf9\x9f\x0f\xd0\xafq\xeat\xc3\xc7Q\x94\xf8\x06\x0c\x1e\x08\x10@\x80\x80\x01\x03\xdb\xed\xe7\x0b\x04\x08\xeaK=S\xa0`\x8e\xb6\x9e\x8f\xf9\xab\'\xfb\xf3\x97\xef\xea\xedvk\xbf\xf9\xbd\xb9\xdd\x9f\x8f\xb9\x99\xd3y\xc9\xe7s\xb7\xee\xf5\xb4~\xce\xd5\x1c\xcc\xd5|\xd6\xae\xebW\xeea>rW\xd3G\xad&w\xdd\x9a:3y\xb5\x16\x98\'\xb7\x9fv\xa7\xed\xb9\xc8E\xd7\xc6\xe6\xadf7\x1fo\xbe&#\x17<\x1d\xd4\xc6k\x11\xd3E\xee\xaf\xde\xd7\xe3zT\x7f\xe65\'0\x17[3\x9c;\xabU\xd4:\xd2^[\xb5??m\xe4\xf9ZX\x8dy\x8ea\xe2+\xc7.\xc7$\xb7[K\xab\xdf\x13\xa7\x1c\xc7ZF\x8dK\xede.s\x96j\xd8j\x86s\x995\x96SU\x8dJ"\x1a9\x1b9\x839y5<%\xed\xd5\xa7r\x19\tO\xcc\xa1\xa8>\\[J\xb4U\xcb\xaa\xa1\xa91K4X\xcb\xa9\x7f\xd9\x7f&3\xd5\xc3j\xcck\xb79\x13\xb5\xbfy\xcc\x0eZ\xb3_\xb3Y\xbb\xad~W{\xa8\x9f%<\x89<\xd6\xc6r\xd3\xf9%Q^\xfe\xa9\xe9\x8cI_\xceZ-\xbe\x96\x90\xc3\x98=\xa2~\xd5P\xd5\x0e\xeaK\rw\xb5\xee\x84k\xd7N\xab\xf5&\xccb2\x9a\xe88\xd1s\xe7#aZ1\x05g\xab\xaem\xe4f\x13\x86\x97\xcd\xa6\xa6\xa9\xc6\xb2\xa62;\xce<\xd6\xb8\xd4\x12\xb3\xe7\xe7\x90\xd5\x90\xe4,fGM\xf4^;\x8e\xb1\xd5l\xfb\xf5+?\x94|T\xd3\xad\xae\x90\x9d)\x17^\xd7\xa7\xa8ZX]\xcf>\x9c\xb0\x9a\x84\xd9e\x9d\xaee\xd5BsQ5S\xb5\xbf\x9c\xf0\xea\x125*9\xb6\ti\xce\x95%\xf4\xa0~e\xbf\xab\xcf5\x1fe%\xdb\x7f\xf6\xa4\xc4G\x9e\xce\x92\x963ZOrYY\'\x13i\xcdB;;J\rs\xd5\xcd\x1c\xbelE\xd9\xd5j\x06\x13\x02)\xf7\\\x1d \xa1\t\t!\xdb\xd6\xdc\xf9H\x85_\xf6\xfd:Z=.\xb7\x91\xcb\xcc-\xe6\xf6s1Yp\xd7\x93,\xc4r|\xebQ\xf6\xec\x84_\xd5\xa2\xb3\xfffo\xa8\xae\x1a\xe3\xef\x89\x04\xe6\xac\xc4\x1aGQ\xde\x1c\xc0\xec\x03\xd9\x93\xb3(f\xebN8y\xc2\xe3c4-\x17\x9c[\x8f\xf1\x88,\xe4\x12\x0e\x9f\x8bHHC\xcex\xa2\xe3,\xd5\xd58\x12I\x8f\xb5\x89*\xde\x02\x12N\x9a\x88yB\xed\x13J\x968\x8aq\xd5\xac\x0c\x99\x8b%B\x96\xb0\xc3\xacqY\x15j\x8f9\x03\xb1v\x9cP\xfa\x1c\xf3\xec\x87\xd9\xf8\xb2F\xe6$\x1b0\x90\xf2\xffDlc$ !\xbb\xf9(\xa7?a\xe0\x89\xf8%\x18o\xe6\xf89[\xb9\xe8\x98\xb8\xd7d\'\xa8n\xe6&\xd9<\x12\xf4+V\xa8\xd4\x04\xd6ld\x92! \xf3\xffl\xb0\xd9\x87k~c<2\x86\xf5$4!+K\x82\xd5\'\xd4+\xc1/cR\x9ep\xe9ZRf\x94\x11Hi\xf6\xfb\xdaG\x0c\xe3\xc9\xd6\x9c33=4\xf5\xca>\x90P\xd7\x84\xa9\xd7F\xaa\x95g!\x96}-\x8bF\x0eC\xc2\x9e\xaaF\'\xca\xcf\xe6\x9c8JP\xdc\xacR\t,\x94\x1d-+c&\xcd9z\t,\x9e2\xc2\xca\xffc\xf2\x9e\x90\xec\x9a\xbe\x84 \x88!\x0f\x19;W\x91Hp\xdd\x9a\xb9\x9c\xcd,"\xb9\xbbl\xad\x890\xd4\xe4\xc6\xe0\xd4\x18TR];Fs3\xfa\xcc\xf45\xf7\xd1\xf9H\xe8\x7f\xe5"\xb9\x94\xdaVFk\x89\xb8$\x98G\x16\xdcY\xae\xf2KF0\t\xd2\x92\xcd23\x9e\xecI\t\xf3M\xe0\xe0\xc4_.=\xa1I\xd9\x15s\x1f\x85Xe\xe5\xcde\'`\x93\x84\xc4\xe6\xcc$$<\xa78!\x04\x13\xe8-\xa1n\tC\x8d\x90\x89,\xba1\x988\x97V\xbf\x13\xd6\x97\x80w\x12\xe1I\x10\xd3\xccm;<\xb9\xc0\x1a\x83\x18~\x92`\x8d\tR\x96\x10\xed\xec\xea\t\xc9\xcb-&\xe0\xfel\xbe\xd5\xce\xb2\xb9$\xa8`.(C\x9b5a\x99\x18%\\5+_\r[\x86R\xb2\x97W\xa8CA\x0e^m%\x01\xb7$\x86\x13\xac5\x01\x05&\xfc#\xc79\xa1+\x99j\xc6\xb0\x99\xec\xe0\t\xbbJ\xb8F6\xe4\x84\xd9&\xa4,\x1bg\x8eb\xc2\xc8\x12R\xd0\xe1I\xa0\xb9\\H,M\xcb\x92\x9c@x\t]\xc8\x06\x99 \xbd\x99\x8adL\x97ipV\xb2\xea"\xf5"\xe1\x891\x85\xc70\xd2\x84f&\x08k>\xc9\x1an\xc0@\x12\xeeO\xb0\xda\xec\xb45[\x192\xaf\x1f\xf9)\x87\xbd\xaao\x0c(\x9b\xcb\xaeg1@K\x86m\x12,6\x0b\xe0\x0c[&2\x9da\xe7\x04=\xcd\xbfY`$\xf4 3\x9e\xa4ZgQ\x8c\ttV\xd2\x04D\x96\xad(\x86fgGK\x00}\x89\xbb\x8cs\xb3!\'`\x97\xcc\x8d\xb2\xd9\xc7\xc0\xbd\x99t\xc5\xe0\xd9\x84\x92\xe7\x8c\x16o\xaf\xfc?\xc301\xe0l\x82?$t$\x01\x83\xe64g?IX[\xc2\xb0\x12\xf2\x95\x00\x1frxs\xe62\xd2\xc8X2\xc3T\x99\rfb\x9f \xfd\t\xfa\x91-c\xee\x9a\xf1dr\x95\xa1\xe1\x0c\xd1&\xec3\x17\x94\xe5\'\x86\x06&\x08Z\xbe\xca\x98\xbezRV\xf6,o\xb9\x87\x1a\xb7\x8c\x87c\xfeb\x88g\x0c\xbc\x9b\xa1\xf8\x04\xe3\xcb.\xdd\xec\xa3\xa6\'FD3\xddN\xf0\xb7\x04i\xcev\x99\xe0/\x99\xf4%\x10\\Bs\x13\xbc#;X\x16\x91\x84\xb9\xc6\x90\xb2\x04\xaaJ\x08\xb8\x1c\xf2\x04L\x97Yh\xa2\xeeb}1\x80U\xf6\x80\x18\xfe\x92\x9b\xccD:\x81\xc4c\x98S\x82Y\xd6\xablE1\x04+?\' \xf2\x18\x17\xac\xae\x95\xd0\x98\x84\xc3gG\xcd"\x9e`A]F\xe6\xff\x89\x86\x12\xcc%{V\xe6\'\xb1v\x96=\xb9\xd2\x87\x04\xb4\x93\x80-\xb32V\xbbN(S\xc2\n2\x08^3\x9c0\x9e\x18\x96\x993\x96\x11`\x0c\xe1\xce\x9c\xb6\xe4#\xb7\x1cK*r1\x99\xb1\xc4 \xc9DZ\x12\xe5$\xee\xb3\xe0\xce.\x9a]&F#\xb3+\xe6\x8c\xc6\xc0k\to\xc96\x91\x0b\xcf\xc46\xc1I\xcaw\x02\xee\xcf\xba\x91\x1b\xac\xa5\xd5\x14&\xe0\xa2\x18\xd1\x8c\x05z\x13\x98:F\xb0\xc7\x18lf\xce\t\x04\x98\x93\x9f\x00\x06k\xbf\xd9\x06r\xf71\xd2\x9c\x80w2^\xcf\xe1A\x90\xc0\xae\t\x1f\xcf\xc0I\x02\xb2\xca\x8d&\xb0I"\xcd\x896\x13\x10u,\x08\x94=/3\x92\x18,\x93\xc0\xbc\t\x81\x97qx\x96\xa7,\xc0\x12\x843;j\n\xf7\'\x80\xf7\xcc\xfacD%F\x16cHCL\xf3\t`$\x93\xc7\x04\xa3M\x80h\xd98\xb2\xf5e\x8d\x8e\x01\xbbk_\x19R\x8c\xf5\xc7l\xa61T=\xcbk\x01\xfc\xb2\xb6D\xe0\xd1\t\x04\x92\xed8\xb7\x9bP\xdb\x1c\xfa\xcc&\x13\xa4;!$\xb2`N\xd0\x98X`\xb7\xbaP\xd6\xd0\x04l\x92\x90\xe3\xec5\xf9,\xfbY1\x9f\x1a\x9eXh!\x91\x8a,\xa11(?\xc1\xd8r\x08\x12qM\xd0\xe1\x8c)k!51\xb5\xd0\x0c6\'\x00\x8f\x844\xc5\xb0\xb4L\xec\x12W9\xba\xd9\x113\x82\x9e\xbb\xb6\xbeD\xca\x13qM`\xdb\x04\xd7\xac\xed&\xc0\x8bL\xa7sV\x13\xa0`\x020\xc9\x9e\x99y]\x82\xdf\xc5\xe8|\x8c\x9c'
first800i = (0, 6, 0, 0, 112, 36, 198, 153, 24, 5, 82, 164, 169, 129, 36, 6, 218, 189, 12, 0, 96, 224, 200, 66, 183, 233, 61, 64, 240, 61, 179, 131, 32, 127, 243, 178, 254, 3, 108, 134, 202, 129, 130, 63, 0, 4, 0, 2, 16, 138, 143, 0, 44, 79, 4, 202, 7, 198, 85, 6, 0, 9, 190, 184, 188, 19, 247, 130, 5, 190, 140, 254, 128, 81, 126, 144, 189, 87, 66, 229, 5, 176, 123, 25, 201, 14, 235, 193, 244, 111, 220, 13, 69, 119, 243, 145, 223, 167, 25, 1, 2, 246, 33, 210, 164, 182, 165, 95, 105, 4, 144, 253, 71, 194, 252, 251, 164, 86, 251, 180, 160, 163, 55, 114, 93, 115, 128, 225, 239, 208, 241, 66, 116, 183, 149, 180, 126, 156, 87, 28, 127, 114, 171, 102, 133, 207, 203, 228, 3, 155, 86, 140, 238, 32, 3, 166, 133, 110, 94, 240, 252, 13, 209, 31, 32, 252, 21, 193, 31, 38, 13, 49, 53, 205, 143, 26, 213, 176, 250, 109, 126, 243, 31, 122, 163, 228, 151, 123, 249, 20, 245, 7, 216, 0, 140, 10, 32, 90, 62, 112, 8, 216, 23, 244, 151, 156, 95, 200, 127, 160, 55, 121, 153, 116, 252, 1, 172, 51, 35, 4, 64, 126, 134, 76, 249, 201, 255, 162, 216, 144, 6, 64, 180, 228, 123, 222, 177, 252, 17, 22, 129, 250, 61, 7, 243, 43, 249, 15, 254, 169, 215, 63, 65, 165, 183, 249, 36, 47, 204, 18, 128, 233, 9, 65, 249, 159, 15, 208, 175, 113, 234, 116, 195, 199, 81, 148, 248, 6, 12, 30, 8, 16, 64, 128, 128, 1, 3, 219, 237, 231, 11, 4, 8, 234, 75, 61, 83, 160, 96, 142, 182, 158, 143, 249, 171, 39, 251, 243, 151, 239, 234, 237, 118, 107, 191, 249, 189, 185, 221, 159, 143, 185, 153, 211, 121, 201, 231, 115, 183, 238, 245, 180, 126, 206, 213, 28, 204, 213, 124, 214, 174, 235, 87, 238, 97, 62, 114, 87, 211, 71, 173, 38, 119, 221, 154, 58, 51, 121, 181, 22, 152, 39, 183, 159, 118, 167, 237, 185, 200, 69, 215, 198, 230, 173, 102, 55, 31, 111, 190, 38, 35, 23, 60, 29, 212, 198, 107, 17, 211, 69, 238, 175, 222, 215, 227, 122, 84, 127, 230, 53, 39, 48, 23, 91, 51, 156, 59, 171, 85, 212, 58, 210, 94, 91, 181, 63, 63, 109, 228, 249, 90, 88, 141, 121, 142, 97, 226, 43, 199, 46, 199, 36, 183, 91, 75, 171, 223, 19, 167, 28, 199, 90, 70, 141, 75, 237, 101, 46, 115, 150, 106, 216, 106, 134, 115, 153, 53, 150, 83, 85, 141, 74, 34, 26, 57, 27, 57, 131, 57, 121, 53, 60, 37, 237, 213, 167, 114, 25, 9, 79, 204, 161, 168, 62, 92, 91, 74, 180, 85, 203, 170, 161, 169, 49, 75, 52, 88, 203, 169, 127, 217, 127, 38, 51, 213, 195, 106, 204, 107, 183, 57, 19, 181, 191, 121, 204, 14, 90, 179, 95, 179, 89, 187, 173, 126, 87, 123, 168, 159, 37, 60, 137, 60, 214, 198, 114, 211, 249, 37, 81, 94, 254, 169, 233, 140, 73, 95, 206, 90, 45, 190, 150, 144, 195, 152, 61, 162, 126, 213, 80, 213, 14, 234, 75, 13, 119, 181, 238, 132, 107, 215, 78, 171, 245, 38, 204, 98, 50, 154, 232, 56, 209, 115, 231, 35, 97, 90, 49, 5, 103, 171, 174, 109, 228, 102, 19, 134, 151, 205, 166, 166, 169, 198, 178, 166, 50, 59, 206, 60, 214, 184, 212, 18, 179, 231, 231, 144, 213, 144, 228, 44, 102, 71, 77, 244, 94, 59, 142, 177, 213, 108, 251, 245, 43, 63, 148, 124, 84, 211, 173, 174, 144, 157, 41, 23, 94, 215, 167, 168, 90, 88, 93, 207, 62, 156, 176, 154, 132, 217, 101, 157, 174, 101, 213, 66, 115, 81, 53, 83, 181, 191, 156, 240, 234, 18, 53, 42, 57, 182, 9, 105, 206, 149, 37, 244, 160, 126, 101, 191, 171, 207, 53, 31, 101, 37, 219, 127, 246, 164, 196, 71, 158, 206, 146, 150, 51, 90, 79, 114, 89, 89, 39, 19, 105, 205, 66, 59, 59, 74, 13, 115, 213, 205, 28, 190, 108, 69, 217, 213, 106, 6, 19, 2, 41, 247, 92, 29, 32, 161, 9, 9, 33, 219, 214, 220, 249, 72, 133, 95, 246, 253, 58, 90, 61, 46, 183, 145, 203, 204, 45, 230, 246, 115, 49, 89, 112, 215, 147, 44, 196, 114, 124, 235, 81, 246, 236, 132, 95, 213, 162, 179, 255, 102, 111, 168, 174, 26, 227, 239, 137, 4, 230, 172, 196, 26, 71, 81, 222, 28, 192, 236, 3, 217, 147, 179, 40, 102, 235, 78, 56, 121, 194, 227, 99, 52, 45, 23, 156, 91, 143, 241, 136, 44, 228, 18, 14, 159, 139, 72, 72, 67, 206, 120, 162, 227, 44, 213, 213, 56, 18, 73, 143, 181, 137, 42, 222, 2, 18, 78, 154, 136, 121, 66, 237, 19, 74, 150, 56, 138, 113, 213, 172, 12, 153, 139, 37, 66, 150, 176, 195, 172, 113, 89, 21, 106, 143, 57, 3, 177, 118, 156, 80, 250, 28, 243, 236, 135, 217, 248, 178, 70, 230, 36, 27, 48, 144, 242, 255, 68, 108, 99, 36, 32, 33, 187, 249, 40, 167, 63, 97, 224, 137, 248, 37, 24, 111, 230, 248, 57, 91, 185, 232, 152, 184, 215, 100, 39, 168, 110, 230, 38, 217, 60, 18, 244, 43, 86, 168, 212, 4, 214, 108, 100, 146, 33, 32, 243, 255, 108, 176, 217, 135, 107, 126, 99, 60, 50, 134, 245, 36, 52, 33, 43, 75, 130, 213, 39, 212, 43, 193, 47, 99, 82, 158, 112, 233, 90, 82, 102, 148, 17, 72, 105, 246, 251, 218, 71, 12, 227, 201, 214, 156, 51, 51, 61, 52, 245, 202, 62, 144, 80, 215, 132, 169, 215, 70, 170, 149, 103, 33, 150, 125, 45, 139, 70, 14, 67, 194, 158, 170, 70, 39, 202, 207, 230, 156, 56, 74, 80, 220, 172, 82, 9, 44, 148, 29, 45, 43, 99, 38, 205, 57, 122, 9, 44, 158, 50, 194, 202, 255, 99, 242, 158, 144, 236, 154, 190, 132, 32, 136, 33, 15, 25, 59, 87, 145, 72, 112, 221, 154, 185, 156, 205, 44, 34, 185, 187, 108, 173, 137, 48, 212, 228, 198, 224, 212, 24, 84, 82, 93, 59, 70, 115, 51, 250, 204, 244, 53, 247, 209, 249, 72, 232, 127, 229, 34, 185, 148, 218, 86, 70, 107, 137, 184, 36, 152, 71, 22, 220, 89, 174, 242, 75, 70, 48, 9, 210, 146, 205, 50, 51, 158, 236, 73, 9, 243, 77, 224, 224, 196, 95, 46, 61, 161, 73, 217, 21, 115, 31, 133, 88, 101, 229, 205, 101, 39, 96, 147, 132, 196, 230, 204, 36, 36, 60, 167, 56, 33, 4, 19, 232, 45, 161, 110, 9, 67, 141, 144, 137, 44, 186, 49, 152, 56, 151, 86, 191, 19, 214, 151, 128, 119, 18, 225, 73, 16, 211, 204, 109, 59, 60, 185, 192, 26, 131, 24, 126, 146, 96, 141, 9, 82, 150, 16, 237, 236, 234, 9, 201, 203, 45, 38, 224, 254, 108, 190, 213, 206, 178, 185, 36, 168, 96, 46, 40, 67, 155, 53, 97, 153, 24, 37, 92, 53, 43, 95, 13, 91, 134, 82, 178, 151, 87, 168, 67, 65, 14, 94, 109, 37, 1, 183, 36, 134, 19, 172, 53, 1, 5, 38, 252, 35, 199, 57, 161, 43, 153, 106, 198, 176, 153, 236, 224, 9, 187, 74, 184, 70, 54, 228, 132, 217, 38, 164, 44, 27, 103, 142, 98, 194, 200, 18, 82, 208, 225, 73, 160, 185, 92, 72, 44, 77, 203, 146, 156, 64, 120, 9, 93, 200, 6, 153, 32, 189, 153, 138, 100, 76, 151, 105, 112, 86, 178, 234, 34, 245, 34, 225, 137, 49, 133, 199, 48, 210, 132, 102, 38, 8, 107, 62, 201, 26, 110, 192, 64, 18, 238, 79, 176, 218, 236, 180, 53, 91, 25, 50, 175, 31, 249, 41, 135, 189, 170, 111, 12, 40, 155, 203, 174, 103, 49, 64, 75, 134, 109, 18, 44, 54, 11, 224, 12, 91, 38, 50, 157, 97, 231, 4, 61, 205, 191, 89, 96, 36, 244, 32, 51, 158, 164, 90, 103, 81, 140, 9, 116, 86, 210, 4, 68, 150, 173, 40, 134, 102, 103, 71, 75, 0, 125, 137, 187, 140, 115, 179, 33, 39, 96, 151, 204, 141, 178, 217, 199, 192, 189, 153, 116, 197, 224, 217, 132, 146, 231, 140, 22, 111, 175, 252, 63, 195, 48, 49, 224, 108, 130, 63, 36, 116, 36, 1, 131, 230, 52, 103, 63, 73, 88, 91, 194, 176, 18, 242, 149, 0, 31, 114, 120, 115, 230, 50, 210, 200, 88, 50, 195, 84, 153, 13, 102, 98, 159, 32, 253, 9, 250, 145, 45, 99, 238, 154, 241, 100, 114, 149, 161, 225, 12, 209, 38, 236, 51, 23, 148, 229, 39, 134, 6, 38, 8, 90, 190, 202, 152, 190, 122, 82, 86, 246, 44, 111, 185, 135, 26, 183, 140, 135, 99, 254, 98, 136, 103, 12, 188, 155, 161, 248, 4, 227, 203, 46, 221, 236, 163, 166, 39, 70, 68, 51, 221, 78, 240, 183, 4, 105, 206, 118, 153, 224, 47, 153, 244, 37, 16, 92, 66, 115, 19, 188, 35, 59, 88, 22, 145, 132, 185, 198, 144, 178, 4, 170, 74, 8, 184, 28, 242, 4, 76, 151, 89, 104, 162, 238, 98, 125, 49, 128, 85, 246, 128, 24, 254, 146, 155, 204, 68, 58, 129, 196, 99, 152, 83, 130, 89, 214, 171, 108, 69, 49, 4, 43, 63, 39, 32, 242, 24, 23, 172, 174, 149, 208, 152, 132, 195, 103, 71, 205, 34, 158, 96, 65, 93, 70, 230, 255, 137, 134, 18, 204, 37, 123, 86, 230, 39, 177, 118, 150, 61, 185, 210, 135, 4, 180, 147, 128, 45, 179, 50, 86, 187, 78, 40, 83, 194, 10, 50, 8, 94, 51, 156, 48, 158, 24, 150, 153, 51, 150, 17, 96, 12, 225, 206, 156, 182, 228, 35, 183, 28, 75, 42, 114, 49, 153, 177, 196, 32, 201, 68, 90, 18, 229, 36, 238, 179, 224, 206, 46, 154, 93, 38, 70, 35, 179, 43, 230, 140, 198, 192, 107, 9, 111, 201, 54, 145, 11, 207, 196, 54, 193, 73, 202, 119, 2, 238, 207, 186, 145, 27, 172, 165, 213, 20, 38, 224, 162, 24, 209, 140, 5, 122, 19, 152, 58, 70, 176, 199, 24, 108, 102, 206, 9, 4, 152, 147, 159, 0, 6, 107, 191, 217, 6, 114, 247, 49, 210, 156, 128, 119, 50, 94, 207, 225, 65, 144, 192, 174, 9, 31, 207, 192, 73, 2, 178, 202, 141, 38, 176, 73, 34, 205, 137, 54, 19, 16, 117, 44, 8, 148, 61, 47, 51, 146, 24, 44, 147, 192, 188, 9, 129, 151, 113, 120, 150, 167, 44, 192, 18, 132, 51, 59, 106, 10, 247, 39, 128, 247, 204, 250, 99, 68, 37, 70, 22, 99, 72, 67, 76, 243, 9, 96, 36, 147, 199, 4, 163, 77, 128, 104, 217, 56, 178, 245, 101, 141, 142, 1, 187, 107, 95, 25, 82, 140, 245, 199, 108, 166, 49, 84, 61, 203, 107, 1, 252, 178, 182, 68, 224, 209, 9, 4, 146, 237, 56, 183, 155, 80, 219, 28, 250, 204, 38, 19, 164, 59, 33, 36, 178, 96, 78, 208, 152, 88, 96, 183, 186, 80, 214, 208, 4, 108, 146, 144, 227, 236, 53, 249, 44, 251, 89, 49, 159, 26, 158, 88, 104, 33, 145, 138, 44, 161, 49, 40, 63, 193, 216, 114, 8, 18, 113, 77, 208, 225, 140, 41, 107, 33, 53, 49, 181, 208, 12, 54, 39, 0, 143, 132, 52, 197, 176, 180, 76, 236, 18, 87, 57, 186, 217, 17, 51, 130, 158, 187, 182, 190, 68, 202, 19, 113, 77, 96, 219, 4, 215, 172, 237, 38, 192, 139, 76, 167, 115, 86, 19, 160, 96, 2, 48, 201, 158, 153, 121, 93, 130, 223, 197, 232, 124, 140, 156)

class A1(Testable):

    #shift = Variable("shift", 0x19231, 2, "<H", debugger)
    data = Variable("data", 0x19E93E, 0x800, "<"+"B"*0x800, debugger)
    word_k = Variable("word_h", 0x19C71E, 2, "<H", debugger)
    word_h = Variable("word_i", 0x19C722, 2, "<H", debugger)
    word_i = Variable("word_e", 0x19C726, 2, "<H", debugger)
    word_j = Variable("word_d", 0x19C728, 2, "<H", debugger)
    word_e = Variable("word_g", 0x19C72A, 2, "<H", debugger)
    word_d = Variable("word_f", 0x19C72C, 2, "<H", debugger)
    word_a = Variable("word_a", 0x19C724, 2, "<H", debugger)

    def __init__(self):
        #self.shift = 3
        self.data = b''
        self.mapfilehandle = 0
        self.buffer_size = A1.data.size
        self.data = first800i

    def initialize(self):
        bp = debugger.go_to_next_breakpoint()
        assert_equal(bp, Breakpoints.ARRAY_TRANSLATION_INIT)

        dx = self.data[1]
        di = self.data[0]
        cx = self.data[2]

        self.word_k = di
        self.word_h = dx
        self.word_i = cx
        self.word_j = 0
        self.word_e = 3
        self.word_d = self.buffer_size

        assert self.word_h == 6

        self.word_a = 0xFFFF >> (0x10 - self.word_h)

        assert self.word_k <= 1

        bp = debugger.go_to_next_breakpoint()
        assert_equal(bp, Breakpoints.ARRAY_TRANSLATION_INIT_END)

        assert_equal(self.test_all_equal(), True)

    def setup_constants(self):
        assert self.word_k == 0




def setup_debugger():
    debugger.setup_connection()
    debugger.initialize()

    debugger.restart()

    import time
    time.sleep(3)

    debugger.go_to_next_breakpoint()
    debugger.clear_breakpoints()
    debugger.set_breakpoints([INIT_BREAKPOINT])
    debugger.go_to_next_breakpoint()
    #Only now, code is loaded into memory to be executed. Set the correct breakpoints
    # debugger.set_breakpoints([Breakpoints.CALL_FILE_PROCESSOR,
    #                           Breakpoints.FILE_PROCESSOR_START,
    #                           ])
    Breakpoints.set(debugger)
    debugger.go_to_next_breakpoint()

    return debugger

global filepath
filepath = ""

def file_processor():
    if not debugger.go_to_next_breakpoint() == Breakpoints.FILE_PROCESSOR_START:
        raise Exception("mismatch in breakpoints, aborting")

    filepath_pointer = debugger.get_register("EDI")
    global filepath
    filepath = ""
    while True:
        ch = debugger.read(filepath_pointer, 1)
        if ch == "\x00":
            break
        filepath_pointer += 1
        filepath += ch

    print("Reading from file: {}".format(debugger.read(0x19FBF0, len(filepath))))
    print("Writing to file: {}".format(filepath))

    mapfilepointers_ptr = debugger.read(debugger.get_register("ESI"), 4)
    mapfilebuffer_ptr = mapfilepointers_ptr + 0x2222

    #read 800 bytes into buffer

def start():

    setup_debugger()

    bp = debugger.get_breakpoint()
    if not bp == Breakpoints.CALL_FILE_PROCESSOR:
        raise Exception()

    file_processor()


def on_drag_and_drop():
    pass

setup_debugger()
debugger.go_to_next_breakpoint()
debugger.go_to_next_breakpoint()
a1 = A1()
a1.initialize()