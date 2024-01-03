#pragma once

#include "EngineCore/core/core.h"
#include <ostream>
#include <array>

namespace jumi
{
	class Vec3;

	class Mat4
	{
	public:
        friend std::ostream& operator<<(std::ostream& stream, const Mat4& mat4);

		Mat4();
        Mat4(float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8,
            float f9, float f10, float f11, float f12, float f13, float f14, float f15, float f16);
		~Mat4();

		Mat4 add(const Mat4& other) const;
		Mat4 subtract(const Mat4& other) const;
		Mat4 operator+(const Mat4& other) const;
		Mat4 operator-(const Mat4& other) const;
		Mat4 operator*(const Mat4& other) const;
		const std::array<float, 4>& operator[](int index) const;
		std::array<float, 4>& operator[](int index);

		const float* get_value_ptr() const;
        static Mat4 transpose(const Mat4& mat);
		static Mat4 translate(const Mat4& mat, const Vec3& translation);
		static Mat4 scale(const Mat4& mat, const Vec3& scale);
		static Mat4 rotate(const Mat4& mat, const Vec3& rotationDegrees);
		static Mat4 identity();

	private:
		std::array<std::array<float, 4>, 4> _matrix;
	};

	inline std::ostream& operator<<(std::ostream& stream, const Mat4& mat4)
	{
		for (size_t i = 0; i < 4; ++i)
		{
			stream << "[";
			for (int j = 0; j < 4; ++j)
			{
				stream << mat4._matrix[i][j];
				if (j != 3)
					stream << ",";
			}
			stream << "]";
			if (i != 3)
				stream << "\n";
		}
		return stream;
	}
}

