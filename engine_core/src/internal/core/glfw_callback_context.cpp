#include "internal/core/glfw_callback_context.h"
#include "engine_core/core/logger.h"
#include <glfw/glfw3.h>

namespace jumi
{

    glfw_callback_context::glfw_callback_context(window_handler& window_handler, input_handler& input_handler)
        : _window_handler(window_handler)
        , _input_handler(input_handler)
    {

    }

    void glfw_callback_context::hookup_callbacks(GLFWwindow* window)
    {
        JUMI_DEBUG("Hooking up glfw callbacks...");
        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, key_callback);
    }

    void glfw_callback_context::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        const glfw_callback_context* ctx = static_cast<const glfw_callback_context*>(glfwGetWindowUserPointer(window));
        ctx->_input_handler.key_callback(key, scancode, action, mods);
    }

}
