import argparse
from .common import main_parser, file_input_file_output

services_parser = main_parser.add_subparsers(title="service", dest="service", required=True)

convert_parser = services_parser.add_parser('convert')
convert_subparsers = convert_parser.add_subparsers(dest='type', required=True, title='type')

convert_aiv_parser = convert_subparsers.add_parser('aiv', parents=[file_input_file_output])
convert_aiv_parser.add_argument('--extra', action='store_true', default=False, help='include properties that have not been parsed as "extra"')
convert_aiv_parser.add_argument('--from-format', required=False, default='')
convert_aiv_parser.add_argument('--to-format', required=False, default='')
convert_aiv_parser.add_argument('--verify', default='', required=False, help='specify file path to verify file with')
convert_aiv_parser.add_argument('--from-invert-y', type=bool, default=False)
convert_aiv_parser.add_argument('--from-invert-x', type=bool, default=False)
convert_aiv_parser.add_argument('--to-invert-y', type=bool, default=True)
convert_aiv_parser.add_argument('--to-invert-x', type=bool, default=False)

memory_parser = services_parser.add_parser('memory')
memory_parser.add_argument('--game', choices=['SHC1.41-latin', "SHCE1.41-latin"], default="SHC1.41-latin")
memory_subparsers = memory_parser.add_subparsers(dest='type', required=True, title='type')

memory_map_parser = memory_subparsers.add_parser('map')
memory_map_subparsers = memory_map_parser.add_subparsers(dest='action', required=True)

memory_common = argparse.ArgumentParser(add_help=False)
memory_common.add_argument('what', choices=['terrain', 'height'])
memory_common.add_argument('--palette', default='', required=False)

memory_map_get_parser = memory_map_subparsers.add_parser('get', parents=[memory_common])
memory_map_get_parser.add_argument('--output', default='')
memory_map_get_parser.add_argument('--output-format', default='png', choices=['png'])

memory_map_set_parser = memory_map_subparsers.add_parser('set', parents=[memory_common])
memory_map_set_parser.add_argument('--input', default='-')
memory_map_set_parser.add_argument('--input-format', default='', choices=['png'])



modify_parser = services_parser.add_parser('modify')
modify_subparser = modify_parser.add_subparsers(dest='type', required=True, title='type')

modify_map_parser = modify_subparser.add_parser('map', parents=[file_input_file_output])
modify_map_parser.add_argument("--unlock", required=False, action='store_const', const=True)
modify_map_parser.add_argument("--lock", required=False, action='store_const', const=True)