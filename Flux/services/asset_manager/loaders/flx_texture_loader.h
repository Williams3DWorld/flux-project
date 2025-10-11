#pragma once

#ifndef FLX_TEXTURE_LOADER_H
#define FLX_TEXTURE_LOADER_H

#include <string_view>
#include "SDL3/SDL_render.h"
#include "utils/flx_loader.h"

using FLX_TextureLoaderConfig = FLX_LoaderConfig;

class FLX_TextureLoader final : public FLX_Loader<FLX_TextureLoaderConfig, SDL_Texture*> {
public:
    explicit FLX_TextureLoader(FLX_TextureLoaderConfig&& config);
    ~FLX_TextureLoader() override = default;

    SDL_Texture* load(std::string_view path) override;
};

#endif