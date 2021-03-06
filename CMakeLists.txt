cmake_minimum_required(VERSION 3.10)
# Set the project name.
project(Ludus-Engine VERSION 1.0)
# Add the project version into the engine.
# configure_file([FILE].in [FILE])
# Specify all the source files for the project.

# =============================================================================
# Set the build configuration for Linux.
set(ENGINE_DEBUG 1)
# Specify the C++ standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# =============================================================================

# =============================================================================
# Get the source directories.
file(GLOB SOURCES "Source/Source/*.cpp")
# =============================================================================

# =============================================================================
# Set the compiler flags.
if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()
if(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")
    if(ENGINE_DEBUG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
    endif()
endif()
# =============================================================================

# =============================================================================
# Set the engine version.
set(ENGINE_VERSION_MAJOR 1)
set(ENGINE_VERSION_MINOR 0)
set(ENGINE_VERSION_PATCH 0)
# Adds the executable for the engine.
# add_executable(Build ${SOURCES})
# target_include_directories(Build PRIVATE "Source/Include/")
# Adds the executable for the testing center.
file(GLOB SOURCES ${SOURCES} "Tests/*.cpp")
add_executable(Tests ${SOURCES})
target_include_directories(Tests PRIVATE "Source/Include/")
# =============================================================================