#pragma once

#include "core/core.h"

namespace jumi
{

	bool JUMI_API approx_equals(float num1, float num2, float epsilon = 0.00001f);
	bool JUMI_API approx_equals(double num0, double num2, double epsilon = 0.00001f);
	float JUMI_API degrees_to_radians(float degrees);
	float JUMI_API radians_to_degrees(float radians);

}

