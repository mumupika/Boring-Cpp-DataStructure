# The minimum required version.
cmake_minimum_required(VERSION 3.10)
# We have to specify compiler for llvm19 because I want to try llvm@19!
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")
# open all the tips.
set(CMAKE_VERBOSE_MAKEFILE ON)

# We need compile commands.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# show the project name.
project(main VERSION 1.0)

# The headers should be searched here.
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the headers and the source files here.
add_library(MyLibrary src/headers.cpp)
add_executable(main src/main.cpp)

# Link the library with the source.
target_link_libraries(main MyLibrary)
