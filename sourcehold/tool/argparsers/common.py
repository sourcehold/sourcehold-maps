import argparse

file_input_file_output = argparse.ArgumentParser(add_help=False)
file_input_file_output.add_argument("--input", help="input file", required=True)
file_input_file_output.add_argument("--output", help="output file", required=False)

multiple_file_input_folder_output = argparse.ArgumentParser(add_help=False)
multiple_file_input_folder_output.add_argument("--input", help="input files", nargs='+', required=True)
multiple_file_input_folder_output.add_argument("--output", help="output folder")

main_parser = argparse.ArgumentParser(prog="sourcehold")
main_parser.add_argument("--debug", action="store_true", default=False, help="debug mode")
