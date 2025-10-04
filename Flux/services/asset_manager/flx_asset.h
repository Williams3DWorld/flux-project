#pragma once

#ifndef FLX_ASSET_H
#define FLX_ASSET_H

#include "types/flx_asset_type.h"
#include "flx_resource.h"

using FLX_AssetConfig = FLX_ResourceConfig;

template <typename T>
concept FLX_AssetConfigDerived = FLX_ResourceConfigDerived<T>;

template <typename FLX_AssetConfigDerived>
class FLX_Asset : protected FLX_Resource<FLX_AssetConfigDerived> {
public:
    explicit FLX_Asset(FLX_AssetConfigDerived&& config);
    ~FLX_Asset() override = default;

    void destroy() override = 0;

    [[nodiscard]] virtual FLX_AssetType asset_type() const noexcept = 0;
};

#endif