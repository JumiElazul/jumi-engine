#include "renderer/mesh.h"
#include <glad/glad.h>

namespace jumi
{

	Mesh::Mesh(const char* mesh_name, const float vertices[], const size_t vertices_size, const unsigned int indices[], const size_t indices_size) 
		: _mesh_name(mesh_name), _vertice_count(calculate_vertice_count(vertices_size)), _indice_count(calculate_indice_count(indices_size))
	{
		_vao.bind_vao();
		glGenBuffers(1, &_vbo);
		glGenBuffers(1, &_ebo);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size, indices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}

	Mesh::~Mesh() 
	{
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ebo);
	}

    void Mesh::bind_mesh() const { _vao.bind_vao(); }

    std::string Mesh::name() const { return _mesh_name; }

	size_t Mesh::get_vertice_count() const { return _vertice_count; }
	size_t Mesh::get_indice_count() const { return _indice_count; }

	void Mesh::unbind_mesh()
	{
		VertexArrayObject::unbind_vao();
	}

	size_t Mesh::calculate_vertice_count(size_t vertSize)
	{
		return vertSize / sizeof(float) * 3;
	}

	size_t Mesh::calculate_indice_count(size_t indiceSize)
	{
		return indiceSize / 4;
	}

}
