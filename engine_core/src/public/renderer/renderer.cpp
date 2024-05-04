#include "engine_core/renderer/renderer.h"
#include "engine_core/core/exceptions.h"
#include "engine_core/core/logger.h"
#include "engine_core/structs/structs.h"
#include "internal/renderer/vertex_array_object.h"
#include "internal/renderer/vertex_buffer_object.h"
#include "internal/renderer/shader.h"
#include <glfw/glfw3.h>
#include <glad/glad.h>
#include <string>

#include <filesystem>

namespace jumi
{

    class test_object
    {
    public:
        test_object()
            : _vao()
            , _vbo()
        {
            _vao.bind();
            _vbo.bind();

            static float vertices[] =
            {
                -0.5f, -0.5f, 0.0f, // Bottom left
                 0.5f, -0.5f, 0.0f, // Bottom right
                -0.5f,  0.5f, 0.0f, // Top left
                 0.5f,  0.5f, 0.0f, // Top right
            };

            _vbo.buffer_data(sizeof(vertices), vertices, GL_STATIC_DRAW);
            _vbo.set_vertex_attributes(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            _vbo.enable_vertex_attributes_array(0);
        }

        void bind()
        {
            _vao.bind();
            _vbo.bind();
        }

    private:
        vertex_array_object _vao;
        vertex_buffer_object _vbo;
        shader _shader;
    };

    // TODO: Decouple the renderer viewport from the window size
    renderer::renderer(const window_info& window_info)
        : _opengl_version{ 4, 6 }
        , _viewport_width(window_info.width)
        , _viewport_height(window_info.width)
        , _test_object(nullptr)
    {
        JUMI_DEBUG("Initializing renderer...");
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw initialization_exception("Failed to initialize GLAD");
        }

        initialize_default_opengl_settings(window_info);
        _test_object = new test_object();
    }

    renderer::~renderer()
    {
        JUMI_DEBUG("Destructing renderer...");
        delete _test_object;
    }

    void renderer::set_clear_color(vec3 color)
    {
        glClearColor(color.r, color.g, color.b, 1.0f);
    }

    void renderer::clear_color_buffer()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void renderer::clear_depth_buffer()
    {
        glClear(GL_DEPTH_BUFFER_BIT);
    }

    void renderer::render_scene()
    {
        _test_object->bind();
        glDrawArrays(GL_TRIANGLES, 0, 4);
    }

    void renderer::initialize_default_opengl_settings(const window_info& window_info)
    {
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_MULTISAMPLE);
        glViewport(0, 0, _viewport_width, _viewport_height);

        if (_opengl_version.major >= 4 && _opengl_version.minor >= 3)
        {
            glDebugMessageCallback(opengl_debug_message_callback, 0);
        }
        else
        {
            // TODO: Deal with versions that are less than 4.3 using the old method of using glGetError.
            JUMI_CRITICAL("OpenGL version does not support debug message callback");
            throw initialization_exception("OpenGL version does not support debug message callback");
        }
    }

    void renderer::framebuffer_size_callback(int width, int height)
    {
        JUMI_DEBUG("Framebuffer size callback: x: {}, y: {}", width, height);
        _viewport_width = width;
        _viewport_height = height;
        glViewport(0, 0, _viewport_width, _viewport_height);
    }

    void renderer::opengl_debug_message_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* user_param)
    {
        std::string source_string = get_debug_source_string(source);
        std::string type_string = get_debug_type_string(type);
        std::string log_message = fmt::format("OpenGL [Source: {}, Type: {}, ID: {}]: {}", source_string, type_string, id, message);

        switch (severity)
        {
            case GL_DEBUG_SEVERITY_HIGH:
            {
                JUMI_ERROR(log_message);
                break;
            }
            case GL_DEBUG_SEVERITY_MEDIUM:
            {
                JUMI_WARN(log_message);
                break;
            }
            case GL_DEBUG_SEVERITY_LOW:
            {
                JUMI_INFO(log_message);
                break;
            }
            case GL_DEBUG_SEVERITY_NOTIFICATION:
            {
                JUMI_DEBUG(log_message);
                break;
            }
            default:
            {
                JUMI_DEBUG("OpenGL: Unknown severity: {}", log_message);
                break;
            }
        }
    }

    std::string renderer::get_debug_source_string(GLenum source)
    {
        switch (source)
        {
            case GL_DEBUG_SOURCE_API:             return "API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   return "Window System";
            case GL_DEBUG_SOURCE_SHADER_COMPILER: return "Shader Compiler";
            case GL_DEBUG_SOURCE_THIRD_PARTY:     return "Third Party";
            case GL_DEBUG_SOURCE_APPLICATION:     return "Application";
            case GL_DEBUG_SOURCE_OTHER:           return "Other";
            default:                              return "Unknown";
        }
    }

    std::string renderer::get_debug_type_string(GLenum type)
    {
        switch (type)
        {
            case GL_DEBUG_TYPE_ERROR:               return "Error";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "Deprecated Behavior";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  return "Undefined Behavior";
            case GL_DEBUG_TYPE_PORTABILITY:         return "Portability";
            case GL_DEBUG_TYPE_PERFORMANCE:         return "Performance";
            case GL_DEBUG_TYPE_MARKER:              return "Marker";
            case GL_DEBUG_TYPE_PUSH_GROUP:          return "Push Group";
            case GL_DEBUG_TYPE_POP_GROUP:           return "Pop Group";
            case GL_DEBUG_TYPE_OTHER:               return "Other";
            default:                                return "Unknown";
        }
    }

}