cmake_minimum_required (VERSION 3.8)

add_library (flux STATIC
        flx.cpp
        flx.h
        flx_window.cpp
        flx_window.h
        flx_instance.cpp
        flx_instance.h
        core/flx_memory.h
        core/flx_unordered_map.h
        services/scene_manager/components/flx_component.h
        utils/flx_cache.h
        FLX_Resource.h
        flx_object.h
        core/flx_integer.h
        core/flx_inheritance.h
        utils/flx_loader.h
        services/asset_manager/flx_asset_manager.cpp
        services/asset_manager/flx_asset_manager.h
        services/asset_manager/assets/flx_texture_source.cpp
        services/asset_manager/assets/flx_texture_source.h
        services/asset_manager/types/flx_asset_type.h
        core/flx_string.h
        services/asset_manager/flx_asset.h
        services/asset_manager/types/flx_asset_store.h
        core/flx_string_view.h
        services/asset_manager/loaders/flx_texture_loader.cpp
        services/asset_manager/loaders/flx_texture_loader.h
        flx_service.h
        flx_context.h
        core/flx_ranges.h
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET flux PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(flux
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_image/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer/include
)

target_link_libraries(flux PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3/lib/SDL3.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_image/lib/SDL3_image.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer/lib/SDL3_mixer.lib
)
