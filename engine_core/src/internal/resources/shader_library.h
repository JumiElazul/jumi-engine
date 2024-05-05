#ifndef JUMI_ENGINE_RESOURCES_SHADER_LIBRARY_H
#define JUMI_ENGINE_RESOURCES_SHADER_LIBRARY_H

#include "engine_core/renderer/shader.h"
#include "engine_core/renderer/shader.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace jumi
{

    class shader_library
    {
    friend class resource_manager_impl;
    public:
        std::shared_ptr<shader> get_shader(const std::string& shader_name) const;
        [[nodiscard]] const std::string& get_default_shader_name() const;

    private:
        void init();

        const std::string _shader_resource_path;
        const std::string _default_shader_name;
        std::unordered_map<std::string, std::shared_ptr<shader>> _shaders;

        void initialize_default_shaders();

        shader_library(const std::string& shader_resource_path);
        ~shader_library();
        shader_library(const shader_library& other) = delete;
        shader_library& operator=(const shader_library& other) = delete;
        shader_library(shader_library&& other) = delete;
        shader_library& operator=(shader_library&& other) = delete;
    };

}

#endif
