#include "internal/resources/shader_library.h"
#include "internal/renderer/shader.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include <string>

namespace jumi
{

    shader_library::shader_library(const std::string& shader_resource_path)
        : _shader_resource_path(shader_resource_path)
        , _shaders()
    {
        JUMI_DEBUG("Initializing default shaders with _shader_resource_path {}...", _shader_resource_path);
        initialize_default_shaders();
    }

    shader_library::~shader_library()
    {

    }

    void shader_library::initialize_default_shaders()
    {
        shader shader;
        std::string default_vertex_shader_name = _shader_resource_path + "__DEFAULT_VERTEX__.vert";
        std::string default_fragment_shader_name = _shader_resource_path + "__DEFAULT_FRAGMENT__.frag";
        shader.prime_shader(default_vertex_shader_name, default_fragment_shader_name);
        if (!shader.shader_primed())
        {
            throw initialization_exception("Failed to prime default shaders.");
        }

        shader.link_shader();
        if (!shader.shader_linked())
        {
            throw initialization_exception("Failed to link default shaders.");
        }

        _shaders.push_back(std::move(shader));
    }

}
