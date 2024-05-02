#ifndef JUMI_ENGINE_CORE_CALLBACK_CONTEXT_H
#define JUMI_ENGINE_CORE_CALLBACK_CONTEXT_H

struct GLFWwindow;

namespace jumi
{
    class window_handler;
    class input_handler;

    class glfw_callback_context
    {
    friend class engine_core;
    public:
        glfw_callback_context(window_handler& window_handler, input_handler& input_handler);
        ~glfw_callback_context() = default;

        void hookup_callbacks(GLFWwindow* window);

    private:
        window_handler& _window_handler;
        input_handler& _input_handler;

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void window_position_callback(GLFWwindow* window, int xpos, int ypos);
        static void window_size_callback(GLFWwindow* window, int width, int height);

        glfw_callback_context(const glfw_callback_context& other) = delete;
        glfw_callback_context operator=(const glfw_callback_context& other) = delete;
        glfw_callback_context(glfw_callback_context&& other) = delete;
        glfw_callback_context operator=(glfw_callback_context&& other) = delete;
    };

}

#endif
