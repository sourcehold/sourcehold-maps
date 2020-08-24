The data in this section seems to be tile data representing terrain height in 16-bit format.
The minimum heights seems to be 0x8, while the maximum height is unknown.
The impact of setting the height to 0x0 is also unknown (why 8 as a minimum?).
Walls count also terrain.

When wiped, everything is flat. Cannot be repaired, but game happily runs validly. Things are merely drawn at different heights.

Some notes (J-T-de):
Regarding height 8 is minimum: Unit elevation ingame can be zero if they stand on digged-out moat. Interestingly, when passing shallow water or bog, the units remain on height 8, but get rendered correctly. Highest terrain elevation is probably 255. In Crusader, the highest elevation is below this value (high plateau and high wall). However, in Stronghold a glitch was reported where one is able to generate max-elevation terrain, and if one places a wall on it, the top of the wall is as high as the terrain (so it looks like a floor tile for the max-height terrain). I might know somebody who knows how to produce such a glitched map, so we might infere some data from that.


## Example image of this section
See [this](https://github.com/sourcehold/sourcehold-maps/tree/master/resources/example_section_images/1005.png)
which is based on [this map](https://github.com/sourcehold/sourcehold-maps/tree/master/resources/example_section_images/example.sav)