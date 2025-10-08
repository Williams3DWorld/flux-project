#pragma once

#ifndef FLX_WINDOW_H
#define FLX_WINDOW_H

#include <SDL3/SDL.h>
#include "flx_object.h"

struct FLX_WindowConfig : FLX_ObjectConfig {
    const char* title = "Flux";
    int width = 800;
    int height = 600;
    bool fullscreen = false;
    bool resizable = false;
};

class FLX_Window final : public FLX_Object<FLX_WindowConfig> {
public:
    explicit FLX_Window(FLX_WindowConfig&& config);
    ~FLX_Window() override;

    [[nodiscard]] SDL_Window* window() const noexcept;

private:
    SDL_Window* _window;
};

#endif