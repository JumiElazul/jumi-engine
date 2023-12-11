#include "window_handler.h"
#include "logging/logger.h"
#include <GLFW/glfw3.h>
#include <cassert>

namespace jumi
{

    WindowHandler::WindowHandler()
    {
        init(); 
    }
    WindowHandler::~WindowHandler()
    {
        // This line causes a segfault for some reason?  Need to figure this out.
        // glfwTerminate();
    }

    WindowHandler& WindowHandler::instance()
    {
        static WindowHandler instance;
        return instance;
    }

    const WindowContext& WindowHandler::get_context() const 
    {
        return instance()._window_context; 
    }

    bool WindowHandler::create_window(const WindowContext& context)
    {
        _window = glfwCreateWindow(context.width, context.height, context.title, nullptr, nullptr);

        if (!_window)
        {
            return false;
        }

        glfwMakeContextCurrent(_window);
        return true;
    }

    void WindowHandler::show_window() const
    {
        if (_window)
        {
            glfwShowWindow(_window);
        }
    }

    void WindowHandler::init()
    {
        bool success = false;
        success = initialize_glfw();

        if (success)
        {
            _initialized = true;
        }
        else
        {
            JUMI_CRITICAL("WindowHandler::init() failed to initialize");
            assert(false);
        }
    }

    bool WindowHandler::initialize_glfw()
    {
        if (!glfwInit())
        {
            JUMI_CRITICAL("glfw could not be initialized");
            return false;
        }
        return true;
    }

    void WindowHandler::swap_buffers() const { glfwSwapBuffers(_window); }

    void WindowHandler::poll_events() const { glfwPollEvents(); }

    float WindowHandler::get_time() const { return glfwGetTime(); }
}
