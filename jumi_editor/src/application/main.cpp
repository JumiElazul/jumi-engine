#include "engine_core/core/engine_core.h"
#include "engine_core/core/logger.h"
#include "engine_core/input/input_handler.h"
#include <iostream>
#include <string>

namespace jumi
{

    int main()
    {
        engine_core& engine_core = engine_core::instance();
        window_handler& window = engine_core.window();
        input_handler& input = engine_core.input();

        window.open_window();

        while (!engine_core.should_quit())
        {
            engine_core.new_frame();

            if (input.key_pressed(jumi_key::key_escape))
            {
                engine_core.quit();
            }

            window.swap_buffers();
        }

        return 0;
    }

}

int main()
{
    return jumi::main();
}
