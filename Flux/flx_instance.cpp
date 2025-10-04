#include "flx_instance.h"
#include <iostream>

#include "./input/flx_input.h"
#include "./input/flx_input_map.h"

FLX_Instance::FLX_Instance(const FLX_InstanceOptions& options) : _options(options) {}

void FLX_Instance::run() const {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    const FLX_Window window(_options.window_options);
    FLX_Input input;
    FLX_InputMap input_map(_options.input_options, input);

    bool running = true;

    while (running) {
        SDL_Event event { 0 };

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

            input.poll_events(event);
        }

        input.update();

        // TODO: update stuff in here

        input.reset();
    }

    window.destroy();
}