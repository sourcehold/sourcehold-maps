## Image format
The preview image data is stored in compressed form.
When uncompressed, it is 40512 bytes long.

The preview image that is stored in a map file is in palette form.
The size of the palette is 512 bytes. The colour data is stored in RGB15 form.
This means that a colour is stored in 2 bytes, or rather, 15 bits (1 bit is left unused).
The maximum number of colours is 256 (512/2).

After the palette, the image data is stored in 40000 bytes, forming a 200 by 200 grid.
Every byte points to a colour in the palette.

### Pseudo C-struct-like code
```c
PreviewImage:
  unsigned short rgb15_palette[256];
  unsigned byte data[200][200];
```