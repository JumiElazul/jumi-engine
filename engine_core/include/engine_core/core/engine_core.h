#ifndef JUMI_ENGINE_ENGINE_CORE_CORE_ENGINE_CORE_H
#define JUMI_ENGINE_ENGINE_CORE_CORE_ENGINE_CORE_H

#include <memory>

namespace jumi
{
    class window_handler;
    class input_handler;
    class engine_callback_context;
    class i_renderer;

    class engine_core
    {
    public:
        static engine_core& instance();
        void run();

    private:
        std::unique_ptr<window_handler> _window_handler;
        std::unique_ptr<input_handler> _input_handler;
        std::unique_ptr<engine_callback_context> _callback_context;
        std::unique_ptr<i_renderer> _renderer;

        engine_core();
        ~engine_core();
        engine_core(const engine_core& other) = delete;
        engine_core& operator=(const engine_core& other) = delete;
        engine_core(engine_core&& other) = delete;
        engine_core& operator=(engine_core&& other) = delete;

        std::unique_ptr<i_renderer> create_renderer();
    };

}

#endif

