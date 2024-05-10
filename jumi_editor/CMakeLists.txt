set(target ${jumi_editor_target_name})
project(${target})

set(SOURCES
    "src/entry_point/main.cpp"
)

add_executable(${target} ${SOURCES})

target_include_directories(${target} PRIVATE "include")

target_link_libraries(${target} PRIVATE
    ${engine_core_target_name}
)
