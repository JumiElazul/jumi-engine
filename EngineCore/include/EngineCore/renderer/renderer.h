#pragma once

#include "EngineCore/core/core.h"
#include <memory>

struct GLFWwindow;

namespace jumi
{
	class Vec3;
	class Mesh;
	class Shader;
	class Camera;
	class Scene;

	struct ViewportTarget
	{
		int x = 0;
		int y = 0;
		int width = 100;
		int height = 100;
	};

	enum RenderMode
	{
		DrawElements,
		DrawArrays,
	};

	class Renderer
	{
	friend class ResourceLibrary;

	public:
		Renderer();
		~Renderer();

		void set_clear_color(const Vec3& color) const;
		void clear_color_buffer() const;
		void clear_depth_buffer() const;
		void set_viewport_target(const ViewportTarget& target);

		void render_scene(const Scene& scene);

        void render_mesh(const Mesh& mesh,
                const Camera& camera,
                std::shared_ptr<Shader> shader = nullptr, 
                RenderMode renderMode = DrawElements);

		void on_framebuffer_size_changed(GLFWwindow* window, int width, int height);

	private:
		ViewportTarget _viewport_target;
	};

}
