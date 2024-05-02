#include "engine_core/core/engine_core.h"
#include "engine_core/core/logger.h"
#include "engine_core/input/input_handler.h"
#include "engine_core/renderer/renderer.h"
#include <iostream>
#include <string>

namespace jumi
{

    int main()
    {
        engine_core& engine_core = engine_core::instance();
        window_handler& window = engine_core.get_window();
        input_handler& input = engine_core.get_input();
        renderer& renderer = engine_core.get_renderer();

        window.open_window();
        renderer.set_clear_color({ 1.0f, 0.0f, 0.0f });

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
    return jumi::main();
}
