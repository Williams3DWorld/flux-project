#include "flx_instance.h"

#include <iostream>

#include "flx_context.h"

FLX_Instance::FLX_Instance(FLX_InstanceConfig&& config) :
    FLX_Object(std::forward<FLX_InstanceConfig>(config)) {}

void FLX_Instance::run() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    FLX_Window window(std::forward<FLX_WindowConfig>(_config.window));

    // Create the context
    const flx_shared<FLX_Context> ctx = flx_make_shared<FLX_Context>();

    // Create the services
    _asset_manager = flx_make_shared<FLX_AssetManager>(FLX_AssetManager({}));

    // Assign context's pointers
    ctx.get()->asset_manager = _asset_manager.get();

    // Inject the context to services
    _asset_manager.get()->inject(ctx.get());

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
}