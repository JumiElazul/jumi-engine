#include "engine_core/core/engine_core.h"

namespace jumi
{

    int entry_point(int argc, char** argv)
    {
        engine_core& core = engine_core::instance();

        return 0;
    }

}

int main()
{
    return jumi::entry_point(0, nullptr);
}