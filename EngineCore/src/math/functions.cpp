#include "math/functions.h"
#include "core/core.h"
#include <cmath>

namespace jumi
{

	bool JUMI_API approx_equals(float num1, float num2, float epsilon)
	{
		return std::abs(num1 - num2) <= epsilon;
	}

	bool JUMI_API approx_equals(double num1, double num2, double epsilon)
	{
		return std::abs(num1 - num2) <= epsilon;
	}

	float JUMI_API degrees_to_radians(float degrees)
	{
        return degrees * (M_PI / 180.0f);
	}

	float JUMI_API radians_to_degrees(float radians)
	{
        return radians * (180.0f / M_PI);
	}

}
