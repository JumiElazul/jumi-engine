#pragma once

#include "components/transform.h"
#include <string>
#include <memory>

namespace jumi
{

	class Mesh;
	class Shader;

	class JUMI_API SceneObject
	{
	public:
		SceneObject(const std::string& name, std::shared_ptr<Mesh> mesh = nullptr, std::shared_ptr<Shader> shader = nullptr);
		~SceneObject();

		Transform& get_transform();
		const std::string& name() const;
        int id() const;
		std::shared_ptr<Mesh> get_mesh() const;
		std::shared_ptr<Shader> get_shader() const;

		int ID() const;

	private:
		int _id = -1;
		std::string _name;
		Transform _transform;
		std::shared_ptr<Mesh> _mesh;
		std::shared_ptr<Shader> _shader;

		int assign_scene_object_id();
	};

}


