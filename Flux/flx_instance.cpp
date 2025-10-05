#include "flx_instance.h"
#include "./input/flx_input_manager.h"
#include <iostream>

FLX_Instance::FLX_Instance(const FLX_InstanceOptions& options) : _options(options) {}

void FLX_Instance::run() const {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    const FLX_Window window(_options.window_options);
    const FLX_InputManager input(_options.input_options);

    bool running = true;

    while (running) {
        SDL_Event event { 0 };

        input.update();

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

        if (input.input_map().is_action_pressed("interact")) {
            std::cout << "interact" << std::endl;
        }
    }

    window.destroy();
}