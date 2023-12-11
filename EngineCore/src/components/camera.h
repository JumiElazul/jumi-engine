#pragma once

#include "core/core.h"
#include "math/matrix.h"
#include "math/vector.h"
#include "components/transform.h"

namespace jumi
{
	enum ProjectionType
	{
		Orthagraphic,
		Perspective,

		MAX_PROJECTION_TYPES
	};

	inline const char* ProjectionTypeToString[]
	{
		"Orthagraphic",
		"Perspective"
	};

	struct CameraSpecification
	{
		ProjectionType projection_type;
		float fov;
		float aspect_ratio;
		float z_near;
		float z_far;
	};

	class JUMI_API Camera
	{
	public:
		Camera(CameraSpecification spec);
		~Camera();

		Mat4 view_matrix() const;
		Mat4 projection_matrix() const;
		void set_projection_type(ProjectionType projectionType);
		const CameraSpecification& get_camera_specification() const;
        Transform& get_transform();
		void calculate_projection_matrix();

	private:
		CameraSpecification _camera_specification;
		Mat4 _projection_matrix;
		Transform _transform;

		Mat4 calculate_perspective_matrix() const;
		Mat4 calculate_orthagraphic_matrix() const;
	};

}
