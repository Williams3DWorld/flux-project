#pragma once

#ifndef FLX_TEXTURE_SOURCE_H
#define FLX_TEXTURE_SOURCE_H

#include "SDL3/SDL_render.h"
#include "services/asset_manager/flx_asset.h"

using FLX_TextureSourceConfig = FLX_AssetConfig<SDL_Texture*>;

class FLX_TextureSource final : public FLX_Asset<FLX_TextureSourceConfig> {
public:
    explicit FLX_TextureSource(FLX_TextureSourceConfig&& config);
    ~FLX_TextureSource() override;

    [[nodiscard]] FLX_AssetType asset_type() const noexcept override;

    [[nodiscard]] SDL_Texture* texture() const noexcept;
};

#endif