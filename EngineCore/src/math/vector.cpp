#include "EngineCore/math/vector.h"
#include "EngineCore/core/core.h"
#include "EngineCore/math/functions.h"
#include <cmath>
#include <ostream>

namespace jumi
{
	Vec2::Vec2() : x(), y() {}
	Vec2::Vec2(float init) : x(init), y(init) {}
	Vec2::Vec2(float initX, float initY) : x(initX), y(initY) {}

	Vec2 Vec2::add(const Vec2& other) const { return Vec2(x + other.x, y + other.y); }
	Vec2 Vec2::subtract(const Vec2& other) const { return Vec2(x - other.x, y - other.y); }

	Vec2 Vec2::operator+(const Vec2& other) const { return add(other); }
	Vec2 Vec2::operator-(const Vec2& other) const { return subtract(other); }
    Vec2 Vec2::operator*(float scalar) const { return Vec2(x * scalar, y * scalar); }
    Vec2 Vec2::operator/(float scalar) const 
    { 
        if (jumi::approx_equals(scalar, 0))
        {
			throw jumi::divide_by_zero_exception("Division by zero (or near-zero) is not allowed.");
        }

        return Vec2(x / scalar, y / scalar);
    }

    Vec2& Vec2::operator+=(const Vec2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& Vec2::operator-=(const Vec2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& Vec2::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2& Vec2::operator/=(float scalar)
    {
        if (jumi::approx_equals(scalar, 0))
			throw jumi::divide_by_zero_exception("Division by zero (or near-zero) is not allowed.");

        x /= scalar;
        y /= scalar;
        return *this;
    }

    Vec2 Vec2::operator-() const { return Vec2(-x, -y); }

    bool Vec2::operator==(const Vec2& other) const { return (jumi::approx_equals(x, other.x) && jumi::approx_equals(y, other.y)); }

    bool Vec2::operator!=(const Vec2& other) const { return !(*this == other); }

	float Vec2::dot(const Vec2& other) const { return x * other.x + y * other.y; }
	float Vec2::magnitude() const { return std::sqrt(x * x + y * y); }

    Vec2& Vec2::normalize() 
	{
        float len = magnitude();

        if (jumi::approx_equals(len, 0))
			throw jumi::divide_by_zero_exception("Vectors with Magnitude/Length of 0 cannot be normalized");

		x /= len;
		y /= len;
        return *this;
    }

    Vec2 Vec2::get_normalized() const
    {
        Vec2 normalized(*this);
        return normalized.normalize();
    }

    float Vec2::distance(const Vec2& other) const
    {
		return (*this - other).magnitude();
    }

    std::ostream& operator<<(std::ostream& stream, const Vec2& vec) 
    {
        stream << '(' << vec.x << "," << vec.y << ')';
        return stream;
    }

	Vec3::Vec3() : x(), y(), z() {}
	Vec3::Vec3(float init) : x(init), y(init), z(init) {}
	Vec3::Vec3(float initX, float initY, float initZ) : x(initX), y(initY), z(initZ) {}

    Vec3 Vec3::add(const Vec3& other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
    Vec3 Vec3::subtract(const Vec3& other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
    Vec3 Vec3::operator+(const Vec3& other) const { return add(other); }
    Vec3 Vec3::operator-(const Vec3& other) const { return subtract(other); }
    Vec3 Vec3::operator*(float scalar) const { return Vec3(x * scalar, y * scalar, z * scalar); }

    Vec3 Vec3::operator/(float scalar) const
    {
        if (jumi::approx_equals(scalar, 0))
			throw jumi::divide_by_zero_exception("Division by zero (or near-zero) is not allowed.");

        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    Vec3& Vec3::operator+=(const Vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3& Vec3::operator-=(const Vec3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3& Vec3::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vec3& Vec3::operator/=(float scalar)
    {
        if (jumi::approx_equals(scalar, 0))
			throw jumi::divide_by_zero_exception("Division by zero (or near-zero) is not allowed.");

        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vec3 Vec3::operator-() const { return Vec3(-x, -y, -z); }

    bool Vec3::operator==(const Vec3& other) const
    {
        return jumi::approx_equals(x, other.x) &&
			   jumi::approx_equals(y, other.y) &&
			   jumi::approx_equals(z, other.z);
    }

    bool Vec3::operator!=(const Vec3& other) const { return !(*this == other); }

    float Vec3::dot(const Vec3& other) const { return x * other.x + y * other.y + z * other.z; }

    float Vec3::normalized_dot(const Vec3& other) const
    {
        Vec3 normA = this->get_normalized();
        Vec3 normB = other.get_normalized();
		return normA.x * normB.x + normA.y * normB.y + normA.z * normB.z;
    }

    float Vec3::magnitude() const { return std::sqrt(x * x + y * y + z * z); }

    Vec3& Vec3::normalize()
    {
        float len = magnitude();

        if (jumi::approx_equals(len, 0))
			throw jumi::divide_by_zero_exception("Vectors with Magnitude/Length of 0 cannot be normalized");

		x /= len;
		y /= len;
		z /= len;
        return *this;
    }

    Vec3 Vec3::get_normalized() const
    {
        Vec3 normalized(*this);
        return normalized.normalize();
    }

    float Vec3::distance(const Vec3& other) const { return (*this - other).magnitude(); }

    std::ostream& operator<<(std::ostream& stream, const Vec3& vec) 
    {
        stream << '(' << vec.x << "," << vec.y << ',' << vec.z << ')';
        return stream;
    }
}
