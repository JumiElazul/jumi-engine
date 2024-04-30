#ifndef JUMI_ENGINE_CORE_ENGINE_CORE_H
#define JUMI_ENGINE_CORE_ENGINE_CORE_H

#include "engine_core/window/window_handler.h"

namespace jumi
{

    class engine_core
    {
    public:
        static engine_core& instance();
        window_handler& window();

    private:
        window_handler _window_handler;

        engine_core();
        ~engine_core();
        engine_core(const engine_core& other) = delete;
        engine_core& operator=(const engine_core& other) = delete;
        engine_core(const engine_core&& other) = delete;
        engine_core& operator=(const engine_core&& other) = delete;
    };

}

#endif
