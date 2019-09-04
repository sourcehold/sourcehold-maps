### About PNGer.exe
PNGer.exe was packed with UPX packer version 1.20. Can be unpacked with UPX.

### About the map preview image in a .map file
Inspecting PNGer.exe for string references yielded the following compression methods:
* inflate 1.1.3 - Mark Adler
* libpng version 1.2.1 - December 12, 2001
* PKWARE Data Compression Library for Win32 version 1.11

The map preview is decompressed using PKWARE decompression. We can use either [this](https://github.com/ladislav-zezula/StormLib/blob/master/src/pklib/explode.c) source, or [this](https://github.com/madler/zlib/blob/master/contrib/blast/blast.c) source for decompressing. They produce the same results.

After decompressing, the first 256 bytes is the color PLTE color palette. Every two bytes contain RGB values in a 5-bit format (the 32nd bit is not used).
Together with the pixel indexes that are in the data, the image can be recreated.

# What we do not know
* (How the final png by PNGer.exe is created.)
* It is unclear what image format the decompressed data is in. Only the indexed pixels from the decompressed map preview are comprehensible right now. 
* How to substitute the map preview in a .map file, and maintain a valid .map file