#include "flx_texture_loader.h"
#include <string_view>
#include <SDL3_image/SDL_image.h>
#include "flx_renderer.h"
#include "services/render_manager/flx_render_manager.h"

FLX_TextureLoader::FLX_TextureLoader(FLX_TextureLoaderConfig&& config) :
    FLX_Loader(std::move(config)) {}

SDL_Texture* FLX_TextureLoader::load(std::string_view path) {
    const FLX_RenderManager* render_manager = _ctx->render_manager;

    SDL_Renderer* renderer = render_manager->renderer()->renderer();

    SDL_Texture* texture = IMG_LoadTexture(renderer, path.data());

    return texture;
}
