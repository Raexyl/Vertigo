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
 - PolyCircle --> Get contact points if overlapping!
 - Add cross product math in Manifold::Solve().

 - What if there is no posDif between bodies? We need a default bias? in Vec2?
 - Links (between bodies)
 - Quadtrees and threading!

### Current Bugs
 - Bodies can vanish on instantiation... is this cos of posDif?

 