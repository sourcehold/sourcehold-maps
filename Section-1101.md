36 bytes, presumably 9 integers.

Integer 0, 1, and 2 are always 0's.
In a .sav file, integer[3] is a 1 if there is two AI players (3 player game).
For a 4 player game, integer[4] is a 2
For a 5 player game, integer[5] is a 3.
(...)
For an 8 player game, integer[8] is a 6.


