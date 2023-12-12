#pragma once

#include "core/core.h"
#include <memory>

struct GLFWwindow;

namespace jumi
{
	struct WindowContext;
	class InputHandler;
	class Renderer;
	class WindowHandler;
	class ResourceLibrary;

	class WindowUserPointer
	{
	public:
		WindowUserPointer(WindowHandler& windowHandler, InputHandler& inputHandler);
		~WindowUserPointer();

		WindowHandler& get_window_handler() const;
		InputHandler& get_input_handler() const;

		void configure_callbacks() const;

	private:
		WindowHandler& _window_handler;
		InputHandler& _input_handler;

		static void glfw_error_callback(int errorCode, const char* description);
		static void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};


	class JUMI_API EngineCore
	{
	public:
		static EngineCore& instance();

		void init();
		void set_window_context(int width, int height, const char* title, bool vSync = false, bool fullscreen = false);
		double get_time() const;
		WindowHandler& get_window();
		InputHandler& get_input();
		Renderer& get_renderer();

	private:
		EngineCore();
		~EngineCore();
		EngineCore(const EngineCore& other) = delete;
		EngineCore operator=(const EngineCore& other) = delete;
		EngineCore(EngineCore&& other) = delete;
		EngineCore operator=(EngineCore&& other) = delete;

		bool _initialized = false;
		std::unique_ptr<WindowHandler> _window_handler;
		std::unique_ptr<InputHandler> _input_handler;
		std::unique_ptr<Renderer> _renderer;
		std::unique_ptr<WindowUserPointer> _window_user_pointer;
		std::unique_ptr<WindowContext> _window_context;

		bool init_glfw();
		bool init_opengl();
		void* get_window_user_pointer();

		static void gl_debug_msg_callback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity,
			int length, const char* message, const void* user_param);
	};

}
