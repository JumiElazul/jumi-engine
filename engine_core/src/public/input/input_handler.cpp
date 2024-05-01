#include "engine_core/input/input_handler.h"
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

}
