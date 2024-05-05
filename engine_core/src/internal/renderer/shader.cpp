#include "internal/renderer/shader.h"
#include "engine_core/core/logger.h"
#include "engine_core/utility/utility.h"
#include <glad/glad.h>
#include <string>

namespace jumi
{

    shader::shader(const std::string& shader_name)
        : _shader_name(shader_name)
        , _opengl_id()
        , _vertex_shader_id()
        , _fragment_shader_id()
        , _shader_primed(false)
        , _shader_linked(false)
    {

    }

    shader::~shader()
    {
        release_opengl_resource();
    }

    shader::shader(shader&& other) noexcept
        : _opengl_id(other._opengl_id)
        , _vertex_shader_id(other._vertex_shader_id)
        , _fragment_shader_id(other._vertex_shader_id)
        , _shader_primed(other._shader_primed)
        , _shader_linked(other._shader_linked)
    {
        other._opengl_id = 0;
        other._vertex_shader_id = 0;
        other._fragment_shader_id = 0;
        other._shader_primed = false;
        other._shader_linked = false;
    }

    shader& shader::operator=(shader&& other) noexcept
    {
        if (this != &other)
        {
            _opengl_id = other._opengl_id;
            _vertex_shader_id = other._vertex_shader_id;
            _fragment_shader_id = other._vertex_shader_id;
            _shader_primed = other._shader_primed;
            _shader_linked = other._shader_linked;

            other._opengl_id = 0;
            other._vertex_shader_id = 0;
            other._fragment_shader_id = 0;
            other._shader_primed = false;
            other._shader_linked = false;
        }

        return *this;
    }

    const std::string& shader::name() const
    {
        return _shader_name;
    }

    const unsigned int& shader::opengl_id() const
    {
        return _opengl_id;
    }

    bool shader::shader_primed() const
    {
        return _shader_primed;
    }

    bool shader::shader_linked() const
    {
        return _shader_linked;
    }

    void shader::prime_shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path)
    {
        if (_shader_linked)
        {
            JUMI_INFO("Shader with _opengl_id {} cannot be primed again, shader program is already linked", _opengl_id);
            return;
        }

        std::fstream vertex_file;
        std::fstream fragment_file;

        try
        {
            vertex_file = utility::open_file(vertex_shader_path);
            fragment_file = utility::open_file(fragment_shader_path);
        }
        catch (const std::runtime_error& e)
        {
            JUMI_ERROR(e.what());
        }

        std::string vertex_shader = utility::stringify_file(vertex_file);
        std::string fragment_shader = utility::stringify_file(fragment_file);

        _vertex_shader_id = compile_shader(vertex_shader, shader_type::vertex);
        if (_vertex_shader_id == 0)
        {
            JUMI_ERROR("Vertex shader could not be compiled");
            return;
        }

        _fragment_shader_id = compile_shader(fragment_shader, shader_type::fragment);
        if (_fragment_shader_id == 0)
        {
            glDeleteShader(_vertex_shader_id);
            _vertex_shader_id = 0;
            JUMI_ERROR("Fragment shader could not be compiled");
            return;
        }

        _shader_primed = true;
    }

    void shader::link_shader()
    {
        if (!_shader_primed)
        {
            JUMI_INFO("Shader with vertex id {} and fragment id {} cannot be linked as it is not properly primed - please call prime_shader()");
            return;
        }
        else if (_shader_linked)
        {
            JUMI_INFO("Shader with id {} is already linked and cannot be relinked");
            return;
        }

        _opengl_id = glCreateProgram();
        glAttachShader(_opengl_id, _vertex_shader_id);
        glAttachShader(_opengl_id, _fragment_shader_id);
        glLinkProgram(_opengl_id);

        int success;
        char info_log[512];
        glGetProgramiv(_opengl_id, GL_LINK_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(_opengl_id, 512, nullptr, info_log);
            glDeleteShader(_vertex_shader_id);
            glDeleteShader(_fragment_shader_id);
            JUMI_CRITICAL("ERROR - Shader program linking failed\nMessage: [ {} ]", info_log);
            return;
        }

        _vertex_shader_id = 0;
        _fragment_shader_id = 0;
        _shader_linked = true;
    }

    void shader::bind() const
    {
        if (!_shader_linked)
        {
            JUMI_ERROR("Shader cannot be bound, it is not properly linked");
        }

        glUseProgram(_opengl_id);
    }

    void shader::unbind() const
    {
        glUseProgram(0);
    }

    unsigned int shader::compile_shader(const std::string& shader_source, shader_type type)
    {
        unsigned int shader_id;

        switch (type)
        {
            case shader_type::vertex: 
            {
                shader_id = glCreateShader(GL_VERTEX_SHADER);
                break;
            }
            case shader_type::fragment: 
            {
                shader_id = glCreateShader(GL_FRAGMENT_SHADER);
                break;
            }
        }

        const char* shader_src = shader_source.c_str();
        glShaderSource(shader_id, 1, &shader_src, nullptr);
        glCompileShader(shader_id);

        int success;
        char info_log[512];
        glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader_id, 512, nullptr, info_log);
            std::string shader_type_str = (type == shader_type::fragment) ? "Fragment" : "Vertex";
            JUMI_CRITICAL("ERROR - {} Shader compilation failed\nMessage: [ {} ]", shader_type_str, info_log);
            return 0;
        }

        return shader_id;
    }

    void shader::release_opengl_resource()
    {
        if (_opengl_id != 0)
        {
            glDeleteProgram(_opengl_id);
        }
    }

}
