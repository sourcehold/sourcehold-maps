# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

from kaitaistruct import __version__ as ks_version, KaitaiStruct
from pkg_resources import parse_version

if parse_version(ks_version) < parse_version('0.7'):
    raise Exception("Incompatible Kaitai Struct Python API: 0.7 or later is required, but you have %s" % (ks_version))


class Map(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        self.magic = self._io.ensure_fixed_contents(b"\xFF\xFF\xFF\xFF")
        self.preview = self._root.Preview(self._io, self, self._root)
        self.description = self._root.Description(self._io, self, self._root)
        self.u1 = self._root.SimpleSection(self._io, self, self._root)
        self.u2 = self._root.SimpleSection(self._io, self, self._root)
        self.u3 = self._root.SimpleSection(self._io, self, self._root)
        self.u4 = self._root.SimpleSection(self._io, self, self._root)
        self.ud = self._io.read_u4le()
        self.directory = self._root.Directory(self._io, self, self._root)
        self.sections = [None] * (self._root.directory.sections_count)
        for i in range(self._root.directory.sections_count):
            _on = self._root.directory.section_compressed[i]
            if _on == 0:
                self.sections[i] = self._root.DefinedSection(i, self._io, self, self._root)
            elif _on == 1:
                self.sections[i] = self._root.CompressedSection(self._io, self, self._root)

    class SimpleSection(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.size = self._io.read_u4le()
            self.data = self._io.read_bytes(self.size)

    class Description(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.size = self._io.read_u4le()
            self.use_string_table = self._io.read_u4le()
            self.string_table_index = self._io.read_u4le()
            self.section = self._root.CompressedSection(self._io, self, self._root)

    class Preview(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.size = self._io.read_u4le()
            self.section = self._root.CompressedSection(self._io, self, self._root)

    class CompressedSection(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.uncompressed_size = self._io.read_u4le()
            self.compressed_size = self._io.read_u4le()
            self.hash = self._io.read_u4le()
            self.data = self._io.read_bytes(self.compressed_size)

    class DefinedSection(KaitaiStruct):
        def __init__(self, i, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self.i = i
            self._read()

        def _read(self):
            self.data = self._io.read_bytes(self._root.directory.section_lengths[self.i])

    class Directory(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.directory_size = self._io.read_u4le()
            self.size = self._io.read_u4le()
            self.sections_count = self._io.read_u4le()
            self.directory_u1 = [None] * (5)
            for i in range(5):
                self.directory_u1[i] = self._io.read_u4le()

            self.uncompressed_lengths = [None] * ((150 if self.directory_u1[0] >= 161 else 100))
            for i in range((150 if self.directory_u1[0] >= 161 else 100)):
                self.uncompressed_lengths[i] = self._io.read_u4le()

            self.section_lengths = [None] * ((150 if self.directory_u1[0] >= 161 else 100))
            for i in range((150 if self.directory_u1[0] >= 161 else 100)):
                self.section_lengths[i] = self._io.read_u4le()

            self.section_indices = [None] * ((150 if self.directory_u1[0] >= 161 else 100))
            for i in range((150 if self.directory_u1[0] >= 161 else 100)):
                self.section_indices[i] = self._io.read_u4le()

            self.section_compressed = [None] * ((150 if self.directory_u1[0] >= 161 else 100))
            for i in range((150 if self.directory_u1[0] >= 161 else 100)):
                self.section_compressed[i] = self._io.read_u4le()

            self.section_offsets = [None] * ((150 if self.directory_u1[0] >= 161 else 100))
            for i in range((150 if self.directory_u1[0] >= 161 else 100)):
                self.section_offsets[i] = self._io.read_u4le()

            self.u7 = self._io.read_u4le()

    @property
    def max_sections_count(self):
        if hasattr(self, '_m_max_sections_count'):
            return self._m_max_sections_count if hasattr(self, '_m_max_sections_count') else None

        self._m_max_sections_count = (150 if self._root.directory.directory_u1[0] >= 161 else 100)
        return self._m_max_sections_count if hasattr(self, '_m_max_sections_count') else None
