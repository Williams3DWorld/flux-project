#pragma once

#ifndef FLX_ASSET_MANAGER_H
#define FLX_ASSET_MANAGER_H

#include "flx_texture_source.h"
#include "types/flx_asset_store.h"

class FLX_AssetManager {
public:
    FLX_AssetManager() = default;
    ~FLX_AssetManager() = default;

    [[nodiscard]] flx_weak<FLX_TextureSource> texture_source(const flx_string& identifier) const;

private:
    flx_asset_store<FLX_TextureSource> _texture_sources;
};

#endif