#include "flx_window.h"

FLX_Window::FLX_Window(const FLX_WindowOptions &options) {
    SDL_WindowFlags flags = SDL_WINDOW_OPENGL;

    if (options.fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    if (options.resizable) {
        flags |= SDL_WINDOW_RESIZABLE;
    }

    _sdl_window = SDL_CreateWindow(options.title, options.width, options.height, flags);
}

FLX_Window::~FLX_Window() {
    if (_sdl_window) {
        destroy();
    }
}

void FLX_Window::destroy() const {
    SDL_DestroyWindow(_sdl_window);
}
