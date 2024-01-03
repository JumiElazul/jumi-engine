#pragma once

#include "EngineCore/core/core.h"
#include <string>

namespace jumi
{
	class MeshImpl;

	class Mesh
	{
	public:
		Mesh(const char* mesh_name, const float vertices[], const size_t vertices_size, const unsigned int indices[], const size_t indices_size);
		~Mesh();

		Mesh(const Mesh& other) = delete;
		Mesh& operator=(const Mesh& other) = delete;
		Mesh(Mesh&& other) noexcept = delete;
		Mesh& operator=(Mesh&& other) noexcept = delete;

		void bind_mesh() const;
		std::string name() const;
		size_t get_vertice_count() const;
		size_t get_indice_count() const;

		static void unbind_mesh();

	private:
		std::unique_ptr<MeshImpl> _impl;

		size_t calculate_vertice_count(size_t vertSize);
		size_t calculate_indice_count(size_t indiceSize);
	};

}
