#pragma once

#include "core/core.h"
#include "math/vector.h"
#include "math/matrix.h"

namespace jumi
{

    struct JUMI_API Transform
    {
    public:
        Transform();
        ~Transform();

        void move(const Vec3& position);
        void move_to(const Vec3& position);
        void rotate(const Vec3& rotation);
        void scale(const Vec3& scale);
        const Vec3& get_position() const;
        const Vec3& get_rotation() const;
        const Vec3& get_scale() const;

        Mat4 model_matrix() const;

    private:
        Vec3 _position;
        Vec3 _rotation;
        Vec3 _scale;
        Vec3 _left_vector;
        Vec3 _right_vector;
        Vec3 _forward_vector;
        Vec3 _back_vector;
        Vec3 _up_vector;
        Vec3 _down_vector;

        void update_direction_vectors();
        void update_left_vector();
        void update_right_vector();
        void update_forward_vector();
        void update_back_vector();
        void update_up_vector();
        void update_down_vector();
    };

}
