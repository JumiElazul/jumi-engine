#!/bin/bash
mkdir -p bin
cmake -S . -B bin -DCMAKE_TOOLCHAIN_FILE=/mnt/d/Programming/libraries/vcpkg/scripts/buildsystems/vcpkg.cmake
cd bin
make
