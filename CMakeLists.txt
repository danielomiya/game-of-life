# set minimum version required of cmake
cmake_minimum_required(VERSION 3.1)

# set project name and lang
project(gameoflife C)

# set name of executable
SET(EXEC main)

# include header files
include_directories(includes)

# include implementation files (.c)
file(GLOB SOURCES src/*.c)

# compile and generate executable
add_executable(${EXEC} ${SOURCES})
