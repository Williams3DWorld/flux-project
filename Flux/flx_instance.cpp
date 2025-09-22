#include "flx_instance.h"

FLX_Instance::FLX_Instance(const FLX_InstanceOptions& options) : _options(options) {}

void FLX_Instance::run() const {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    const FLX_Window window(_options.window_options);

    bool running = true;

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

    window.destroy();
}