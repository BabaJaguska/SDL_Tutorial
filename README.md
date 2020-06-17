# SDL_Tutorial
Followed a yt tutorial by ArchieG

SDL (Simple DirectMedia Layer) is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.
SDL is written in C, works natively with C++, and there are bindings available for several other languages, including C# and Python.

This little project uses C++ to create a window, plot a little square on it, and move it around through processing keystroke events. 

To make SDL work, the library should be in the project folder. Then adjust a few things in project properties:
- Configuration properties
	- Edit Include Directories by adding the path to the Dependencies/include folder
	- Edit Lib Directories by adding the path to the Dependencies/lib folder
- Linker Input Additional Dependencies, add manually: SDL2.lib, SDL2main.lib
- Set the entry point to Console (Properties/Linker/System/SubSystem = Console)
- The lib in this project is x86, check if the target machine corresponds to this (Build/Configuration Manager)
