#include "engine_core/core/engine_core.h"
#include "engine_core/core/logger.h"

namespace jumi
{

    int entry_point(int argc, char** argv)
    {
        engine_core& core = engine_core::instance();
        JUMI_TRACE("Entry point...");

        return 0;
    }

}

int main()
{
    return jumi::entry_point(0, nullptr);
}