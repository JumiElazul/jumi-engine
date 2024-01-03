#include "EngineCore/renderer/renderer.h"
#include "EngineCore/components/scene.h"
#include "EngineCore/components/scene_object.h"
#include "EngineCore/core/core.h"
#include "EngineCore/log/logger.h"
#include "EngineCore/math/vector.h"
#include "EngineCore/renderer/mesh.h"
#include "EngineCore/renderer/shader.h"
#include "EngineCore/resources/resource_library.h"
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

	void Renderer::on_framebuffer_size_changed(GLFWwindow* window, int width, int height)
	{
		JUMI_INFO("Framebuffer size changed to {}, {}", width, height);
		glViewport(0, 0, width, height);
	}

    void Renderer::render_mesh(const Mesh& mesh,
            JUMI_UNUSED const Camera& camera,
            std::shared_ptr<Shader> shader, 
            RenderMode render_mode)
    {
		if (shader == nullptr)
		{
			shader = ResourceLibrary::get_default_shader();
		}

#ifdef JUMI_RENDER_LOGGING
        JUMI_INFO("Rendering: Mesh: [name: {}, vert_count: {}, indice_count: {}] with Shader: [id: {}, name: {}]    RenderMode: [{}]",
                mesh.name(), mesh.get_vertice_count(), mesh.get_indice_count(),
                shader->get_shader_id(), shader->name(),
                render_mode);
#endif

		mesh.bind_mesh();
		shader->bind_shader();

		switch (render_mode)
		{
		case jumi::DrawElements:
			glDrawElements(GL_TRIANGLES, mesh.get_indice_count(), GL_UNSIGNED_INT, 0);
			break;
		case jumi::DrawArrays:
            glDrawArrays(GL_TRIANGLES, 0, mesh.get_vertice_count());
			break;
		default:
			JUMI_ERROR("Invalid RenderMode");
			break;
		}
	}


}
