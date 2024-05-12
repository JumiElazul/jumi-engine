#ifndef JUMI_ENGINE_INTERNAL_WINDOW_WINDOW_HANDLER_H
#define JUMI_ENGINE_INTERNAL_WINDOW_WINDOW_HANDLER_H

#include "engine_core/core/structs.h"
#include "internal/interfaces/i_requires_init.h"

struct GLFWwindow;
struct GLFWvidmode;

namespace jumi
{

    class window_handler : public i_requires_init
    {
    friend class engine_callback_context;
    friend class engine_core;
    public:
        window_handler();
        ~window_handler();

        virtual void init() override;
        bool should_close() const;
        void close_window(bool close = true);
        const window_data& get_window_data() const;
        const monitor_data& get_primary_monitor_data() const;
        void show_window();
        void hide_window();
        void swap_buffers();

    private:
        bool _should_close;
        GLFWwindow* _window;
        monitor_data _primary_monitor_data;
        window_data _window_data;

        void create_window();
        monitor_data collect_monitor_data();
        GLFWwindow* get_window();
    };

}

#endif

