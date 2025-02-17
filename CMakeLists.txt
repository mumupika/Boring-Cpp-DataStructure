# The minimum required version.
cmake_minimum_required(VERSION 3.30)

# We have to specify compiler for llvm19 because I want to try llvm@19!
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# Set the standard of the C and CPP.
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CXX_STANDARD_REQUIRED ON)

# Scanning for module dependencies.
set(CXX_SCAN_FOR_MODULES ON)

# open all the tips.
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set directed libraries.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Libraries)
# Set directed modules.
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/Modules)

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
message("The cmake module directory: " ${CMAKE_MODULE_PATH})


add_executable(main)
target_sources(main
    PUBLIC
    src/main.cpp
)

add_library(BinaryTreeNode SHARED)
target_sources(BinaryTreeNode
    PUBLIC
    FILE_SET modules TYPE CXX_MODULES
    FILES
        management/BinaryTreeNode.cppm
        include/BinaryTreeNode_defs.cpp
        src/BinaryTreeNode_impl.cpp
        
)

add_library(BinaryTree SHARED)
target_sources(BinaryTree
    PUBLIC
    FILE_SET modules TYPE CXX_MODULES
    FILES
        management/BinaryTree.cppm
        include/BinaryTree_defs.cpp
        src/BinaryTree_impl.cpp
)
target_link_libraries(BinaryTree BinaryTreeNode)

target_link_libraries(main BinaryTree)
