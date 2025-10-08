#include "flx_instance.h"
#include "flx_context.h"

FLX_Instance::FLX_Instance(FLX_InstanceConfig&& config) :
    FLX_Object(std::move(config)) {}

void FLX_Instance::run() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // Create window
    const std::shared_ptr<FLX_Window> window = std::make_shared<FLX_Window>(std::move(_config.window));

    // Create context
    const std::shared_ptr<FLX_Context> ctx = std::make_shared<FLX_Context>();

    // Create services
    _asset_manager = std::make_shared<FLX_AssetManager>(FLX_AssetManager({}));
    _render_manager = std::make_shared<FLX_RenderManager>(FLX_RenderManager({.window = window.get()}));

    // Assign context pointers
    ctx->asset_manager = _asset_manager.get();
    ctx->render_manager = _render_manager.get();

    // Inject context
    _asset_manager->inject(ctx.get());
    _render_manager->inject(ctx.get());

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