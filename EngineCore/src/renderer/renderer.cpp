#include "renderer/renderer.h"
#include "components/scene.h"
#include "components/scene_object.h"
#include "logging/logger.h"
#include "math/vector.h"
#include "renderer/mesh.h"
#include "renderer/shader.h"
#include "resources/resource_library.h"
#include <vector>
#include <memory>
#include <glad/glad.h>

namespace jumi
{

	Renderer::Renderer() { }

	Renderer::~Renderer() { }

	void Renderer::set_clear_color(const Vec3& color) const
	{
		glClearColor(color.r, color.g, color.b, 1.0f);
	}

	void Renderer::clear_color_buffer() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::clear_depth_buffer() const
	{
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::render_scene(const Scene& scene)
	{
		const Camera& camera = scene.get_camera();
		const std::vector<std::shared_ptr<SceneObject>> scene_objects = scene.get_scene_objects();

		for (const auto& scene_object : scene_objects)
		{
			std::shared_ptr<Mesh> mesh = scene_object->get_mesh();
			std::shared_ptr<Shader> shader = scene_object->get_shader();

			if (mesh)
			{
				render_mesh(*mesh.get(), camera, shader, RenderMode::DrawElements);
			}
		}
	}

    void Renderer::render_mesh(const Mesh& mesh,
            const Camera& camera,
            std::shared_ptr<Shader> shader, 
            RenderMode renderMode)
    {
		if (shader == nullptr)
		{
			shader = ResourceLibrary::get_default_shader();
		}

		mesh.bind_mesh();
		shader->bind_shader();

		switch (renderMode)
		{
		case jumi::DrawElements:
			glDrawElements(GL_TRIANGLES, mesh.get_indice_count(), GL_UNSIGNED_INT, 0);
			break;
		case jumi::DrawArrays:
            glDrawArrays(GL_TRIANGLES, 0, mesh.get_vertice_count());
			break;
		default:
			JUMI_ERROR("Invalid Renderer RenderMode");
			break;
		}
	}


}
