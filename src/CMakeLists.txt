include_directories(../include/Vertigo)
include_directories(./)
add_library(Vertigo SHARED App.cpp Core.cpp Logger.cpp)