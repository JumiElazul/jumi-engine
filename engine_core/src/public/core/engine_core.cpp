#include "engine_core/core/engine_core.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include "engine_core/core/timers.h"
#include "engine_core/resources/resource_manager.h"
#include "internal/core/glfw_callback_context.h"
#include <glfw/glfw3.h>
#include <memory>

namespace jumi
{
    // TODO: Create a configuration file for the engine using json or something
    engine_core::engine_core()
        : _should_quit(false)
        , _window_handler()
        , _input_handler()
        , _resource_manager()
        , _renderer(_window_handler.get_window_info(), _resource_manager)
        , _glfw_callback_context(std::make_unique<glfw_callback_context>(_window_handler, _input_handler, _renderer))
        , _timers(timers::instance())
    {
        JUMI_DEBUG("Initializing engine_core...");
        init_glfw();
        _window_handler.init();
        init_glad();
        _input_handler.init();
        _resource_manager.init();
        _renderer.init();

        _glfw_callback_context->hookup_callbacks(_window_handler.window());
    }

    engine_core::~engine_core()
    {
        JUMI_DEBUG("Destructing engine_core...");
        glfwTerminate();
    }

    void engine_core::init_glfw() const
    {
        if (!glfwInit())
        {
            throw initialization_exception("GLFW could not be initialized");
        }
    }

    void engine_core::init_glad() const
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw initialization_exception("GLAD could not be initialized");
        }
    }

    engine_core& engine_core::instance()
    {
        static engine_core instance;
        return instance;
    }

    window_handler& engine_core::get_window()
    {
        return _window_handler;
    }

    input_handler& engine_core::get_input()
    {
        return _input_handler;
    }

    renderer& engine_core::get_renderer()
    {
        return _renderer;
    }

    resource_manager& engine_core::get_resource_manager()
    {
        return _resource_manager;
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
        _timers.calculate_deltatime();
        _input_handler.new_frame_keymap();
        glfwPollEvents();
    }
}
