#include "flx_texture_source.h"

FLX_TextureSource::FLX_TextureSource(FLX_TextureSourceConfig&& config) :
    FLX_Asset(std::move(config)) {}

FLX_TextureSource::~FLX_TextureSource() {
    SDL_DestroyTexture(_config.data);
}

[[nodiscard]] SDL_Texture* FLX_TextureSource::texture() const noexcept {
    return _config.data;
}

[[nodiscard]] FLX_AssetType FLX_TextureSource::asset_type() const noexcept {
    return FLX_AssetType::TextureSource;
}