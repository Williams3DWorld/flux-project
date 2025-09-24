#pragma once

#ifndef FLX_WINDOW_H
#define FLX_WINDOW_H

#include "flx_size.h"

#include <SDL3/SDL.h>

struct FLX_WindowOptions : FLX_Size {
    const char* title = "Flux";
    int width = 800;
    int height = 600;
    bool fullscreen = false;
    bool resizable = false;
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