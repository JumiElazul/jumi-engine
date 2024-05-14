#include "internal/core/backend.h"
#include "engine_core/core/logger.h"
#include <magic_enum.hpp>
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

        JUMI_INFO("Initializing backend with window_input_api {} and rendering_api {}...", magic_enum::enum_name(w_api), magic_enum::enum_name(r_api));

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

        s_initialized = true;
    }

    window_input_api backend::get_window_input_api()
    {
        return s_window_input_api;
    }

    rendering_api backend::get_rendering_api()
    {
        return s_renderer_api;
    }

    void backend::cleanup()
    {
        switch (s_window_input_api)
        {
            case window_input_api::glfw:
            {
                glfwTerminate();
                break;
            }
        }
    }

    void backend::init_glfw()
    {
        JUMI_INFO("Initializing glfw...");

        if (!glfwInit())
        {
            JUMI_CRITICAL("Failed to initialize glfw...");
            return;
        }
        JUMI_INFO("glfw Initialized!");
    }

    void backend::cleanup_glfw()
    {
        JUMI_INFO("Cleaning up glfw...");
        glfwTerminate();
    }

}
