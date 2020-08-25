# Orientation

Orientation of the map. Bit mind-twisting, because the orientation is enumerated counterclockwise (North (0) -> North-West (1) -> West (2) -> ... -> North-East (7) -> North (0) -> ...), but the game circles clockwise (rotation; North -> East -> South -> West -> North -> ...):

| Rotation  | Orientation   | Direction |
| :-------: | :-----------: | :-------- |
| 0 	    | 0             | North     |
| 1         | 6             | East      |
| 2         | 4             | South     |
| 3         | 2             | West      |

Consistent with unit orientation, where also orientation 1, 3, 5 and 7 is valid.