#include "engine_core/core/engine_core.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include "internal/core/glfw_callback_context.h"
#include <glfw/glfw3.h>

namespace jumi
{

    // TODO: Create a configuration file for the engine using json or something
    engine_core::engine_core()
        : _window_handler(1920, 1080)
        , _input_handler(_window_handler.window())
        , _glfw_callback_context(std::make_unique<glfw_callback_context>(_window_handler, _input_handler))
    {
        logger::init();
        logger::print_debug_log_info();
        JUMI_DEBUG("Initializing engine_core..");

        _glfw_callback_context->hookup_callbacks(_window_handler.window());
    }

    engine_core::~engine_core()
    {

    }

    engine_core& engine_core::instance()
    {
        static engine_core instance;
        return instance;
    }

    window_handler& engine_core::window()
    {
        return _window_handler;
    }

    input_handler& engine_core::input()
    {
        return _input_handler;
    }

    double engine_core::time() const
    {
        return glfwGetTime();
    }

}
