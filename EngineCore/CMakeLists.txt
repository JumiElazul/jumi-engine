cmake_minimum_required(VERSION 3.10)

# Define the project
project(EngineCore)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the required libraries
find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the library
add_library(EngineCore SHARED ${SOURCES})

# Include directories
target_include_directories(EngineCore PUBLIC "${PROJECT_SOURCE_DIR}/src/")

# Define JUMIAPI_EXPORT when building the library
target_compile_definitions(EngineCore PRIVATE JUMIAPI_EXPORT)

# Link dependencies from vcpkg or other sources here
target_link_libraries(EngineCore PUBLIC spdlog::spdlog glfw)
