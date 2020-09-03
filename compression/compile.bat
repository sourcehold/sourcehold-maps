
cl.exe /c crc32.c explode.c implode.c buffers.cpp
link.exe /DLL /DEF:compressionlib-nocb.def crc32.obj buffers.obj explode.obj implode.obj