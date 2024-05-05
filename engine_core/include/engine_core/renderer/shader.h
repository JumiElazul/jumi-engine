#ifndef JUMI_ENGINE_RENDERER_SHADER_H
#define JUMI_ENGINE_RENDERER_SHADER_H

#include "engine_core/renderer/i_opengl_resource.h"
#include <string>

namespace jumi
{
    enum class shader_type
    {
        vertex,
        fragment,
    };

    class shader : public i_opengl_resource
    {
    public:
        shader(const std::string& shader_name);
        ~shader();
        shader(const shader& other) = delete;
        shader operator=(const shader& other) = delete;
        shader(shader&& other) noexcept;
        shader& operator=(shader&& other) noexcept;

        [[nodiscard]] const std::string& name() const;
        [[nodiscard]] const unsigned int& opengl_id() const;
        [[nodiscard]] bool shader_primed() const;
        [[nodiscard]] bool shader_linked() const;
        void bind() const;
        void unbind() const;

        void prime_shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
        void link_shader();

    private:
        std::string _shader_name;
        unsigned int _opengl_id;
        unsigned int _vertex_shader_id;
        unsigned int _fragment_shader_id;
        bool _shader_primed;
        bool _shader_linked;

        unsigned int compile_shader(const std::string& shader_source, shader_type type);

        virtual void release_opengl_resource() ;
    };

}

#endif
