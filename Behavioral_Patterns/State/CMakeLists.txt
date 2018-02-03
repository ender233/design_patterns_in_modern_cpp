cmake_minimum_required(VERSION 3.9)
project(State)

set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65.1 COMPONENTS log thread system regex REQUIRED)

add_executable(State main.cpp)
target_link_libraries (State ${Boost_LIBRARIES})
