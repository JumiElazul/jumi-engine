#include "internal/resources/shader_library.h"
#include "internal/renderer/shader.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include "engine_core/renderer/i_shader.h"
#include <memory>
#include <string>
#include <stdexcept>

namespace jumi
{

    shader_library::shader_library(const std::string& shader_resource_path)
        : _shader_resource_path(shader_resource_path)
        , _default_shader_name("__DEFAULT_SHADER__")
        , _shaders()
    {
        JUMI_DEBUG("Initializing shader_library...");
        JUMI_DEBUG("Initializing default shaders with _shader_resource_path {}...", _shader_resource_path);
    }

    shader_library::~shader_library()
    {
        JUMI_DEBUG("Destructing shader_library...");
    }

    std::shared_ptr<i_shader> shader_library::get_shader(const std::string& shader_name) const
    {
        try
        {
            return _shaders.at(shader_name);
        }
        catch (const std::out_of_range& e)
        {
            JUMI_INFO("Shader with name {} not found: [{}]", shader_name, e.what());
            return nullptr;
        }
    }

    const std::string& shader_library::get_default_shader_name() const
    {
        return _default_shader_name;
    }

    void shader_library::init()
    {
        initialize_default_shaders();
    }

    void shader_library::initialize_default_shaders()
    {
        std::shared_ptr<i_shader> default_shader = std::make_shared<shader>(_default_shader_name);
        std::string default_vertex_shader_name = _shader_resource_path + "__DEFAULT_VERTEX__.vert";
        std::string default_fragment_shader_name = _shader_resource_path + "__DEFAULT_FRAGMENT__.frag";
        default_shader->prime_shader(default_vertex_shader_name, default_fragment_shader_name);
        if (!default_shader->shader_primed())
        {
            throw initialization_exception("Failed to prime default shaders.");
        }

        default_shader->link_shader();
        if (!default_shader->shader_linked())
        {
            throw initialization_exception("Failed to link default shaders.");
        }

        _shaders[default_shader->name()] = default_shader;
    }

}
