#include "internal/renderer/vertex_buffer_object.h"
#include "engine_core/core/logger.h"
#include <glad/glad.h>

namespace jumi
{

    vertex_buffer_object::vertex_buffer_object()
    {
        glGenBuffers(1, &_opengl_id);
        JUMI_DEBUG("Initializing new vertex_buffer_object with OpenGL Id: {}", _opengl_id);
    }

    vertex_buffer_object::~vertex_buffer_object()
    {
        release_opengl_resource();
    }

    vertex_buffer_object::vertex_buffer_object(vertex_buffer_object&& other) noexcept
        : _opengl_id(other._opengl_id)
    {
        other._opengl_id = 0;
    }

    vertex_buffer_object& vertex_buffer_object::operator=(vertex_buffer_object&& other) noexcept
    {
        if (this != &other)
        {
            _opengl_id = other._opengl_id;
            other._opengl_id = 0;
        }

        return *this;
    }

    const unsigned int& vertex_buffer_object::opengl_id() const
    {
        return _opengl_id;
    }

    void vertex_buffer_object::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _opengl_id);
    }

    void vertex_buffer_object::buffer_data(GLsizeiptr size, const void* data, GLenum usage) const
    {
        glBufferData(GL_ARRAY_BUFFER, size, data, usage);
    }

    void vertex_buffer_object::set_vertex_attributes(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer) const
    {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    }

    void vertex_buffer_object::enable_vertex_attributes_array(unsigned int index) const
    {
        glEnableVertexAttribArray(index);
    }

    void vertex_buffer_object::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void vertex_buffer_object::release_opengl_resource()
    {
        JUMI_DEBUG("Freeing vertex_buffer_object with OpenGL Id: {}", _opengl_id);
        glDeleteBuffers(1, &_opengl_id);
    }

}
