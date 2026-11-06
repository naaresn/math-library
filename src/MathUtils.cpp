#include "MathUtils.hpp"
#include <cmath>

namespace mathlib{

float degreesToRadians(float degrees){
    return degrees * (PI / 180.0f);
}

float radiansToDegrees(float radians){
    return radians * (180.0f / PI);
}

float clamp(float value, float minValue, float maxValue){
    if(value < minValue) return minValue;
    if(value > maxValue) return maxValue;

    return value;
}

float lerp(float a, float b, float t){
    return a + t * (b - a);
}

bool approximatelyEqual(float a, float b, float epsilon){
    return std::fabs(a-b) < epsilon;
}








}