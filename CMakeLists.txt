cmake_minimum_required(VERSION 3.10)
# Set the project name.
project(Propiertary-Engine VERSION 1.0)
# Add the project version into the engine.
# configure_file([FILE].in [FILE])
# Specify all the source files for the project.

# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set( ENGINE_SOURCES
    Source/Entry/Main.cpp
)
# Set the engine version.
set(ENGINE_VERSION_MAJOR 1)
set(ENGINE_VERSOIN_MINOR 0)
set(ENGINE_VERSION_PATCH 0)
# Adds an executable
add_executable(Main Source/Entry/Main.cpp)
