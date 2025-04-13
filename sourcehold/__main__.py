import pathlib
import argparse
import sys

from sourcehold.maps.Map import Map
from sourcehold import save_map
from sourcehold import load_map
from sourcehold.structure_tools.Buffer import Buffer
from sourcehold.compression import COMPRESSION

from sourcehold.tool.argparsers.common import main_parser
from sourcehold.tool.argparsers.services import services_parser, convert_parser

file_input_output = argparse.ArgumentParser(add_help=False)
file_input_output.add_argument("--in", help="files or folders to (un)pack", nargs='+', required=True)
file_input_output.add_argument("--out", help="a folder to (un)pack files to")

multiple_file_input_output = argparse.ArgumentParser(add_help=False)
multiple_file_input_output.add_argument("--in", help="files or folders to (un)pack", nargs='+', required=True)
multiple_file_input_output.add_argument("--out", help="a folder to (un)pack files to")



file_manipulation_parser = argparse.ArgumentParser(add_help=False, parents=[file_input_output])
file_manipulation_parser_group = file_manipulation_parser.add_mutually_exclusive_group(required=True)
file_manipulation_parser_group.add_argument("--unpack", action='store_const', const=True, default=False, help="unpack a .map/.sav/.msv file to a folder")
file_manipulation_parser_group.add_argument("--pack", action='store_const', const=True, default=False, help="pack a folder into a .map/.sav/.msv file")
file_manipulation_parser_group.add_argument("--what", help="what to unpack from the map file, e.g., '1001' for section 1001", default="all")

aiv_parser = services_parser.add_parser('aiv')
aiv_subparsers = aiv_parser.add_subparsers(dest='method', required=True, title='method')
aiv_file_parser = aiv_subparsers.add_parser('file', parents=[file_manipulation_parser])



# 
# python -m sourcehold convert aiv --in 'C:\Program Files (x86)\Steam\steamapps\common\Stronghold Crusader Extreme\aiv\snake1.aiv' --extra
#



compression_parser = services_parser.add_parser('compression')
compression_parser_group = compression_parser.add_mutually_exclusive_group(required=True)
compression_parser_group.add_argument("--decompress", action='store_const', const=True, default=False, help="decompress data")
compression_parser_group.add_argument("--compress", action='store_const', const=True, default=False, help="compress data")
compression_parser.add_argument("--in", help="files to (de)compress", required=True)
compression_parser.add_argument("--out", help="destination file", required=True)
# compression_parser.add_argument("--level", help="compression level", type=int, default=6, required=False)

maps_parser = services_parser.add_parser('map')
maps_subparsers = maps_parser.add_subparsers(dest="method", required=True, title="method")
maps_subparsers.add_parser('file', parents=[file_manipulation_parser])

image_parser = maps_subparsers.add_parser("image")
image_parser.add_argument("--in", help="tile image", required=True)
image_parser.add_argument("--out", help="destination image file", default="-")
image_parser.add_argument("--perspective", help="create perspective image", default=False, action="store_const", const=True)
image_parser.add_argument("--rgb", help="rgb image, default is cmyk", default=False, action="store_const", const=True)
image_parser.add_argument("--transform", help="for cmyk, make byte sized sections paint in the 32 bit color range", default=False, action="store_const", const=True)

memory_parser = maps_subparsers.add_parser("memory")
memory_parser_group = memory_parser.add_mutually_exclusive_group(required=True)
memory_parser_group.add_argument("--write", help="write to memory section")
memory_parser_group.add_argument("--read", help="read from memory section")
memory_parser_group.add_argument("--inject", help="inject map/sav file into memory")
memory_parser_group.add_argument("--dump-into", help="dump game state memory (map/sav/msv) into a binary dump")
memory_parser.add_argument("--in", help="input data location")
memory_parser.add_argument("--out", help="output data location", default="-")
memory_parser.add_argument("--config", help="location of the CheatEngine .CT file", default=None)
memory_parser.add_argument("--data", help="raw data to write in hex format (00)", type=str)
memory_parser.add_argument("--recycle", action='store_const', const=True, default=False)
memory_parser.add_argument("--process-version", help="version of the Stronghold process", default="SHCHD1.41")
memory_parser.add_argument("--standardized", help="standardize tilemap sections to use 400x400", action='store_const', const=True, default=False)

args = main_parser.parse_args()

from .tool.convert.aiv import convert_aiv

