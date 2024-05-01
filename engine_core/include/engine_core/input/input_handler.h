#ifndef JUMI_ENGINE_INPUT_INPUT_HANDLER_H
#define JUMI_ENGINE_INPUT_INPUT_HANDLER_H

#include "engine_core/input/input_handler.h"

struct GLFWwindow;

namespace jumi
{

    class input_handler
    {
    friend class engine_core;
    friend class glfw_callback_context;
    public:
        void poll_inputs() const;

    private:

        input_handler(GLFWwindow* window);
        ~input_handler();
        input_handler(const input_handler& other) = delete;
        input_handler& operator=(const input_handler& other) = delete;
        input_handler(const input_handler&& other) = delete;
        input_handler& operator=(const input_handler&& other) = delete;

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

}

#endif
