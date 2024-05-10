set(target ${engine_core_target_name})
project(${target})

set(SOURCES
    "src/core/engine_core.cpp"
)

add_library(${target} STATIC ${SOURCES})

target_include_directories(${target} PUBLIC "include")

