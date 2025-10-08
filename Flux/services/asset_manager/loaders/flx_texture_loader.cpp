#include "flx_texture_loader.h"
#include <string_view>

FLX_TextureLoader::FLX_TextureLoader(FLX_LoaderConfig&& config) :
    FLX_Loader(std::move(config)) {}

SDL_Texture* FLX_TextureLoader::load(std::string_view path) {
    SDL_Texture* texture = nullptr;

    // TODO!

    return texture;
}
