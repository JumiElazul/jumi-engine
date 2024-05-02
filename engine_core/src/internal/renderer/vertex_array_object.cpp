#include "internal/renderer/vertex_array_object.h"
#include "engine_core/core/logger.h"
#include <glad/glad.h>

namespace jumi
{

    vertex_array_object::vertex_array_object()
    {
        glGenVertexArrays(1, &_opengl_id);
        JUMI_DEBUG("Initializing new vertex_array_object with OpenGL Id: {}", _opengl_id);
    }

    vertex_array_object::~vertex_array_object()
    {
        release_opengl_resource();
    }

    vertex_array_object::vertex_array_object(vertex_array_object&& other) noexcept
        : _opengl_id(other._opengl_id)
    {
        other._opengl_id = 0;
    }

    vertex_array_object& vertex_array_object::operator=(vertex_array_object&& other) noexcept
    {
        if (this != &other)
        {
            _opengl_id = other._opengl_id;
            other._opengl_id = 0;
        }

        return *this;
    }

    const unsigned int& vertex_array_object::opengl_id() const
    {
        return _opengl_id;
    }

    void vertex_array_object::bind() const
    {
        glBindVertexArray(_opengl_id);
    }

    void vertex_array_object::unbind()
    {
        glBindVertexArray(0);
    }

    void vertex_array_object::release_opengl_resource()
    {
        JUMI_DEBUG("Freeing vertex_array_object with OpenGL Id: {}", _opengl_id);
        glDeleteVertexArrays(1, &_opengl_id);
    }

}
