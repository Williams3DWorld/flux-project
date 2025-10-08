#include "flx_instance.h"
#include "flx_context.h"
#include "flx_renderer.h"

FLX_Instance::FLX_Instance(FLX_InstanceConfig&& config) :
    FLX_Object(std::move(config)) {}

void FLX_Instance::run() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // Create the window
    const std::shared_ptr<FLX_Window> window = std::make_shared<FLX_Window>(std::move(_config.window));

    // Create the context
    const std::shared_ptr<FLX_Context> ctx = std::make_shared<FLX_Context>();

    // Create the services
    _asset_manager = std::make_shared<FLX_AssetManager>(FLX_AssetManager({}));

    // Assign context's pointers
    ctx->asset_manager = _asset_manager.get();

    // Inject the context to services
    _asset_manager->inject(ctx.get());

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