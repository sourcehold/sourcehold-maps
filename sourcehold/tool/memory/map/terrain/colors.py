import pathlib
import json

class Palette(object):
  
  def __init__(self, path: None = None, palette = None):
    if not path and not palette:
      raise Exception()
    self.palette_hex = {}
    if path:
      data = pathlib.Path(path).read_text()
      self.palette_hex = json.loads(data)
    elif palette:
      self.palette_hex = palette
    else:
      raise Exception()
    self.palette_bgr = {key: hex_to_bgr(value) for key, value in self.palette_hex.items()}
    self.bgr_palette = {hex_to_bgr(value): key for key, value in self.palette_hex.items()}
  


monsterfish1_hex = {
  'none': '#000000',
  'default_earth_or_texture': '#ae9467',
  'plateau_medium': '#ae9467', # todo: is this bug prone?
  'plateau_high': '#ae9467', # todo: is this bug prone?

  'border': '#FF0000',
  'border_edge': '#DD0000',
  'plain1_and_farm': '#cccccc',
  'plain2_and_pitch': '#eeeeee',
  'marsh': "#475937",
  'oil': '#314235',
  'boulders': '#c3bdb4',
  'pebbles': '#978f80',

  'rocks': '#675335',
  
  'iron': '#9e4f00',
  'ford': '#567c71',
  'river': '#427068',

  'moat_undug': '#0000FF',
  'moat_dug': '#0000FF',
  'moat': '#0000FF',
  'ocean': '#1e4a44',
  'oasis_grass': '#47540b',
  'thick_scrub': '#6a692b',
  'scrub': '#937e44',
  'earth_and_stones': '#7c7059',
  
  'driven_sand': '#b79453',
  'beach': '#deb977',

  
}

def hex_to_bgr(string):
  return (int(string[5:7], 16), int(string[3:5], 16), int(string[1:3], 16))

def hex_to_rgb(string):
  return (int(string[1:3], 16), int(string[3:5], 16), int(string[5:7], 16))

monsterfish1_rgb = {key: hex_to_rgb(v) for key, v in monsterfish1_hex.items()}
monsterfish1_bgr = {key: hex_to_bgr(v) for key, v in monsterfish1_hex.items()}
rgb_monsterfish1 = {v: key for key, v in monsterfish1_rgb.items()}
bgr_monsterfish1 = {v: key for key, v in monsterfish1_bgr.items()}

MONSTERFISH1 = Palette(palette=monsterfish1_hex)
DEFAULT_PALETTE = MONSTERFISH1