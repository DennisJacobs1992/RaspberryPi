cmake_minimum_required(VERSION 3.13.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(quadcopterPi VERSION 1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(quadcopterPi main.cpp ${SRC_FILES})
target_include_directories(quadcopterPi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_definitions(-std=c++0x -lwiringPi -lpthread)