#pragma once

#include "core/core.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace jumi
{

	class Mesh;
	class Shader;

	extern const float s_cube_vertices[];
	extern const unsigned int s_cube_indices[];
	extern const size_t s_cube_vertices_size;
	extern const size_t s_cube_indices_size;

	enum MeshType
	{
		Cube,
		Sphere,
		Diamond,
		Plane,
	};

	class JUMI_API ResourceLibrary
	{
	public:
		static std::shared_ptr<Mesh> create_primitive_mesh(MeshType mesh_type);
		static std::shared_ptr<Shader> create_shader(const std::string& shader_name, const std::string& vertex_path, const std::string& fragment_path);
		static std::shared_ptr<Shader> get_shader(const std::string& shader_name);
		static std::shared_ptr<Shader> get_default_shader();

	private:
		std::unordered_map<std::string, std::shared_ptr<Shader>> _shader_library;

		ResourceLibrary();
		~ResourceLibrary();
		ResourceLibrary(const ResourceLibrary& other) = delete;
		ResourceLibrary& operator=(const ResourceLibrary& other) = delete;
		ResourceLibrary(ResourceLibrary&& other) = delete;
		ResourceLibrary operator=(ResourceLibrary&& other) = delete;

		static ResourceLibrary& instance();
		std::shared_ptr<Mesh> create_primitive_mesh_impl(MeshType mesh_type);
		std::shared_ptr<Shader> create_shader_impl(const std::string& shader_name, const std::string& vertex_path, const std::string& fragment_path);
		std::shared_ptr<Shader> get_shader_impl(const std::string& shader_name);
		std::shared_ptr<Shader> get_default_shader_impl();

		void init_default_shaders();
		void init_default_meshes();

		static const std::string s_default_shader_name;
		static const std::string s_default_vertex_shader;
		static const std::string s_default_fragment_shader;
	};

}
