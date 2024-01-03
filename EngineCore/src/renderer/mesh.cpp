#include "EngineCore/renderer/mesh.h"
#include "renderer/vertex_array_object.h"
#include <memory>
#include <glad/glad.h>

namespace jumi
{

	class MeshImpl
	{
    friend class Mesh;

	public:
		MeshImpl(const char* mesh_name, const float vertices[], const size_t vertices_size, const unsigned int indices[], const size_t indices_size);
		~MeshImpl();

		MeshImpl(const MeshImpl& other) = delete;
		MeshImpl& operator=(const MeshImpl& other) = delete;
		MeshImpl(MeshImpl&& other) noexcept = delete;
		MeshImpl& operator=(MeshImpl&& other) noexcept = delete;

		void bind_mesh() const;
		std::string name() const;
		size_t get_vertice_count() const;
		size_t get_indice_count() const;

		static void unbind_mesh();

	private:
		std::string _mesh_name;
		VertexArrayObject _vao;
		unsigned int _vbo = 0;
		unsigned int _ebo = 0;
		size_t _vertice_count = 0;
		size_t _indice_count = 0;

		size_t calculate_vertice_count(size_t vertSize);
		size_t calculate_indice_count(size_t indiceSize);
	};

	Mesh::Mesh(const char* mesh_name, const float vertices[], const size_t vertices_size, const unsigned int indices[], const size_t indices_size) 
		: _impl(std::make_unique<MeshImpl>(mesh_name, vertices, vertices_size, indices, indices_size)) { }
	MeshImpl::MeshImpl(const char* mesh_name, const float vertices[], const size_t vertices_size, const unsigned int indices[], const size_t indices_size) 
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

	Mesh::~Mesh() {}
	MeshImpl::~MeshImpl() 
	{
		glDeleteBuffers(1, &_vbo);
		glDeleteBuffers(1, &_ebo);
	}

	void Mesh::bind_mesh() const { _impl->bind_mesh(); }
    void MeshImpl::bind_mesh() const { _vao.bind_vao(); }

	std::string Mesh::name() const { return _impl->name(); }
    std::string MeshImpl::name() const { return _mesh_name; }

	size_t Mesh::get_vertice_count() const { return _impl->_vertice_count; }
	size_t MeshImpl::get_vertice_count() const { return _vertice_count; }
	size_t Mesh::get_indice_count() const { return _impl->_indice_count; }
	size_t MeshImpl::get_indice_count() const { return _indice_count; }

	void Mesh::unbind_mesh() { MeshImpl::unbind_mesh(); }
	void MeshImpl::unbind_mesh()
	{
		VertexArrayObject::unbind_vao();
	}

	size_t Mesh::calculate_vertice_count(size_t vertSize) { return _impl->calculate_vertice_count(vertSize); }
	size_t MeshImpl::calculate_vertice_count(size_t vertSize)
	{
		return vertSize / sizeof(float) * 3;
	}

	size_t Mesh::calculate_indice_count(size_t indiceSize) { return _impl->calculate_indice_count(indiceSize); }
	size_t MeshImpl::calculate_indice_count(size_t indiceSize)
	{
		return indiceSize / 4;
	}

}
