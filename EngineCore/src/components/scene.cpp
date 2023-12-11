#include "components/scene.h"
#include "components/camera.h"
#include "components/directional_light.h"
#include "components/scene_object.h"
#include "logging/logger.h"

namespace jumi
{

    Scene::Scene() { }

    Scene::~Scene() { }

	void Scene::add_scene_object(std::shared_ptr<SceneObject> scene_object)
	{
		JUMI_INFO("SceneObject with id {} added to Scene", scene_object->ID());
		_scene_objects.emplace_back(scene_object);
	}

	const std::vector<std::shared_ptr<SceneObject>>& Scene::get_scene_objects() const { return _scene_objects; }

	const Camera& Scene::get_camera() const { return *_main_camera; }

}

