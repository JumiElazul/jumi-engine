#include "window/window_handler.h"
#include "logging/logger.h"
#include "core/core.h"
#include <GLFW/glfw3.h>
#include <sstream>

namespace jumi
{

	std::string WindowContext::to_string()
	{
		std::stringstream ss;

		ss << "[Width: " << width <<
			" Height: " << height <<
			" Title: " << title <<
			" Vsync: " << std::boolalpha << v_sync <<
			" Fullscreen: " << fullscreen << "]" <<
			std::noboolalpha;

		return ss.str();
	}

	std::string MonitorContext::to_string()
	{
		std::stringstream ss;

		ss << "[Width: " << width <<
			" Height: " << height <<
			" Redbits: " << red_bits <<
			" Bluebits: " << blue_bits <<
			" Greenbits: " << green_bits <<
			" RefreshRate: " << refresh_rate << "]";

		return ss.str();
	}

	WindowHandler::WindowHandler() { }

	WindowHandler::~WindowHandler() 
    {
        if (_window)
        {
            JUMI_INFO("WindowHandler destructor called: destroying window");
            glfwDestroyWindow(_window);
        }
    }

	bool WindowHandler::init(const WindowContext& window_context)
	{
		_window_context = window_context;

		set_glfw_window_hints();

		if (!setup_glfw_window())
		{
			throw initialization_exception("GLFW window could not be created");
		}

        if (!get_monitor_context())
		{
			throw initialization_exception("Monitor Context could not be retrieved");
		}

		// Enable raw mouse motion if supported
		int rawmouse_supported = glfwRawMouseMotionSupported();
		if (rawmouse_supported)
		{
			glfwSetInputMode(_window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
		}

		_initialized = true;
		return true;
	}

	bool WindowHandler::is_initialized() const { return _initialized; }

	void WindowHandler::swap_buffers()
	{
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}

	bool WindowHandler::should_close() const { return glfwWindowShouldClose(_window); }

	void WindowHandler::close_window() { glfwSetWindowShouldClose(_window, true); }

    void WindowHandler::shutdown() { }

    void WindowHandler::show_window() const { glfwShowWindow(_window); }

	GLFWwindow* WindowHandler::get_window() const { return _window; }

	void WindowHandler::change_resolution(int width, int height)
	{
		_window_context.width = width;
		_window_context.height = height;
		glfwSetWindowSize(_window, width, height);
	}

	void WindowHandler::set_fullscreen(bool fullscreen)
	{
		_window_context.fullscreen = fullscreen;

		if (fullscreen)
		{
			glfwSetWindowMonitor(_window, glfwGetPrimaryMonitor(), 0, 0, _window_context.width, _window_context.height, _monitor_context.refresh_rate);
		}
		else
		{
			glfwSetWindowMonitor(_window, nullptr, 0, 0, _window_context.width, _window_context.height, _monitor_context.refresh_rate);
		}
	}

	const WindowContext& WindowHandler::get_window_context() const { return _window_context; }
	const MonitorContext& WindowHandler::get_monitor_context() const { return _monitor_context; }

	void WindowHandler::set_glfw_window_hints()
	{
        // Currently we are setting the OpenGL version to 4.2 since WSL uses Mesa which by default only supports up
        // to Open GL version 4.2.  We can add support for higher versions later if necessary.
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 4);
	}

	bool WindowHandler::get_monitor_context()
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();

		if (!monitor)
		{
			return false;
		}

		const GLFWvidmode* video_mode = glfwGetVideoMode(monitor);
		_monitor_context.width = video_mode->width;
		_monitor_context.height = video_mode->height;
		_monitor_context.red_bits = video_mode->redBits;
		_monitor_context.blue_bits = video_mode->blueBits;
		_monitor_context.green_bits = video_mode->greenBits;
		_monitor_context.refresh_rate = video_mode->refreshRate;

		return true;
	}

	bool WindowHandler::setup_glfw_window()
	{
		_window = glfwCreateWindow(_window_context.width, _window_context.height, _window_context.title, nullptr, nullptr);
		_window_context.v_sync ? glfwSwapInterval(1) : glfwSwapInterval(0);

		if (!_window)
		{
			return false;
		}

		return true;
	}

}

