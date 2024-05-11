#ifndef JUMI_ENGINE_ENGINE_CORE_INTERNAL_BACKEND_H
#define JUMI_ENGINE_ENGINE_CORE_INTERNAL_BACKEND_H

namespace jumi
{

    enum class window_input_api
    {
        glfw,

        none
    };

    enum class rendering_api
    {
        open_gl,
        direct3d,
        vulkan,

        none
    };

    class backend
    {
    public:
        static void init(window_input_api w_api, rendering_api r_api);
        static void cleanup();
        static window_input_api get_window_input_api();
        static rendering_api get_rendering_api();

    private:
        static bool s_initialized;
        static window_input_api s_window_input_api;
        static rendering_api s_renderer_api;

        static void init_glfw();
        static void init_open_gl();
        static void init_direct3d();
        static void init_vulkan();
        static void cleanup_glfw();
        static void cleanup_open_gl();
        static void cleanup_direct3d();
        static void cleanup_vulkan();
    };

}

#endif
