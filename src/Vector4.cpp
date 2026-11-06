#include "Vector4.hpp"
#include "MathUtils.hpp"
#include "Vector3.hpp"
#include <cmath>
#include <iostream>

namespace mathlib {
    Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}

    Vector4::Vector4(const Vector3& v, float w) : x(v.getX()), y(v.getY()), z(v.getZ()), w(w) {}

    float Vector4:: getX() const{return x;} 
    float Vector4:: getY() const{return y;}
    float Vector4:: getZ() const{return z;}
    float Vector4:: getW() const{return w;}

    void Vector4:: setX(float value){x = value;}
    void Vector4:: setY(float value){y = value;}
    void Vector4:: setZ(float value){z = value;}
    void Vector4:: setW(float value){w = value;}

    Vector3 Vector4::toVector3() const{
        return Vector3(x, y, z);
    }

    Vector4 Vector4::operator+(const Vector4& other) const{
        return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }
    
    Vector4 Vector4::operator-(const Vector4& other) const{
        return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vector4 Vector4::operator*(float scalar) const{
        return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    float Vector4::magnitude() const{
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    Vector4 Vector4::normalize() const{
        float mag = magnitude();

        if(mag < 1e-6f){
            return Vector4(0.0f, 0.0f,  0.0f, 0.0f);
        }

        return Vector4(x/mag, y/mag, z/mag, w/mag);
    }

    float Vector4::dot(const Vector4& other) const{
        return x * other.x + y * other.y + z * other.z + w * other.z; 
    }

    bool Vector4::isPoint() const{
        return mathlib::approximatelyEqual(w, 1.0f);
    }

    bool Vector4::isDirection() const{
        return mathlib::approximatelyEqual(w, 0.0f);
    }

    void Vector4:: print() const{
        std::cout << "(" << x << "," << y << "," << z << "," << w << ")";

    }


}