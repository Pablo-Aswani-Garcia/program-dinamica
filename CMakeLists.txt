# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake -DCMAKE_BUILD_TYPE=Debug ..
#   5. make

cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(programacion-dinamica               # Mandatory
    VERSION 1.0
    DESCRIPTION "Experimentación con programación dinámica"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 23) 			# Use c++23
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-13")    # Use g++-13

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic -Weffc++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Automatically add all .cpp files
file(GLOB_RECURSE ALL_CPP_FILES "${PROJECT_SOURCE_DIR}/src/*.cc")

add_executable(programacion-dinamica ${ALL_CPP_FILES})

# Add expected compiler features to a target.
target_compile_features(programacion-dinamica PRIVATE cxx_std_23)

# Add compile options to a target.
target_compile_options(programacion-dinamica PRIVATE -Wall -Wextra -Wpedantic -Weffc++)