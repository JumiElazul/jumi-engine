#include "internal/renderer/opengl_renderer.h"
#include "internal/core/backend.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace jumi
{

    opengl_renderer::opengl_renderer()
    {

    }

    opengl_renderer::~opengl_renderer()
    {

    }

    void opengl_renderer::init()
    {
        JUMI_INFO("Initializing opengl_renderer...");

        // TODO: Abstract the backend glfw call to the backend class, so that we don't need
        // glfw as a dependency in the renderer.
        if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            JUMI_INFO("OpenGL function pointers initialized!");
        }
        else
        {
            throw jexcept::initialization_exception("OpenGL renderer failed to initialize...");
        }
    }

    void opengl_renderer::set_clear_color(const vec3& color)
    {
        _clear_color = color;
        glClearColor(color.r, color.g, color.b, 1.0f);
    }

    void opengl_renderer::clear_color_buffer() const
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void opengl_renderer::clear_depth_buffer() const
    {
        glClear(GL_DEPTH_BUFFER_BIT);
    }

}