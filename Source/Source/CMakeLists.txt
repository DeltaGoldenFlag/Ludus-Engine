cmake_minimum_required(VERSION 3.10)
# =============================================================================
file(GLOB ENGINE_SOURCES "*.cxx")
source_group("Engine" FILES )
# Adds the executable.
add_executable("Game" Main.cpp)
# =============================================================================