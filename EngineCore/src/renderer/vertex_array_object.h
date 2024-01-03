#pragma once

namespace jumi
{

	class VertexArrayObject
	{
	public:
		VertexArrayObject();
		~VertexArrayObject();
		VertexArrayObject(const VertexArrayObject& other) = delete;
		VertexArrayObject& operator=(const VertexArrayObject& other) = delete;
		VertexArrayObject(VertexArrayObject&& other) noexcept;
		VertexArrayObject& operator=(VertexArrayObject&& other) noexcept;

		unsigned int get_id() const;
		void bind_vao() const;

		static void unbind_vao();

	private:
		unsigned int _vao = 0;
	};

}
