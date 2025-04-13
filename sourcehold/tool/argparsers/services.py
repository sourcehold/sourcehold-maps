from .common import main_parser, file_input_file_output

services_parser = main_parser.add_subparsers(title="service", dest="service", required=True)

convert_parser = services_parser.add_parser('convert')
convert_subparsers = convert_parser.add_subparsers(dest='type', required=True, title='type')

convert_aiv_parser = convert_subparsers.add_parser('aiv', parents=[file_input_file_output])
convert_aiv_parser.add_argument('--extra', action='store_const', const=True, default=False, help='include properties that have not been parsed as "extra"')
convert_aiv_parser.add_argument('--from-format', required=False, default='')
convert_aiv_parser.add_argument('--to-format', required=False, default='')

memory_parser = services_parser.add_parser('memory')
