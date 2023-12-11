#include "math/math.h"
#include "logging/logger.h"
#include "window/window_handler.h"

int main()
{
    int result = jumi::add(1, 3);
    JUMI_INFO("{}", result);

    jumi::WindowHandler& window_handler = jumi::WindowHandler::instance();
    window_handler.create_window({ 1280, 720, "!!Test Window!!" });
    window_handler.show_window();

    float time{};
    while (time < 2.0f)
    {
        time = window_handler.get_time();

        window_handler.swap_buffers();
        window_handler.poll_events();
    }

    return 0;
}
