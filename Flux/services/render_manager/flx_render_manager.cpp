#include "flx_render_manager.h"
#include "flx_renderer.h"

FLX_RenderManager::FLX_RenderManager(FLX_RenderManagerConfig &&config) :
    FLX_Service(std::move(config)),
    _renderer(std::make_shared<FLX_Renderer>(std::forward<FLX_RendererConfig>({.window = config.window}))) {}

[[nodiscard]] FLX_Renderer* FLX_RenderManager::renderer() const noexcept {
    return _renderer.get();
}