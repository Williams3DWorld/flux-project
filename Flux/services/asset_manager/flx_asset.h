#pragma once

#ifndef FLX_ASSET_H
#define FLX_ASSET_H

#include "flx_resource.h"
#include "types/flx_asset_type.h"

template<typename T>
struct FLX_AssetConfig : FLX_ResourceConfig {
    T data;
};

template <typename T, typename Data>
concept FLX_AssetConfigDerived = flx_is_base_of<FLX_AssetConfig<Data>, T>;

template <typename FLX_AssetConfigDerived>
class FLX_Asset : public FLX_Resource<FLX_AssetConfigDerived> {
public:
    explicit FLX_Asset(FLX_AssetConfigDerived&& config);
    ~FLX_Asset() override = default;

    [[nodiscard]] virtual FLX_AssetType asset_type() const noexcept = 0;
};

template <typename FLX_AssetConfigDerived>
FLX_Asset<FLX_AssetConfigDerived>::FLX_Asset(FLX_AssetConfigDerived&& config) :
    FLX_Resource<FLX_AssetConfigDerived>(std::forward<FLX_AssetConfigDerived>(config)) {};

#endif