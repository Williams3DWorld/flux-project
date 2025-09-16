cmake_minimum_required (VERSION 3.8)

add_executable (game game.cpp )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET game PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(game PRIVATE flux)