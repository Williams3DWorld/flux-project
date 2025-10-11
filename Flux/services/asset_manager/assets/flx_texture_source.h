#pragma once

#ifndef FLX_TEXTURE_SOURCE_H
#define FLX_TEXTURE_SOURCE_H

#include "flx_resource.h"
#include "SDL3/SDL_render.h"

using FLX_TextureSourceConfig = FLX_ResourceConfig<SDL_Texture*>;

class FLX_TextureSource final : public FLX_Resource<FLX_TextureSourceConfig, SDL_Texture*> {
public:
    explicit FLX_TextureSource(FLX_TextureSourceConfig&& config);
    ~FLX_TextureSource() override;

    [[nodiscard]] SDL_Texture* data() const noexcept override;
};

#endif