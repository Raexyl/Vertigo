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
 - Thread OnRender() and OnUpdate()[this is input :S] / Physics in core? ---> YES Thread each part and then join threads at end of frame?
 - Polygons?
	 - Find and store contact points?
	 - Rotations! (scalar cross product)

 - What if there is no posDif between bodies? We need a default bias? in Vec2?
 - Links (between bodies)
 - Quadtrees and threading!

### Current Bugs
 - Bodies can vanish on instantiation... is this cos of posDif?

 