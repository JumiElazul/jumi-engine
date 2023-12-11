#include "components/transform.h"
#include "math/matrix.h"

namespace jumi
{

    Transform::Transform() {}

    Transform::~Transform() {}

    void Transform::move(const Vec3& position) { _position += position; }

    void Transform::move_to(const Vec3& position) { _position = position; }

    void Transform::rotate(const Vec3& rotation) { _rotation = rotation; }

    void Transform::scale(const Vec3& scale) { _scale = scale; }

    const Vec3& Transform::get_position() const { return _position; }

    const Vec3& Transform::get_rotation() const { return _rotation; }

    const Vec3& Transform::get_scale() const { return _scale; }

    Mat4 Transform::model_matrix() const
    {
        Mat4 modelMatrix{ Mat4::identity() };
        modelMatrix = Mat4::scale(modelMatrix, _scale);
        modelMatrix = Mat4::rotate(modelMatrix, _rotation);
        modelMatrix = Mat4::translate(modelMatrix, _position);

        return modelMatrix;
    }


}
