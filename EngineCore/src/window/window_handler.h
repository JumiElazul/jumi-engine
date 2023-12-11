#pragma once

struct GLFWwindow;

namespace jumi
{

    struct WindowContext
    {
        int width;
        int height;
        const char* title;
    };

    class WindowHandler
    {
    public:
        WindowHandler(const WindowHandler& other) = delete;
        WindowHandler operator=(const WindowHandler& other) = delete;
        WindowHandler(const WindowHandler&& other) = delete;
        WindowHandler operator=(const WindowHandler&& other) = delete;

        static WindowHandler& instance();
        const WindowContext& get_context() const;
        bool create_window(const WindowContext& context);
        void show_window() const;
        void swap_buffers() const;
        void poll_events() const;
        float get_time() const;

    private:
        WindowHandler();
        ~WindowHandler();

        GLFWwindow* _window;
        WindowContext _window_context;
        bool _initialized = false;

        void init();
        bool initialize_glfw();
    };

}
