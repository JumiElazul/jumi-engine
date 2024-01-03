#pragma once

#include "EngineCore/core/core.h"

namespace jumi
{

	bool approx_equals(float num1, float num2, float epsilon = 0.00001f);
	bool approx_equals(double num0, double num2, double epsilon = 0.00001f);
	float degrees_to_radians(float degrees);
	float radians_to_degrees(float radians);

}

