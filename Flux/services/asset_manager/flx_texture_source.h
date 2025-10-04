#pragma once

#ifndef FLX_TEXTURE_SOURCE_H
#define FLX_TEXTURE_SOURCE_H

#include "flx_asset.h"
#include "SDL3/SDL_render.h"

struct FLX_TextureSourceConfig : FLX_AssetConfig {
      SDL_Texture* texture = nullptr;
};

class FLX_TextureSource : FLX_Asset<FLX_TextureSourceConfig> {
public:
    explicit FLX_TextureSource(FLX_TextureSourceConfig&& config);
    ~FLX_TextureSource() override;

    void destroy() override;

    [[nodiscard]] FLX_AssetType asset_type() const noexcept override;

    [[nodiscard]] SDL_Texture* texture() const noexcept;
};

#endif