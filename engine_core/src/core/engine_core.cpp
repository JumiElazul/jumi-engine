#include "engine_core/core/engine_core.h"
#include "internal/backend.h"

namespace jumi
{

    engine_core& engine_core::instance()
    {
        static engine_core instance;
        return instance;
    }

    engine_core::engine_core()
    {
        backend::init(window_input_api::glfw, rendering_api::open_gl);
    }

    engine_core::~engine_core()
    {
        backend::cleanup();
    }

}