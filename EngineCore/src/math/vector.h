#pragma once

#include "core/core.h"
#include <iosfwd>

namespace jumi
{

	class JUMI_API Vec2
	{
	public:
		float x;
		float y;

		Vec2();
		Vec2(float init);
		Vec2(float initX, float initY);

		Vec2 add(const Vec2& other) const;
		Vec2 subtract(const Vec2& other) const;

		Vec2 operator+(const Vec2& other) const;
		Vec2 operator-(const Vec2& other) const;
		Vec2 operator*(float scalar) const;
		Vec2 operator/(float scalar) const;
		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(float scalar);
		Vec2& operator/=(float scalar);
		Vec2 operator-() const;
		bool operator==(const Vec2& other) const;
		bool operator!=(const Vec2& other) const;

		float dot(const Vec2& other) const;
		float magnitude() const;
		Vec2& normalize();
		Vec2 get_normalized() const;
		float distance(const Vec2& other) const;
	};

	class JUMI_API Vec3
	{
	public:
		union
		{
			float x{};
			float r;
		};
		union
		{
			float y{};
			float g;
		};
		union
		{
			float z{};
			float b;
		};

		Vec3();
		Vec3(float init);
		Vec3(float initX, float initY, float initZ);

		Vec3 add(const Vec3& other) const;
		Vec3 subtract(const Vec3& other) const;

		Vec3 operator+(const Vec3& other) const;
		Vec3 operator-(const Vec3& other) const;
		Vec3 operator*(float scalar) const;
		Vec3 operator/(float scalar) const;
		Vec3& operator+=(const Vec3& other);
		Vec3& operator-=(const Vec3& other);
		Vec3& operator*=(float scalar);
		Vec3& operator/=(float scalar);
		Vec3 operator-() const;
		bool operator==(const Vec3& other) const;
		bool operator!=(const Vec3& other) const;

		float dot(const Vec3& other) const;
		float normalized_dot(const Vec3& other) const;
		float magnitude() const;
		Vec3& normalize();
		Vec3 get_normalized() const;
		float distance(const Vec3& other) const;
	};

	JUMI_API std::ostream& operator<<(std::ostream& stream, const Vec2& vec);
	JUMI_API std::ostream& operator<<(std::ostream& stream, const Vec3& vec);

}
