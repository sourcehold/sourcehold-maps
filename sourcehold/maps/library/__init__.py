def expand_var_path(path: str):
    path = str(path)
    if "~" in path:
        i = path.index("~/")
        j = i + 2
        remainder = path[j:]
        name = path[:i]
        name = name.lower()
        if "shc" in name:
            if "user" in name:
                if "sav" in name:
                    return SHC_FILES_USER._saves / remainder
                if "map" in name:
                    return SHC_FILES_USER._maps / remainder
            else:
                if "sav" in name:
                    return SHC_FILES._saves / remainder
                if "map" in name:
                    return SHC_FILES._maps / remainder
        if "sh" in name:
            if "user" in name:
                if "sav" in name:
                    return SH_FILES_USER._saves / remainder
                if "map" in name:
                    return SH_FILES_USER._maps / remainder
            else:
                if "sav" in name:
                    return SH_FILES._saves / remainder
                if "map" in name:
                    return SH_FILES._maps / remainder

    return Path(path).expanduser()


class Library(object):

    def __init__(self, path, mapsub="Maps", savsub="Saves", mapsuf=".map", savsuf=".sav"):
        self._path = path.expanduser()
        self._maps = self._path / mapsub
        self._saves = self._path / savsub
        self._mapsuf = mapsuf
        self._savsuf = savsuf

    def _as_file(self, name, suffix):
        return name if name.endswith(suffix) else name + suffix

    def _as_folder(self, name, suffix):
        return name if not name.endswith(suffix) else name[-4:]

    def get_path_from_saves(self, name):
        return self._saves / self._as_file(name, suffix=self._savsuf)

    def get_path_from_maps(self, name):
        return self._maps / self._as_file(name, suffix=self._mapsuf)

    def get_all_map_paths(self):
        return [f for f in self._maps.iterdir()]

    def get_all_save_paths(self):
        return [f for f in self._saves.iterdir()]


from pathlib import Path

import sourcehold

SHC_FILES_USER = Library(path=Path(sourcehold.CONFIG['shc_user']))
SHC_FILES = Library(path=Path(sourcehold.CONFIG['shc']))
SH_FILES_USER = Library(path=Path(sourcehold.CONFIG['sh_user']))
SH_FILES = Library(path=Path(sourcehold.CONFIG['sh']))
