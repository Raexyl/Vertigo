include_directories(../../include/Vertigo/Impact)
include_directories(./)
add_library(Impact STATIC
			Math/Vec2.cpp 
			Shape.cpp 
			Rigidbody.cpp 
			Scene.cpp 
)