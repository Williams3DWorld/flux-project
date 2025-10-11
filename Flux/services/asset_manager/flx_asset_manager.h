#pragma once

#ifndef FLX_ASSET_MANAGER_H
#define FLX_ASSET_MANAGER_H

#include "flx_service.h"
#include "assets/flx_texture_source.h"
#include "types/flx_asset_store.h"

struct FLX_AssetManagerConfig : FLX_ServiceConfig {

};

class FLX_AssetManager final : public FLX_Service<FLX_AssetManagerConfig> {
public:
    explicit FLX_AssetManager(FLX_AssetManagerConfig&& config);
    ~FLX_AssetManager() override;

private:
    flx_asset_store<FLX_TextureSource> _texture_sources;
};

#endif