#include "engine_core/core/engine_core.h"
#include <iostream>
#include <string>
#include <imgui.h>

int main()
{
    jumi::engine_core& engine_core = jumi::engine_core::instance();
    jumi::window_handler& window = engine_core.window();
    jumi::input_handler& input = engine_core.input();

    window.open_window();

    while (engine_core.time() < 2.0)
    {
        input.poll_inputs();

        window.swap_buffers();
    }
}
