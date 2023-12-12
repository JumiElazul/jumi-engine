#include "core/core.h"
#include "core/engine_core.h"
#include "components/camera.h"
#include "components/scene.h"
#include "components/scene_object.h"
#include "input/input_handler.h"
#include "input/keycodes.h"
#include "math/matrix.h"
#include "math/vector.h"
#include "renderer/mesh.h"
#include "renderer/renderer.h"
#include "renderer/shader.h"
#include "resources/resource_library.h"
#include "window/window_handler.h"
#include <iostream>

int main(JUMI_UNUSED int argc, JUMI_UNUSED char* argv[])
{
	jumi::EngineCore& engine_core = jumi::EngineCore::instance();

	engine_core.set_window_context(1920, 1080, "jumi Window!", false, true);
	engine_core.init();

	jumi::WindowHandler& window = engine_core.get_window();
	jumi::InputHandler& input = engine_core.get_input();
	jumi::Renderer& renderer = engine_core.get_renderer();
	renderer.set_clear_color({ 0.2f, 0.2f, 0.2f });

	std::shared_ptr<jumi::Mesh> cube_mesh = jumi::ResourceLibrary::create_primitive_mesh(jumi::MeshType::Cube);
	std::shared_ptr<jumi::Shader> shader = jumi::ResourceLibrary::get_default_shader();

	jumi::Mat4 model{ jumi::Mat4::identity() };
	model = jumi::Mat4::rotate(model, { 45.0f, 0.0f, 0.0f });
	model = jumi::Mat4::translate(model, { 0.0f, 0.0f, -10.0f });

	shader->bind_shader();

	jumi::CameraSpecification camera_specification{};
	camera_specification.projection_type = jumi::ProjectionType::Perspective;
	camera_specification.fov = 55.0f;
	camera_specification.aspect_ratio = 16.0f / 9.0f;
	camera_specification.z_near = 0.01f;
	camera_specification.z_far = 500.0f;
	jumi::Camera camera{ camera_specification };

	std::shared_ptr<jumi::SceneObject> cube = std::make_shared<jumi::SceneObject>("CubeSceneObject", cube_mesh);

    std::cout << "Cube sceneobject has a mesh: " << (cube->get_mesh() != nullptr) << '\n';

	jumi::Scene main_scene;
	main_scene.add_scene_object(cube);

	while (!window.should_close())
	{
		renderer.clear_color_buffer();
		renderer.clear_depth_buffer();

        shader->set_uniform_mat4("u_model_matrix", model);
        shader->set_uniform_mat4("u_view_matrix", camera.view_matrix());
        shader->set_uniform_mat4("u_projection_matrix", camera.projection_matrix());

		if (input.is_key_held(JUMI_KEY_F))
		{
			camera.get_transform().move({ 0.0f, 0.01f, 0.0f });
		}
		if (input.is_key_held(JUMI_KEY_S))
		{
			camera.get_transform().move({ 0.0f, -0.01f, 0.0f });
		}
		if (input.is_key_held(JUMI_KEY_R))
		{
			camera.get_transform().move({ -0.01f, 0.0f, 0.0f });
		}
		if (input.is_key_held(JUMI_KEY_T))
		{
			camera.get_transform().move({ 0.01f, 0.0f, 0.0f });
		}

		renderer.render_scene(main_scene);
		//renderer.RenderMesh(mesh, camera, shader);

		window.swap_buffers();
		if (input.is_key_down(JUMI_KEY_Q))
		{
			window.close_window();
		}
	}

	return 0;
}
