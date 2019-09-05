
import palette, io, subprocess
from PIL import Image

def extract_preview(f):
    data = f.read()

    result = subprocess.run("resources/blast.exe", input = data[20:], stdout = subprocess.PIPE)
    result.check_returncode()

    f2 = io.BytesIO(result.stdout)

    size = len(result.stdout)
    image_size = size - 512
    print(image_size)
    width = int(image_size ** 0.5)
    height = int(image_size ** 0.5)

    f2.seek(0)
    p = palette.build_serial_palette(f2)
    data = list(f2.read(image_size))

    image = Image.new("P", (width, height))
    image.putpalette(p)
    image.putdata(data)

    return image


if __name__ == "__main__":
    import sys
    if len(sys.argv) == 1:
        sys.argv.append("resources/MxM_unseen_1.map")
        #raise Exception("Too few arguments. No inputfile and optional outputfile specified")
    inputfile = outputfile = None
    if len(sys.argv) >= 2:
        inputfile = sys.argv[1]
    if len(sys.argv) == 3:
        outputfile = sys.argv[2]

    with open(inputfile, 'rb') as f:
        image = extract_preview(f)
        if outputfile:
            with open(outputfile, 'wb') as f2:
                image.save(f2)
        else:
            image.show()