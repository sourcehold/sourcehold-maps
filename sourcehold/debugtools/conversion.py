

from xml.etree import ElementTree as ET

def create_data_properties_from_csx(xml_path):
    doc = ET.parse(xml_path)
    elements = doc.findall(".//Element")

    for element in elements:
        offset = int(element.attrib['Offset'])
        bytesize = int(element.attrib['Bytesize'])
        name = element.attrib.get("Description", None)
        if bytesize == 4:
            fmt = "I"
        elif bytesize == 2:
            fmt = "H"
        elif bytesize == 1:
            fmt = "B"
        else:
            raise Exception(f"no format for bytesize: {bytesize}")

        yield name, fmt, offset





