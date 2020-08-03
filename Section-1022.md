# Player data

Gold owned by every player can be found by looking for a little endian integer at index 16128 for player 1
at 16128+14836 for player 2, etcetera 

This means that player data is 14836 bytes long, and oddly enough, there is space for 9 players.
Maybe the 0th player isn't real data, just like for buildings and units.

If true, than gold of player 1 can be found at offset 1292 of player 1 slot (1292 + 14836*1)

In other words, the data of player 1 (usually human), can be found at 14836*1 until 14836*2


When wiped, everything is 0, but amount of peasants and capacity is restored, but popularity and gold remain 0.
Popularity also does not seem to increase, despite +3 situation.

Taxes are set to +7 popularity level. Rations are set to 0. There are no forbidden foods.

Popularity seems broken, also because taxation is just +1 popularity for a while (a month until update?), and cannot be set higher.
Changing rations also does not remove the -8 popularity penalty.
The rations screen is absolutely broken, nobody eats anymore.