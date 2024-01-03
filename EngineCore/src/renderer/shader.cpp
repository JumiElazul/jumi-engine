#include "EngineCore/renderer/shader.h"
#include "EngineCore/log/logger.h"
#include "EngineCore/core/core.h"
#include "EngineCore/math/vector.h"
#include "EngineCore/math/matrix.h"
#include "EngineCore/components/camera.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <glad/glad.h>

namespace jumi
{

	void BasicUniformStrategy::apply_uniforms(JUMI_UNUSED Shader& shader, JUMI_UNUSED const Camera& camera)
	{

	}

	Shader::Shader(const std::string& shader_name, const std::string& vertex_shader_path, const std::string& fragment_shader_path)
		: _shader_name(shader_name)
	{
		std::ifstream vertex_fs(vertex_shader_path);
		std::ifstream fragment_fs(fragment_shader_path);

		if (!vertex_fs || ! fragment_fs)
		{
            JUMI_PAUSE;
		}

		std::ostringstream vertex_ss;
		std::ostringstream fragment_ss;

		vertex_ss << vertex_fs.rdbuf();
		fragment_ss << fragment_fs.rdbuf();
		std::string vertex_string = vertex_ss.str();
		std::string fragment_string = fragment_ss.str();

		vertex_fs.close();
		fragment_fs.close();

		unsigned int vertex_id = compile_vertex_shader(vertex_string.c_str());
		unsigned int fragment_id = compile_fragment_shader(fragment_string.c_str());
		compile_shader_program(vertex_id, fragment_id);
	}

	// Private constructor
	Shader::Shader(const std::string& shader_name, const std::string& vertex_shader, const std::string& fragment_shader, ShaderSourceTag)
		: _shader_name(shader_name)
	{
		unsigned int vertex_id = compile_vertex_shader(vertex_shader.c_str());
		unsigned int fragment_id = compile_fragment_shader(fragment_shader.c_str());
		compile_shader_program(vertex_id, fragment_id);
	}

	Shader::~Shader()
	{
		glDeleteProgram(_shader_program_id);
	}

	Shader::Shader(Shader&& other) noexcept
		: _shader_name(other._shader_name), _shader_program_id(other._shader_program_id)
	{
		other._shader_name = "";
		other._shader_program_id = 0;
	}

	Shader& Shader::operator=(Shader&& other) noexcept
	{
		if (this != &other)
		{
			_shader_name = other._shader_name;
			_shader_program_id = other._shader_program_id;

			other._shader_name = "";
			other._shader_program_id = 0;
		}

		return *this;
	}

	const std::string& Shader::name() const { return _shader_name; }

    unsigned int Shader::get_shader_id() const { return _shader_program_id; }

	void Shader::bind_shader() const
	{
		glUseProgram(_shader_program_id);
	}

	void Shader::set_uniform_float(const char* uniform, float value) const
	{
		int32 location = get_uniform_location(uniform);
		glUniform1f(location, value);
	}

	void Shader::set_uniform_int(const char* uniform, int32 value) const
	{
		int32 location = get_uniform_location(uniform);
		glUniform1i(location, value);
	}

	void Shader::set_uniform_vec3(const char* uniform, const Vec3& value) const
	{
		int32 location = get_uniform_location(uniform);
		glUniform3f(location, value.x, value.y, value.z);
	}

	void Shader::set_uniform_mat4(const char* uniform, const Mat4& value) const
	{
		int32 location = get_uniform_location(uniform);
		glUniformMatrix4fv(location, 1, GL_FALSE, value.get_value_ptr());
	}

	void Shader::set_uniform_strategy(std::unique_ptr<IUniformStrategy> strategy)
	{
		_uniform_strategy = std::move(strategy);
	}

	void Shader::apply_uniforms(const Camera& camera)
	{
		if (_uniform_strategy)
		{
			_uniform_strategy->apply_uniforms(*this, camera);
		}
		JUMI_ERROR("_uniform_strategy is nullptr, apply_uniforms() could not be called");
	}

	int32 Shader::get_uniform_location(const char* uniform) const
	{
		int32 location = glGetUniformLocation(_shader_program_id, uniform);

		if (location < 0)
			JUMI_CRITICAL("Uniform {} on ShaderID {} doesn't exist", uniform, _shader_program_id);

		return location;
	}

	unsigned int Shader::compile_vertex_shader(const char* vertex_shader)
	{
		unsigned int vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader_id, 1, &vertex_shader, nullptr);
		glCompileShader(vertex_shader_id);

		int32 success;
		char buffer[512];
		glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertex_shader_id, 512, nullptr, buffer);
            JUMI_CRITICAL(buffer);
            JUMI_PAUSE;
		}

		return vertex_shader_id;
	}

	unsigned int Shader::compile_fragment_shader(const char* fragment_shader)
	{
		unsigned int fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader_id, 1, &fragment_shader, nullptr);
		glCompileShader(fragment_shader_id);

		int32 success;
		char buffer[512];
		glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &success);

		if (!success)
		{
            JUMI_CRITICAL(buffer);
			glGetShaderInfoLog(fragment_shader_id, 512, nullptr, buffer);
            JUMI_PAUSE;
		}

		return fragment_shader_id;
	}

	void Shader::compile_shader_program(unsigned int vertex_id, unsigned int fragment_id)
	{
		_shader_program_id = glCreateProgram();
		glAttachShader(_shader_program_id, vertex_id);
		glAttachShader(_shader_program_id, fragment_id);

		int32 success;
		char buffer[512];
		glLinkProgram(_shader_program_id);
		glGetProgramiv(_shader_program_id, GL_LINK_STATUS, &success);

		if (!success)
		{
            JUMI_CRITICAL(buffer);
			glGetProgramInfoLog(_shader_program_id, 512, NULL, buffer);
            JUMI_PAUSE;
		}

		glUseProgram(_shader_program_id);
		glDetachShader(_shader_program_id, vertex_id);
		glDetachShader(_shader_program_id, fragment_id);
		glDeleteShader(vertex_id);
		glDeleteShader(fragment_id);
		glUseProgram(0);
	}

	void Shader::unbind_shader()
	{
		glUseProgram(0);
	}

}
