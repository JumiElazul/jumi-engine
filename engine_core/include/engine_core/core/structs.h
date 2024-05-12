#ifndef JUMI_ENGINE_CORE_CORE_STRUCTS_H
#define JUMI_ENGINE_CORE_CORE_STRUCTS_H

namespace jumi
{
    enum class window_mode
    {
        windowed,
        fullscreen,
        borderless,

        none
    };

    struct window_data
    {
        int width = 1920;
        int height = 1080;
        const char* title = "jumi-engine";
        window_mode mode = window_mode::windowed;
        bool shown = false;
    };

    struct monitor_data
    {
        int width;
        int height;
        int refresh_rate;
        int red_bits;
        int green_bits;
        int blue_bits;
    };
}

#endif


