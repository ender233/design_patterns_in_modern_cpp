cmake_minimum_required(VERSION 3.8)
project(Mediation)

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65.1 COMPONENTS log thread system regex REQUIRED)

set(SOURCE_FILES main.cpp user_signal.cpp)
set(SOURCE_FILES2 user_signal.cpp)
add_executable(Mediation ${SOURCE_FILES})
target_link_libraries (Mediation ${Boost_LIBRARIES})


add_executable(User ${SOURCE_FILES2})
target_link_libraries (User ${Boost_LIBRARIES})
