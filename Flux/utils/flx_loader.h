#pragma once

#ifndef FLX_LOADER_H
#define FLX_LOADER_H

#include "flx_service.h"
#include "core/flx_string_view.h"

using FLX_LoaderConfig = FLX_ServiceConfig;

template<typename T>
concept FLX_LoaderConfigDerived = flx_is_base_of<FLX_LoaderConfig, T>;

template<typename FLX_LoaderConfigDerived, typename Data>
class FLX_Loader : public FLX_Service<FLX_LoaderConfigDerived> {
public:
    explicit FLX_Loader(FLX_LoaderConfigDerived&& config);
    ~FLX_Loader() override = default;

    virtual Data load(flx_string_view path) = 0;
};

template<typename FLX_LoaderConfigDerived, typename Data>
FLX_Loader<FLX_LoaderConfigDerived, Data>::FLX_Loader(FLX_LoaderConfigDerived&& config) :
    FLX_Service<FLX_LoaderConfigDerived>(std::forward<FLX_LoaderConfigDerived>(config)) {}

#endif