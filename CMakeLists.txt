cmake_minimum_required(VERSION 3.10)

message(STATUS "C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")

# Define the workspace
project(JumiEngine)

# Compiler flags for debug and release mode
if(MSVC)
    add_compile_options(/W3 /EHsc)
else()
    add_compile_options(-Wall -Wextra -fsanitize=address)
    add_link_options(-fsanitize=address)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()


# Include the subdirectories
add_subdirectory(EngineCore)
add_subdirectory(Sandbox)

if(WIN32)
    target_compile_definitions(EngineCore PUBLIC JUMI_WINDOWS)
    target_compile_definitions(Sandbox PUBLIC JUMI_WINDOWS)
endif()

