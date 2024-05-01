#include "engine_core/core/engine_core.h"
#include <iostream>
#include <string>

int main()
{
    jumi::engine_core& engine_core = jumi::engine_core::instance();
    jumi::window_handler& window = engine_core.window();

    window.open_window();

    std::string input;

    while (input != "exit")
    {
        std::getline(std::cin, input);
        if (input == "s")
        {
            window.open_window();
        }
        else if (input == "h")
        {
            window.close_window();
        }
    }
}
