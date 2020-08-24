# Player Data

Lots of the player data can be found in this section. There are basically 14.932 bytes of yet unknown data (probably including a player0) and an 8 x 14.836 (8 x 0x39F4) byte array with player data (in the disassembly, the players are enumerated 1-8, not 0-7).

This data includes hard data (which is editable with CE) like popularity and gold, some live statistics (which gets periodically updated) like total wood or housing, settings like taxes and potentially more.

Some settings only get updated if another action takes place. For example if one changes the taxes in this section (0 corresponds to +7 popularity, 1 to +5 and so on), it only gets updated if one opens the keep.

When wiped, everything is 0, but amount of peasants and capacity is restored, but popularity and gold remain 0.
Popularity also does not seem to increase, despite +3 situation.

Taxes are set to +7 popularity level. Rations are set to 0. There are no forbidden foods.

Popularity seems broken, also because taxation is just +1 popularity for a while (a month until update?), and cannot be set higher.
Changing rations also does not remove the -8 popularity penalty.
The rations screen is absolutely broken, nobody eats anymore.