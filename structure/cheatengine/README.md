# sourchold-maps/structure/cheatengine

Here are the CheatEngine structure definitions.

## Usage

CheatEngine is an extremely powerful tool. This is cannot be a general introduction, there is lots of information in the internet. Some examples: 
- CE [Forums](https://forum.cheatengine.org/)
- CE [Wiki](https://wiki.cheatengine.org/)
- Video Tutorials, e.g. [here](https://www.youtube.com/watch?v=XJpNn2GyrNc&list=PLNffuWEygffbbT9Vz-Y1NXQxv2m6mrmHr)
  
This should be a minimal introduction to be able to contribute something within 20 minutes of setup time ;)

### Install Cheat Engine:
- download CE from [here](https://cheatengine.org/downloads.php).  
  We recommend the [portable version](https://cheatengine.org/download/CheatEngine7.1_MissingSetup.rar), which comes without the installer (which might install some bundleware if one is not careful) and also does not install some stuff, which many anti-virus software blocks.
- unpack it (portable version) or install it (normal version)

### Open the CE's "Structure Dissect" window
- start a version of Stronghold, Stronghold Crusader or Stronghold Crusader Extreme (We mainly use Stronghold Crusader 1.4.1, so best go with this one), best in windowed mode TODO
- start CheatEngine and attach it to Stronghold Crusader by clicking "Select a process to open" on the top left in CheatEngine
-  click "Memory View" on the center of the left side to open the "Memory Viewer" window
-  click at "Tools", "Dissect data/structures" to open the "Structure Dissect" window

### The fastest introduction to memory ever
- if you start a game, data gets copied from your drive to memory
- data has an "address" (where is it saved?), a "type" (how do I interpret this data?) and a "value" (what number is saved).
- TODO

### Find out stuff
- download one of the `.CSX` files from this folder you are interested in
- open the associated `.md` file 
- open the "Structure Dissect" window
- copy the first address TODO


## Files

|             name | section | description                     |
| ---------------: | :-----: | :------------------------------ |
|   `Building.CSX` |  1013   |                                 |
|       `Unit.CSX` |  1015   |                                 |
| `PlayerData.CSX` |  1022   |                                 |
|           `*.md` |    -    | addresses associated to `*.CSX` |