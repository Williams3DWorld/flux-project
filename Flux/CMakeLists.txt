cmake_minimum_required (VERSION 3.8)

add_library (flux STATIC
        flux.cpp
        flux.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET flux PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(flux
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(flux
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_image/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer/include
)

target_link_libraries(flux PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3/lib/SDL3.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_image/lib/SDL3_image.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer/lib/SDL3_mixer.lib
)
