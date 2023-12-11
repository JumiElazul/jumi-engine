#!/bin/bash

# Define the path to the vcpkg toolchain file
VCPKG_TOOLCHAIN=~/Documents/programming/vcpkg/scripts/buildsystems/vcpkg.cmake

# Create the build directory
if [ ! -d "bin" ]; then
    mkdir -p bin
fi

# Run CMake with the vcpkg toolchain
cmake -S . -B bin --log-level=VERBOSE -DCMAKE_TOOLCHAIN_FILE=${VCPKG_TOOLCHAIN} -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Build the project
cd bin
make
