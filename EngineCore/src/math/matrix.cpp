#include "math/matrix.h"
#include "math/functions.h"
#include "math/vector.h"
#include <cmath>

namespace jumi
{

    Mat4::Mat4() : _matrix() { }

    Mat4::Mat4(float f1, float f2, float f3, float f4,
        float f5, float f6, float f7, float f8,
        float f9, float f10, float f11, float f12,
        float f13, float f14, float f15, float f16)
        : _matrix{{
            {f1,   f2,  f3,  f4},
            {f5,   f6,  f7,  f8},
            {f9,  f10, f11, f12},
            {f13, f14, f15, f16}}} {}

    Mat4::~Mat4() { }

	Mat4 Mat4::add(const Mat4& other) const
	{
		Mat4 result;
		result = *this + other;
		return result;
	}

	Mat4 Mat4::subtract(const Mat4& other) const
	{
		Mat4 result;
		result = *this - other;
		return result;
	}

	const float* Mat4::get_value_ptr() const
	{
		return &(_matrix[0][0]);
	}

	Mat4 Mat4::transpose(const Mat4& mat)
	{
		Mat4 result = mat;
        for (size_t i = 0; i < 4; ++i) 
        {
            for (size_t j = i + 1; j < 4; ++j) 
			{
				result[i][j] = mat[j][i];
            }
        }
		return result;
	}
	
	Mat4 Mat4::translate(const Mat4& mat, const Vec3& translation)
	{
		Mat4 result = mat;
		result[3][0] += translation.x;
		result[3][1] += translation.y;
		result[3][2] += translation.z;
		return result;
	}

	Mat4 Mat4::scale(const Mat4& mat, const Vec3& scale)
	{
		Mat4 result = mat;
		result[0][0] *= scale.x;
		result[1][1] *= scale.y;
		result[2][2] *= scale.z;
		return result;
	}

    Mat4 Mat4::rotate(const Mat4& mat, const Vec3& rotationDegrees)
    {
        Vec3 rotationRadians;
        rotationRadians.x = degrees_to_radians(rotationDegrees.x);
        rotationRadians.y = degrees_to_radians(rotationDegrees.y);
        rotationRadians.z = degrees_to_radians(rotationDegrees.z);

        Mat4 rotateX{ Mat4::identity() };
        Mat4 rotateY{ Mat4::identity() };
        Mat4 rotateZ{ Mat4::identity() };

        rotateX[1][1] = cos(rotationRadians.x);
        rotateX[1][2] = -sin(rotationRadians.x);
        rotateX[2][1] = sin(rotationRadians.x);
        rotateX[2][2] = cos(rotationRadians.x);

        rotateY[0][0] = cos(rotationRadians.y);
        rotateY[0][2] = sin(rotationRadians.y);
        rotateY[2][0] = -sin(rotationRadians.y);
        rotateY[2][2] = cos(rotationRadians.y);

        rotateZ[0][0] = cos(rotationRadians.z);
        rotateZ[0][1] = -sin(rotationRadians.z);
        rotateZ[1][0] = sin(rotationRadians.z);
        rotateZ[1][1] = cos(rotationRadians.z);

        Mat4 combinedRotation = rotateZ * rotateY * rotateX;
        Mat4 result = mat * combinedRotation;

        return result;
    }

    Mat4 Mat4::operator+(const Mat4& other) const
    {
        Mat4 result;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                result[i][j] = _matrix[i][j] + other._matrix[i][j];
            }
        }
        return result;
    }

    Mat4 Mat4::operator-(const Mat4& other) const
    {
        Mat4 result;
        for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				result[i][j] = _matrix[i][j] - other._matrix[i][j];
			}
		}
		return result;
	}

	Mat4 Mat4::operator*(const Mat4& other) const
	{
		Mat4 result;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				result[i][j] = 0;
				for (int k = 0; k < 4; ++k)
				{
					result[i][j] += _matrix[i][k] * other._matrix[k][j];
				}
			}
		}
		return result;
	}

	const std::array<float, 4>& Mat4::operator[](int index) const { return _matrix[index]; }
	std::array<float, 4>& Mat4::operator[](int index) { return _matrix[index]; }

	Mat4 Mat4::identity()
	{
		Mat4 mat4;
		mat4[0][0] = 1.0f;
		mat4[1][1] = 1.0f;
		mat4[2][2] = 1.0f;
		mat4[3][3] = 1.0f;
		return mat4;
	}

}

