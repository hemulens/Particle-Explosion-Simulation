cmake_minimum_required(VERSION 2.6)

# SET COMPILER TO GCC
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

project(Fire-Particles-Simulation)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(particles main.cpp)
target_link_libraries(particles ${SDL2_LIBRARIES})