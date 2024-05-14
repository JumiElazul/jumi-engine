#include "engine_core/core/engine_core.h"
#include "engine_core/core/logger.h"
#include "internal/core/backend.h"
#include "internal/core/engine_callback_context.h"
#include "internal/window/window_handler.h"
#include "internal/input/input_handler.h"
#include "internal/interfaces/i_renderer.h"
#include "internal/renderer/opengl_renderer.h"
#include "internal/renderer/direct3d_renderer.h"
#include "internal/renderer/vulkan_renderer.h"
#include <magic_enum.hpp>
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
        , _renderer(nullptr)
    {
        backend::init(window_input_api::glfw, rendering_api::open_gl);
        _renderer = std::move(create_renderer());

        _window_handler->init();
        _input_handler->init();
        _callback_context->init();
        _renderer->init();

        _window_handler->show_window();
    }

    engine_core::~engine_core()
    {
        backend::cleanup();
    }

    void engine_core::run()
    {
        _renderer->set_clear_color({ 1.0f, 0.0f, 0.0f });
        // Main loop
        while (!_window_handler->should_close())
        {
            _renderer->clear_color_buffer();
            // Clear the color and depth buffers

            // Poll events

            // Update the window

            // Swap the buffers
            _window_handler->swap_buffers();
        }
    }

    std::unique_ptr<i_renderer> engine_core::create_renderer()
    {
        rendering_api api = backend::get_rendering_api();
        JUMI_INFO("Creating renderer with backend {}", magic_enum::enum_name(api));
        switch (api)
        {
            case rendering_api::open_gl:
            {
                return std::make_unique<opengl_renderer>();
                break;
            }
            case rendering_api::direct3d:
            {
                //return std::make_unique<direct3d_renderer>();
                break;
            }
            case rendering_api::vulkan:
            {
                //return std::make_unique<vulkan_renderer>();
                break;
            }
        }

        return nullptr;
    }


}