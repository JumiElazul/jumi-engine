set(target ${engine_core_target_name})
project(${target})

set(PUBLIC_SOURCES
    "src/core/engine_core.cpp"
    "src/events/event_bus.cpp"
    "src/events/event_types.cpp"
)

set(PUBLIC_HEADERS
    "include/engine_core/core/engine_core.h"
    "include/engine_core/core/exceptions.h"
    "include/engine_core/core/logger.h"
    "include/engine_core/core/structs.h"
    "include/engine_core/events/event_bus.h"
    "include/engine_core/events/event_types.h"
)

set(PRIVATE_SOURCES
    "src/internal/core/backend.cpp"
    "src/internal/core/engine_callback_context.cpp"
    "src/internal/core/logger.cpp"
    "src/internal/input/input_handler.cpp"
    "src/internal/math/math_types.cpp"
    "src/internal/renderer/opengl_renderer.cpp"
    "src/internal/window/window_handler.cpp"
)

set(PRIVATE_HEADERS
    "src/internal/core/backend.h"
    "src/internal/core/engine_callback_context.h"
    "src/internal/input/input_handler.h"
    "src/internal/interfaces/i_requires_init.h"
    "src/internal/interfaces/i_renderer.h"
    "src/internal/math/math_types.h"
    "src/internal/renderer/opengl_renderer.h"
    "src/internal/window/window_handler.h"
)

add_library(${target} STATIC ${PUBLIC_SOURCES} ${PRIVATE_SOURCES} ${PUBLIC_HEADERS} ${PRIVATE_HEADERS})

target_compile_definitions(${target} PRIVATE GLFW_INCLUDE_NONE)

target_include_directories(${target} PUBLIC "include")
target_include_directories(${target} PRIVATE "src")

find_package(magic_enum CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

target_link_libraries(${target} PRIVATE magic_enum::magic_enum)
target_link_libraries(${target} PRIVATE glfw)
target_link_libraries(${target} PRIVATE fmt::fmt)
target_link_libraries(${target} PRIVATE spdlog::spdlog)
target_link_libraries(${target} PRIVATE glad::glad)
target_link_libraries(${target} PRIVATE glm::glm)
