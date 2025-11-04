#include "flx_instance.h"
#include "flx_context.h"

#include <iostream>

#include "SDL3_mixer/SDL_mixer.h"

FLX_Instance::FLX_Instance(FLX_InstanceConfig&& config) :
    FLX_Object(std::move(config)) {}

void FLX_Instance::run() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    if (!MIX_Init()) {
        std::cerr << "MIX_Init failed: " << SDL_GetError() << "\n";
        SDL_Quit();
    }

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

    std::cout << "Current working dir: " << SDL_GetBasePath() << std::endl;

    // SDL mixer test ////////////////
    SDL_AudioDeviceID dev = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
    if (!dev) {
        std::cerr << "SDL_OpenAudioDevice failed: " << SDL_GetError() << "\n";
    }

    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = 48000;
    audio_spec.format = SDL_AUDIO_F32;
    audio_spec.channels = 2;

    MIX_Mixer* mixer = MIX_CreateMixerDevice(dev, &audio_spec);
    if (!mixer) {
        std::cerr << "Error creating mixer: " << SDL_GetError() << "\n";
    }

    MIX_Audio* sound = MIX_LoadAudio(mixer, "bgm.mp3", true);
    if (!sound) {
        std::cerr << "Error loading sound: " << SDL_GetError() << "\n";
    }

    MIX_Track* track = MIX_CreateTrack(mixer);
    if (!track) {
        std::cerr << "Error creating track: " << SDL_GetError() << "\n";
    }

    if (!MIX_SetTrackAudio(track, sound)) {
        std::cerr << "MIX_SetTrackAudio failed: " << SDL_GetError() << "\n";
    }

    if (!MIX_PlayTrack(track, 0)) {
        std::cerr << "MIX_PlayTrack failed: " << SDL_GetError() << "\n";
    } else {
        std::cout << "Playing sound...\n";
    }
    //////////////////////////////////

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