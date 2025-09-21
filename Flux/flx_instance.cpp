#include "flx_instance.h"

FLX_Instance::FLX_Instance(const FLX_InstanceOptions& options) :
    _window(FLX_Window({})) {}

void FLX_Instance::run() const {
    auto running = true;

    while (running) {
        SDL_Event event{ 0 };

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                {
                    running = false;
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }


}

void FLX_Instance::_cleanup() const {
    _window.destroy();

    SDL_Quit();
}

