#pragma once

#ifndef FLX_ASSET_H
#define FLX_ASSET_H

#include "flx_cache.h"
#include "flx_resource.h"
#include "flx_texture.h"

template<typename T>
using flx_asset_store = FLX_Cache<flx_string, T>;

struct FLX_AssetData {
    const flx_asset_store<FLX_Texture> textures;
};

class FLX_Asset {
public:
    FLX_Asset();
    ~FLX_Asset();

private:
    FLX_AssetData _data;
};

#endif