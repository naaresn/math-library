# MathLibrary — Vector & Geometry Math Library

A small, hand-written C++17 math library for 3D graphics, built without GLM or
other math dependencies. It provides `Vector3` and `Vector4` types plus common
math helpers, and is intended as the foundation for a larger OpenGL renderer
project (positions, rotations, scaling, cameras, and light directions).

The current `main.cpp` is a **console demo** that exercises the library. GLFW
and glad are already vendored in the repository for the upcoming rendering
stage, but no window or render loop exists yet. All source code and console

## Features

### `Vector3`
- Construction with default values `(0, 0, 0)`
- Encapsulated `x`, `y`, `z` with getters and setters
- Operator overloading: `+`, `-`, `*` (scalar), `==` (epsilon-based)
- `magnitude()`, `normalize()`, `dot()`, `cross()`, `print()`
- Zero-safe normalization (returns a zero vector when the magnitude is near zero)

### `Vector4`
- Homogeneous 4D vector with default `w = 1`
- Construct from a `Vector3` plus an explicit `w`
- Encapsulated `x`, `y`, `z`, `w` with getters and setters
- Operator overloading: `+`, `-`, `*` (scalar)
- `magnitude()`, `normalize()`, `dot()`, `print()`
- `toVector3()` conversion
- `isPoint()` / `isDirection()` helpers based on the `w` component

### `MathUtils`
- `PI` constant
- `degreesToRadians()` / `radiansToDegrees()`
- `clamp(value, min, max)`
- `lerp(a, b, t)`
- `approximatelyEqual(a, b, epsilon = 1e-6f)`

## Project structure

```text
MathLibrary/
├── CMakeLists.txt
├── README.md
├── include/
│   ├── Vector3.hpp
│   ├── Vector4.hpp
│   ├── MathUtils.hpp
│   ├── GLFW/            # Vendored GLFW headers (for the rendering stage)
│   ├── glad/            # glad OpenGL loader header
│   └── KHR/             # Khronos platform header
├── lib/
│   └── glfw3.lib        # Prebuilt GLFW import library (MSVC-compatible)
├── src/
│   ├── Vector3.cpp
│   ├── Vector4.cpp
│   ├── MathUtils.cpp
│   ├── glad.c           # OpenGL loader implementation
│   └── main.cpp         # Console demo
└── build/               # CMake-generated build tree (not source)
```

The CMake target is named **`OpenGLRenderer`** and links `glfw3` and
`opengl32`, even though the current executable is still a console-only demo.
`build/` may also contain an older `MathLibrary.exe` from a previous target
name.

## Requirements

- A C++17 compiler (tested with MSVC/clang-cl on Windows)
- CMake 3.20 or newer
- Windows for the bundled `lib/glfw3.lib` (MSVC-compatible import library)

## Build & run

### Using CMake (recommended)

```bash
cmake -S . -B build
cmake --build build --config Debug
./build/Debug/OpenGLRenderer.exe
```

With a single-config generator (for example MinGW Makefiles or Ninja), the
binary is written directly to the build directory:

```bash
cmake -S . -B build -G Ninja
cmake --build build
./build/OpenGLRenderer.exe
```

### Quick compile without CMake

The console demo does not use GLFW or glad, so only the math sources are
needed:

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/Vector3.cpp src/Vector4.cpp src/MathUtils.cpp -o demo
./demo
```

> The demo ends with `std::cin.get()`, so press **Enter** to close it.

## Usage example

```cpp
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "MathUtils.hpp"
#include <iostream>

