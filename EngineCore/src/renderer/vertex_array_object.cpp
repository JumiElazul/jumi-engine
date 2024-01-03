#include "EngineCore/renderer/vertex_array_object.h"
#include <glad/glad.h>

namespace jumi
{

    VertexArrayObject::VertexArrayObject()
    {
		glGenVertexArrays(1, &_vao);
    }

    VertexArrayObject::~VertexArrayObject()
    {
        glDeleteVertexArrays(1, &_vao);
    }

    VertexArrayObject::VertexArrayObject(VertexArrayObject&& other) noexcept
        : _vao(other._vao)
    {
        other._vao = 0;
    }

    VertexArrayObject& VertexArrayObject::operator=(VertexArrayObject&& other) noexcept
    {
        if (this != &other)
        {
            _vao = other._vao;
            other._vao = 0;
        }

        return *this;
    }

    unsigned int VertexArrayObject::get_id() const { return _vao; }

    void VertexArrayObject::bind_vao() const { glBindVertexArray(_vao); }
    void VertexArrayObject::unbind_vao() { glBindVertexArray(0); }

}
