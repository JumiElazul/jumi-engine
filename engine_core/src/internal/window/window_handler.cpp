#include "internal/window/window_handler.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include <GLFW/glfw3.h>

namespace jumi
{

    window_handler::window_handler()
        : _should_close(false)
        , _window(nullptr)
        , _primary_monitor_data()
        , _window_data()
    {
        JUMI_INFO("Constructing window_handler...");
    }

    window_handler::~window_handler()
    {
        JUMI_INFO("Destructing window_handler...");
        if (_window)
        {
            glfwDestroyWindow(_window);
        }
    }

    void window_handler::init()
    {
        JUMI_INFO("Initializing window_handler...");
        // This needs to be done in the init() method because it requires glfw to be initialized
        _primary_monitor_data = collect_monitor_data();

        create_window();
        _initialized = true;
    }

    void window_handler::close_window(bool close)
    {
        _should_close = close;
    }

    void window_handler::show_window()
    {
        if (_initialized)
        {
            glfwShowWindow(_window);
            _window_data.shown = true;
        }
    }

    void window_handler::hide_window()
    {
        if (_initialized)
        {
            glfwHideWindow(_window);
            _window_data.shown = false;
        }
    }

    void window_handler::swap_buffers()
    {
        if (_initialized)
        {
            glfwSwapBuffers(_window);

            glfwPollEvents();

            if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            {
                close_window(true);
            }
        }
    }

    void window_handler::create_window()
    {
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        glfwWindowHint(GLFW_RED_BITS, _primary_monitor_data.red_bits);
        glfwWindowHint(GLFW_GREEN_BITS, _primary_monitor_data.green_bits);
        glfwWindowHint(GLFW_BLUE_BITS, _primary_monitor_data.blue_bits);
        glfwWindowHint(GLFW_REFRESH_RATE, _primary_monitor_data.refresh_rate);

        bool fullscreen = _window_data.mode == window_mode::fullscreen;
        int width = fullscreen ? _primary_monitor_data.width : _window_data.width;
        int height = fullscreen ? _primary_monitor_data.height : _window_data.height;
        GLFWmonitor* monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

        _window = glfwCreateWindow(
            width,
            height,
            _window_data.title,
            monitor,
            nullptr);

        if (!_window)
        {
            throw jexcept::initialization_exception("Failed to create window");
        }
    }

    monitor_data window_handler::collect_monitor_data()
    {
        const GLFWvidmode* vid_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        monitor_data data;

        data.width = vid_mode->width;
        data.height = vid_mode->height;
        data.red_bits = vid_mode->redBits;
        data.green_bits = vid_mode->greenBits;
        data.blue_bits = vid_mode->blueBits;
        data.refresh_rate = vid_mode->refreshRate;

        return data;
    }

    const window_data& window_handler::get_window_data()           const { return _window_data; }
    const monitor_data& window_handler::get_primary_monitor_data() const { return _primary_monitor_data; }
    GLFWwindow* window_handler::get_window()                             { return _window; }
    bool window_handler::should_close()                            const { return _should_close; }

}