def main():
  convert_aiv(args)

  if args.service == "aiv":
    if args.method == "file":
      raise Exception("not implemented")
    
    if args.method == "memory":
      raise Exception("not implemented")

    return

  if args.service == "map":
    if args.method == "file":
        input_files = args.input

        if args.output == "-":
            if len(input_files) > 1:
                raise Exception("the parameter '--out -' only supports unpacking a single input file")
            if args.what == "all":
                raise Exception("the parameter '--out -' does not support unpacking 'all', please select with '--what'. For example, '--what preview'")

        if not args.unpack and not args.pack and args.output:
            if all(inf[-4:] in [".sav", ".map", ".msv"] for inf in input_files):
                args.unpack = True
            if all(pathlib.Path(inf).is_dir() for inf in input_files):
                args.pack = True

        if args.unpack:
            for inf in input_files:
                if not pathlib.Path(inf).is_file():
                    raise Exception("Unexpected usage of unpack: all inputs must be files")

            if not args.output:
                args.output = str(pathlib.Path().absolute())

        if args.pack:
            for inf in input_files:
                if not pathlib.Path(inf).is_dir():
                    raise Exception("Unexpected usage of pack: all inputs must be directories")

            if not args.output:
                args.output = str(pathlib.Path().absolute())


    if args.method == "file":
        input_files = args.input

        if args.unpack and args.pack:
            raise Exception("Cannot unpack and pack at the same time")

        if args.unpack:
            for file in input_files:

                path = pathlib.Path(file)
                map = load_map(file)

                name = path.name
                name = name.split(".")[0]

                if args.what != "all":
                    if args.what.isnumeric():
                        section = args.what
                        what = map.directory[int(section)].get_data()
                        what_name = section
                    else:
                        what_elements = [p for p in args.what.split("/") if p]
                        obj = map

                        wel = what_elements

                        if wel[0] == "directory" and wel[1].isnumeric():
                            obj = map.directory[int(wel[1])]
                            what_name = wel[1]
                            wel = wel[2:]

                        for i, key in enumerate(wel):
                            if not hasattr(obj, key):
                                raise Exception(f"error in --what '{args.what}', invalid path: {wel[:i+1]}")
                            obj = getattr(obj, key)
                        what = obj.get_data()
                        what_name = what_elements[-1]

                    if args.output == "-":
                        dst_handle = sys.stdout.buffer
                        dst_handle.write(what)
                    else:

                        dst = pathlib.Path(args.output) / name
                        if not dst.exists():
                            dst.mkdir(parents=True)

                        if args.debug:
                            print(f"unpacking {what_name} to folder {dst.name}")

                        (dst / what_name).write_bytes(what)
                else:
                    dst = pathlib.Path(args.output) / name
                    if not dst.exists():
                        dst.mkdir(parents=True)

                    if args.debug:
                        print(f"unpacking file {name} to folder {dst.name}")

                    map.dump_to_folder(str(dst))

        if args.pack:
            for file in input_files:
                path = pathlib.Path(file).absolute()

                map = Map().load_from_folder(str(path))
                map.pack(True)

                name = path.name

                dst = pathlib.Path(args.output).absolute()

                print(f"packing file from folder {path} to file {str(dst)}")

                save_map(map, dst)

    import PIL.Image
    import struct
    from sourcehold.maps.sections.types import TileSystem
    if args.method == "image":

        input_file = args.input
        output_file = args.output
        if input_file == "-":
            input_data = sys.stdin.buffer.read()
        else:
            input_data = pathlib.Path(input_file).read_bytes()

        if len(input_data) % 80400 != 0:
            raise Exception(f"Invalid tile data length: {len(input_data)}, not a tile map section?")

        tile_size = len(input_data) // 80400
        if tile_size == 1:
            fmt = "B"
        elif tile_size == 2:
            fmt = "H"
        elif tile_size == 4:
            fmt = "I"
        else:
            raise Exception(f"unsupported tile size: {tile_size}")

        if args.perspective:
            ts = TileSystem().from_bytes(data=input_data, fmt=fmt)
            img = ts.create_image()
        else:
            if args.rgb:
                size = struct.calcsize(fmt)
                values = struct.unpack(f"<{80400}" + fmt, input_data)

                from sourcehold.debugtools.maps import populate_value_matrix, init_matrix
                from sourcehold.maps.sections.tools import build_palette
                matrix = init_matrix(shape=(400, 400), value=None)
                populate_value_matrix(matrix, values)

                mapping, palette = build_palette(set(values))

                img = PIL.Image.new('RGB', (400,400), color=0)
                pixelmap = img.load()
                for i, row in enumerate(matrix):
                    for j, value in enumerate(row):
                        if value is None:
                            continue
                        pixelmap[i, j] = palette[mapping.index(value)] # type: ignore
            else:
                # cmyk
                size = struct.calcsize(fmt)
                values = struct.unpack(f"<{80400}" + fmt, input_data)

                from sourcehold.debugtools.maps import populate_value_matrix, init_matrix
                from sourcehold.maps.sections.tools import build_palette
                matrix = init_matrix(shape=(400, 400), value=None)
                populate_value_matrix(matrix, values)

                if args.transform:
                  if tile_size == 1:
                      multiplier = lambda v: v << (32 - 8)
                  elif tile_size == 2:
                      multiplier = lambda v: v << (32 - 16)
                  elif tile_size == 4:
                      multiplier = lambda v: v
                  else:
                      raise Exception()
                else:
                    multiplier = lambda v: v

                img = PIL.Image.new('CMYK', (400,400), color=-1)
                pixelmap = img.load()
                for i, row in enumerate(matrix):
                    for j, value in enumerate(row):
                        if value is None:
                            continue
                        pixelmap[i, j] = multiplier(value) # type: ignore

        if output_file == "-":
            img.show()
        else:
            img.save(output_file)

    import binascii
    import platform

    if args.method == "memory":

        if platform.system().lower() != "windows":
            raise Exception("memory debugging is currently only supported on Windows")

        #  import sourcehold.debugtools.memory.common.access
        #  from sourcehold.debugtools.memory.common.access import AccessContext
        from sourcehold.debugtools.memory.access import SHC, SHCE, SH

        #  if args.config is None:
        #      args.config = str(pathlib.Path(pkg_resources.resource_filename(sourcehold.debugtools.memory.common.access.__name__, "shc_data.CT")))
        if args.process_version == "SHCHD1.41":
            process = SHC()
        elif args.process_version == "SHCHD1.41.1-E":
            process = SHCE()
        elif args.process_version == "SH1.41":
            process = SH()
        else:
            raise RuntimeError("Misspecified process version? Supported version: SH1.41, SHCHD1.41, SHCHD1.41.1-E")

        if args.read:
            if args.read == "all":
                dump = process.read_all_memory()
            else:
                dump = process.read_section(str(args.read))
                if args.standardized:
                    if len(dump) % 80400 != 0:
                        raise Exception(f"--standardize is only supported on tile map sections")
                    tile_size = len(dump) // 80400
                    if tile_size == 1:
                        fmt = "B"
                    elif tile_size == 2:
                        fmt = "H"
                    elif tile_size == 4:
                        fmt = "I"
                    else:
                        raise Exception(f"unsupported tile size: {tile_size}")
                    
                    import struct
                    from sourcehold.world import create_matrix, create_binary_matrix
                    matrix = create_matrix()
                    i = create_binary_matrix()

                    matrix[i] = struct.unpack(f"<80400{fmt}", dump)

                    dump = matrix.tobytes()
            if args.output == "-":
                sys.stdout.buffer.write(dump)
            elif args.output:
                pathlib.Path(args.output).write_bytes(dump)

        elif args.write:
            infile = args.input
            if infile is None and args.data:
                input_data = binascii.a2b_hex(args.data)
            elif infile == "-":
                input_data = sys.stdin.buffer.read()
            else:
                input_data = pathlib.Path(infile).read_bytes()

            if args.write == "all":
                process.write_bytes(0, input_data)
            else:
                if args.standardized:
                    if len(input_data) % 400*400 != 0:
                        raise Exception(f"--standardize is only supported with 400x400 data")
                    tile_size = len(input_data) // (400*400)
                    if tile_size == 1:
                        fmt = "B"
                    elif tile_size == 2:
                        fmt = "H"
                    elif tile_size == 4:
                        fmt = "I"
                    else:
                        raise Exception(f"unsupported tile size: {tile_size}")
                    
                    import struct
                    from sourcehold.world import create_matrix, create_binary_matrix
                    matrix = create_matrix()
                    i = create_binary_matrix()

                    import numpy
                    trues = numpy.zeros(shape=(400, 400), dtype="bool")
                    trues[:] = True

                    matrix[trues] = struct.unpack(f"<{400*400}{fmt}", input_data)

                    input_data = matrix[i].tobytes()
                process.write_section(section=str(args.write), data=input_data, recycle=args.recycle)

        elif args.inject:
            m = load_map(args.inject)
            for index, section in process.memory_sections.items():
                if index == "0":
                    continue
                try:
                    process.write_section(index, m.directory[int(index)].get_data()) # type: ignore
                except Exception as e:
                    print(f"failed on section: {e}")

        elif args.dump_into:
            with open(args.dump_into, "wb") as ofile:
                for index, section in process.memory_sections.items():
                    if index == "0":
                        continue
                    try:
                        data = process.read_section(section)
                        header = struct.pack("<I", int(index))
                        header += struct.pack("<I", len(data))
                        ofile.write(header)
                        ofile.write(data)
                    except Exception as e:
                        print(f"failed on section: {e}")

  if args.service == "compression":
        input_file = args.input
        if input_file == "-":
            input_data = sys.stdin.buffer.read()
        else:
            input_data = pathlib.Path(input_file).read_bytes()

        if args.decompress:
            output_data = COMPRESSION.decompress(input_data)
        elif args.compress:
            output_data = COMPRESSION.compress(input_data)
        else:
            raise Exception("either select --compress or --decompress")

        output_file = args.output
        if output_file == "-":
            sys.stdout.buffer.write(output_data)
        else:
            pathlib.Path(output_file).write_bytes(output_data)
  # if __name__ == "__main__":
  #     main()
main()