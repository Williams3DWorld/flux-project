#pragma once

#ifndef FLX_TEXTURE_H
#define FLX_TEXTURE_H

#include "flx_resource.h"
#include "SDL3/SDL_render.h"

struct FLX_TextureConfig : FLX_ResourceConfig {
      SDL_Texture* texture = nullptr;
};

class FLX_Texture : FLX_Resource<FLX_TextureConfig> {
public:
    explicit FLX_Texture(FLX_TextureConfig&& config);
    ~FLX_Texture() override;

    void destroy() override;

    [[nodiscard]] SDL_Texture* texture() const noexcept;
};

#endif