#pragma once

#ifndef FLX_TEXTURE_LOADER_H
#define FLX_TEXTURE_LOADER_H

#include <string_view>
#include "SDL3/SDL_render.h"
#include "utils/flx_loader.h"

class FLX_TextureLoader final : public FLX_Loader<FLX_LoaderConfig, SDL_Texture*> {
    explicit FLX_TextureLoader(FLX_LoaderConfig&& config);
    ~FLX_TextureLoader() override = default;

    SDL_Texture* load(std::string_view path) override;
};

#endif