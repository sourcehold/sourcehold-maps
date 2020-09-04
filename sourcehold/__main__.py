import pathlib
import argparse

main_parser = argparse.ArgumentParser(prog="sourcehold")
main_parser.add_argument("--debug", action="store_true", default=False, help="debug mode")
subparsers = main_parser.add_subparsers(dest="subparser_name")

file_manipulation_parser = subparsers.add_parser('file')
file_manipulation_parser.add_argument("--unpack", action='store_const', const=True, default=False, help="unpack a .map/.sav/.msv file to a folder")
file_manipulation_parser.add_argument("--pack", action='store_const', const=True, default=False, help="pack a folder into a .map/.sav/.msv file")
file_manipulation_parser.add_argument("--in", help="files or folders to (un)pack", nargs='+', required=True)
file_manipulation_parser.add_argument("--out", help="a folder to (un)pack files to")
file_manipulation_parser.add_argument("--ext", help="when packing, which extension to give the file", default=".map")

args = main_parser.parse_args()

if args.subparser_name == "file":
    input_files = getattr(args, "in")

    if not args.unpack and not args.pack and args.out:
        if all(inf[-4:] in [".sav", ".map", ".msv"] for inf in input_files):
            args.unpack = True
        if all(pathlib.Path(inf).is_dir() for inf in input_files):
            args.pack = True

    if args.unpack:
        for inf in input_files:
            if not pathlib.Path(inf).is_file():
                raise Exception("Unexpected usage of unpack: all inputs must be files")

        if not args.out:
            args.out = str(pathlib.Path().absolute())

    if args.pack:
        for inf in input_files:
            if not pathlib.Path(inf).is_dir():
                raise Exception("Unexpected usage of pack: all inputs must be directories")

        if not args.out:
            args.out = str(pathlib.Path().absolute())

if args.debug:
    print(args)

if args.subparser_name == "file":
    from . import load_map
    input_files = getattr(args, "in")
    if args.unpack:
        for file in input_files:

            path = pathlib.Path(file)
            map = load_map(file)

            name = path.name
            name = name.split(".")[0]

            dst = pathlib.Path(args.out) / name
            if not dst.exists():
                dst.mkdir(parents=True)

            if args.debug:
                print(f"unpacking file {name} to folder {dst.name}")

            map.dump_to_folder(str(dst))

    if args.pack:
        for file in input_files:
            path = pathlib.Path(file)
            from . import maps
            from . import save_map
            map = maps.Map().load_from_folder(str(path))
            map.pack(True)

            name = path.name

            dst = pathlib.Path(args.out) / (name + args.ext)

            if args.debug:
                print(f"packing file from folder {name} to file {dst.name}")

            save_map(map, dst)
