#include "internal/resources/shader_library.h"
#include "engine_core/core/logger.h"

namespace jumi
{

    shader_library::shader_library()
        : _shaders()
    {

    }

    shader_library::~shader_library()
    {

    }

    void shader_library::initialize_default_shaders()
    {
        JUMI_DEBUG("Initializing default shaders...");
    }

}
