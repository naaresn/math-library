#ifndef MATHLIB_VECTOR4_HPP
#define MATHLIB_VECTOR4_HPP
#include "Vector3.hpp"


namespace mathlib{

class Vector4{
private:
    float x;
    float y;
    float z;
    float w;

public:
    Vector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);

    Vector4(const Vector3& v, float w);

    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;

    void setX(float value);
    void setZ(float value);
    void setY(float value);
    void setW(float value);

    Vector3 toVector3() const;

    Vector4 operator+(const Vector4& other) const;
    Vector4 operator-(const Vector4& other) const;
    Vector4 operator*(float scalar) const;

    float magnitude() const;
    Vector4 normalize() const;
    float dot(const Vector4& other) const;
    bool isPoint() const;
    bool isDirection() const;
    void print() const;
};




}
#endif