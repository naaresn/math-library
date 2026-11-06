cmake_minimum_required(VERSION 3.20)
project(OpenGLRenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_executable(OpenGLRenderer ${SOURCES})

target_link_libraries(OpenGLRenderer PRIVATE glfw3 opengl32)