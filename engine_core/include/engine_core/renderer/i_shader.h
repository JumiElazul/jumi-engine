#ifndef JUMI_ENGINE_RENDERER_I_SHADER_H
#define JUMI_ENGINE_RENDERER_I_SHADER_H

#include <string>

namespace jumi
{

    class i_shader
    {
    public:
        virtual ~i_shader() = default;
        virtual const std::string& name() const = 0;
        virtual const unsigned int& opengl_id() const = 0;
        virtual bool shader_primed() const = 0;
        virtual bool shader_linked() const = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual void prime_shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path) = 0;
        virtual void link_shader() = 0;
    };

}

#endif