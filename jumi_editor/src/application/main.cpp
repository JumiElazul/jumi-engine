#include "engine_core/core/engine_core.h"
#include "engine_core/core/logger.h"
#include "engine_core/input/input_handler.h"
#include "engine_core/renderer/renderer.h"
#include "engine_core/renderer/i_shader.h"
#include <iostream>
#include <memory>
#include <string>

namespace jumi
{

    int entry_point()
    {
        engine_core& engine_core = engine_core::instance();
        window_handler& window = engine_core.get_window();
        input_handler& input = engine_core.get_input();
        renderer& renderer = engine_core.get_renderer();
        resource_manager& resource_manager = engine_core.get_resource_manager();

        const std::string& default_shader_name = resource_manager.default_shader_name();
        std::shared_ptr<i_shader> default_shader = resource_manager.get_shader(default_shader_name);

        default_shader->bind();

        window.open_window();
        renderer.set_clear_color({ 1.0f, 1.0f, 1.0f });

        while (!engine_core.should_quit())
        {
            renderer.clear_color_buffer();
            engine_core.new_frame();

            if (input.key_pressed(jumi_key::key_escape))
            {
                engine_core.quit();
            }

            renderer.render_scene();
            window.swap_buffers();
        }

        return 0;
    }

}

int main()
{
    return jumi::entry_point();
}
