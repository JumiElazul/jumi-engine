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
    };

}
