#include "internal/backend.h"
#include "engine_core/core/logger.h"

namespace jumi
{
    bool backend::s_initialized = false;
    window_input_api backend::s_w_api = window_input_api::none;
    rendering_api backend::s_r_api = rendering_api::none;

    void backend::init(window_input_api w_api, rendering_api r_api)
    {
        JUMI_INFO("Initializing backend...");
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
        JUMI_INFO("Initializing glfw");
    }

    void backend::init_open_gl()
    {
        JUMI_INFO("Initializing opengl");
    }

    void backend::init_direct3d()
    {
        JUMI_INFO("Initializing direct3d");
    }

    void backend::init_vulkan()
    {
        JUMI_INFO("Initializing vulkan");
    }

    void backend::cleanup_glfw()
    {
        JUMI_INFO("Cleaning up glfw");
    }

    void backend::cleanup_open_gl()
    {
        JUMI_INFO("Cleaning up opengl");
    }

    void backend::cleanup_direct3d()
    {
        JUMI_INFO("Cleaning up direct3d");
    }

    void backend::cleanup_vulkan()
    {
        JUMI_INFO("Cleaning up vulkan");
    }

}
