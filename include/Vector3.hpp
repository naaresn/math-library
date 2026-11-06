#ifndef MATHLIB_VECTOR3_HPP
#define MATHLIB_VECTOR3_HPP

namespace mathlib {

class Vector3 {
private:
    float x;
    float y;
    float z;

public:
    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float value);
    void setY(float value);
    void setZ(float value);

    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(float scalar) const;
    bool operator==(const Vector3& other) const;

    float magnitude() const;
    Vector3 normalize() const;
    float dot(const Vector3& other) const;
    Vector3 cross(const Vector3& other) const;
    void print() const;

};

}

#endif







