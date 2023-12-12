#!/bin/bash

# Define the path to the vcpkg toolchain file
VCPKG_TOOLCHAIN=~/Documents/programming/vcpkg/scripts/buildsystems/vcpkg.cmake

# Create the build directory
if [ ! -d "bin" ]; then
    mkdir -p bin
fi

# Ask user for build mode
echo "Select build mode: (d) Debug, (r) Release"
read -p "Enter choice: " choice

# Set build type based on user input
case "$choice" in
  d|D) BUILD_TYPE="Debug" ;;
  r|R) BUILD_TYPE="Release" ;;
  *) echo "Invalid choice. Defaulting to Release mode."
     BUILD_TYPE="Release" ;;
esac

# Run CMake with the vcpkg toolchain and build type
cmake -S . -B bin --log-level=VERBOSE -DCMAKE_TOOLCHAIN_FILE=${VCPKG_TOOLCHAIN} -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=${BUILD_TYPE}

# Build the project
cd bin
make
