## Basic section information
Every section has a four digit key identifier in the 1000-1126 range. Not every number in this range is used.

Every section is fixed in size, even for different map sizes.

So far, there are three general structures for sections:
- Tile data.
When sections contain tile data, they are a multiple of 80400 in size (there are 80400 usable tiles in a world map).
- Array data. Other data such as unit data is stored in fixed-size array form where each element is of a fixed-size.
- Other data. There are also sections with data such as the in-game date, popularity, stock levels, etcetera.

A section can be in a compressed state. Most tile data sections are stored in a compressed state (exception: section 1008).