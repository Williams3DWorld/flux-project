#pragma once

#ifndef FLX_LOADER_H
#define FLX_LOADER_H

#include "flx_resource.h"
#include "types/flx_unordered_map.h"
#include "types/flx_inheritance.h"
#include "types/flx_memory.h"
#include "types/flx_path_map.h"

struct FLX_LoaderConfig {
    const flx_path_map path_config;
};

template<typename T>
concept FLX_LoaderConfigDerived = flx_is_base_of<FLX_LoaderConfig, T>;

template<typename T, typename ResourceConfig>
concept FLX_ResourceDerived = flx_is_base_of<FLX_Resource<ResourceConfig>, T>;

template<typename ResourceConfig, typename Resource>
requires FLX_ResourceDerived<Resource, ResourceConfig>
using FLX_LoaderResult = flx_unordered_map<const char*, flx_unique<Resource>>;

template<typename LoaderConfig, typename ResourceConfig, typename Resource>
requires FLX_LoaderConfigDerived<LoaderConfig> && FLX_ResourceDerived<Resource, ResourceConfig>
class FLX_Loader : public FLX_Object<LoaderConfig> {
public:
    explicit FLX_Loader(const LoaderConfig&& config);

    virtual FLX_LoaderResult<Resource, ResourceConfig> load() = 0;
};

#endif