int main() {
    using mathlib::Vector3;
    using mathlib::Vector4;

    Vector3 a(10.0f, 5.0f, 8.0f);
    Vector3 b(4.0f, 12.0f, 2.0f);

    Vector3 sum   = a + b;
    Vector3 diff  = a - b;
    Vector3 cross = a.cross(b);

    std::cout << "a + b   = "; sum.print();   std::cout << "\n";
    std::cout << "a - b   = "; diff.print();  std::cout << "\n";
    std::cout << "a x b   = "; cross.print(); std::cout << "\n";
    std::cout << "a . b   = " << a.dot(b) << "\n";
    std::cout << "|a|     = " << a.magnitude() << "\n";

    // Homogeneous coordinates: w = 1 is a point, w = 0 is a direction.
    Vector4 point(a, 1.0f);
    Vector4 lightDirection(0.0f, -1.0f, 0.0f, 0.0f);

    std::cout << "is point:     " << point.isPoint() << "\n";
    std::cout << "is direction: " << lightDirection.isDirection() << "\n";

    // Frame update: position += velocity * deltaTime
    Vector3 position(0.0f, 0.0f, 0.0f);
    Vector3 velocity(1.0f, 0.0f, 0.0f);
    position = position + velocity * 0.016f;

    std::cout << "position after one frame = "; position.print(); std::cout << "\n";
}
```

## API reference

### `mathlib::Vector3`

| Member | Description |
| --- | --- |
| `Vector3(float x = 0, float y = 0, float z = 0)` | Constructs a vector |
| `getX()`, `getY()`, `getZ()` | Component accessors |
| `setX(v)`, `setY(v)`, `setZ(v)` | Component mutators |
| `operator+(const Vector3&)` | Component-wise addition |
| `operator-(const Vector3&)` | Component-wise subtraction |
| `operator*(float)` | Scalar multiplication |
| `operator==(const Vector3&)` | Epsilon-based comparison |
| `magnitude()` | Euclidean length |
| `normalize()` | Unit vector, or zero vector if length ≈ 0 |
| `dot(const Vector3&)` | Dot product |
| `cross(const Vector3&)` | Cross product |
| `print()` | Prints `(x, y, z)` to `std::cout` |

### `mathlib::Vector4`

| Member | Description |
| --- | --- |
| `Vector4(float x = 0, float y = 0, float z = 0, float w = 1)` | Constructs a 4D vector |
| `Vector4(const Vector3&, float w)` | Expands a `Vector3` into homogeneous form |
| `getX()`, `getY()`, `getZ()`, `getW()` | Component accessors |
| `setX(v)`, `setY(v)`, `setZ(v)`, `setW(v)` | Component mutators |
| `toVector3()` | Drops `w` and returns a `Vector3` |
| `operator+(const Vector4&)` | Component-wise addition |
| `operator-(const Vector4&)` | Component-wise subtraction |
| `operator*(float)` | Scalar multiplication |
| `magnitude()` | Euclidean length in 4D |
| `normalize()` | Unit vector, or zero vector if length ≈ 0 |
| `dot(const Vector4&)` | Dot product |
| `isPoint()` | `true` when `w ≈ 1` |
| `isDirection()` | `true` when `w ≈ 0` |
| `print()` | Prints `(x,y,z,w)` to `std::cout` |

### `mathlib` utilities

| Function | Description |
| --- | --- |
| `degreesToRadians(deg)` | Converts degrees to radians |
| `radiansToDegrees(rad)` | Converts radians to degrees |
| `clamp(value, min, max)` | Constrains a value to a range |
| `lerp(a, b, t)` | Linear interpolation: `a + t * (b - a)` |
| `approximatelyEqual(a, b, eps)` | Floating-point comparison |

## Sample output

Output from the current build:

```text
A = (10, 5, 8)
B = (4, 12, 2)
A + B = (14, 17, 10)
A - B = (6, -7, 6)
Magnitude A = 13.7477
Magnitude B = 12.8062
Normalize A = (0.727393, 0.363696, 0.581914)
Normalize B = (0.312348, 0.937043, 0.156174)
Dot (A, B) = 116
Cross (A, B) = (-86, 12, 100)
Lerp (A, B, 0.5) = (9.7, 5.35, 7.7)
Object position after 1 frame = (0.016, 0, 0)

================== VECTOR 4 ==================
Point A, w(1) : (10,5,8,1)
isPoint : true
Direction light (w = 0) = (0,-1,0,0)
isDirection: true
Point A + direction light = (10,4,8,1)
Back to 3d = (10, 5, 8)
```

## Notes and known issues

These are current behaviors of the code, documented here so they are not
mistaken for intended API guarantees:

- `MathUtils.hpp` declares `camp(...)`, while `MathUtils.cpp` defines
  `clamp(...)`. The names do not match; the demo never calls `clamp`, so it
  still builds.
- `Vector4::dot()` multiplies the fourth pair using `other.z` instead of
  `other.w`.
- The demo prints `Lerp (A, B, 0.5)` but actually uses `t = 0.05`.
- `normalize()` returns a zero vector when the magnitude is below `1e-6`
  rather than throwing or returning the original vector.
- The CMake project/target is `OpenGLRenderer`, but the current program has no
  window or rendering code. GLFW/glad are prepared for the next stage.

## Learning objectives

This project was built as a hands-on exercise covering:

- Classes and access specifiers (`private` / `public`)
- Constructors and member initializer lists
- Encapsulation through getters and setters
- `const`-qualified member functions
- Passing by `const` reference (`const Vector3&`)
- Operator overloading (`+`, `-`, `*`, `==`)
- Header/source separation (`.hpp` in `include/`, `.cpp` in `src/`)
- Namespaces (`mathlib::`)
- Multi-file project organization with CMake

## Possible next steps

1. Fix the `clamp` / `camp` naming mismatch and the `Vector4::dot()` term.
2. Add `operator/` and compound assignment operators (`+=`, `-=`, `*=`, `/=`).
3. Add a `Vector2` type for 2D work.
4. Add a free function `distance(a, b)` based on `(a - b).magnitude()`.
5. Add equality/stream operators (`<<`) instead of printing from the class.
6. Write unit tests with fixed expected values.
7. Open a GLFW window and use the library for transforms, a camera, and
   lighting in the rendering stage.

## License

No license file is included in this repository. Treat it as educational code
unless a license is added.
