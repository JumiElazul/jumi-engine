#include "EngineCore/components/scene_object.h"
#include "EngineCore/renderer/mesh.h"
#include "EngineCore/renderer/shader.h"

namespace jumi
{

	SceneObject::SceneObject(const std::string& name, std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader)
		: _name(name), _mesh(mesh), _shader(shader)
	{
		_id = assign_scene_object_id();
	}

	SceneObject::~SceneObject()
	{
	}

	Transform& SceneObject::get_transform() { return _transform; }

	const std::string& SceneObject::name() const { return _name; }

    int SceneObject::id() const { return _id; }

	std::shared_ptr<Mesh> SceneObject::get_mesh() const { return _mesh; }

	std::shared_ptr<Shader> SceneObject::get_shader() const { return _shader; }

	int SceneObject::ID() const { return _id; }

	int SceneObject::assign_scene_object_id()
	{
		static int id{ 0 };
		return id++;
	}

}

