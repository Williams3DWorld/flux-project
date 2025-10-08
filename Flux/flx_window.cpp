#include "flx_window.h"
#include "core/flx_memory.h"

FLX_Window::FLX_Window(FLX_WindowConfig&& config) :
    FLX_Object(std::move(config)) {
    SDL_WindowFlags flags = SDL_WINDOW_OPENGL;

    if (config.fullscreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    if (config.resizable) {
        flags |= SDL_WINDOW_RESIZABLE;
    }

    _window = SDL_CreateWindow(config.title, config.width, config.height, flags);
}

FLX_Window::~FLX_Window() {
    SDL_DestroyWindow(_window);
}

[[nodiscard]] SDL_Window *FLX_Window::window() const noexcept {
    return _window;
}
