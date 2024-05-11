#include "internal/backend.h"
#include "engine_core/core/logger.h"
#include <magic_enum.hpp>
#include <fmt/format.h>
#include <glfw/glfw3.h>

namespace jumi
{
    bool backend::s_initialized = false;
    window_input_api backend::s_window_input_api = window_input_api::none;
    rendering_api backend::s_renderer_api = rendering_api::none;

    void backend::init(window_input_api w_api, rendering_api r_api)
    {
        if (s_initialized)
        {
            return;
        }

        // TODO: Get a proper logging library with format strings
        std::string init_message = fmt::format("Initializing backend with window_input_api {} and rendering_api {}...", magic_enum::enum_name(w_api), magic_enum::enum_name(r_api));
        JUMI_INFO(init_message);

        s_window_input_api = w_api;
        s_renderer_api = r_api;

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

        switch (s_window_input_api)
        {
            case window_input_api::glfw:
            {
                cleanup_glfw();
                break;
            }
        }

        switch (s_renderer_api)
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
        return s_window_input_api;
    }

    rendering_api backend::get_rendering_api()
    {
        return s_renderer_api;
    }

    void backend::init_glfw()
    {
        JUMI_INFO("Initializing glfw");

        if (!glfwInit())
        {
            JUMI_CRITICAL("Failed to initialize glfw");
            return;
        }
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

        glfwTerminate();
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
