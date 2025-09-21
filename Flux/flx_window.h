#pragma once

#ifndef FLX_WINDOW_H
#define FLX_WINDOW_H

#include "flx_size.h"

#include <SDL3/SDL.h>

constexpr auto FLX_WINDOW_DEFAULT_TITLE = "Flux";
constexpr const int FLX_WINDOW_DEFAULT_WIDTH = 800;
constexpr const int FLX_WINDOW_DEFAULT_HEIGHT = 600;
constexpr const SDL_WindowFlags FLX_WINDOW_DEFAULT_FLAGS = SDL_WINDOW_RESIZABLE;

struct FLX_WindowOptions : FLX_Size {
    const char* title = FLX_WINDOW_DEFAULT_TITLE;
    const FLX_Size size = {
        .width = FLX_WINDOW_DEFAULT_WIDTH,
        .height = FLX_WINDOW_DEFAULT_HEIGHT
    };

    SDL_WindowFlags flags = FLX_WINDOW_DEFAULT_FLAGS;
};

class FLX_Window {
public:
    explicit FLX_Window(const FLX_WindowOptions &options);
    ~FLX_Window();
    void destroy() const;

private:
    SDL_Window* _sdl_window;
};

#endif