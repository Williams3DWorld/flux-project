#pragma once

#ifndef FLX_RENDERER_H
#define FLX_RENDERER_H

#include "flx_object.h"
#include "SDL3/SDL_render.h"

class FLX_Window;

struct FLX_RendererConfig : FLX_ObjectConfig {
    FLX_Window* window;
};

class FLX_Renderer final : public FLX_Object<FLX_RendererConfig> {
public:
    explicit FLX_Renderer(FLX_RendererConfig&& config);
    ~FLX_Renderer() override;

    [[nodiscard]] SDL_Renderer* renderer() const noexcept;

private:
    SDL_Renderer* _renderer;
};

#endif