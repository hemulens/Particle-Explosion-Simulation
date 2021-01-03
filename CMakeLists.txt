cmake_minimum_required(VERSION 2.6)

# SET COMPILER TO GCC
set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(Particle-Motion-Simulation)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# INCLUDE ALL .CPP FILES FROM SRC DIRECTORY
file(GLOB project_SRCS src/*.cpp)

add_executable(particles ${project_SRCS})
target_link_libraries(particles ${SDL2_LIBRARIES})





# IF FILES ARE IN MAIN PROJECT FOLDER (NOT SRC)
# add_executable(particles main.cpp screen.cpp particle.cpp swarm.cpp)