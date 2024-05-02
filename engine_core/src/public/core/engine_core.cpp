#include "engine_core/core/engine_core.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include "internal/core/glfw_callback_context.h"
#include <glfw/glfw3.h>

namespace jumi
{

    // TODO: Create a configuration file for the engine using json or something
    engine_core::engine_core()
        : _should_quit(false)
        , _window_handler()
        , _input_handler()
        , _renderer(_window_handler.get_window_info())
        , _glfw_callback_context(std::make_unique<glfw_callback_context>(_window_handler, _input_handler, _renderer))
    {
        logger::print_debug_log_info();
        JUMI_DEBUG("Initializing engine_core...");

        _glfw_callback_context->hookup_callbacks(_window_handler.window());
    }

    engine_core::~engine_core()
    {
        JUMI_DEBUG("Destructing engine_core...");
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

    bool engine_core::should_quit() const
    {
        return _should_quit;
    }

    void engine_core::quit()
    {
        _should_quit = true;
    }

    void engine_core::new_frame()
    {
        _input_handler.new_frame_keymap();
        glfwPollEvents();
    }

}
