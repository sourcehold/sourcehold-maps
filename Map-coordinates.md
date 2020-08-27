## General

A map is shaped in a diamond. 


The top right of the screen is North, which means that placing an object there corresponds to placing an object on tile 0 (however, there are unbuildable game map borders, so if you would try this, you would probably build on tile 3 or 4).

There are four sizes of maps: 160x160, 200x200, 300x300, and 400x400.
However, all tile data sections in a map are of the same size, regardless of the map size.

So, given a map of 160x160, the same 400x400 coordinate system is used, but only the center of that space is used.

For illustration purposes, the map size below is set to 6 instead of 400.

## Serialized representation of tiles
Given that every tile is a byte, and an array of 24 bytes, then the byte at index 4 (array[4]) will point to the tile (i = 1, j = 2).

 ![this](../resources/tiles-illustration-serialized-1.png)

## Representation of tiles in the game
Basically, j is adjusted by the distance of i to the middle of the diamond (i=2 and i=3 in this case).
Given that every tile is a byte, and an array of 24 bytes, then the byte at index 4 (array[4]) will point to the tile (i = 1, j = 2) and the game tile (i = 1, j = 3).

 ![this](../resources/tiles-illustration-game-1.png)
