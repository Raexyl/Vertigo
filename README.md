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
 - I need a list of all instances of Rigidbody... NOTHING WORKS!? --> Should scene be a singleton?
 - FOR NOW - KEEP IMPACT AND SFML MOSTLY DISTINCT FROM THE CORE (work out how to integrate once the physics is done)
 - Make deterministic (calculate dt)
 - max iterations to avoid spiral of death
 - Material class?
 - Polygons?