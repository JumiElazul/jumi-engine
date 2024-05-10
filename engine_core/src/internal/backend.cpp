#include "internal/backend.h"
#include <iostream>

namespace jumi
{
    bool backend::s_initialized = false;
    window_input_api backend::s_w_api = window_input_api::none;
    rendering_api backend::s_r_api = rendering_api::none;

    void backend::init(window_input_api w_api, rendering_api r_api)
    {
        if (s_initialized)
        {
            return;
        }

        switch (w_api)
        {
            case window_input_api::glfw:
            {
                init_glfw();
                break;
            }
        }

        switch (r_api)
        {
            case rendering_api::open_gl:
            {
                init_open_gl();
                break;
            }
            case rendering_api::direct3d:
            {
                init_direct3d();
                break;
            }
            case rendering_api::vulkan:
            {
                init_vulkan();
                break;
            }
        }

        s_initialized = true;
    }

    void backend::cleanup()
    {
        if (!s_initialized)
        {
            return;
        }

        switch (s_w_api)
        {
            case window_input_api::glfw:
            {
                cleanup_glfw();
                break;
            }
        }

        switch (s_r_api)
        {
            case rendering_api::open_gl:
            {
                cleanup_open_gl();
                break;
            }
            case rendering_api::direct3d:
            {
                cleanup_direct3d();
                break;
            }
            case rendering_api::vulkan:
            {
                cleanup_vulkan();
                break;
            }
        }
    }

    window_input_api backend::get_window_input_api()
    {
        return s_w_api;
    }

    rendering_api backend::get_rendering_api()
    {
        return s_r_api;
    }

    void backend::init_glfw()
    {
        std::cout << "Initializing glfw\n";
    }

    void backend::init_open_gl()
    {
        std::cout << "Initializing opengl\n";
    }

    void backend::init_direct3d()
    {
        std::cout << "Initializing direct3d\n";
    }

    void backend::init_vulkan()
    {
        std::cout << "Initializing vulkan\n";
    }

    void backend::cleanup_glfw()
    {
        std::cout << "Cleaning up glfw\n";
    }

    void backend::cleanup_open_gl()
    {
        std::cout << "Cleaning up opengl\n";
    }

    void backend::cleanup_direct3d()
    {
        std::cout << "Cleaning up direct3d\n";
    }

    void backend::cleanup_vulkan()
    {
        std::cout << "Cleaning up vulkan\n";
    }

}
