#include "EngineCore/core/core.h"
#include "EngineCore/core/engine_core.h"
#include "EngineCore/components/camera.h"
#include "EngineCore/components/scene.h"
#include "EngineCore/components/scene_object.h"
#include "EngineCore/events/event_bus.h"
#include "EngineCore/input/input_handler.h"
#include "EngineCore/input/keycodes.h"
#include "EngineCore/math/matrix.h"
#include "EngineCore/math/vector.h"
#include "EngineCore/renderer/mesh.h"
#include "EngineCore/renderer/renderer.h"
#include "EngineCore/renderer/shader.h"
#include "EngineCore/resources/resource_library.h"
#include "EngineCore/window/window_handler.h"

#include "editor/imgui_core.h"

namespace jumi
{

    void show_test_scene()
    {
        EngineCore& engine_core = EngineCore::instance();
        engine_core.set_window_context(1920, 1080, "Jumi Editor", false, false);
        engine_core.init();

        WindowHandler& window = engine_core.get_window();
        InputHandler& input = engine_core.get_input();
        Renderer& renderer = engine_core.get_renderer();
        renderer.set_clear_color({ 0.2f, 0.2f, 0.2f });

        ImGuiCore& imgui_core = ImGuiCore::instance();
        imgui_core.init(window.get_window());

        std::shared_ptr<Mesh> cube_mesh = ResourceLibrary::create_primitive_mesh(MeshType::Cube);
        std::shared_ptr<Shader> shader = ResourceLibrary::get_default_shader();

        Mat4 model{ Mat4::identity() };
        model = Mat4::rotate(model, { 45.0f, 0.0f, 0.0f });
        model = Mat4::translate(model, { 0.0f, 0.0f, -10.0f });

        shader->bind_shader();

        CameraSpecification camera_specification{};
        camera_specification.projection_type = ProjectionType::Perspective;
        camera_specification.fov = 55.0f;
        camera_specification.aspect_ratio = 16.0f / 9.0f;
        camera_specification.z_near = 0.01f;
        camera_specification.z_far = 500.0f;
        Camera camera{ camera_specification };

        std::shared_ptr<SceneObject> cube = std::make_shared<SceneObject>("CubeSceneObject", cube_mesh);

        Scene main_scene;
        main_scene.add_scene_object(cube);
        const WindowContext& target = window.get_window_context();

        while (!window.should_close())
        {
            imgui_core.begin_frame();
            input.poll_input_events();

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

            imgui_core.draw_ui();
            window.swap_buffers();
            if (input.is_key_down(JUMI_KEY_Q))
            {
                window.close_window();
            }
            renderer.clear_color_buffer();
            renderer.clear_depth_buffer();
            imgui_core.end_frame();
        }
    }

    int main()
    {
        show_test_scene();
        return 0;
    }

}

int main()
{
    return jumi::main();
}
