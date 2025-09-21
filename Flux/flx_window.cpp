#include "flx_window.h"

FLX_Window::FLX_Window(const FLX_WindowOptions &options) :
    _sdl_window(SDL_CreateWindow(options.title, options.size.width, options.size.height, options.flags)) {}

FLX_Window::~FLX_Window() {
    if (_sdl_window) {
        destroy();
    }
}
void FLX_Window::destroy() const {
    SDL_DestroyWindow(_sdl_window);
}
