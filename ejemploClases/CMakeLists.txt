cmake_minimum_required(VERSION 3.10)

# Set the project name

project(EjemploClases)

include_directories(include)

# # Add the executable for CubeUnified.cpp
# add_executable(cubeUnified Example1.cpp)

# Add the executable for ComplexUnified.cpp
add_executable(ComplexUnified complex.cpp)

# # Add the executable for VehicleUnified.cpp 
# add_executable(VehicleUnified Vehicle.cpp)

add_library(ComplexLib src/Complex.cpp)
add_library(SphereLib src/Sphere.cpp)
add_library(CubeLib src/Cube.cpp)

# Add the executable for Cube.cpp
add_executable(ComplexSeparated src/main.cpp)
target_link_libraries(ComplexSeparated ComplexLib SphereLib CubeLib)

add_executable(ComplexSeparated2 src/main.cpp src/Complex.cpp src/Sphere.cpp src/Cube.cpp)


