#include "Vector3.hpp"
#include "MathUtils.hpp"
#include <cmath>
#include <iostream>


namespace mathlib {
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z){
}

float Vector3::getX()const{return x;}
float Vector3::getY()const{return y;}
float Vector3::getZ()const{return z;}

void Vector3::setX(float value) {x = value;}
void Vector3::setY(float value) {y = value;}
void Vector3::setZ(float value) {z = value;}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

bool Vector3::operator==(const Vector3& other) const{
    return mathlib::approximatelyEqual(x, other.x)&&
            mathlib::approximatelyEqual(y, other.y)&&
            mathlib::approximatelyEqual(z, other.z);
}

float Vector3::magnitude() const{
    return std::sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::normalize()const{
    float mag = magnitude();
    if(mag < 1e-6f){
        return Vector3(0.0f, 0.0f, 0.0f);
    }

    return Vector3(x/mag, y/mag, z/mag);
}

float Vector3::dot(const Vector3& other)const{
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other)const{
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

void Vector3::print()const{
    std::cout << "(" << x << ", " << y << ", " << z << ")";
}

}