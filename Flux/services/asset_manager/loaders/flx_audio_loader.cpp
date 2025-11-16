#include "flx_audio_loader.h"
#include <iostream>

FLX_AudioLoader::FLX_AudioLoader(FLX_AudioLoaderConfig&& config) : FLX_Loader(std::move(config)) {
    _audio_device_id = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
    if (!_audio_device_id) {
        std::cerr << "SDL_OpenAudioDevice failed: " << SDL_GetError() << "\n";
    }

    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = 48000;
    audio_spec.format = SDL_AUDIO_F32;
    audio_spec.channels = 2;

    _audio_mixer = MIX_CreateMixerDevice(_audio_device_id, &audio_spec);
    if (!_audio_mixer) {
        std::cerr << "Error creating mixer: " << SDL_GetError() << "\n";
    }

    create_track_pool(10);
}

MIX_Audio* FLX_AudioLoader::load(std::string_view path) {
    MIX_Audio* sound = MIX_LoadAudio(_audio_mixer, path.data(), true);
    if (!sound) {
        std::cerr << "Error loading sound: " << SDL_GetError() << "\n";
        return nullptr;
    }

    MIX_Track* track = get_track();
    if (!MIX_SetTrackAudio(track, sound)) {
        std::cerr << "MIX_SetTrackAudio failed: " << SDL_GetError() << "\n";
    }

    _audio_source.push_back({
        .identifier = "test_sound",
        .audio = sound,
        .track = track
    });

    return sound;
}

void FLX_AudioLoader::create_track_pool(int pool_size) {
    if (pool_size <= 0) {
        return;
    }

    for (int i = 0; i < pool_size; i++) {
        MIX_Track* track = MIX_CreateTrack(_audio_mixer);
        _track_pool.push_back(track);
    }
}

MIX_Track *FLX_AudioLoader::get_track() {
    MIX_Track* track = _track_pool[0];
    _track_pool.erase(_track_pool.begin());
    return track;
}


