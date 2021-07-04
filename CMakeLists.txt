cmake_minimum_required(VERSION 3.13.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(quadcopterPi VERSION 1.0)

file(GLOB_RECURSE SRC_FILES ../src/*.cpp)
add_executable(quadcopterPi main.cpp ${SRC_FILES})

find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
target_link_libraries(quadcopterPi ${WIRINGPI_LIBRARIES})

target_include_directories(quadcopterPi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)