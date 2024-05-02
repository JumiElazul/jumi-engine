#include "internal/core/glfw_callback_context.h"
#include "engine_core/window/window_handler.h"
#include "engine_core/input/input_handler.h"
#include "engine_core/renderer/renderer.h"
#include "engine_core/core/logger.h"
#include <glfw/glfw3.h>

namespace jumi
{

    glfw_callback_context::glfw_callback_context(window_handler& window_handler, input_handler& input_handler, renderer& renderer)
        : _window_handler(window_handler)
        , _input_handler(input_handler)
        , _renderer(renderer)
    {

    }

    void glfw_callback_context::hookup_callbacks(GLFWwindow* window)
    {
        JUMI_INFO("Hooking up glfw callbacks...");
        glfwSetWindowUserPointer(window, this);

        glfwSetKeyCallback(window, key_callback);
        glfwSetWindowPosCallback(window, window_position_callback);
        glfwSetWindowSizeCallback(window, window_size_callback);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    }

    void glfw_callback_context::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        const glfw_callback_context* ctx = static_cast<const glfw_callback_context*>(glfwGetWindowUserPointer(window));
        ctx->_input_handler.key_callback(key, scancode, action, mods);
    }

    void glfw_callback_context::window_position_callback(GLFWwindow* window, int xpos, int ypos)
    {
        const glfw_callback_context* ctx = static_cast<const glfw_callback_context*>(glfwGetWindowUserPointer(window));
        ctx->_window_handler.window_position_callback(xpos, ypos);
    }

    void glfw_callback_context::window_size_callback(GLFWwindow* window, int width, int height)
    {
        const glfw_callback_context* ctx = static_cast<const glfw_callback_context*>(glfwGetWindowUserPointer(window));
        ctx->_window_handler.window_size_callback(width, height);
    }

    void glfw_callback_context::framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        const glfw_callback_context* ctx = static_cast<const glfw_callback_context*>(glfwGetWindowUserPointer(window));
        ctx->_renderer.framebuffer_size_callback(width, height);
    }
}
