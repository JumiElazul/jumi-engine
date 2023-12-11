cmake_minimum_required(VERSION 3.10)

message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")

# Define the workspace
project(JumiEngine)

# Include the subdirectories
add_subdirectory(EngineCore)
add_subdirectory(Sandbox)

