# Vertigo
Cross-platform game engine as a static library.

### Dependencies
 - SFML

### How To Build
 - Make sure you have installed the dependencies.
 - Open a terminal.
 - cd into the build directory.
 - run "cmake .."
 - run "cmake --build ."

### Dev Todo
 - Integrate SFML
	- App.h needs a window pointer?
		 - Window should be made in OnStart(), and core should quit if it doesn't find a window?
 - Write Math (library or folder?)
 - Write Physics (library)
