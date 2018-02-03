cmake_minimum_required(VERSION 3.9)
project(Factory)

set(CMAKE_CXX_STANDARD 11)

add_executable(Factory main.cpp renderer.hpp openglrenderer.hpp directxrenderer.hpp rendererfactory.hpp rendererfactory.cpp)