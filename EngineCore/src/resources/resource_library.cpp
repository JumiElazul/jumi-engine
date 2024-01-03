#include "resources/resource_library.h"
#include "log/logger.h"
#include "renderer/shader.h"
#include "renderer/mesh.h"
#include <memory>
#include <string>

namespace jumi
{

	const std::string ResourceLibrary::s_default_shader_name = "_DEFAULT_SHADER";

	const std::string ResourceLibrary::s_default_vertex_shader =
		"#version 460 compatibility\n"										     		                         \
		"layout(location = 0) in vec3 VPOS;\n\n"						     	                                 \
                                                                                                                 \
		"uniform mat4 u_model_matrix;\n"                                                                         \
		"uniform mat4 u_view_matrix;\n"                                                                          \
		"uniform mat4 u_projection_matrix;\n"                                                                    \
                                                                                                                 \
		"void main()\n"														                                     \
		"{\n"														                                             \
			"gl_Position = u_projection_matrix * u_view_matrix * u_model_matrix * vec4(VPOS, 1.0);"              \
		"}\n";

	const std::string ResourceLibrary::s_default_fragment_shader =
		"#version 460 compatibility\n"							                                	             \
		                                                                                                         \
		"out vec4 fragColor;\n"										     		                                 \
		                                                                                                         \
		"void main()\n"		    												                                 \
		"{\n"																	                                 \
			"fragColor = vec4(0.0, 1.0, 1.0, 1.0);\n"							                                 \
		"}\n";


    const float s_cube_vertices[]
    {
        -1.0f,  1.0f, -1.0f, // Top left close
         1.0f,  1.0f, -1.0f, // Top right close
        -1.0f, -1.0f, -1.0f, // Bottom left close
         1.0f, -1.0f, -1.0f, // Bottom right close
        -1.0f,  1.0f,  1.0f, // Top left far
         1.0f,  1.0f,  1.0f, // Top right far
        -1.0f, -1.0f,  1.0f, // Bottom left far
         1.0f, -1.0f,  1.0f, // Bottom right far
    };

    const unsigned int s_cube_indices[]
    {
        // Front face (Z-)
        0, 2, 1,
        2, 3, 1,
        // Right face (X+)
        1, 3, 5,
        3, 7, 5,
        // Back face (Z+)
        5, 7, 4,
        7, 6, 4,
        // Left face (X-)
        4, 6, 0,
        6, 2, 0,
        // Top face (Y+)
        4, 0, 5,
        0, 1, 5,
        // Bottom face (Y-)
        2, 6, 3,
        6, 7, 3 
    };

    const size_t s_cube_vertices_size = sizeof(s_cube_vertices);
    const size_t s_cube_indices_size = sizeof(s_cube_indices);

	ResourceLibrary::ResourceLibrary()
	{
		init_default_shaders();
		init_default_meshes();
	}

    ResourceLibrary::~ResourceLibrary() { }

	ResourceLibrary& ResourceLibrary::instance()
	{
		static ResourceLibrary instance;
		return instance;
	}

	std::shared_ptr<Mesh> ResourceLibrary::create_primitive_mesh(MeshType mesh_type)
	{
		return ResourceLibrary::instance().create_primitive_mesh_impl(mesh_type);
	}

	std::shared_ptr<Mesh> ResourceLibrary::create_primitive_mesh_impl(MeshType mesh_type)
	{
		switch (mesh_type)
		{
            case MeshType::Cube:
            {
                JUMI_INFO("Creating MeshType::Cube");
                return std::make_shared<Mesh>("CubeMesh", s_cube_vertices, s_cube_vertices_size, s_cube_indices, s_cube_indices_size);
            }
            case MeshType::Sphere:
            {
                JUMI_INFO("Creating MeshType::Sphere");
                break;
            }
            case MeshType::Diamond:
            {
                JUMI_INFO("Creating MeshType::Diamond");
                break;
            }
            case MeshType::Plane:
            {
                JUMI_INFO("Creating MeshType::Plane");
                break;
            }
            default:
            {
                JUMI_ERROR("Invalid meshtype specified");
                break;
            }
		}

        return nullptr;
	}

	std::shared_ptr<Shader> ResourceLibrary::create_shader(const std::string& shader_name, const std::string& vertex_path, const std::string& fragment_path)
	{
		return ResourceLibrary::instance().create_shader_impl(shader_name, vertex_path, fragment_path);
	}

	std::shared_ptr<Shader> ResourceLibrary::create_shader_impl(const std::string& shader_name, const std::string& vertex_path, const std::string& fragment_path)
	{
		std::unordered_map<std::string, std::shared_ptr<Shader>>::iterator iter = _shader_library.find(shader_name);

		if (iter == _shader_library.end())
		{
			JUMI_INFO("Shader with name {} added to ShaderLibrary", shader_name);
			std::shared_ptr<Shader> shader(new Shader(shader_name, vertex_path, fragment_path));
			_shader_library.emplace(shader_name, shader);
			return shader;
		}
		JUMI_WARN("Shader with name {} already exists in ShaderLibrary", shader_name);
        return _shader_library.at(shader_name);
	}

	std::shared_ptr<Shader> ResourceLibrary::get_shader(const std::string& shader_name) { return ResourceLibrary::instance().get_shader_impl(shader_name); }
	std::shared_ptr<Shader> ResourceLibrary::get_shader_impl(const std::string& shader_name)
	{
		std::unordered_map<std::string, std::shared_ptr<Shader>>::iterator iter = _shader_library.find(shader_name);

		if (iter != _shader_library.end())
		{
			return iter->second;
		}
		return nullptr;
	}

	std::shared_ptr<Shader> ResourceLibrary::get_default_shader() { return ResourceLibrary::instance().get_default_shader_impl(); }
	std::shared_ptr<Shader> ResourceLibrary::get_default_shader_impl()
	{
		return _shader_library.at(s_default_shader_name);
	}

	void ResourceLibrary::init_default_shaders()
	{
		JUMI_INFO("Default shader being added to ResourceLibrary shaders");
		ShaderSourceTag tag{};
		std::shared_ptr<Shader> defaultShader(new Shader(s_default_shader_name, s_default_vertex_shader, s_default_fragment_shader, tag));
		_shader_library.emplace(defaultShader->name(), defaultShader);
	}

	void ResourceLibrary::init_default_meshes()
	{

	}

}
