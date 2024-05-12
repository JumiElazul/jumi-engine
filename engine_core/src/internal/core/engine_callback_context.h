#ifndef JUMI_ENGINE_ENGINE_CORE_INTERNAL_ENGINE_CALLBACK_CONTEXT_H
#define JUMI_ENGINE_ENGINE_CORE_INTERNAL_ENGINE_CALLBACK_CONTEXT_H

#include "internal/interfaces/i_requires_init.h"

struct GLFWwindow;

namespace jumi
{
    class window_handler;
    class input_handler;

    class engine_callback_context : public i_requires_init
    {
    public:
        engine_callback_context(window_handler& window_handler, input_handler& input_handler);
        ~engine_callback_context();

        virtual void init() override;

    private:
        window_handler& _window_handler;
        input_handler& _input_handler;
        void hookup_glfw_callbacks();

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };

}

#endif
