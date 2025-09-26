#include "flx_instance.h"
#include <iostream>

#include "./input/flx_input.h"
#include "input/input_devices/flx_keyboard_device.h"
#include "input/input_devices/flx_mouse_device.h"

FLX_Instance::FLX_Instance(const FLX_InstanceOptions& options) : _options(options) {}

void FLX_Instance::run() const {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    const FLX_Window window(_options.window_options);

    bool running = true;

    FLX_Input* input = new FLX_Input();

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

            input->update_events(event);
        }

        input->update();

        if (input->get_mouse_device()-) {
            std::cout << "Mouse button down" << std::endl;
        }

        input->reset();
    }

    window.destroy();
}