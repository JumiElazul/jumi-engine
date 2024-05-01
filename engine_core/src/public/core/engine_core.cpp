#include "engine_core/core/engine_core.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"

namespace jumi
{

    engine_core::engine_core()
        : _window_handler(1920, 1080)
    {
        logger::init();
        logger::print_debug_log_info();

        JUMI_TRACE("Initializing engine_core");
    }

    engine_core::~engine_core()
    {

    }

    engine_core& engine_core::instance()
    {
        static engine_core instance;
        return instance;
    }

    window_handler& engine_core::window()
    {
        return _window_handler;
    }

}
