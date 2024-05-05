#ifndef JUMI_ENGINE_CORE_ENGINE_CORE_H
#define JUMI_ENGINE_CORE_ENGINE_CORE_H

#include "engine_core/window/window_handler.h"
#include "engine_core/input/input_handler.h"
#include "engine_core/renderer/renderer.h"
#include "engine_core/resources/resource_manager.h"
#include <memory>

namespace jumi
{

    class glfw_callback_context;
    class timers;

    class engine_core
    {
    public:
        [[nodiscard]] static engine_core& instance();
        [[nodiscard]] window_handler& get_window();
        [[nodiscard]] input_handler& get_input();
        [[nodiscard]] renderer& get_renderer();
        [[nodiscard]] resource_manager& get_resource_manager();
        [[nodiscard]] double time() const;
        [[nodiscard]] bool should_quit() const;
        void quit();
        void new_frame();

    private:
        bool _should_quit;
        window_handler _window_handler;
        input_handler _input_handler;
        resource_manager _resource_manager;
        renderer _renderer;
        std::unique_ptr<glfw_callback_context> _glfw_callback_context;
        timers& _timers;

        void init_glfw() const;
        void init_glad() const;

        engine_core();
        ~engine_core();
        engine_core(const engine_core& other) = delete;
        engine_core& operator=(const engine_core& other) = delete;
        engine_core(const engine_core&& other) = delete;
        engine_core& operator=(const engine_core&& other) = delete;
    };

}

#endif
