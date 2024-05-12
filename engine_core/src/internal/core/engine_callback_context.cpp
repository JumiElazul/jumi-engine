#include "internal/core/engine_callback_context.h"
#include "internal/core/backend.h"
#include "internal/window/window_handler.h"
#include "internal/input/input_handler.h"
#include "engine_core/core/logger.h"
#include <GLFW/glfw3.h>

namespace jumi
{

    engine_callback_context::engine_callback_context(window_handler& window_handler, input_handler& input_handler)
        : _window_handler(window_handler)
        , _input_handler(input_handler)
    {
        JUMI_INFO("Constructing engine_callback_context...");
    }

    engine_callback_context::~engine_callback_context()
    {
        JUMI_INFO("Destructing engine_callback_context...");
    }

    void engine_callback_context::init()
    {
        JUMI_INFO("Initializing engine_callback_context...");

        window_input_api window_api = backend::get_window_input_api();

        switch (window_api)
        {
            case window_input_api::glfw:
            {
                hookup_glfw_callbacks();
                break;
            }
        }

        _initialized = true;
    }

    void engine_callback_context::hookup_glfw_callbacks()
    {
        GLFWwindow* window = _window_handler.get_window();
        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, key_callback);
    }

    void engine_callback_context::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        const engine_callback_context* const ctx = static_cast<const engine_callback_context*>(glfwGetWindowUserPointer(window));
        ctx->_input_handler.key_callback(key, scancode, action, mods);
    }

}


