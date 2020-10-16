# Player Data

Lots of the player data can be found in this section. There is basically a 9 x 14.836 (9 x 0x39F4) byte array with player data (in the disassembly, the players are enumerated 1-8, not 0-7).

This data includes hard data (which is editable with CE) like popularity and gold, some live statistics (which gets periodically updated) like total wood or housing, settings like taxes and potentially more.

Some settings only get updated if another action takes place. For example if one changes the taxes in this section (0 corresponds to +7 popularity, 1 to +5 and so on), it only gets updated if one opens the keep.

The unique ID of the lord is stored in PlayerData, if you set this to 0, a new lord is spawned. If you set it to nonzero before the lord is spawned at the start of the game, the lord is never spawned, so you become invincible... if the nonzero value (unique ID) is a peasant, that peasant will never despawn from the campfire and will count as an extra citizen for some weird reason (causing overpopulation penalty). If that peasant is killed, the game does not end, it only ends if any lord type unit is killed.
The AI also stops attacking if there is no lord, I guess because it cannot find any lord to attack.