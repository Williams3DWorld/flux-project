cmake_minimum_required (VERSION 3.8)

add_executable (sandbox src/main.cpp
        src/scenes/menu_scene.h
        src/scenes/game_scene.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sandbox PROPERTY CXX_STANDARD 20)
endif()

add_custom_command(TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Flux/libs/SDL3/bin/SDL3.dll
        $<TARGET_FILE_DIR:sandbox>/SDL3.dll
)

add_custom_command(TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Flux/libs/SDL3_image/bin/SDL3_image.dll
        $<TARGET_FILE_DIR:sandbox>/SDL3_image.dll
)

add_custom_command(TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/Flux/libs/SDL3_mixer/bin/SDL3_mixer.dll
        $<TARGET_FILE_DIR:sandbox>/SDL3_mixer.dll
)

target_link_libraries(sandbox PRIVATE flux)