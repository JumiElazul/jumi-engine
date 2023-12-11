#pragma once

#include "core/core.h"
#include <memory>
#include <string>

namespace jumi
{
	class Vec3;
	class Mat4;
	class Shader;
	class Camera;

	class IUniformStrategy
	{
	public:
        virtual ~IUniformStrategy() = default;
		virtual void apply_uniforms(Shader& shader, const Camera& camera) = 0;
	};

	class BasicUniformStrategy : public IUniformStrategy
	{
	public:
		virtual void apply_uniforms(Shader& shader, const Camera& camera) override;
	};
	
	struct ShaderSourceTag { }; 

	class JUMI_API Shader
	{
	friend class ResourceLibrary;

	public:
		Shader(const std::string& shader_name, const std::string& vertex_shader_path, const std::string& fragment_shader_path);
		~Shader();

		Shader(const Shader& shader) = delete;
		Shader& operator=(const Shader& shader) = delete;
		Shader(Shader&& other) noexcept;
		Shader& operator=(Shader&& other) noexcept;

		const std::string& name() const;
        unsigned int get_shader_id() const;
		void bind_shader() const;
		void set_uniform_float(const char* uniform, float value) const;
		void set_uniform_int(const char* uniform, int value) const;
		void set_uniform_vec3(const char* uniform, const Vec3& value) const;
		void set_uniform_mat4(const char* uniform, const Mat4& value) const;
		void set_uniform_strategy(std::unique_ptr<IUniformStrategy> strategy);
		void apply_uniforms(const Camera& camera);

		static void unbind_shader();

	private:
		std::string _shader_name;
		std::unique_ptr<IUniformStrategy> _uniform_strategy;
		unsigned int _shader_program_id = 0;

		Shader(const std::string& shader_name, const std::string& vertex_shader, const std::string& fragment_shader, ShaderSourceTag);

		int get_uniform_location(const char* uniform) const;

		unsigned int compile_vertex_shader(const char* vertexShader);
		unsigned int compile_fragment_shader(const char* fragmentShader);
		void compile_shader_program(unsigned int vertexID, unsigned int fragmentID);
	};

}
