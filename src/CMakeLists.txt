include_directories(../include/Vertigo)
include_directories(../include/Vertigo/Impact)
include_directories(./Impact)
include_directories(./)
add_library(Vertigo STATIC
			App.cpp
			Core.cpp 
			Logger.cpp 
			Impact/Math/Vec2.cpp 
			Impact/Shape.cpp 
			Impact/Rigidbody.cpp
			Impact/Scene.cpp
)

#link with SFML
find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED)
target_link_libraries(Vertigo -lsfml-graphics -lsfml-window -lsfml-system)