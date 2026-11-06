#include "Vector3.hpp"
#include "Vector4.hpp"
#include "MathUtils.hpp"
#include <ios>
#include <iostream>

int main(){
    using mathlib::Vector3;

    Vector3 A(10.0f, 5.0f, 8.0f);
    Vector3 B(4.0f, 12.0f, 2.0f);
    std::cout << "A = ";
    A.print();
    std::cout << "\n";

    std::cout << "B = ";
    B.print();
    std::cout << "\n";

    Vector3 sum = A + B;
    std::cout << "A + B = ";
    sum.print();
    std::cout << "\n";

    Vector3 diff = A - B;
    std::cout << "A - B = ";
    diff.print();
    std::cout << "\n";

    std::cout << "Magnitude A = " << A.magnitude() << "\n";
    std::cout << "Magnitude B = " << B.magnitude() << "\n";

    std::cout << "Normalize A = "; 
    A.normalize().print(); 
    std::cout << "\n";

    std::cout << "Normalize B = "; 
    B.normalize().print(); 
    std::cout << "\n";
    
    std:: cout << "Dot (A, B) = " << A.dot(B);
    std::cout << "\n";
    
    Vector3 crossResult = A.cross(B);
    std::cout << "Cross (A, B) = ";
    crossResult.print();
    std::cout << "\n";

    float t = 0.05f;
    Vector3 lerped(
        mathlib::lerp(A.getX(), B.getX(), t ),
        mathlib::lerp(A.getY(), B.getY(), t),
        mathlib::lerp(A.getZ(), B.getZ(), t)
    );
    std::cout << "Lerp (A, B, 0.5) = ";
    lerped.print();
    std::cout << "\n";

    Vector3 objectPosition(0.0f, 0.0f, 0.0f);
    Vector3 objectVecocity(1.0f, 0.0f, 0.0f);

    float deltaTime = 0.016f;
    objectPosition = objectPosition + (objectVecocity * deltaTime);
    std::cout << "Object position after 1 frame = " ;
    objectPosition.print();
    std::cout << "\n\n";


    using mathlib::Vector4;
    std::cout << "================== VECTOR 4 ==================\n";

    Vector4 pointA(A, 1.0f);
    std::cout << "Point A, w(1) : ";
    pointA.print();
    std::cout << "\n";
    
    std::cout << "isPoint : " << std::boolalpha << pointA.isPoint() << "\n";

    Vector4 directionLight(0.0f, -1.0f, 0.0f, 0.0f);
    std::cout << "Direction light (w = 0) = ";
    directionLight.print();
    std::cout << "\n";
    std::cout << "isDirection: " << std::boolalpha << directionLight.isDirection() << "\n";


    Vector4 sumA = pointA + directionLight;
    std::cout << "Point A + direction light = ";
    sumA.print();
    std::cout << "\n";

    Vector3 to3D = pointA.toVector3();
    std::cout << "Back to 3d = ";
    to3D.print();
    std::cout << "\n";


    std::cin.get();
    return 0;
}