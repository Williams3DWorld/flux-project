#include "flx_audio_loader.h"
#include <iostream>
#include <filesystem>

FLX_AudioLoader::FLX_AudioLoader(FLX_AudioLoaderConfig&& config)
    : FLX_Loader(std::move(config)), _mixer(create_mixer()) {
    create_track_pool(MAX_NUM_TRACKS);
}

MixerUniquePtr FLX_AudioLoader::create_mixer() {
    _device_id = SDL_OpenAudioDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
    if (!_device_id) {
        std::cerr << "SDL_OpenAudioDevice failed: " << SDL_GetError() << "\n";
        return MixerUniquePtr(nullptr, &MIX_DestroyMixer);
    }

    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = 48000;
    audio_spec.format = SDL_AUDIO_F32;
    audio_spec.channels = 2;

    return std::unique_ptr<MIX_Mixer, decltype(&MIX_DestroyMixer)>(
        MIX_CreateMixerDevice(_device_id, &audio_spec),
        &MIX_DestroyMixer
    );
}

MIX_Track* FLX_AudioLoader::load(const std::string_view path) {
    const std::filesystem::path p(path);

    MIX_Audio* sound = MIX_LoadAudio(_mixer.get(), path.data(), true);
    if (!sound) {
        std::cerr << "Error loading sound: " << SDL_GetError() << "\n";
        return nullptr;
    }

    MIX_Track* track = get_track();
    if (!MIX_SetTrackAudio(track, sound)) {
        std::cerr << "MIX_SetTrackAudio failed: " << SDL_GetError() << "\n";
    }

    _sources.push_back({
        .identifier = p.stem().string(),
        .audio = AudioUniquePtr(sound, &MIX_DestroyAudio),
        .track = track
    });

    return track;
}

void FLX_AudioLoader::create_track_pool(const int pool_size) {
    if (pool_size <= 0) {
        std::cerr << "Track pool size is equal to or less than 0!" << std::endl;
        return;
    }

    for (int i = 0; i < pool_size; i++) {
        auto track = TrackUniquePtr(
            MIX_CreateTrack(_mixer.get()), &MIX_DestroyTrack
        );
        _track_pool.push_back(std::move(track));
    }
}

MIX_Track *FLX_AudioLoader::get_track() {
    if (_track_pool.empty()) {
        std::cerr << "No tracks available!" << std::endl;
        return nullptr;
    }
    MIX_Track* track = _track_pool.front().release();
    _track_pool.pop_front();
    return track;
}


