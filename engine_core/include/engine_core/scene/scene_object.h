#ifndef JUMI_ENGINE_ENGINE_CORE_SCENE_SCENE_OBJECT_H
#define JUMI_ENGINE_ENGINE_CORE_SCENE_SCENE_OBJECT_H

#include "jumi_math/math/math_types.h"
#include <memory>

namespace jumi
{
    class mesh;
    class scene_object_impl;
    class scene_object
    {
    public:
        scene_object();
        scene_object(const vec3& start_world_position);
        ~scene_object();
        void move_by(const vec3& move_vector);
        void move_to(const vec3& move_vector);
        void rotate_by(const vec3& rotate_vector);
        void rotate_to(const vec3& rotate_vector);
        void scale_by(const vec3& scale_vector);
        void scale_to(const vec3& scale_vector);
        const vec3& get_world_position();
        const vec3& get_rotation();
        const vec3& get_scale();
        mat4 get_model_matrix() const;

        const mesh& get_mesh() const;

        void prepare_for_render() const;

    private:
        std::unique_ptr<scene_object_impl> _impl;
    };

}

#endif

