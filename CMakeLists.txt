cmake_minimum_required(VERSION, 3.10)
# Set the project name.
project(Propiertary-Engine VERSION 1.0)
# Specify all the source files for the project.
set( ENGINE_SOURCES
    Source/Main.cxx
)
# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 03)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Adds an executable
add_executable(Main main.cxx)
