cmake_minimum_required(VERSION 3.10)

project(MyCProject C)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add include directories
include_directories(include)

# Set source files
file(GLOB SOURCES src/*.c)

# Set the output directory for the binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Create the executable
add_executable(cshell ${SOURCES})
