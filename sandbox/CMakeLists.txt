include_directories(sandbox ../include)
add_executable(sandbox sandbox.cpp)
target_link_libraries(sandbox Vertigo)