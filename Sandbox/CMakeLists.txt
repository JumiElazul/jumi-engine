cmake_minimum_required(VERSION 3.10)

# Define the project
project(Sandbox)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the executable
add_executable(Sandbox ${SOURCES})

# Include directories
target_include_directories(Sandbox PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Link with the EngineCore library
add_dependencies(Sandbox EngineCore)
target_link_libraries(Sandbox PRIVATE EngineCore)

# Link dependencies from vcpkg or other sources here
# target_link_libraries(Sandbox <dependencies>)
