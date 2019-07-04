# sourcehold-maps
Reversing the map file format of Stronghold

### Project goal
The goal is to understand the .map file format of Stronghold (& Stronghold Crusader).

Progress can be made my looking at the machine code of PNGer.exe with a debugger such as x64dbg.
The meaningful parts of the machine code are turned into 

### Project structure
```
# Quite literal Python re-implementation of PNGer in which machine code is converted to meaningful code
├── pnger.py 
# Old versions that might be meaningful to someone again
├── old/     
# Tiny CPU and Memory emulator that facilitates cross validation of machine code and Python code
├── cpu_emulator/__init__.py 
# The map file I use to reverse engineer PNGer.exe
├── resources/MxM_unseen_1.map
# A structure file that can be read into a hex editor such as Hex Editor Neo
├── map_structure.h
# x64dbg database file that contains labels & comments for the machine code
├── Stronghold Map PNGer.exe.dd32
```

### Instructions for using x64dbg
- Put the .dd32 file into the same folder as PNGer.exe
- Start x32dbg
- Open PNGer.exe
- "Run" PNGer.exe until fully running
- Go to breakpoints tab
- Activate the file_processor breakpoint
