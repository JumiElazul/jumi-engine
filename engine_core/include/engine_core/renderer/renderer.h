#ifndef JUMI_ENGINE_ENGINE_CORE_RENDERER_RENDERER_H
#define JUMI_ENGINE_ENGINE_CORE_RENDERER_RENDERER_H

#include "jumi_math/math/math_types.h"
#include <glad/glad.h>
#include <string>

namespace jumi
{
    struct window_info;
    class resource_manager;
    class test_object;

    struct opengl_version
    {
        int major;
        int minor;
    };

    class renderer
    {
    friend class engine_core;
    friend class glfw_callback_context;
    public:
        void init();
        void set_clear_color(vec3 color);
        void clear_depth_buffer();
        void clear_color_buffer();
        void render_scene();

    private:
        opengl_version _opengl_version;
        int _viewport_width;
        int _viewport_height;
        const resource_manager& _resource_manager;
        test_object* _test_object;

        void framebuffer_size_callback(int width, int height);

        static void opengl_debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void *user_param);
        static std::string get_debug_source_string(GLenum source);
        static std::string get_debug_type_string(GLenum type);

        renderer(const window_info& window_info, const resource_manager& resource_manager);
        ~renderer();
        renderer(const renderer& other) = delete;
        renderer operator=(const renderer& other) = delete;
        renderer(renderer&& other) = delete;
        renderer operator=(renderer&& other) = delete;
    };

}

#endif
