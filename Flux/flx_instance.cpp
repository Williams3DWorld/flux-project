#include "flx_instance.h"
#include "flx_context.h"
#include "flx_event.h"

#include <iostream>

#include "./services/scene_manager/scenes/flx_test_scene_01.h"
#include "./services/scene_manager/scenes/flx_test_scene_02.h"

FLX_Instance::FLX_Instance(FLX_InstanceConfig&& config) :
    FLX_Object(std::move(config)) {}

void FLX_Instance::run() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    // Create window
    const std::shared_ptr<FLX_Window> window = std::make_shared<FLX_Window>(std::move(_config.window));

    // Create context
    const std::shared_ptr<FLX_Context> ctx = std::make_shared<FLX_Context>();

    // Create services
    _input_manager = std::make_shared<FLX_InputManager>(FLX_InputManager({.actions = {
        {"scene_1", {FLX_Scancode::Scancode1, FLX_InputDeviceType::Keyboard}},
        {"scene_2", {FLX_Scancode::Scancode2, FLX_InputDeviceType::Keyboard}}
    }}));

    _asset_manager = std::make_shared<FLX_AssetManager>(FLX_AssetManager({}));
    _render_manager = std::make_shared<FLX_RenderManager>(FLX_RenderManager({.window = window.get()}));

    _scene_manager = std::make_shared<FLX_SceneManager>(FLX_SceneManager({.scenes = {
        {"test_scene_01", std::make_shared<FLX_TestScene01>()},
        {"test_scene_02", std::make_shared<FLX_TestScene02>()},
    }}));

    // Assign context pointers
    ctx->input_manager = _input_manager.get();
    ctx->asset_manager = _asset_manager.get();
    ctx->render_manager = _render_manager.get();
    ctx->scene_manager = _scene_manager.get();

    // Inject context
    _input_manager->inject(ctx.get());
    _asset_manager->inject(ctx.get());
    _render_manager->inject(ctx.get());
    _scene_manager->inject(ctx.get());

    bool running = true;

    while (running) {
        FLX_Event event = FLX_Event({});

        while (SDL_PollEvent(&event.event())) {
            if (event.event().type == SDL_EVENT_QUIT) {
                running = false;
            }

            if (_input_manager->is_action("scene_1")) {
                _scene_manager->set_active_scene("test_scene_01");
            }

            if (_input_manager->is_action("scene_2")) {
                _scene_manager->set_active_scene("test_scene_02");
            }

            _input_manager->poll_events(event);
        }
    }
}