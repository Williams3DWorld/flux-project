#include "flx_renderer.h"
#include "flx_window.h"

FLX_Renderer::FLX_Renderer(FLX_RendererConfig &&config) :
    FLX_Object(std::forward<FLX_RendererConfig>(config)),
    _renderer(SDL_CreateRenderer(config.window->window(), NULL)) {
}

FLX_Renderer::~FLX_Renderer() {
    SDL_DestroyRenderer(_renderer);
}

[[nodiscard]] SDL_Renderer* FLX_Renderer::renderer() noexcept {
    return _renderer;
}