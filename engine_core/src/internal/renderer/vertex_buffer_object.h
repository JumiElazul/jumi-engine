#ifndef JUMI_ENGINE_RENDERER_VERTEX_BUFFER_OBJECT_H
#define JUMI_ENGINE_RENDERER_VERTEX_BUFFER_OBJECT_H

#include "internal/renderer/i_opengl_resource.h"
#include <glad/glad.h>

namespace jumi
{

    class vertex_buffer_object : public i_opengl_resource
    {
    public:
        vertex_buffer_object();
        ~vertex_buffer_object();
        vertex_buffer_object(const vertex_buffer_object& other) = delete;
        vertex_buffer_object operator=(const vertex_buffer_object& other) = delete;
        vertex_buffer_object(vertex_buffer_object&& other) noexcept;
        vertex_buffer_object& operator=(vertex_buffer_object&& other) noexcept;

        [[no_discard]] const unsigned int& opengl_id() const;
        void bind() const;
        void buffer_data(GLsizeiptr size, const void* data, GLenum usage);
        void set_vertex_attributes(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
        void enable_vertex_attributes_array(unsigned int index);
        static void unbind();

    private:
        unsigned int _opengl_id;

        virtual void release_opengl_resource() override;
    };

}

#endif
