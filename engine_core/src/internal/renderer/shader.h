#ifndef JUMI_ENGINE_RENDERER_SHADER_H
#define JUMI_ENGINE_RENDERER_SHADER_H

#include "internal/renderer/i_opengl_resource.h"
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
        shader();
        ~shader();
        shader(const shader& other) = delete;
        shader operator=(const shader& other) = delete;
        shader(shader&& other) noexcept;
        shader& operator=(shader&& other) noexcept;

        [[no_discard]] const unsigned int& opengl_id() const;
        void prime_shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
        void link_shader();
        void bind() const;
        static void unbind();

    private:
        unsigned int _opengl_id;
        unsigned int _vertex_shader_id;
        unsigned int _fragment_shader_id;
        bool _shader_primed;
        bool _shader_linked;

        unsigned int compile_shader(const std::string& shader_source, shader_type type);

        virtual void release_opengl_resource() override;
    };

}

#endif
