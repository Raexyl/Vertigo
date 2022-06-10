#SANDBOX
include_directories(polycircle ../include)
add_executable(polycircle polycircle.cpp)
target_link_libraries(polycircle Vertigo)

#CIRCLES
include_directories(circles ../include)
add_executable(circles circles.cpp)
target_link_libraries(circles Vertigo)

