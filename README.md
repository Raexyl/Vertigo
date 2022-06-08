# Vertigo
Cross-platform game engine as a static library.

### Dependencies
 - SFML 2.5

### How To Build
 - Make sure you have installed the dependencies.
 - Open a terminal.
 - cd into the build directory.
 - run "cmake .."
 - run "cmake --build ."

### Dev Todo
 - Kinematic rigibodies! --> Rigidbody should store a bool, that says if it's kinematic or not!
 - Polygons?
	 - Shapes need to hold vertices!
	 - Re-work manifolds to contain contact-points

 - Links (between bodies)
 - Quadtrees and threading!