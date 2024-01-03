#include "EngineCore/math/functions.h"
#include "EngineCore/core/core.h"
#include <cmath>

#ifdef JUMI_WINDOWS
#include <corecrt_math_defines.h>
#endif

namespace jumi
{

	bool approx_equals(float num1, float num2, float epsilon)
	{
		return std::abs(num1 - num2) <= epsilon;
	}

	bool approx_equals(double num1, double num2, double epsilon)
	{
		return std::abs(num1 - num2) <= epsilon;
	}

	float degrees_to_radians(float degrees)
	{
        return degrees * (M_PI / 180.0f);
	}

	float radians_to_degrees(float radians)
	{
        return radians * (180.0f / M_PI);
	}

}
