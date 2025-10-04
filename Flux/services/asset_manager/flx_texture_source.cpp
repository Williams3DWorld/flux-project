#include "flx_texture_source.h"
#include "flx_resource.h"
#include "types/flx_memory.h"

FLX_TextureSource::FLX_TextureSource(FLX_TextureSourceConfig&& config) :
    FLX_Asset(flx_move(config)) {}

FLX_TextureSource::~FLX_TextureSource() {
    FLX_TextureSource::destroy();
}

void FLX_TextureSource::destroy() {
    SDL_DestroyTexture(this->_config.texture);
}

[[nodiscard]] SDL_Texture* FLX_TextureSource::texture() const noexcept {
    return this->_config.texture;
}

[[nodiscard]] FLX_AssetType FLX_TextureSource::asset_type() const noexcept {
    return FLX_AssetType::TextureSource;
}