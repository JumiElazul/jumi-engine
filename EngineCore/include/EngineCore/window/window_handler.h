#pragma once

#include "EngineCore/core/core.h"
#include <string>

struct GLFWwindow;

namespace jumi
{
	struct WindowContext
	{
		int32 width = 1280;
		int32 height = 720;
		const char* title = "DefaultWindow";
		bool v_sync = false;
		bool fullscreen = false;

		std::string to_string();
	};

	struct MonitorContext
	{
		int32 width = 0;
		int32 height = 0;
		int32 red_bits = 0;
		int32 green_bits = 0;
		int32 blue_bits = 0;
		int32 refresh_rate = 0;

		std::string to_string();
	};

	class WindowHandler
	{
	public:
		WindowHandler();
		~WindowHandler();

		bool init(const WindowContext& window_context);
		bool is_initialized() const;

		void swap_buffers();
		bool should_close() const;
		void close_window();
		void shutdown();
		void show_window() const;
		GLFWwindow* get_window() const;
		void change_resolution(int32 width, int32 height);
		void set_fullscreen(bool fullscreen);
		const WindowContext& get_window_context() const;
		const MonitorContext& get_monitor_context() const;

	private:
		GLFWwindow* _window;
		MonitorContext _monitor_context;
		WindowContext _window_context;
		bool _should_close = false;
		bool _initialized = false;

		void set_glfw_window_hints();
		bool get_monitor_context();
		bool setup_glfw_window();
	};

}


