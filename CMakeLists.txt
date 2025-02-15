# The minimum required version.
cmake_minimum_required(VERSION 3.10)

# We have to specify compiler for llvm19 because I want to try llvm@19!
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# open all the tips.
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set directed libraries.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Libraries)

# We need compile commands.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Debug settings
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O3 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O3 -DNDEBUG")
endif()

# show the project name.
project(main VERSION 1.0)

# The headers should be searched here.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the headers and the source files here.
message("The cmake binary directory: " ${CMAKE_BINARY_DIR})
message("The libraries directory: " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
add_library(LibBinaryTreeNode SHARED src/BinaryTreeNode.cpp)
add_library(LibBinaryTree SHARED src/BinaryTree.cpp)
add_executable(main src/main.cpp)

# Link the library with the source.
target_link_libraries(main LibBinaryTree)
