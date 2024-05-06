#include "engine_core/scene/scene_object.h"

namespace jumi
{

    scene_object::scene_object()
        : _world_position()
        , _orientation()
        , _scale(1.0f)
    {
    }

    scene_object::scene_object(const vec3& start_world_position)
        : _world_position(start_world_position)
        , _orientation()
        , _scale(1.0f)
    {
    }

    void scene_object::move_by(const vec3& move_vector)
    {
        _world_position += move_vector;
    }

    void scene_object::move_to(const vec3& move_vector)
    {
        _world_position = move_vector;
    }

    void scene_object::rotate_by(const vec3& rotate_vector)
    {
        quat q = quat(glm::radians(rotate_vector));
        _orientation = _orientation * q;
    }

    void scene_object::rotate_to(const vec3& rotate_vector)
    {
        _orientation = quat(glm::radians(rotate_vector));
    }

    void scene_object::scale_by(const vec3& scale_vector)
    {
        _scale += scale_vector;
    }

    void scene_object::scale_to(const vec3& scale_vector)
    {
        _scale = scale_vector;
    }

    const vec3& scene_object::get_world_position()
    {
        return _world_position;
    }

    const vec3& scene_object::get_rotation()
    {
        vec3 euler_angles_radians = glm::eulerAngles(_orientation);
        return glm::degrees(euler_angles_radians);
    }

    const vec3& scene_object::get_scale()
    {
        return _scale;
    }

    mat4 scene_object::get_model_matrix() const
    {
        mat4 model_matrix = glm::translate(mat4(1.0f), _world_position);
        model_matrix *= glm::toMat4(_orientation);
        model_matrix = glm::scale(model_matrix, _scale);
        return model_matrix;
    }

}