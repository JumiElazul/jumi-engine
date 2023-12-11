#pragma once

#include "core/core.h"
#include "renderer/vertex_array_object.h"
#include <string>

namespace jumi
{

	class JUMI_API Mesh
	{
	public:
		Mesh(const char* mesh_name, const float vertices[], const size_t vertices_size, const unsigned int indices[], const size_t indices_size);
		~Mesh();

		Mesh(const Mesh& other) = delete;
		Mesh& operator=(const Mesh& other) = delete;
		// TODO: implement these
		Mesh(Mesh&& other) noexcept = delete;
		Mesh& operator=(Mesh&& other) noexcept = delete;

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

}
