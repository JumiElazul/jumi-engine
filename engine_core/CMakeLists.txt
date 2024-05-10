set(target ${engine_core_target_name})
project(${target})

set(PUBLIC_SOURCES
    "src/core/engine_core.cpp"
)

set(PUBLIC_HEADERS
    "include/engine_core/core/engine_core.h"
    "include/engine_core/core/logger.h"
)

set(PRIVATE_SOURCES
    "src/internal/backend.cpp"
    "src/internal/logger.cpp"
)

set(PRIVATE_HEADERS
    "src/internal/backend.h"
)

add_library(${target} STATIC ${PUBLIC_SOURCES} ${PRIVATE_SOURCES} ${PUBLIC_HEADERS} ${PRIVATE_HEADERS})

target_include_directories(${target} PUBLIC "include")
target_include_directories(${target} PRIVATE "src")

