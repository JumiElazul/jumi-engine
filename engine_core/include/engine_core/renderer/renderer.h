#ifndef JUMI_ENGINE_RENDERER_RENDERER_H
#define JUMI_ENGINE_RENDERER_RENDERER_H

#include <glad/glad.h>
#include <string>

namespace jumi
{
    struct window_info;

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

    private:
        opengl_version _opengl_version;
        int _viewport_width;
        int _viewport_height;

        void initialize_default_opengl_settings(const window_info& window_info);
        void framebuffer_size_callback(int width, int height);

        static void opengl_debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void *user_param);
        static std::string get_debug_source_string(GLenum source);
        static std::string get_debug_type_string(GLenum type);

        renderer(const window_info& window_info);
        ~renderer();
        renderer(const renderer& other) = delete;
        renderer operator=(const renderer& other) = delete;
        renderer(renderer&& other) = delete;
        renderer operator=(renderer&& other) = delete;
    };

}

#endif
