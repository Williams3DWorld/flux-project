# CMakeList.txt : CMake project for game-project, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.8)

project ("flux")

# Add source to this project's executable.
add_library (flux STATIC flux.cpp
        flux.cpp
        flux.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET flux PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_include_directories(flux PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})