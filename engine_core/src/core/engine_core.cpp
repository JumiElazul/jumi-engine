#include "engine_core/core/engine_core.h"
#include "internal/core/backend.h"
#include "internal/core/engine_callback_context.h"
#include "internal/window/window_handler.h"
#include "internal/input/input_handler.h"
#include <memory>

namespace jumi
{

    engine_core& engine_core::instance()
    {
        static engine_core instance;
        return instance;
    }

    engine_core::engine_core()
        : _window_handler(std::make_unique<window_handler>())
        , _input_handler(std::make_unique<input_handler>())
        , _callback_context(std::make_unique<engine_callback_context>(*_window_handler.get(), *_input_handler.get()))
    {
        backend::init(window_input_api::glfw, rendering_api::open_gl);
        _window_handler->init();
        _input_handler->init();
        _callback_context->init();

        _window_handler->show_window();
    }

    engine_core::~engine_core()
    {
        backend::cleanup();
    }

    void engine_core::run()
    {
        // Main loop
        while (!_window_handler->should_close())
        {
            // Clear the color and depth buffers

            // Poll events

            // Update the window

            // Swap the buffers
            _window_handler->swap_buffers();
        }
    }


}