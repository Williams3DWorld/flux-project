#pragma once

#ifndef FLX_ASSET_LOADER_H
#define FLX_ASSET_LOADER_H

#include "flx_asset.h"
#include "utils/flx_loader.h"

template<typename T, typename AssetConfig>
concept FLX_AssetDerived = flx_is_base_of<FLX_Asset<AssetConfig>, T>;

template<typename T, typename Asset, typename AssetConfig>
requires FLX_AssetDerived<Asset, AssetConfig>
class FLX_AssetLoader : FLX_Loader<T> {
    explicit FLX_AssetLoader(flx_string_view path);
    ~FLX_AssetLoader() override = default;

    T load() override = 0;
};

#endif