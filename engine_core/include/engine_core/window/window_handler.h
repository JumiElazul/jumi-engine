#ifndef JUMI_ENGINE_WINDOW_WINDOW_HANDLER_H
#define JUMI_ENGINE_WINDOW_WINDOW_HANDLER_H

#include "engine_core/window/window_handler.h"

namespace jumi
{

    class window_handler
    {
    friend class engine_core;
    public:

        void open_window();
        void close_window();

    private:
        bool _window_open;
        int _window_width;
        int _window_height;

        window_handler(int width, int height);
        ~window_handler();
        window_handler(const window_handler& other) = delete;
        window_handler& operator=(const window_handler& other) = delete;
        window_handler(const window_handler&& other) = delete;
        window_handler& operator=(const window_handler&& other) = delete;
    };

}

#endif
