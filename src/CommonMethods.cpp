#include "CommonMethods.h"

#include <cmath>

namespace blocki
{
constexpr float EPSILON = 0.001f;

bool FloatClose(float lhs, float rhs)
{
	return std::abs(lhs - rhs) < EPSILON;
}
}