This section contains markers for areas that cannot be walked to from another area.
The counting starts at the north of the map. If a tile is encountered that is not walkable, it is given the value of 0.
If a area is not reachable by unit pathing, it is given the next number, e.g. 2.

The top of a wall is a separate area, but placing stairs makes it the same area as the start of the staircase.

In case of areas surrounded by moat: the moat is value 0, and the enclosed area within the moat is given a number.



### old notes 

When wiped, workers disappear and buildings go sleep.
Also, all units disappear.
This only happens when wiped for the second time, and unpaused, though. Weird.

Unclear. All player units disappear, but not all AI units.


## Example image of this section
See [this](https://github.com/sourcehold/sourcehold-maps/tree/master/resources/example_section_images/1021.png)
which is based on [this map](https://github.com/sourcehold/sourcehold-maps/tree/master/resources/example_section_images/example.sav)