#include "engine_core/input/input_handler.h"
#include "engine_core/input/keycodes.h"
#include <glfw/glfw3.h>
#include <fmt/format.h>

namespace jumi
{
    input_handler::input_handler(GLFWwindow* window)
    {

    }

    input_handler::~input_handler()
    {

    }

    void input_handler::poll_inputs() const
    {
        glfwPollEvents();
    }

    void input_handler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {

    }

}
