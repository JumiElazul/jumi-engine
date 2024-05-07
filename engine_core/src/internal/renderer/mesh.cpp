#include "internal/renderer/mesh.h"
#include <vector>

namespace jumi
{
    mesh::mesh()
        : _vertice_data()
        , _vertice_count()
        , _bytes_size()
        , _vao()
        , _vbo()
    {
        // TODO: Temporary constructor to test vertex_data
        {
            //_vertice_data =
            //{
            //    -0.5f, -0.5f, 0.0f, // Bottom left
            //     0.5f, -0.5f, 0.0f, // Bottom right
            //    -0.5f,  0.5f, 0.0f, // Top left
            //     0.5f,  0.5f, 0.0f, // Top right
            //};

            _vertice_data =
            {
                -0.5f, -0.5f, 0.0f, // Bottom left
                 0.5f, -0.5f, 0.0f, // Bottom right
                 0.0f,  0.5f, 0.0f, // Top middle
            };
            _vertice_count = calculate_vertice_count();
            _bytes_size = sizeof(_vertice_data[0]) * _vertice_data.size();
        }

        setup_mesh();
    }

    mesh::mesh(const std::vector<float>& vertices)
        : _vertice_data(vertices)
        , _vertice_count(calculate_vertice_count())
        , _bytes_size(sizeof(_vertice_data[0]) * _vertice_data.size())
        , _vao()
        , _vbo()
    {
        setup_mesh();
    }

    mesh::~mesh()
    {
    }

    int mesh::vertice_count() const
    {
        return _vertice_count;
    }

    void mesh::bind() const
    {
        _vao.bind();
    }

    void mesh::unbind() const
    {
        _vao.unbind();
    }

    int mesh::calculate_vertice_count()
    {
        // TODO: Fix the hard coding of the vertice data to only contain positional information
        return (sizeof(_vertice_data[0]) * _vertice_data.size()) / 3;
    }

    void mesh::setup_mesh() const
    {
        _vao.bind();
        _vbo.bind();

        _vbo.buffer_data(_bytes_size, _vertice_data.data(), GL_STATIC_DRAW);
        _vbo.set_vertex_attributes(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        _vbo.enable_vertex_attributes_array(0);
    }

}