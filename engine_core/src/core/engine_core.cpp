#include <engine_core/core/engine_core.h>
#include <stdio.h>

namespace jumi
{

    engine_core& engine_core::instance()
    {
        static engine_core instance;
        return instance;
    }

    void engine_core::print(const char* str) const
    {
        printf("%s\n", str);
    }

}