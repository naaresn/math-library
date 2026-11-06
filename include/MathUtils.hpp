#ifndef MATHLIB_MATHUTILS_HPP
#define MATHLIB_MATHUTILS_HPP

namespace mathlib{
constexpr float PI = 3.14159265358979323846f;

float degreesToRadians(float degrees);
float radiansToDegrees(float radians);

float camp(float value, float minValue, float maxValue);
float lerp(float a, float b, float t);
bool approximatelyEqual(float a, float b, float epsilon = 1e-6f);

}

#endif