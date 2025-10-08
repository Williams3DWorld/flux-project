#include "flx_texture_source.h"

FLX_TextureSource::FLX_TextureSource(FLX_TextureSourceConfig&& config) :
    FLX_Resource(std::move(config)) {}

FLX_TextureSource::~FLX_TextureSource() {
    SDL_DestroyTexture(_config.data);
}

[[nodiscard]] SDL_Texture* FLX_TextureSource::data() const noexcept {
    return _config.data;
}