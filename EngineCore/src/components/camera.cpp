#include "EngineCore/components/camera.h"
#include "EngineCore/logging/logger.h"
#include <cmath>

namespace jumi
{

    Camera::Camera(CameraSpecification spec) :
        _camera_specification(spec),
		_projection_matrix(Mat4::identity()),
		_transform()
	{
		calculate_projection_matrix();
	}

	Camera::~Camera() { }

	Mat4 Camera::view_matrix() const
	{
		return Mat4::translate(Mat4::identity(), _transform.get_position());
	}

	Mat4 Camera::projection_matrix() const { return _projection_matrix; }

	void Camera::set_projection_type(ProjectionType projectionType)
	{
		JUMI_INFO("Camera ProjectionType being set to {}", ProjectionTypeToString[projectionType]);
		_camera_specification.projection_type = projectionType;

		calculate_perspective_matrix();
	}

	const CameraSpecification& Camera::get_camera_specification() const { return _camera_specification; }

	Transform& Camera::get_transform() { return _transform; }

	void Camera::calculate_projection_matrix()
	{
		switch (_camera_specification.projection_type)
		{
            case ProjectionType::Orthagraphic:
			{
				_projection_matrix = calculate_orthagraphic_matrix();
                break;
			}
            case ProjectionType::Perspective:
			{
				_projection_matrix = calculate_perspective_matrix();
                break;
			}
            case ProjectionType::MAX_PROJECTION_TYPES:
            {
                break;
            }
		}
	}

	Mat4 Camera::calculate_perspective_matrix() const
	{
		Mat4 result{ Mat4::identity() };

		float fov = _camera_specification.fov;
		float aspect = _camera_specification.aspect_ratio;
		float z_near = _camera_specification.z_near;
		float z_far = _camera_specification.z_far;
        float tan_half_fov = tan(fov / 2.0f);

        result[0][0] = 1.0f / (tan_half_fov * aspect);
        result[1][1] = 1.0f / tan_half_fov;
        result[2][2] = -(z_far + z_near) / (z_far - z_near);
        result[2][3] = -1.0f;
        result[3][2] = -(2.0f * z_far * z_near) / (z_far - z_near);

		return result;
	}

	Mat4 Camera::calculate_orthagraphic_matrix() const
	{
        Mat4 result{ Mat4::identity() };

        return result;
	}

}
