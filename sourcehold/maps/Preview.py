from sourcehold import palette
from sourcehold.maps.CompressedSection import CompressedSection


from PIL import Image


import io


class Preview(CompressedSection):

    def get_image(self) -> Image:
        palette_size = 512

        buff = io.BytesIO(self.uncompressed)
        size = len(self.uncompressed)
        image_size = size - palette_size
        width = height = int(image_size ** 0.5)

        buff.seek(0)
        p = palette.build_serial_palette(buff)
        data = list(buff.read(image_size))

        img = Image.new("P", (width, height))
        img.putpalette(p)
        img.putdata(data)

        return img

    def set_image(self, image: Image):
        palette_size = 512

        width, height = 200, 200

        if image.mode != 'P':
            image = image.convert('P')
        if image.size != (width, height):
            image = image.resize((width, height))

        if (len(image.getpalette()) / 3) * 2 != 512:
            # raise Exception("Used too many colors, please stick to 256 colors")
            image = image.quantize(256)  # TODO: mode P conversion may be redundant

        pal = palette.pack_palette_to_stream(image.getpalette())
        if len(pal) < palette_size:
            togo = palette_size - len(pal)
            pal += b'\x00' * togo
        if len(pal) != palette_size:
            raise Exception("Invalid length: {}".format(len(pal)))

        self.uncompressed = pal + image.tobytes()