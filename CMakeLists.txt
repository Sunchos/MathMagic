cmake_minimum_required(VERSION 2.8)

project(MathMagic)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
#
# External dependencies.
#

include(ExternalProject)

# Install location for external dependencies.
set(EXTERNAL_PATH "${CMAKE_BINARY_DIR}/external")

#
# Subdirectories.
#

add_subdirectory(modules/MathApplication)
add_subdirectory(modules/MathLib)
enable_testing ()
add_subdirectory(modules/TestSolution)