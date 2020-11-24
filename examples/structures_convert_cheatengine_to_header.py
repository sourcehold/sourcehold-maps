import xml.etree.ElementTree as ET
import sys
import pathlib
import io

import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--input", default="-", required=True)
parser.add_argument("--output", default="-", required=True)
parser.add_argument("--input_type", default="csx", required=True)
parser.add_argument("--output_type", default="h", required=True)

args = parser.parse_args()

if args.input == "-":
    input_data = sys.stdin.buffer.read().decode('utf-8')
else:
    input_data = pathlib.Path(args.input).read_text(encoding='utf-8')

if args.input_type != "csx":
    raise NotImplementedError("sorry, any other input type than csx is not yet supported")

input_doc = ET.parse(io.StringIO(input_data))

elements = input_doc.find(".//Elements")