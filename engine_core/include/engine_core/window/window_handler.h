#ifndef JUMI_ENGINE_WINDOW_WINDOW_HANDLER_H
#define JUMI_ENGINE_WINDOW_WINDOW_HANDLER_H

#include "engine_core/window/window_handler.h"
#include "engine_core/structs/structs.h"

struct GLFWwindow;

namespace jumi
{

    class window_handler
    {
    friend class engine_core;
    friend class glfw_callback_context;
    public:
        void open_window();
        void close_window();
        void swap_buffers() const;
        GLFWwindow* window() const;
        const window_info& get_window_info() const;

    private:
        GLFWwindow* _window;
        bool _window_open;
        window_info _window_info;

        window_info get_initial_window_info() const;
        void window_position_callback(int xpos, int ypos);
        void window_size_callback(int width, int height);
        GLFWwindow* create_window();

        window_handler();
        ~window_handler();
        window_handler(const window_handler& other) = delete;
        window_handler& operator=(const window_handler& other) = delete;
        window_handler(const window_handler&& other) = delete;
        window_handler& operator=(const window_handler&& other) = delete;
    };

}

#endif
