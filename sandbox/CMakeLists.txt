include_directories(sandbox ../include)
link_libraries(../build/src/libVertigo.so)
add_executable(sandbox sandbox.cpp)