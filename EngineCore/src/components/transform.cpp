#include "EngineCore/components/transform.h"
#include "EngineCore/math/matrix.h"

namespace jumi
{

    Transform::Transform() :
        _position(),
        _rotation(),
        _scale() {}

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
        Mat4 model_matrix{ Mat4::identity() };
        model_matrix = Mat4::scale(model_matrix, _scale);
        model_matrix = Mat4::rotate(model_matrix, _rotation);
        model_matrix = Mat4::translate(model_matrix, _position);

        return model_matrix;
    }

    void Transform::update_direction_vectors()
    {

    }

    void Transform::update_left_vector()
    {

    }

    void Transform::update_right_vector()
    {

    }

    void Transform::update_forward_vector()
    {

    }

    void Transform::update_back_vector()
    {

    }

    void Transform::update_up_vector()
    {

    }

    void Transform::update_down_vector()
    {

    }

}
