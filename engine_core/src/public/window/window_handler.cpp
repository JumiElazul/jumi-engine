#include "engine_core/window/window_handler.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include "engine_core/structs/structs.h"
#include <glfw/glfw3.h>

namespace jumi
{

    window_handler::window_handler()
        : _window(nullptr)
        , _window_open(false)
        , _window_info()
    {
        JUMI_DEBUG("Initializing window_handler...");
        if (!glfwInit())
        { 
            throw initialization_exception("Failed to initialize GLFW");
        }

        _window_info = get_initial_window_info();
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        _window = glfwCreateWindow(_window_info.width, _window_info.height, "Jumi Engine", nullptr, nullptr);

        if (!_window)
        {
            throw initialization_exception("Failed to create GLFW window");
        }

        glfwSetWindowPos(_window, _window_info.x, _window_info.y);
        glfwMakeContextCurrent(_window);
    }

    window_handler::~window_handler()
    {
        JUMI_DEBUG("Destructing window_handler...");
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

    void window_handler::swap_buffers() const
    {
        glfwSwapBuffers(_window);
    }

    GLFWwindow* window_handler::window() const
    {
        return _window;
    }

    window_info window_handler::get_initial_window_info() const
    {
        window_info initial_window_info;

        const GLFWvidmode* video_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        int screen_width = video_mode->width;
        int screen_height = video_mode->height;

        initial_window_info.width = 1920;
        initial_window_info.height = 1080;

        initial_window_info.x = (screen_width - initial_window_info.width) / 2;
        initial_window_info.y = (screen_height - initial_window_info.height) / 2;

        return initial_window_info;
    }

    void window_handler::window_position_callback(int xpos, int ypos)
    {
        JUMI_DEBUG("Window position callback: x: {}, y: {}", xpos, ypos);
    }

    void window_handler::window_size_callback(int width, int height)
    {
        JUMI_DEBUG("Window size callback: width: {}, height: {}", width, height);
    }
}
