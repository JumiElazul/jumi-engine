#ifndef JUMI_ENGINE_ENGINE_CORE_RENDERER_MESH_H
#define JUMI_ENGINE_ENGINE_CORE_RENDERER_MESH_H

#include "internal/renderer/vertex_array_object.h"
#include "internal/renderer/vertex_buffer_object.h"
#include <vector>

namespace jumi
{

    class mesh
    {
    public:
        mesh();
        mesh(const std::vector<float>& vertices);
        ~mesh();
        
        int vertice_count() const;
        void bind() const;
        void unbind() const;

    private:
        std::vector<float> _vertice_data;
        int _vertice_count;
        int _bytes_size;
        vertex_array_object _vao;
        vertex_buffer_object _vbo;

        int calculate_vertice_count();
        void setup_mesh() const;
    };

}

#endif