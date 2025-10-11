#pragma once

#ifndef FLX_RENDER_MANAGER_H
#define FLX_RENDER_MANAGER_H

#include <memory>
#include "flx_service.h"

class FLX_Window;
class FLX_Renderer;

struct FLX_RenderManagerConfig : FLX_ServiceConfig {
    FLX_Window* window;
};

class FLX_RenderManager final : public FLX_Service<FLX_RenderManagerConfig> {
public:
    explicit FLX_RenderManager(FLX_RenderManagerConfig&& config);
    ~FLX_RenderManager() override = default;

    [[nodiscard]] FLX_Renderer* renderer() const noexcept;

private:
    std::shared_ptr<FLX_Renderer> _renderer;
};

#endif