#include "flx_texture.h"
#include "flx_resource.h"
#include "types/flx_memory.h"

FLX_Texture::FLX_Texture(FLX_TextureConfig&& config) : FLX_Resource(flx_move(config)) {}

FLX_Texture::~FLX_Texture() {
    FLX_Texture::destroy();
}

void FLX_Texture::destroy() {
    SDL_DestroyTexture(this->_config.texture);
}

[[nodiscard]] SDL_Texture* FLX_Texture::texture() const noexcept {
    return this->_config.texture;
}