#!/bin/bash

# Exit on any error
set -e

# Create and enter the build directory
cd build

# Run CMake configuration
cmake ..

# Build the project
cmake --build .

echo "✅ Build complete. Binary is in ./bin/"
