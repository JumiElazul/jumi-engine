#ifndef JUMI_ENGINE_CORE_ENGINE_CORE_H
#define JUMI_ENGINE_CORE_ENGINE_CORE_H

#include "engine_core/window/window_handler.h"
#include "engine_core/input/input_handler.h"
#include "engine_core/renderer/renderer.h"
#include <memory>

namespace jumi
{

    class glfw_callback_context;

    class engine_core
    {
    public:
        static engine_core& instance();
        window_handler& window();
        input_handler& input();
        double time() const;
        bool should_quit() const;
        void quit();
        void new_frame();

    private:
        bool _should_quit;
        window_handler _window_handler;
        input_handler _input_handler;
        renderer _renderer;
        std::unique_ptr<glfw_callback_context> _glfw_callback_context;

        engine_core();
        ~engine_core();
        engine_core(const engine_core& other) = delete;
        engine_core& operator=(const engine_core& other) = delete;
        engine_core(const engine_core&& other) = delete;
        engine_core& operator=(const engine_core&& other) = delete;
    };

}

#endif
