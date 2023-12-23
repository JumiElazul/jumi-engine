cmake_minimum_required(VERSION 3.10)

message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")

# Define the workspace
project(JumiEngine)

# Compiler flags for debug and release mode
if(MSVC)
    add_compile_options(/W4 /EHsc)
else()
    add_compile_options(-Wall -Wextra -fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Include the subdirectories
add_subdirectory(EngineCore)
add_subdirectory(Sandbox)
