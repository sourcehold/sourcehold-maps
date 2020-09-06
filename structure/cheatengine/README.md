# sourcehold-maps/structure/cheatengine

Here are the CheatEngine (CE) structure definitions.

## Files

|             name | section | description                       |
| ---------------: | :-----: | :-------------------------------- |
|   `Building.CSX` |  1013   |                                   |
|       `Unit.CSX` |  1015   |                                   |
| `PlayerData.CSX` |  1022   |                                   |
|           `*.md` |    -    | information associated to `*.CSX` |

## Usage
CheatEngine is an extremely powerful tool. This is cannot be a general introduction, there is lots of information available in the internet. Some examples:

- [CE Tutorials by Stephen Chapman](https://www.youtube.com/watch?v=XJpNn2GyrNc&list=PLNffuWEygffbbT9Vz-Y1NXQxv2m6mrmHr): The first few videos should prepare you for most of the things you will need
- [CE Forums](https://forum.cheatengine.org/) and the [CE Wiki](https://wiki.cheatengine.org/)
- [Guided Hacking](https://guidedhacking.com/forums/the-game-hacking-bible-learn-how-to-hack-games.469/): Much more than you need to contribute to this project
  
This should be a minimal introduction to be able to contribute something within 30 minutes of setup time ;)

### Setup
#### Install CE:
- download CE from [here](https://cheatengine.org/downloads.php).  
  We recommend the [portable version](https://cheatengine.org/download/CheatEngine7.1_MissingSetup.rar), which comes without the installer (which installs bundleware if one is not careful) and also does not install some stuff, which many anti-virus software block.
- unpack it (portable version) or install it (normal version)

#### Run Stronghold in Windowed Mode
All 2D Stronghold games run in fullscreen mode. This makes it hard to use CE in parallel. To run the game in windowed mode, there are multiple tools, one is DXWnd:
- download DXWnd from their [website](https://sourceforge.net/projects/dxwnd/)
- import a game as described [here](https://www.play-old-pc-games.com/compatibility-tools/using-dxwnd/)

### Find Out Things

TODO: This part is still pretty basic.

#### Open the CE's "Structure Dissect" window
- start Stronghold Crusader 1.4.1 (this is the main game and version we observe), best in [windowed mode](#run-stronghold-crusader-in-windowed-mode)
- start CheatEngine and attach it to Stronghold Crusader by clicking "Select a process to open" on the top left in CheatEngine
- click "Memory View" on the center of the left side to open the "Memory Viewer" window
- click at "Tools", "Dissect data/structures" to open the "Structure Dissect" window

#### Open the CSX File
- download one of the CSX files from [here](/structure/cheatengine/)
- open the associated md file 
- open the "Structure Dissect" window and import the CSX file
- copy the first address from the md file into the "Group 1" text field
- observe and interpret the displayed numbers

If you found out something interesting, let us know as described in [`Contributing.md`](/CONTRIBUTING.md/#how-to-contact-us).