#pragma once

#include "EngineCore/core/core.h"
#include <memory>
#include <vector>

namespace jumi
{
	class Camera;
	class DirectionalLight;
	class SceneObject;

	class Scene
	{
	public:
		Scene();
		~Scene();

		void add_scene_object(std::shared_ptr<SceneObject> sceneObject);
		const std::vector<std::shared_ptr<SceneObject>>& get_scene_objects() const;
		const Camera& get_camera() const;

	private:
		std::unique_ptr<Camera> _main_camera;
		std::unique_ptr<DirectionalLight> _directional_light;
		std::vector<std::shared_ptr<SceneObject>> _scene_objects;
	};

}
