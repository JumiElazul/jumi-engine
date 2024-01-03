#include "EngineCore/core/engine_core.h"
#include "EngineCore/core/core.h"
#include "EngineCore/logging/logger.h"
#include "EngineCore/input/keycodes.h"
#include "EngineCore/input/input_handler.h"
#include "EngineCore/renderer/renderer.h"
#include "EngineCore/window/window_handler.h"
#include <memory>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace jumi
{
	EngineCore::EngineCore() :
		_window_handler(std::make_unique<WindowHandler>()),
		_input_handler(std::make_unique<InputHandler>()),
		_renderer(std::make_unique<Renderer>()),
		_window_context(nullptr)
	{

	}

	EngineCore::~EngineCore() 
    {
        if (!_initialized)
        {
            JUMI_ERROR("Not calling glfwTerminate(), EngineCore was never initialized.  Destructor called.");
        }
        else
        {
            glfwTerminate();
        }
    }

	EngineCore& EngineCore::instance()
	{
		static EngineCore instance;
		return instance;
	}

    void EngineCore::init()
    {
        Logger::init();
        KeyCodeConverter::init();

        if (!init_glfw())
        {
            JUMI_INFO("GLFW initialization : FAILURE");
            throw initialization_exception("GLFW could not be intialized");
        }
        else
        {
            JUMI_INFO("GLFW initialization : SUCCESS");
        }

        if (!_window_context)
        {
            JUMI_WARN("WindowHandler being initialized without a WindowContext object - WindowContext default will be used");
            _window_handler->init({});
        }
        else
        {
            JUMI_INFO("WindowHandler being initialized with WindowContext object: {}", _window_context->to_string());
            _window_handler->init(*_window_context);
        }

        // Context needs to be current before intializing OpenGL or setting callbacks
        glfwMakeContextCurrent(_window_handler->get_window());

        if (!init_opengl())
        {
            JUMI_INFO("glad initialization : FAILURE");
            throw initialization_exception("GLAD could not be intialized");
        }
        else
        {
            JUMI_INFO("glad initialization : SUCCESS");
        }

        // This needs to be created after glfw is initialized, which is why its not in the EngineCore initializer list
		_window_user_pointer = std::make_unique<WindowUserPointer>(*_window_handler.get(), *_input_handler.get(), *_renderer.get());
		glfwSetWindowUserPointer(_window_handler->get_window(), _window_user_pointer.get());

        _initialized = true;
    }

    bool EngineCore::init_opengl()
	{
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            JUMI_CRITICAL("glad loading proc addresses : FAILURE");
            return false;
        }
        else
        {
            JUMI_CRITICAL("glad loading proc addresses : SUCCESS");
        }

		const WindowContext& context = _window_handler->get_window_context();

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_MULTISAMPLE);  
		glViewport(0, 0, context.width, context.height);

		glDebugMessageCallback(gl_debug_msg_callback, nullptr);

		return true;
	}

	void EngineCore::set_window_context(int32 width, int32 height, const char* title, bool v_sync, bool fullscreen)
	{
		_window_context = std::make_unique<WindowContext>(width, height, title, v_sync, fullscreen);
	}

    double EngineCore::get_time() const { return glfwGetTime(); }
    double EngineCore::get_deltatime() const { return _deltatime; }

	WindowHandler& EngineCore::get_window()
	{
		if (!_initialized)
		{
			JUMI_ERROR("WindowHandler cannot be retrieved until EngineCore is initialized - please call Jumi::EngineCore::Initialize()");
            JUMI_PAUSE;
		}

		return *_window_handler.get();
	}

	InputHandler& EngineCore::get_input()
	{
		if (!_initialized)
        {
			JUMI_ERROR("InputHandler cannot be retrieved until EngineCore is initialized - please call Jumi::EngineCore::Initialize()");
            JUMI_PAUSE;
        }

		return *_input_handler.get();
	}

	Renderer& EngineCore::get_renderer()
	{
		if (!_initialized)
        {
			JUMI_ERROR("Renderer cannot be retrieved until EngineCore is initialized - please call Jumi::EngineCore::Initialize()");
            JUMI_PAUSE;
        }

		return *_renderer.get();
	}

	bool EngineCore::init_glfw()
	{
		if (!glfwInit())
		{
			JUMI_CRITICAL("GLFW could not be initialized");
			return false;
		}

		return true;
	}

    void* EngineCore::get_window_user_pointer() { return glfwGetWindowUserPointer(_window_handler->get_window()); }

    void EngineCore::calculate_deltatime()
    {
        double current_frame_time = get_time();
        _deltatime = current_frame_time - _last_frame_time;
        _last_frame_time = current_frame_time;
    }


	// Window User Pointer ----------------------------------------
	WindowUserPointer::WindowUserPointer(WindowHandler& window_handler, InputHandler& input_handler, Renderer& renderer)
		: _window_handler(window_handler), _input_handler(input_handler), _renderer(renderer)
	{ 
		configure_callbacks();
	}

	WindowUserPointer::~WindowUserPointer() { } 

	WindowHandler& WindowUserPointer::get_window_handler() const { return _window_handler; }
	InputHandler& WindowUserPointer::get_input_handler() const { return _input_handler; }
	Renderer& WindowUserPointer::get_renderer() const { return _renderer; }

	void WindowUserPointer::configure_callbacks() const
	{
		GLFWwindow* window = _window_handler.get_window();

		glfwSetErrorCallback(glfw_error_callback);
		glfwSetKeyCallback(window, glfw_key_callback);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        //glfwSetErrorCallback();
		//glfwSetMouseButtonCallback(window, MouseButtonCallback);
		//glfwSetWindowFocusCallback(window, WindowFocusCallback);
		//glfwSetScrollCallback(window, ScrollCallback);
		//glfwSetWindowCloseCallback(window, WindowCloseCallback);
		//glfwSetCursorPosCallback(window, CursorPosCallback);
		//glfwSetWindowFocusCallback(window, WindowFocusCallback);
		//glfwSetWindowSizeCallback(window, WindowSizeCallback);
		//glfwSetCharCallback(window, );
		//glfwSetCharModsCallback(window, );
		//glfwSetCursorEnterCallback(window, );
		//glfwSetDropCallback(window, );
		//glfwSetJoystickCallback(window, );
		//glfwSetMonitorCallback(window, );
		//glfwSetWindowContentScaleCallback(window, );
		//glfwSetWindowIconifyCallback(window, );
		//glfwSetWindowMaximizeCallback(window, );
		//glfwSetWindowPosCallback(window, );
		//glfwSetWindowRefreshCallback(window, );
	}

	void WindowUserPointer::glfw_error_callback(int err_code, const char* description)
	{
		JUMI_ERROR("[err_code: {}] {}", err_code, description);
	}

	void WindowUserPointer::glfw_key_callback(GLFWwindow* window, int key, JUMI_UNUSED int scancode, int action, JUMI_UNUSED int mods)
	{
		// Convert the incoming glfw keycode to our custom engine keycodes
		JUMI_KEYCODE keycode = KeyCodeConverter::glfw_to_jumi_keycode(key);
		JUMI_KEYACTION keyaction = KeyCodeConverter::glfw_to_jumi_keyaction(action);
		WindowUserPointer* window_user_pointer = static_cast<WindowUserPointer*>(glfwGetWindowUserPointer(window));

		// TODO: Maybe handle the other parameters like action/mods
		window_user_pointer->get_input_handler().on_key_pressed(keycode, keyaction);
	}

    void WindowUserPointer::framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        WindowUserPointer* window_user_pointer = static_cast<WindowUserPointer*>(glfwGetWindowUserPointer(window));
        window_user_pointer->get_renderer().on_framebuffer_size_changed(window, width, height);
    }

    void EngineCore::gl_debug_msg_callback(unsigned int source, unsigned int type, unsigned int id, unsigned int severity,
            JUMI_UNUSED int length, const char* message, JUMI_UNUSED const void* user_param)
	{
		std::string _source;
		std::string _type;
		std::string _severity;

		switch (source) 
		{
            case GL_DEBUG_SOURCE_API:
            {
                _source = "API";
                break;
            }
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            {
                _source = "WINDOW SYSTEM";
                break;
            }
            case GL_DEBUG_SOURCE_SHADER_COMPILER:
            {
                _source = "SHADER COMPILER";
                break;
            }
            case GL_DEBUG_SOURCE_THIRD_PARTY:
            {
                _source = "THIRD PARTY";
                break;
            }
            case GL_DEBUG_SOURCE_APPLICATION:
            {
                _source = "APPLICATION";
                break;
            }
            case GL_DEBUG_SOURCE_OTHER:
            {
                _source = "UNKNOWN";
                break;
            }
            default:
            {
                _source = "DEFAULT";
                break;
            }
		}

		switch (type)
		{
            case GL_DEBUG_TYPE_ERROR:
            {
                _type = "ERROR";
                break;
            }
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            {
                _type = "DEPRECATED BEHAVIOR";
                break;
            }
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            {
                _type = "UNDEFINED BEHAVIOR";
                break;
            }
            case GL_DEBUG_TYPE_PORTABILITY:
            {
                _type = "PORTABILITY";
                break;
            }
            case GL_DEBUG_TYPE_PERFORMANCE:
            {
                _type = "PERFORMANCE";
                break;
            }
            case GL_DEBUG_TYPE_OTHER:
            {
                _type = "OTHER";
                break;
            }
            case GL_DEBUG_TYPE_MARKER:
            {
                _type = "MARKER";
                break;
            }
            default:
            {
                _type = "UNKNOWN";
                break;
            }
		}

		switch (severity) 
		{
            case GL_DEBUG_SEVERITY_HIGH:
            {
                _severity = "HIGH";
                break;
            }
            case GL_DEBUG_SEVERITY_MEDIUM:
            {
                _severity = "MEDIUM";
                break;
            }
            case GL_DEBUG_SEVERITY_LOW:
            {
                _severity = "LOW";
                break;
            }
            case GL_DEBUG_SEVERITY_NOTIFICATION:
            {
                _severity = "NOTIFICATION";
                break;
            }
            default:
            {
                _severity = "UNKNOWN";
                break;
            }
		}

		JUMI_CRITICAL("[OpenGLDebugCallback] [{}, {}, {}, {}]:  {}", id, _source, _severity, _type, message);
	}

}
