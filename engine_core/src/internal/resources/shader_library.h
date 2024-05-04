#ifndef JUMI_ENGINE_RESOURCES_SHADER_LIBRARY_H
#define JUMI_ENGINE_RESOURCES_SHADER_LIBRARY_H

#include "internal/renderer/shader.h"
#include <vector>

namespace jumi
{

    class shader_library
    {
    friend class resource_manager_impl;
    public:

    private:
        std::vector<shader> _shaders;

        void initialize_default_shaders();

        shader_library();
        ~shader_library();
        shader_library(const shader_library& other) = delete;
        shader_library& operator=(const shader_library& other) = delete;
        shader_library(shader_library&& other) = delete;
        shader_library& operator=(shader_library&& other) = delete;
    };

}

#endif
