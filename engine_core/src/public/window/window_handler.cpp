#include "engine_core/window/window_handler.h"
#include "engine_core/core/exceptions.h"
#include <glfw/glfw3.h>

namespace jumi
{

    window_handler::window_handler(int width, int height)
        : _window_open(false)
        , _window_width(width)
        , _window_height(height)
    {
        if (!glfwInit())
        { 
            throw initialization_exception("Failed to initialize GLFW");
        }

        //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 6);
        //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        _window = glfwCreateWindow(_window_width, _window_height, "Jumi Engine", nullptr, nullptr);

        if (!_window)
        {
            throw initialization_exception("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(_window);
    }

    window_handler::~window_handler()
    {
        glfwTerminate();
    }

    void window_handler::open_window()
    {
        glfwShowWindow(_window);
        _window_open = true;
    }

    void window_handler::close_window()
    {
        glfwHideWindow(_window);
        _window_open = true;
    }

}
