cmake_minimum_required(VERSION 3.10)

# set the project name
project(Vertigo VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# directories
SET(include_dir		"${CMAKE_SOURCE_DIR}/include")
SET(src_dir		"${CMAKE_SOURCE_DIR}/src")

# subdirectories
add_subdirectory(${src_dir})