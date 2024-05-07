#include "engine_core/scene/scene_object.h"
#include "internal/renderer/vertex_array_object.h"
#include "internal/renderer/vertex_buffer_object.h"
#include <memory>
#include <internal/renderer/mesh.h>

namespace jumi
{

    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    //                                             IMPLEMENTATION
    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    class scene_object_impl
    {
    friend class scene_object;
    public:
        scene_object_impl()
            : _world_position()
            , _orientation()
            , _scale(1.0f)
            , _mesh()
        {
        }

        scene_object_impl(const vec3& start_world_position)
            : _world_position(start_world_position)
            , _orientation()
            , _scale(1.0f)
            , _mesh()
        {
        }

        ~scene_object_impl()
        {
        }

        void move_by(const vec3& move_vector)
        {
            _world_position += move_vector;
        }

        void move_to(const vec3& move_vector)
        {
            _world_position = move_vector;
        }

        void rotate_by(const vec3& rotate_vector)
        {
            quat q = quat(glm::radians(rotate_vector));
            _orientation = _orientation * q;
        }

        void rotate_to(const vec3& rotate_vector)
        {
            _orientation = quat(glm::radians(rotate_vector));
        }

        void scale_by(const vec3& scale_vector)
        {
            _scale += scale_vector;
        }

        void scale_to(const vec3& scale_vector)
        {
            _scale = scale_vector;
        }

        const vec3& get_world_position()
        {
            return _world_position;
        }

        const vec3& get_rotation()
        {
            vec3 euler_angles_radians = glm::eulerAngles(_orientation);
            return glm::degrees(euler_angles_radians);
        }

        const vec3& get_scale()
        {
            return _scale;
        }

        mat4 get_model_matrix() const
        {
            mat4 model_matrix = glm::translate(mat4(1.0f), _world_position);
            mat4 rotation_matrix = glm::mat4_cast(_orientation);
            model_matrix = model_matrix * rotation_matrix;
            model_matrix = glm::scale(model_matrix, _scale);
            return model_matrix;
        }

        void prepare_for_render() const
        {
            _mesh.bind();
        }

        const mesh& get_mesh() const
        {
            return _mesh;
        }

    private:
        vec3 _world_position;
        quat _orientation;
        vec3 _scale;

        mesh _mesh;
    };


    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    //                                             INTERFACE
    // ----------------------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------------------
    scene_object::scene_object()
        : _impl(std::make_unique<scene_object_impl>())
    {

    }

    scene_object::scene_object(const vec3& start_world_position)
        : _impl(std::make_unique<scene_object_impl>(start_world_position))
    {
    }

    scene_object::~scene_object()
    {
    }

    void scene_object::move_by(const vec3& move_vector)
    {
        _impl->move_by(move_vector);
    }

    void scene_object::move_to(const vec3& move_vector)
    {
        _impl->move_to(move_vector);
    }

    void scene_object::rotate_by(const vec3& rotate_vector)
    {
        _impl->rotate_by(rotate_vector);
    }

    void scene_object::rotate_to(const vec3& rotate_vector)
    {
        _impl->rotate_to(rotate_vector);
    }

    void scene_object::scale_by(const vec3& scale_vector)
    {
        _impl->scale_by(scale_vector);
    }

    void scene_object::scale_to(const vec3& scale_vector)
    {
        _impl->scale_to(scale_vector);
    }

    const vec3& scene_object::get_world_position()
    {
        return _impl->get_world_position();
    }

    const vec3& scene_object::get_rotation()
    {
        return _impl->get_rotation();
    }

    const vec3& scene_object::get_scale()
    {
        return _impl->get_scale();
    }

    mat4 scene_object::get_model_matrix() const
    {
        return _impl->get_model_matrix();
    }

    const mesh& scene_object::get_mesh() const
    {
        return _impl->get_mesh();
    }

    void scene_object::prepare_for_render() const
    {
        _impl->prepare_for_render();
    }

}